FLAGS=-Wall -Werror -Wextra

all: format s21_math.a test

test: format
	gcc -c $(FLAGS) -fprofile-arcs -ftest-coverage -g -lgcov s21_math.c -o s21_math.a
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage -g -lgcov test.c s21_math.a -o test -lm -lcheck -lsubunit

	# gcc -c $(FLAGS) s21_math.c -o s21_math.a
	# gcc $(FLAGS) -g test_r.c s21_math.a -o test -lm

s21_math.a: s21_math.c
	gcc -c $(FLAGS) s21_math.c -o s21_math.a

gcov_report:
	lcov --directory . --capture --output-file gcov_report.info -c -d .
	genhtml -o gcov_report gcov_report.info

format:
	clang-format -style=Google -i *.c *.h

clean:
	rm -rf *.info *.gcno *.gcda *.gcov gcov_report test.o s21_math.a test