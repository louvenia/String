UNAME := $(shell uname)
all: s21_string.a test
rebuild: clean s21_string.a test
s21_string.a:
	gcc -Wall -Wextra -Werror -std=c11 -g -c -o s21_string.o functions.c 
	ar rcs s21_string.a s21_string.o
	ranlib s21_string.a
	
ifeq ($(UNAME), Linux)
test: s21_string.a
	gcc test_string.c s21_string.a -L. -lcheck -lrt -lsubunit -lm -pthread -o check_unit_tests
	chmod +x check_unit_tests
	./check_unit_tests
else
test: s21_string.a
	gcc test_string.c s21_string.a -L. -lcheck -lm -pthread -o check_unit_tests
	chmod +x check_unit_tests
	./check_unit_tests
endif

clean:
	rm -rf *.gcno *.o *.a *.gcda *.gcov *.exec *.info *.css *.html check_unit_tests

gcov_report: gcov_test
	gcovr -r . --html --html-details -o coverage_report.html
	./check_unit_tests

cppcheck: 
	cppcheck --enable=all --suppress=missingIncludeSystem functions.c test_string.c *.h
linter:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
check_all: cppcheck linter

ifeq ($(UNAME), Linux)
gcov_test: gcov_s21_string.a
	gcc test_string.c s21_string.a -L. -lcheck -lrt -lsubunit -lm -pthread --coverage -o check_unit_tests
	chmod +x check_unit_tests
	./check_unit_tests
else
gcov_test: gcov_s21_string.a
	gcc test_string.c s21_string.a -L. -lcheck -lm -pthread --coverage -o check_unit_tests
	chmod +x check_unit_tests
	./check_unit_tests
endif

gcov_s21_string.a:
	gcc -Wall -Wextra -Werror -std=c11 --coverage -g -c -o s21_string.o functions.c 
	ar rcs s21_string.a s21_string.o
	ranlib s21_string.a