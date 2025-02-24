// set include guard 
#ifndef UTILS_H
#define UTILS_H

// import libraries
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

// prototype declaration
// セキュアな乱数を生成する関数
uint32_t secure_rand(void);

// エラーメッセージの出力関数
void print_error(const char* msg);

// calculate inverse
int mod_inverse(int a, int m);

// finish include guard
#endif  // UTILS_H
