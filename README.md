# AR

## Start

Clone opencv in version 3.0.0:
```
  cd AR

  git clone --branch 3.0.0 https://github.com/Itseez/opencv.git
```

Build:
```
  mkdir build

  cd build

  cmake -G "Unix Makefiles" ../opencv/
```

Make opencv:
```
  make -j8

  sudo make install
```

Make uninstall opencv:
```
  sudo make uninstall
```

## Requirement

### cmake

- Ubuntu
```
  sudo apt-get install cmake
```

- Mac
```
  brew install cmake
```

## Development environment

- Mac OS X 10.11
- If you are other os, you may need to modify `extraLib` and `extraMod` in `Makefile`.

## Library

### opencv

- version: 3.0.0
- [website](http://opencv.org)
- [github](https://github.com/Itseez/opencv)

## Reference

- [Using OpenCV with gcc and CMake](http://docs.opencv.org/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html)
- [OPENCV ON MAC OSX: A STEP-BY-STEP GUIDE](http://tilomitra.com/opencv-on-mac-osx/)
- [compile opencv by g++](http://askubuntu.com/questions/239891/opencv-program-wont-compile-quantal)
- [opencv introduction](http://www.dotblogs.com.tw/v6610688/archive/2013/10/25/image_process_intro_opencv.aspx)
- [OpenCV Tutorial](http://ccw1986.blogspot.tw/2013/09/learningopencv.html)
