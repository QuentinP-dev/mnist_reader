# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)


# ---- doxygen source files (from CMAKE_ROOT) ---
set(PROJECT_DOXYGEN_FILES
    "README.md"
    "include/mnist_reader/mnist_reader.hpp"
    "include/system/endianess.hpp")


# --------- parsing source files's paths --------

foreach(IT_PATH IN LISTS PROJECT_DOXYGEN_FILES)
    set(PROJECT_DOXYGEN_INPUT "${PROJECT_DOXYGEN_INPUT} \\\n\"${CMAKE_SOURCE_DIR}/${IT_PATH}\"")
endforeach()


# -------------- configure .in file -------------

configure_file("Doxyfile.in" "Doxyfile" @ONLY)


# ----------------- adding target ---------------

add_custom_target(
	"doc" ALL "${DOXYGEN_EXECUTABLE}"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/doc"
    COMMENT "Generating HTML documentation" VERBATIM)


# -------- creating a link to index.html --------

if(NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	execute_process(
		COMMAND ln html/index.html index.html -s
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif()


# ---------------- installing doc ---------------

install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/html" DESTINATION "doc")


# ------------- installing the link -------------

if(NOT ${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
	install(FILES "${CMAKE_CURRENT_BINARY_DIR}/index.html" DESTINATION "doc")
endif()

# -----------------------------------------------
