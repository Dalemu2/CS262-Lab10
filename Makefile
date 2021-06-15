#Daniel Alemu G00884794
# CS 262, Lab Section 207
# lab 10
# The Compile  gcc for C programs, g++ for C++ programs, etc
CC= gcc
CFLAGS=-g -Wall
TARGET = lab10_dalemu2_207
#all=   $(TARGET)
$(TARGET):  $(TARGET).c
	$(CC) $(CFLAGS) -o0 $(TARGET) $(TARGET).c
clean:
	rm $(TARGET)

