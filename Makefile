OS := $(shell uname)

$(info $(OS))

G_FLAGZ=-std=c++11 -Wall -g

ifeq ($(OS), Darwin)
    FLAGZ=$(G_FLAGZ) -std=c++11 -lresourcemanager
else
    FLAGZ=$(G_FLAGZ) -std=c++11 -lresourcemanager
endif

EXEC = wscript.out
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC): $(OBJECTS)
	g++ $(OBJECTS) $(FLAGZ) -o $(EXEC)

%.o: %.cpp includes/%.hpp
	g++ -c $(G_FLAGZ) $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o
