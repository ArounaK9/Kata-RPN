CXX = g++
CXXFLAGS = -std=c++11 -Wall

INCLUDES = -Iinclude
SRC = src/CalculatriceRPN.cpp
OBJ = $(SRC:.cpp=.o)
MAIN = main/main.cpp
TARGET = calculatrice_rpn

all: $(TARGET)

$(TARGET): $(OBJ) $(MAIN)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(TARGET) $(OBJ) $(MAIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
