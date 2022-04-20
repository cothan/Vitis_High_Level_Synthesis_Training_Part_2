[0x100003e34]> s sym.neon_l2_norm_short_const_ 
[0x100003dd0]> pdf
            ;-- section.0.__TEXT.__text:
            ;-- func.100003dd0:
            ; UNKNOWN XREF from aav.0x100000020 @ +0xb0
┌ 92: sym.neon_l2_norm_short_const_ ();
│           0x100003dd0      00e4006f       movi v0.2d, 0000000000000000 ; [00] -r-x section size 412 named 0.__TEXT.__text
│           0x100003dd4      e8038092       movn x8, 0x1f
│           0x100003dd8      01e4006f       movi v1.2d, 0000000000000000
│       ┌─> 0x100003ddc      0224df4c       ld1 {v2.8h, v3.8h, v4.8h, v5.8h}, [x0], 0x40
│       ╎   0x100003de0      4090620e       sqdmlal v0.4s, v2.4h, v2.4h
│       ╎   0x100003de4      6090630e       sqdmlal v0.4s, v3.4h, v3.4h
│       ╎   0x100003de8      8090640e       sqdmlal v0.4s, v4.4h, v4.4h
│       ╎   0x100003dec      a090650e       sqdmlal v0.4s, v5.4h, v5.4h
│       ╎   0x100003df0      4190624e       sqdmlal2 v1.4s, v2.8h, v2.8h
│       ╎   0x100003df4      6190634e       sqdmlal2 v1.4s, v3.8h, v3.8h
│       ╎   0x100003df8      8190644e       sqdmlal2 v1.4s, v4.8h, v4.8h
│       ╎   0x100003dfc      a190654e       sqdmlal2 v1.4s, v5.8h, v5.8h
│       ╎   0x100003e00      08810091       add x8, x8, 0x20
│       ╎   0x100003e04      1f8107f1       cmp x8, 0x1e0
│       └─< 0x100003e08      a3feff54       b.lo 0x100003ddc
│           0x100003e0c      0004a14e       shadd v0.4s, v0.4s, v1.4s
│           0x100003e10      0140006e       ext v1.16b, v0.16b, v0.16b, 8
│           0x100003e14      000ca10e       sqadd v0.2s, v0.2s, v1.2s
│           0x100003e18      083c0c0e       mov w8, v0.s[1]
│           0x100003e1c      0101271e       fmov s1, w8
│           0x100003e20      000ca15e       sqadd s0, s0, s1
│           0x100003e24      0000261e       fmov w0, s0
└           0x100