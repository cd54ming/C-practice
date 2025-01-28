# ANSI 顏色代碼
GREEN = \033[32m
BLUE = \033[34m
YELLOW = \033[33m
RED = \033[31m
RESET = \033[0m

# 編譯器與檔案
CC = gcc

SRC_MAIN = main.c generic_linked_list.c
SRC_TEST = tests/generic_linked_list_test.c generic_linked_list.c

TARGET_MAIN = program
TARGET_TEST = test

# 預設目標
all: ${TARGET_TEST} ${TARGET_MAIN}
	@echo "${GREEN}All targets compiled successfully!${RESET}\n"
.PHONY: all

# 編譯主程式
${TARGET_MAIN}: ${SRC_MAIN}
	${CC} -o $@ $^
	@echo "${GREEN}Program compiled successfully!${RESET}\n"
	@echo "${BLUE}Running Program...${RESET}"
	@./${TARGET_MAIN}
	@echo "${YELLOW}------------------------------------------${RESET}\n"
.PHONY: ${TARGET_MAIN}

# 編譯測試程式
${TARGET_TEST}: ${SRC_TEST}
	${CC} -o $@ $^
	@echo "${GREEN}Test compiled successfully!${RESET}\n"
	@echo "${BLUE}Running Test...${RESET}"
	@./${TARGET_TEST}
	@echo "${GREEN}Test End!${RESET}\n"
	@echo "${YELLOW}------------------------------------------${RESET}\n"
.PHONY: ${TARGET_TEST}

# 清理目標
clean: clean_program clean_test
	@echo "${RED}Cleaned all compiled files.${RESET}"
.PHONY: clean

clean_program:
	rm -f ${TARGET_MAIN}
	@echo "${RED}Removed program: ${TARGET_MAIN}.${RESET}"
.PHONY: clean_program

clean_test:
	rm -f ${TARGET_TEST}
	@echo "${RED}Removed test: ${TARGET_TEST}.${RESET}"
.PHONY: clean_test