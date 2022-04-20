#include <stdlib.h>
#include <stdio.h>
#include "l2-norm.h"

i32 l2_norm(const i32 a[N]) {
    i32 tmp, tmp_sum, sum = 0;
    for (auto i = 0; i < N; i++) {
        tmp = a[i]*a[i];
        tmp_sum = tmp + sum; 
        if (tmp_sum < sum) {
            // Overflow happen, return maximum value then exit
            sum = INT32_MAX;
            break;
        }
        else {
            sum = tmp_sum;
        }
    }
    return sum; 
}

int main()
{
    srand(0);

    i32 a[N], e_gold, e_hls;

    for (auto i = 0; i < N; i++)
    {
        a[i] = rand();
    }

    e_gold = l2_norm(a);
    e_hls = hls_l2_norm(a);

    cout << "gold: " << e_gold << endl;
    cout << " HLS: " << e_hls << endl;

    if (e_gold != e_hls)
    {
        cout << "Error" << endl;
        return 1;
    }

    cout << "OK" << endl;

    return 0;
}