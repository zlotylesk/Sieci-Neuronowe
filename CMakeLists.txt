cmake_minimum_required(VERSION 3.2)
project(Sieci_Neuronowe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Sieci_Neuronowe ${SOURCE_FILES} header.h menu.cpp logo.cpp "Model McCullocha-Pittsa.h" "Model McCullocha-Pittsa.cpp" Perceptron.h Perceptron.cpp "Model asocjacji.h" "Model asocjacji.cpp" "Metoda gradientu.h" "Metoda gradientu.cpp" "Propagacja wsteczna.h" "Propagacja wsteczna.cpp" "Sieci Hopfielda.h" "Sieci Hopfielda.cpp" faktoryzacja.h faktoryzacja.cpp)