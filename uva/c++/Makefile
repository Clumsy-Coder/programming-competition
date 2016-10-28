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
# type the following. NOTE: <filename> is the filename to be compiled. NO file extensions
#	make <filename>

#example:
#	make 01124

#--------------------------------------------

#to cleanup object files and compiled file

#open the terminal
#change directory to where this makefile and the target file is visible.
#	NOTE: both the makefile and the target file MUST be in the same directory.
#type the following.
#	make clean

#--------------------------------------------

CC = g++
CFLAGS = -Wall -g
MAKECMDGOALS := $(filter-out clean, $(MAKECMDGOALS))
INCLUDE = -I./$(MAKECMDGOALS)
OBJS = $(MAKECMDGOALS).o

.PHONY: $(MAKECMDGOALS) clean

# command for compiling source file, removing any junk files,
# creates a .in file in inputFiles folder
# and running the compiled file with the .in file as the input
# to use command, type the following
# make <filename>
#
# note: the command does not take file extentions.
# example:
# make helloWorld
#
# Assumes the source file is .cpp
$(MAKECMDGOALS): $(OBJS)
	$(CC) $(CFLAGS) $^ -o Main-$@
	rm -rf *.o *~ *% *# .#*
	touch inputFiles/$(MAKECMDGOALS).in
	./Main-$(MAKECMDGOALS) < inputFiles/$(MAKECMDGOALS).in
%.o : %.cpp
	$(CC) -c $(CFLAGS) $<

# for cleaning up the compiled file and any junk files.
# to use command, type the following:
# make clean
clean:
	rm -rf *.o *~ *% *# .#*
	rm Main-*
