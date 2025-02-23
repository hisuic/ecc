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
