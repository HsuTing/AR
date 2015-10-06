#argument
compiler = g++
extraLib = -I/usr/local/include/
extraMod = -L/usr/local/lib/
objs = FaceDetect.o

#start
main: main.cpp $(objs)
	$(compiler) -o main main.cpp $(objs) $(extraLib) $(extraMod) -lopencv_core -lopencv_videoio -lopencv_highgui

FaceDetect.o: FaceDetect/FaceDetect.cpp FaceDetect/FaceDetect.h
	$(compiler) -c FaceDetect/FaceDetect.cpp

clean:
	rm *.o
