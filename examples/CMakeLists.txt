# Copyright (C) 2020 Quentin Putaud
# Distributed under the GNU General Public License version 3
# (http://www.gnu.org/licenses)


if(MNIST_STATIC_CLASS)
	add_subdirectory("static")
else()
	add_subdirectory("instantiable")
	if(MNIST_SUPER_CLASS)
		add_subdirectory("inheritance")
	endif()
endif()

# ----------- installing required datas ---------

install(DIRECTORY "datas" DESTINATION examples)

# -----------------------------------------------
