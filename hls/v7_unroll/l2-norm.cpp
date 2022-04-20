#include "l2-norm.h"

i32 square(i32 a, int index)
{
    return a[index] * a[index];
}

// Saturating add
i32 sat_add(i32 a, i32 b)
{
    i32 tmp, ret;
    tmp = a + b;
    if ( (tmp < a) || (tmp < b) )
    {
        ret = INT32_MAX;
    }
    else
    {
        ret = tmp;
    }

    return ret; 
}

i32 adder_tree(const i32 a[16])
{
    i32 tmp[4], result;
    // First stage adder
adder_tree_1:
    for (auto i = 0; i < 4; i++)
    {
        for (auto j = 0; j < 4; j++)
        {
            auto prev = (i == 0) ? static_cast<i32>(0) : tmp[i];
            // tmp[i] = prev + square(a, 4*i + j);
            tmp[i] = sat_add(prev, square(a, 4*i + j));
        }
    }

adder_tree_2:
    // Second stage adder
    for (auto i = 0; i < 4; i++)
    {
        auto prev = (i == 0) ? static_cast<i32>(0) : result;
        // result = prev + tmp[i];
        result = sat_add(prev, tmp[i]);
    }
    return result;
}

i32 hls_l2_norm(const i32 a[N / 16][16])
{
#pragma HLS ARRAY_RESHAPE variable = a type = complete dim = 2
    i32 tmp, tmp_sum, sum = 0;
    
    for (auto i = 0; i < N / 16; i++)
    {
        tmp_sum = adder_tree(a[i]);
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