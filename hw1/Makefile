#argument
compiler = g++
extraLib = -I/usr/local/include/
extraMod = -L/usr/local/lib/
mods = -lopencv_core -lopencv_videoio -lopencv_highgui -lopencv_objdetect -lopencv_imgproc
objs = Detect.o

#start
main: main.cpp $(objs)
	$(compiler) -o main main.cpp $(objs) $(extraLib) $(extraMod) $(mods)

Detect.o: Detect/Detect.cpp Detect/Detect.h
	$(compiler) -c Detect/Detect.cpp $(extraLib) 

clean:
	rm *.o
