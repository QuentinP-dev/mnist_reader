# mnist_reader

mnist_reader gives a simple and easy way to read and store the mnist database in C++.

Mnist is a database of hand writing numbers used to test and improve image recognition programs.

Download the database at : http://yann.lecun.com/exdb/mnist/

## How to use it

#### 1. Download the repositorie

Download the repositorie with your browser or with git using :

```
git clone https://github.com/QuentinP-dev/mnist_reader.git
```

#### 2. Add the library to your project

You can used the mnist_reader library in two different ways.

##### a. Use directly the source files

Put the [include](/include) and the [src](/src) folders in your project folder.

And add [src/mnist_reader.cpp](/src/mnist_reader.cpp) at the list of sources you give to your compiler.

##### b. Compile and link the libmnist_reader.a static library

Use the CMakeList.txt to create the libmnist_reader.a library :

*(example for a Unix system)*
```
cmake -G Unix\ Makefiles
make
```
Put the created library in your project folder.

And add libmnist_reader.a at the list of sources you give to your compiler.

#### 3. In your code

Include the library with :

```c++
#include "include/mnist_reader/mnist_reader.hpp"
```

Then you can simply load the database with :
```c++
MnistReader reader(path_to_training_dataset,path_to_training_labels,path_to_test_dataset,path_to_test_labels,true);
```

And use it with :
```c++
reader.getData(n_data,n_pixel);
```
To get the n_pixel pixel of the n_data data of the database.

You can see other examples of use in the [examples](examples/) section.

## Notes

Since the bytes in the Mnist database are writen in big endian, the mnist_reader library use an [endianess.hpp](/include/system/endianess.hpp) file to convert the database in little endian.

## Contact

If you find any bugs or issues using the code, feel free to send me an email at :
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
