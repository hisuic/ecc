#include "fp.h"

// add
fp_t fp_add(fp_t a, fp_t b, fp_t p) {
    return (a + b) % p;
}

// sub
fp_t fp_sub(fp_t a, fp_t b, fp_t p) {
    return ((a >= b) ? (a - b) : (p - (b - a))) % p;
}

// mul
fp_t fp_mul(fp_t a, fp_t b, fp_t p) {
    return (a * b) % p;
}

// inverse element
fp_t fp_inv(fp_t a, fp_t p) {
    fp_t t = 0, newt = 1;
    fp_t r = p, newr = a;
    while (newr != 0) {
        fp_t quotient = r / newr;
        fp_t temp = newt;
        newt = t - quotient * newt;
        t = temp;
        temp = newr;
        newr = r - quotient * newr;
        r = temp;
    }
    if (r > 1) {
        // a は逆元を持たない（エラー処理が必要）
        return 0;
    }
    if (t < 0) {
        t += p;
    }
    return t;
}

