# CMakeList.txt : CMake project for CalcMaster, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (CalcMaster "calc_master.c" "calc_master.h" "menu.h" "menu.c" "operations.c" "operations.h" )


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CalcMaster PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.