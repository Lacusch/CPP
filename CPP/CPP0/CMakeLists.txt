cmake_minimum_required(VERSION 3.25)

project(Megaphone DESCRIPTION "Very nice project" LANGUAGES CXX)

if(UNIX)
	add_compile_options(
	-Wextra
	-Wall
	-Werror
	-Wunreachable-code
	
	# Some low priority warnings that are annoying.
	-Wno-char-subscripts
	-Wno-sign-compare
	-Wno-unused-parameter
	-Wno-missing-field-initializers
	)
endif()

add_executable (Megaphone megaphone.cpp)
set_target_properties( Megaphone PROPERTIES COMPILE_FLAGS "-Wextra -Wall -Werror" )