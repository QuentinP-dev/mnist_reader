# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)


# ------------- list of source files ------------

set(EXAMPLE_NAME "inheritance")

# ------------- list of source files ------------

set(EXAMPLE_SOURCE_FILES
	"${EXAMPLE_NAME}.cpp")

# ----------------- adding target ---------------

add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE_FILES})

# -------------- linking to the lib -------------

target_link_libraries(${EXAMPLE_NAME} PUBLIC ${PROJECT_NAME})

# -------------- installing example -------------

install(TARGETS ${EXAMPLE_NAME} DESTINATION examples)

# -----------------------------------------------
