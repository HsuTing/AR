#argument
compiler = g++
extraLib = -I/usr/local/include/
extraMod = -L/usr/local/lib/
mods = -lopencv_core

#start
main: main.cpp
	$(compiler) -o main main.cpp $(extraLib) $(extraMod) $(mods)

clean:
	rm *.o
