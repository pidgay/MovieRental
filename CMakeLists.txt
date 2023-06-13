cmake_minimum_required(VERSION 3.24)
project(MovieRental)

set(CMAKE_CXX_STANDARD 23)

add_executable(MovieRental main.cpp Movie.cpp Movie.h Rental_Base.h menu.cpp menu.h Client.cpp Client.h Rental_Base.cpp validate.cpp validate.h Movie_Digital.cpp Movie_Digital.h Movie_Physical.cpp Movie_Physical.h text_processing.cpp text_processing.h)
