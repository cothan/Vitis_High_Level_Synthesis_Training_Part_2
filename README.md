## High Level Synthesis Introduction

### Summary

High Level Synthesis Introduction, this lecture consist of demo, live coding, and slides based on a self-made algorithm.


### Problems and Correctness

Algorithm
```c
int32_t l2_norm(const int32_t a[N])
{
    int32_t tmp, tmp_sum, sum = 0;
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
```


The proposed algorithm in this lecture is not a practical algorithm, I mix popular coding pattern I've seen from image processing, cryptography, high performance computing. 

I have not run this code in `C simulation` and `Co-simulation` yet.
If there is a mistake in the code, let me know. 

### Directory structure

```
.
├── Algo_Vitis_High_Level_Synthesis_Training_2.pdf
├── LICENSE
├── README.md
├── Vitis_High_Level_Synthesis_Introduction_2022.pdf
├── hls
│   ├── v0_baseline
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v1_widen_buswidth
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v2_widen_buswidth_reformat
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v3_array_reshape
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v4_adder_tree
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v5_resolve_adder_violation
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v6_handle_overflow_addition
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v7_unroll
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   ├── v8_pipeline
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   └── v9_bind_op
│   │   ├── l2-norm.cpp
│   │   ├── l2-norm.h
│   │   └── l2-norm_tb.cpp
│   └── v10_inline
│       ├── l2-norm.cpp
│       ├── l2-norm.h
│       └── l2-norm_tb.cpp

└── neon
    ├── l2-norm.cpp
    ├── l2_norm
    └── l2_norm.asm
```

### Contribution

Knowledge from this work is taken from public domain, thus, returned to public domain. Feel free to make a pull request. 


### Contact 

Feel free to shoot me an email, if you do NEON versus HLS comparison. 

