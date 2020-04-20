# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)

set (EXAMPLE_SOURCE_FILES
	main.cpp
	)

add_executable(example ${EXAMPLE_SOURCE_FILES})

target_link_libraries(example ${PROJECT_NAME})

#uncomment if it needs to move a data folder
# Copy data files
#add_custom_command(TARGET example POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E copy_directory
#	${CMAKE_CURRENT_SOURCE_DIR}/data/
#	${CMAKE_CURRENT_BINARY_DIR}/data/)
