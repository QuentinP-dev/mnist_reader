# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)

#Doxygen source file (from CMAKE_ROOT)
set(PROJECT_DOXYGEN_FILES
    "README.md"
    "include/mnist_reader/mnist_reader.hpp"
    )

foreach(path IN LISTS PROJECT_DOXYGEN_FILES)
    set(PROJECT_DOXYGEN_INPUT "${PROJECT_DOXYGEN_INPUT} \\\n\"${CMAKE_SOURCE_DIR}/${path}\"")
endforeach()

configure_file(Doxyfile.in Doxyfile @ONLY)

message("Doxygen build started")

add_custom_target(docs ALL "${DOXYGEN_EXECUTABLE}"
                  WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/docs"
                  COMMENT "Generating HTML documentation" VERBATIM
                  )

