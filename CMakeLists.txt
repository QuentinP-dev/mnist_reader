# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)



# ------------ cmake minimum version ------------

cmake_minimum_required(VERSION 3.16.3)



# ------------------ metadatas------------------

set(PROJECT_NAME "mnist_reader")
set(PROJECT_VERSION 1.1)
set(PROJECT_BRIEF "A &nbsp; simple &nbsp; c++  &nbsp; lib  &nbsp; to &nbsp; read &nbsp; the &nbsp; mnist &nbsp; database.")


# -------------- type of output -----------------

# ----- (BINARY or LIBRARY) -----
set(PROJECT_TYPE "LIBRARY")



# ------------------- options -------------------

# ----- (DEBUG or RELEASE) ------
set(BUILD_MODE "RELEASE" CACHE STRING "Build mode, possible values are RELEASE and DEBUG.")

if(PROJECT_TYPE STREQUAL "LIBRARY")
# ----- (SHARED or STATIC) ------
	set(LIBRARY_TYPE "STATIC" CACHE STRING "Type of the output library, possible values are SHARED and STATIC.")
endif()

# --------- (ON or OFF) ---------
option(BUILD_DOC "Build documentation" OFF)

# --------- (ON or OFF) ---------
option(BUILD_EXAMPLES "Build example" OFF

# --------- (ON or OFF) ---------
option(MNIST_STATIC_CLASS "Use MnistReader as a static class" OFF)

# --------- (ON or OFF) ---------
option(MNIST_SUPER_CLASS "Use MnistReader as a super class" OFF)

# --------- (ON or OFF) ---------
option(C++_STATIC_LIB "Build with the C++ static library" OFF)

# --------------- options feedback --------------

message(${PROJECT_NAME} " building configuration start with the options :" )
message("PROJECT_TYPE : " ${PROJECT_TYPE})
if(PROJECT_TYPE STREQUAL "LIBRARY")
	message("LIBRARY_TYPE : " ${LIBRARY_TYPE})
endif()
message("BUILD_MODE : " ${BUILD_MODE})
message("BUILD_DOC : " ${BUILD_DOC})
message("BUILD_EXAMPLES : " ${BUILD_EXAMPLES})
message("MNIST_STATIC_CLASS : " ${MNIST_STATIC_CLASS})
message("MNIST_SUPER_CLASS : " ${MNIST_SUPER_CLASS})
message("C++_STATIC_LIB : " ${C++_STATIC_LIB})

message("You can change this options using the -D option of cmake\n")



# ------------ project configurations -----------

# ---- C++ required standart ----
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ----- compilation options -----
ADD_COMPILE_OPTIONS(-O3 -Ofast -Wall -Wextra)
if(BUILD_MODE STREQUAL "DEBUG")
	set(DEBUG CMAKE_CXX_FLAGS_DEBUG)
	add_compile_options(-g)
else()
	set(RELEASE CMAKE_CXX_FLAGS_RELEASE)
endif()

if(C++_STATIC_LIB)
	add_compile_options(-static -static-libgcc -static-libstdc++)
endif()

if(MNIST_STATIC_CLASS)
	add_compile_options(-D MNIST_READER_STATIC_CLASS)
endif()

if(MNIST_SUPER_CLASS)
	add_compile_options(-D MNIST_READER_SUPER_CLASS)
endif()

# --------- project's name --------
set(INSTALL_DIR "${CMAKE_SOURCE_DIR}/${PROJECT_NAME}-${PROJECT_VERSION}")

if(C++_STATIC_LIB)
	set(PROJECT_NAME "${PROJECT_NAME}-csl")
endif()

if(MNIST_STATIC_CLASS)
	set(PROJECT_NAME "${PROJECT_NAME}-stc")
endif()

if(MNIST_SUPER_CLASS)
	set(PROJECT_NAME "${PROJECT_NAME}-suc")
endif()

if(BUILD_MODE STREQUAL "DEBUG")
	set(PROJECT_NAME "${PROJECT_NAME}-d")
endif()

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

# -- default installation folder --
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR})


# ---------------- subdirectories ---------------

# ------ lib or binary config -----
add_subdirectory("src")

# ----------- doc config ----------
if (BUILD_DOC)
    find_package(Doxygen)
    if (DOXYGEN_FOUND)
    	add_subdirectory("doc")
	endif()
endif()

# -------- examples config --------
if (BUILD_EXAMPLES)
    add_subdirectory("examples")
endif()

# -----------------------------------------------
