# コンパイラとコンパイルオプションの設定
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude

# ディレクトリ設定
SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

# ソースファイルとオブジェクトファイルの取得
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# 出力ファイル名
TARGET = ecc_app

# デフォルトターゲット
all: $(TARGET)

# 実行ファイルの生成
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# オブジェクトファイル生成ルール
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# オブジェクトディレクトリの作成
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# テストターゲット
test: $(TARGET)
	$(CC) $(CFLAGS) -o test_ecc $(TEST_DIR)/test_ecc.c $(OBJECTS)
	./test_ecc

# クリーンアップ
clean:
	rm -rf $(OBJ_DIR) $(TARGET) test_ecc

.PHONY: all test clean
