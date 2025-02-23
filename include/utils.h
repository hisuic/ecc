// set include guard 
#ifndef UTILS_H
#define UTILS_H

// import libraries
#include <stdlib.h>
#include <time.h>

// prototype declaration
// セキュアな乱数を生成する関数（実装に応じて、より高度な乱数生成手法を利用）
uint32_t secure_rand(void);

// エラーメッセージの出力関数
void print_error(const char* msg);

// finish include guard
#endif  // UTILS_H
