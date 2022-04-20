#ifndef L2_NORM_H
#define L2_NORM_H

#include "ap_int.h"
#include "hls_stream.h"
#include "ap_axi_sdata.h"

#define N 200
#define SIZE N
#define DWIDTH 32
#define INT32_MAX ((1 << 31) - 1)


typedef ap_int<32> i32;
typedef ap_int<512> i512;


i32 hls_l2_norm(const i512 a[N]);


#endif
