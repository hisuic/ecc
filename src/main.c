#include "fp.h"
#include "ecc.h"
#include "utils.h"
#include <stdio.h>

int main(void) {
    // テスト用の楕円曲線パラメータ
    fp_t p = 17;           // 素数
    fp_t a = 2;            // 楕円曲線のパラメータ
    fp_t b = 2;            // 楕円曲線のパラメータ
    
    // 基準点 G の設定
    EC_Point G = {5, 1, 0};
    
    // スカラー乗算の例: 2 * G を計算
    uint32_t d = 2;
    EC_Point R = ec_scalar_mult(G, d, a, p);
    
    if (R.is_infinity) {
        printf("Result is point at infinity\n");
    } else {
        printf("R = (%u, %u)\n", R.x, R.y);
    }
    
    return 0;
}
