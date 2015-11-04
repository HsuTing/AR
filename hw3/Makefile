#argument
compiler = g++
extraLib = -I/usr/local/include/
extraMod = -L/usr/local/lib/
mods = -lopencv_core -lopencv_imgcodecs -lopencv_imgproc -lopencv_highgui -lopencv_videoio

#start
main: main.cpp
	$(compiler) -o main main.cpp $(extraLib) $(extraMod) $(mods)

clean:
	rm *.o
