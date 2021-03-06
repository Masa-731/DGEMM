#ifndef _DGEMM_H_
#define _DGEMM_H_

#include <immintrin.h>

#define UNROLL 4
#define BLOCKSIZE 32

void dgemm(double * restrict, double * restrict, double * restrict, const int);
void dgemm_block(double * restrict A, double * restrict B, double * restrict C, const int n);
void dgemm_avx2(double * restrict, double * restrict, double * restrict, const int);
void dgemm_avx2_unroll(double * restrict, double * restrict, double * restrict, const int);
void dgemm_avx2_unroll_block(double * restrict, double * restrict, double * restrict, const int);
void dgemm_avx2_unroll_block_omp(double * restrict, double * restrict, double * restrict, const int);
void dgemm_avx512(double * restrict, double * restrict, double * restrict, const int);
void dgemm_avx512_unroll(double * restrict, double * restrict, double * restrict, const int);
void dgemm_avx512_unroll_block(double * restrict, double * restrict, double * restrict, const int);
void dgemm_avx512_unroll_block_omp(double * restrict, double * restrict, double * restrict, const int);

static double calcMmulFLOPS(int nElem, double dtime) {
    double cost = 2.0 * nElem;
    return cost * nElem * nElem / dtime / 1.0e+9;
}

#endif