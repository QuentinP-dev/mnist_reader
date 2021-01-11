# mnist_reader

mnist_reader gives a simple and easy way to read and store the mnist database in C++.

Mnist is a database of hand writing numbers used to test and improve image recognition programs.

See : http://yann.lecun.com/exdb/mnist/

## How to use it

#### 1. Download the repository

Download the repository with your browser or with git using :

```
git clone https://github.com/QuentinP-dev/mnist_reader.git
```

#### 2. Build the mnist_reader library

Use the [CMakeLists.txt](/CMakeLists.txt) to create the mnist_reader library :

*(example for a Linux system)*
```
cmake CMakeLists.txt -G Unix\ Makefiles -B conf/
cd conf/
cmake --build .
cmake --install .
```
By default, the library, documentation and examples will be installed in the cmake root folder in a subdirectory named mnist_reader-x.y . *(Where x and y are the major and minor version of the lib).*

You can pass options to the cmake command using -D (see man cmake)


Option | meaning | default value| added suffix
------ | ------- | -------------| ------------
BUILD_DOC | Build the documentation using doxygen | OFF |
BUILD_EXAMPLE | Build a little example | OFF |
C++_STATIC_LIB | Build using the static C++ library | OFF | **ON:** -csl
MNIST_STATIC_CLASS | Use the mnist_reader as a static class | OFF | **ON:** -stc
MNIST_SUPER_CLASS | Use the mnist_reader as a super class | OFF | **ON:** -suc
BUILD_MODE | If DEBUG, add debugging flags to the output library | RELEASE | **ON:** -d
LIBRARY_TYPE | The type of the output library | STATIC | **ON:** .a **OFF:** .so *or* .dll

So if you call cmake with the following line :
```
cmake CMakeLists.txt -B conf/ -D LIBRARY_TYPE=SHARED -D BUILD_MODE=DEBUG -D MNIST_STATIC_CLASS=ON -D C++_STATIC_LIB=ON
```
The name of the output library will be:
**libmnist_reader-csl-stc-d.so**


Include the [mnist_reader.hpp](/include/mnist_reader/mnist_reader.hpp) header in your source code.

Pass the created library to your compiler.

*(example for a g++)*
```
g++ my_source_file.cpp -L path/to/lib/ -lmnist_reader
```

#### 3. In your code

As you can see, mnist_reader comes in differents flavours.
The basic mnist_reader configuration allows you to call :

```c++
MnistReader reader(path_to_training_dataset,path_to_training_labels,path_to_test_dataset,path_to_test_labels,true);
reader.getData(n_data,n_pixel);
```
Where the **MNIST_STATIC_CLASS** option will build the library as a static class:

```c++
MnistReader::setPathToTrainingDataset(path_to_training_dataset);
MnistReader::setPathToTestDataset(path_to_test_dataset);
MnistReader::setPathToTrainingLabels(path_to_training_labels);
MnistReader::setPathToTestLabels(path_to_test_labels);
MnistReader::load();
MnistReader::getData(n_data,n_pixel);
```

To get the *n_pixel* pixel of the n_data data of the database.

the **MNIST_SUPER_CLASS** option will allows you to fully inherit from the MnistReader class.

You can see other examples of use in the [examples](examples/) section.

## Notes

Since the bytes in the Mnist database are writen in big endian, the mnist_reader library use an [endianess.hpp](/include/system/endianess.hpp) file to convert the database in little endian.

## Contact

If you find any bugs or issues using this code, please feel free to send me an email at :
quentinp.dev@gmail.com

## Licence

GNU GENERAL PUBLIC LICENSE

Version 3, 29 June 2007

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See theGNU General Public License for more details.
