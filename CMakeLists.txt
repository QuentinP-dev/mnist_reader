# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)

cmake_minimum_required(VERSION 3.8)

# ------- config -------

set(PROJECT_NAME mnist_reader)
set(PROJECT_VERSION 1.0)
set(PROJECT_BRIEF "A &nbsp; C++ &nbsp; library &nbsp; to &nbsp; read &nbsp; the &nbsp; mnist &nbsp; dataset.")

#bin or library
set(PROJECT_TYPE library)

# ------- options -------

option(SHARED_LIBRARY "Type of the output library, shared if set to yes, static if not." OFF)

option(BUILD_DOCS "Build documentation" OFF)

option(BUILD_EXAMPLE "Build example" OFF)

# ----------------------

message(${PROJECT_NAME} " building configuration start with the options :" )
if(PROJECT_TYPE STREQUAL "library")
	message("SHARED_LIBRARY : " ${SHARED_LIBRARY})
endif()
message("BUILD_DOCS : " ${BUILD_DOCS})
message("BUILD_EXAMPLE : " ${BUILD_EXAMPLE})
message("You can change this using the -D option of cmake\n")

# ----------------------

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)

# ----------------------

if (BUILD_DOCS)
    find_package(Doxygen)
endif()

if (DOXYGEN_FOUND AND BUILD_DOCS)
    add_subdirectory(docs)
endif()

if (BUILD_EXAMPLE)
    add_subdirectory (example)
endif()

