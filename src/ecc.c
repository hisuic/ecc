#include "ecc.h"
#include "fp.h"

// add 2 points on elliptic curve
EC_Point ec_point_add(EC_Point P, EC_Point Q, fp_t a, fp_t p) {
    EC_Point R;
    // 無限遠点のケースの処理
    if (P.is_infinity) return Q;
    if (Q.is_infinity) return P;

    // 逆数の場合、結果は無限遠点となる
    if (P.x == Q.x && (P.y + Q.y) % p == 0) {
        R.is_infinity = 1;
        return R;
    }
    
    fp_t lambda;
    if (P.x == Q.x && P.y == Q.y) {
        // 点の倍加の場合
        // λ = (3*x1^2 + a) / (2*y1) mod p
        lambda = fp_mul(3, fp_mul(P.x, P.x, p), p);
        lambda = fp_add(lambda, a, p);
        lambda = fp_mul(lambda, fp_inv(fp_mul(2, P.y, p), p), p);
    } else {
        // 通常の加算の場合
        // λ = (y2 - y1) / (x2 - x1) mod p
        lambda = fp_mul(fp_sub(Q.y, P.y, p), fp_inv(fp_sub(Q.x, P.x, p), p), p);
    }
    
    // x3 = λ^2 - x1 - x2 mod p
    R.x = fp_sub(fp_sub(fp_mul(lambda, lambda, p), P.x, p), Q.x, p);
    // y3 = λ*(x1 - x3) - y1 mod p
    R.y = fp_sub(fp_mul(lambda, fp_sub(P.x, R.x, p), p), P.y, p);
    R.is_infinity = 0;
    return R;
}

// point addition
EC_Point ec_point_double(EC_Point P, fp_t a, fp_t p) {
    return ec_point_add(P, P, a, p);
}

// point doubling
EC_Point ec_scalar_mult(EC_Point P, uint32_t d, fp_t a, fp_t p) {
    EC_Point R;
    R.is_infinity = 1; // 初期値は無限遠点
    while (d > 0) {
        if (d & 1) {
            R = ec_point_add(R, P, a, p);
        }
        P = ec_point_double(P, a, p);
        d >>= 1;
    }
    return R;
}
