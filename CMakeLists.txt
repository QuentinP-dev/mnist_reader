# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)

cmake_minimum_required(VERSION 3.0)

# ------- config -------

set(PROJECT_NAME mnist_reader)

set(PROJECT_TYPE_LIB true)

set(CPP_11_OR_HIGHER true)

set(SOURCES src/mnist_reader.cpp)
set(HEADERS include/mnist_reader/mnist_reader.hpp include/system/endianess.hpp)

# ----------------------

project(${PROJECT_NAME} CXX)

if(PROJECT_TYPE_LIB)
	add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
else()
	add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
endif()

if(CPP_11_OR_HIGHER)
	target_compile_features(${PROJECT_NAME} PUBLIC cxx_nullptr)
endif()


