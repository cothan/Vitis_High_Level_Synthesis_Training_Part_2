#include <arm_neon.h>
#include <stdlib.h>
#include <stdio.h>
#define N 512

// Compile flags:
// gcc -O3 -o l2_norm l2-norm.cpp; ./l2_norm

int32_t neon_l2_norm(const int16_t a[N])
{
    int16x8x4_t tmp;
    int32x4_t neon_s, neon_sh;
    int32x2_t neon_t;
    int32_t s;

    neon_s = vdupq_n_s32(0);
    neon_sh = vdupq_n_s32(0);
    for (int i = 0; i < N; i += 32)
    {
        tmp = vld1q_s16_x4(&a[i]);

        neon_s = vqdmlal_s16(neon_s, vget_low_s32(tmp.val[0]), vget_low_s32(tmp.val[0]));
        neon_s = vqdmlal_s16(neon_s, vget_low_s32(tmp.val[1]), vget_low_s32(tmp.val[1]));
        neon_s = vqdmlal_s16(neon_s, vget_low_s32(tmp.val[2]), vget_low_s32(tmp.val[2]));
        neon_s = vqdmlal_s16(neon_s, vget_low_s32(tmp.val[3]), vget_low_s32(tmp.val[3]));

        neon_sh = vqdmlal_high_s16(neon_sh, tmp.val[0], tmp.val[0]);
        neon_sh = vqdmlal_high_s16(neon_sh, tmp.val[1], tmp.val[1]);
        neon_sh = vqdmlal_high_s16(neon_sh, tmp.val[2], tmp.val[2]);
        neon_sh = vqdmlal_high_s16(neon_sh, tmp.val[3], tmp.val[3]);
    }
    neon_s = vhaddq_s32(neon_s, neon_sh);

    // 32x4 -> 32x2
    neon_t = vqadd_s32(vget_low_s32(neon_s), vget_high_s32(neon_s));

    // 32x2 -> 32x1
    // Use saturating add to handle overflow
    s = vqadds_s32(vget_lane_s32(neon_t, 0), vget_lane_s32(neon_t, 1));

    return s;
}

int32_t l2_norm(const int16_t a[N])
{
    int32_t tmp, tmp_sum, sum;
    sum = 0;
    for (int i = 0; i < N; i++)
    {
        tmp = (int32_t)a[i];
        tmp *= tmp;
        tmp_sum = sum + tmp;
        if (tmp_sum < 0)
        {
            sum = tmp_sum;
        }
        else
        {
            // Overflow happen, return maximum value then exit
            sum = INT32_MAX;
            break;
        }
    }
    return sum;
}

#define TESTS 10000

int main()
{
    int16_t a[N];
    int32_t gold, test;

    for (int j = 0; j < TESTS; j++)
    {
        for (int i = 0; i < N; i++)
        {
            a[i] = rand() & 0xffff;
        }

        gold = l2_norm(a);
        test = neon_l2_norm(a);

        if (gold != test)
        {
            printf("ERROR %d != %d\n", gold, test);
            return 1;
        }
    }
    printf("OK\n");
    return 0;
}