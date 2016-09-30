#this makefile is used to compile and run Programming contest source files with ease
#the makefile takes in an argument that will be the filename of the source file. NO file extensions.
#this will be used to compile c++ files only.

#made by Muhammad Umar Bari

#--------------------------------------------
#README

#to compile and run source file

#open the terminal
#change directory to where this makefile and the target file is visible
#	NOTE: both the makefile and the target file MUST be in the same directory.
# type the following. NOTE: <target> is the filename to be compiled. NO file extensions
#	make target=<target>

#example:
#	make target=01124

#--------------------------------------------

#to cleanup object files

#open the terminal
#change directory to where this makefile and the target file is visible.
#	NOTE: both the makefile and the target file MUST be in the same directory.
#type the following. NOTE: <target> is the filename to be removed. NO file extensions
#	make clean target=<target>

#example:
#	make clean target=01124

#--------------------------------------------

#to cleanup object files and compiled files
#type the following. NOTE <target> is the filename to be removed. NO file extensions
#	make clean-all target=<target>

#example:
#	make clean-all target=01224

#--------------------------------------------

OBJS = $(target).o
CC = g++
CFLAGS = -Wall -g -std=c++11
INCLUDE = -I./$(target)

#default command to run
all : Main-$(target) clean run

#compile and build
Main-$(target) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o : %.cpp
	$(CC) -c $(CFLAGS) $<

#remove object and any other garbage files.
clean:
	rm -rf -d $(target).o *~ *% *# .#*

#remove the compiled file
clean-all:
	$(clean) rm Main-$(target)

#run the compiled file
run:
	./Main-$(target)
