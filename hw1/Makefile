#argument
compiler = g++
extraLib = /usr/local/include/
extraMod = /usr/local/lib/

#start
main: main.cpp
	$(compiler) -o main main.cpp -I$(extraLib) -L$(extraMod) -lopencv_core -lopencv_videoio -lopencv_highgui

clean:
	rm *.o
