// set include guard
#ifndef ECC_H
#define ECC_H

// include library
#include "fp.h"

typedef struct {
    fp_t x;
    fp_t y;
    int is_infinity;  // 1なら無限遠点を示す
} EC_Point;

// prototype declaration
// 点の加算
EC_Point ec_point_add(EC_Point P, EC_Point Q, fp_t a, fp_t p);

// 点の倍加
EC_Point ec_point_double(EC_Point P, fp_t a, fp_t p);

// スカラー乗算：d * P を計算
EC_Point ec_scalar_mult(EC_Point P, uint32_t d, fp_t a, fp_t p);

// finish include guard
#endif  // ECC_H
