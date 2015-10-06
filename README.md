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

- cmake

Ubuntu
```
  sudo apt-get install cmake
```

Mac
```
  brew install cmake
```

## Library

### opencv

- version: 3.0.0
- [website](http://opencv.org)
- [github](https://github.com/Itseez/opencv)

## Reference

- [Using OpenCV with gcc and CMake](http://docs.opencv.org/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html)
- [OPENCV ON MAC OSX: A STEP-BY-STEP GUIDE](http://tilomitra.com/opencv-on-mac-osx/)
