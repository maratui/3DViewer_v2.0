CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -Werror -Wuninitialized
CLIBS  = -lgtest -lgtest_main
FILES = s21_controller/* s21_facade/* s21_model/* s21_strategy/* s21_tests/*.cc s21_view/* *.html

all: uninstall install

install: clean
	mkdir -p build
	mkdir -p bin
	cd build && cp ../s21_3dviewer.pro ./s21_3dviewer.pro && \
	qmake6 && make && rm -f *.o *.pro && mv s21_3dviewer* ../bin/ && cd ../

uninstall: clean
	rm -rf bin

clean:
	rm -f *.gcda *.gcno
	rm -rf build

dvi:
	open dvi.html

dist: uninstall install
	tar  -cvzf ./bin/dist.tar ./bin/s21_3dviewer*
	rm -f ./bin/s21_3dviewer*

tests: clean
	mkdir -p build
	$(CC) $(CFLAGS) \
	s21_facade/s21_vertex.cc s21_facade/s21_edge.cc s21_facade/s21_figure.cc \
	s21_facade/s21_scene.cc s21_facade/s21_file_reader.cc \
	s21_strategy/s21_transform_client.h s21_strategy/s21_p* s21_strategy/s21_translate* \
	s21_strategy/s21_v* s21_strategy/s21_r* s21_strategy/s21_s* s21_strategy/s21_c* \
	s21_model/* s21_tests/*.cc -o ./build/s21_tests $(CLIBS)
	./build/s21_tests

gcov-report: CFLAGS+= --coverage
gcov-report: tests
	lcov -t "tests" -o ./build/gcov-report.info -c -d . --no-external
	genhtml -o ./build/report ./build/gcov-report.info

googlestyle:
	cp ../materials/linters/.clang-format ./
	clang-format -i $(FILES)
	rm -f ./.clang-format

clang-format:
	cp ../materials/linters/.clang-format ./
	clang-format -n $(FILES)
	rm -f ./.clang-format

valgrind: CFLAGS+= -g
valgrind: tests
	valgrind --tool=memcheck --leak-check=yes -s -q ./build/s21_tests

leaks: tests
	CK_FORK=no leaks -atExit -- ./build/s21_tests
