# Compiler and compiler flags
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra

SRCS := main.cpp Assign4asm616.cpp

OBJS := $(SRCS:.cpp=.o)

TARGET := Assign4asm616

.PHONY: all clean

all: $(TARGET)

%.o: %.cpp
  $(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
  $(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

  rm -f $(OBJS) $(TARGET)
