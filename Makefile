CXX = g++
CXXFLAGS = -Wall -g

SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

LIBS = -lsfml-graphics -lsfml-window -lsfml-system

src/%.o: src/%.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

dmg: $(OBJ)
	mkdir -p bin
	$(CXX) $(LIBS) $(CXXFLAGS) $^ -o bin/$@

clean:
	rm -rf src/*.o bin/
