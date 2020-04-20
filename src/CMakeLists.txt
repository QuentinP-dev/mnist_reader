# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)

#list of source files
set(PROJECT_SOURCE_FILES
	mnist_reader.cpp
	)

set(PROJECT_HEADER_FILES
	../include/mnist_reader/mnist_reader.hpp
	../include/system/endianess.hpp
	)

if(PROJECT_TYPE STREQUAL "library")
	if(NOT SHARED_LIBRARY)
		add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCE_FILES} ${PROJECT_HEADER_FILES})
	elseif(SHARED_LIBRARY)
		add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_FILES} ${PROJECT_HEADER_FILES})
	endif()
	target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
	target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
elseif(PROJECT_TYPE STREQUAL "bin")
	add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES} ${PROJECT_HEADER_FILES})
endif()

