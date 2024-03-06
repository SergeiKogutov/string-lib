CFLAGS = -Wall -Wextra -Werror -std=c11 
GCC = gcc
TEST_SRC = s21_string_test.c

ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread
endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
	ADD_LIB =
endif

all: s21_string.a test

test: s21_string.a
	$(GCC) $(CFLAGS) s21_string.a s21_string_test.c -o s21_string_test $(shell pkg-config --cflags --libs check)
	./s21_string_test

s21_string.a:
	$(GCC) $(CFLAGS) -c ./source/*.c
	ar rcs s21_string.a *.o
	make clean

gcov_report: $(TEST_SRC) ./source/*.c
	$(GCC) $(CFLAGS) $^ -fprofile-arcs -ftest-coverage -g -o s21_string_test_gcov_report -lcheck $(TEST_CHECK_F) $(ADD_LIB)
	./s21_string_test_gcov_report
	lcov -t "report_gcov" -o report_gcov.info -c -d ./
	genhtml -o report report_gcov.info
	rm *.gcda
	rm *.gcno

clang:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c *.h source/*.c --verbose
	clang-format -i *.c *.h source/*.c --verbose

clean:
	rm -rf *.o
	rm -rf *.gcda
	rm -rf *.gcno
