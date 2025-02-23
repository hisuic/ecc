// set include guard 
#ifndef FP_H
#define FP_H

// include libraries
#include <stdint.h>
#include <stdio.h>

// set type
typedef uint32_t fp_t;

// prototype declaration
// 有限体の加算：結果 = (a + b) mod p
fp_t fp_add(fp_t a, fp_t b, fp_t p);

// 有限体の減算：結果 = (a - b) mod p
fp_t fp_sub(fp_t a, fp_t b, fp_t p);

// 有限体の乗算：結果 = (a * b) mod p
fp_t fp_mul(fp_t a, fp_t b, fp_t p);

// 有限体の逆元計算：a^{-1} mod p を返す（存在しない場合のエラーチェックも）
fp_t fp_inv(fp_t a, fp_t p);

// finish include guard
#endif  // FP_H
