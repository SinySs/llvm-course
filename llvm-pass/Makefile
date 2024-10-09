create_lib:
	clang -c ../SDL-task/graphics.cpp -lSDL2 -I/usr/include/SDL2 -o graphics.o
	ar rcs graphics-lib.a  graphics.o

pass:
	clang++ pass.cpp -c -fPIC -I`llvm-config --includedir` -o pass.o

log_function:
	clang log_function.c -c -fPIC -o log.o

lib_pass: pass
	clang++ pass.o -fPIC -shared -o lib_pass.so

game: lib_pass
	clang ../SDL-task/game.cpp -c -o game.o -Xclang -load -Xclang ./lib_pass.so -O2

trace: game log_function
	clang++ ../SDL-task/main.cpp log.o game.o graphics-lib.a -lSDL2 -I/usr/include/SDL -o trace.o

run_pass: trace
	./trace.o > trace.txt

clean:
	rm  *.o  *.so