#include "utils.h"
#include <stdio.h>
#include <stdint.h>
#include <sys/random.h>

// generate random value
uint32_t secure_rand(void) {
    // return (uint32_t)rand();
    uint32_t num;
    if (getrandom(&num, sizeof(num), 0) != sizeof(num)) {
        // エラー時の処理
        return 0; 
    }
    return num;
}

void print_error(const char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

// 拡張ユークリッドの互除法を使って a^(-1) mod m を求める関数
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;  // 逆元が存在しない場合

    while (a > 1) {
        // q は a を m で割った商
        q = a / m;
        t = m;

        // m を a の剰余に更新
        m = a % m;
        a = t;
        t = x0;

        // x0, x1 を更新
        x0 = x1 - q * x0;
        x1 = t;
    }

    // x1 が負の場合、正の剰余に変換
    if (x1 < 0)
        x1 += m0;

    return x1;
}
