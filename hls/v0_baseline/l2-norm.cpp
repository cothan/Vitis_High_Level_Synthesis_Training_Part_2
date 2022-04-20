#include "l2-norm.h"

i32 hls_l2_norm(const i32 a[N])
{
    i32 tmp, tmp_sum, sum = 0;
    for (auto i = 0; i < N; i++)
    {
        tmp = a[i] * a[i];
        tmp_sum = tmp + sum;
        if (tmp_sum < sum)
        {
            // Overflow happen, return maximum value then exit
            sum = INT32_MAX;
            break;
        }
        else
        {
            sum = tmp_sum;
        }
    }
    return sum;
}