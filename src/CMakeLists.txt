# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)



# ------------- list of source files ------------

set(PROJECT_SOURCE_FILES
	"mnist_reader.cpp")



# ------------ library configuration ------------

if(PROJECT_TYPE STREQUAL "LIBRARY")

# --------- adding target ---------
	add_library(${PROJECT_NAME} ${LIBRARY_TYPE} ${PROJECT_SOURCE_FILES})

# ---- linking to header files ----
	target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/include")
	target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# ------- installing headers ------
	install(DIRECTORY "../include" DESTINATION "./")

# --- installing static library ---
	if(LIBRARY_TYPE STREQUAL "STATIC")
		install(TARGETS ${PROJECT_NAME} DESTINATION lib/)

# --- installing shared library ---
	else()
		install(TARGETS ${PROJECT_NAME} DESTINATION "bin/${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
	endif()



# ------------ binary configuration -------------

else()

# --------- adding target ---------
	add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

# ------- installing binary -------
	install(TARGETS ${PROJECT_NAME} DESTINATION "bin/${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}")
endif()

# -----------------------------------------------
