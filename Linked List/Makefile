# Reference: https://hackmd.io/@sysprog/SySTMXPvl
# Reference: https://blog.goodjack.tw/2023/01/use-makefile-to-manage-workflows-for-web-projects.html

# 編譯器與選項
CC = gcc
CFLAGS = -Wall -g

# 檔案定義
SRC_MAIN = main.c linked_list.c
SRC_TEST = tests/linked_list_test.c linked_list.c

# 輸出檔案
TARGET_MAIN = program
TARGET_TEST = test

# 建置所有目標
build_all_targets: $(TARGET_MAIN) $(TARGET_TEST)
	@echo "All targets built successfully!"
.PHONY: build_all_targets

# 只建置主程式
build_program: $(TARGET_MAIN)
	@echo "Program built successfully!"
.PHONY: build_program

# 通用規則，建置目標
$(TARGET_MAIN): $(SRC_MAIN)
	$(CC) $(CFLAGS) -o $@ $^

$(TARGET_TEST): $(SRC_TEST)
	$(CC) $(CFLAGS) -o $@ $^

# 清理所有檔案
clean_all: clean_targets clean_symbols
	@echo "All cleaned!"
.PHONY: clean_all

# 清理目標檔案
clean_targets:
	@echo "Cleaning targets..."
	rm -f $(TARGET_MAIN) $(TARGET_TEST)
.PHONY: clean_targets

# 清理符號檔
clean_symbols:
	@echo "Cleaning symbols..."
	rm -rf $(TARGET_MAIN).dSYM $(TARGET_TEST).dSYM
.PHONY: clean_symbols