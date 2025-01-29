GREEN = \033[32m
RESET = \033[0m

CC = gcc
CFLAGS =

TARGET_MAIN = program
TARGET_TEST = test

SOURCE_MAIN = main.c qsort.c
SOURCE_TEST = tests/qsort_test.c qsort.c

all: ${TARGET_MAIN} ${TARGET_TEST}
.PHONY: all

${TARGET_MAIN}: ${SOURCE_MAIN}
	${CC} ${CFLAGS} -o ${TARGET_MAIN} ${SOURCE_MAIN}

${TARGET_TEST}: ${SOURCE_TEST}
	${CC} ${CFLAGS} -o ${TARGET_TEST} ${SOURCE_TEST}
	@echo "${GREEN}\nRunning Test...${RESET}"
	@./${TARGET_TEST}
	@echo "${GREEN}Test End!${RESET}"

clean:
	rm -f ${TARGET_MAIN} ${TARGET_TEST} *.o
.PHONY: clean