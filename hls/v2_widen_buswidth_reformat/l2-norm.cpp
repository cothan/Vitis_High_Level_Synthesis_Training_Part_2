#include "l2-norm.h"

i32 hls_l2_norm(const i32 a[N / 16][16])
{
    i32 tmp, tmp_sum, sum = 0;
    unsigned int high, low;
    for (auto i = 0; i < N / 16; i++)
    {
        for (auto j = 0; j < 16; j++)
        {
            tmp = a[i][j] * a[i][j];
            tmp_sum = tmp + sum;

            if (tmp_sum < sum)
            {
                // Overflow happen, return maximum value then exit
                sum = INT32_MAX;
                return sum;
            }
            else
            {
                sum = tmp_sum;
            }
        }
    }
    return sum;
}