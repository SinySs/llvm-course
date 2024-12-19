To compile:  
```
clang++ $(llvm-config --cppflags --ldflags --libs) graphics.c IR-gen.cpp -lSDL2 -I/usr/include/SDL2
```
