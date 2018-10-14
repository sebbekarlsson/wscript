OS := $(shell uname)

$(info $(OS))

G_FLAGZ=-std=c++11 -Wall -g

ifeq ($(OS), Darwin)
    FLAGZ=$(G_FLAGZ) -std=c++11 -lresourcemanager -ldl
else
    FLAGZ=$(G_FLAGZ) -std=c++11 -lresourcemanager -ldl
endif

EXEC = wscript.out
SOURCES := $(wildcard src/*.cpp)
SOURCES += $(wildcard src/*/*.cpp)
SOURCES += $(wildcard src/*/*/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
OBJECTS_NO_MAIN := $(filter-out src/main.o,$(OBJECTS))

$(info $(OBJECTS_NO_MAIN))

$(EXEC): $(OBJECTS)
	g++ $(OBJECTS) $(FLAGZ) -o $(EXEC)

test:\
    $(OBJECTS_NO_MAIN) unit.o
	g++\
	    $(OBJECTS_NO_MAIN) unit.o -o test.out -ldl

unit.o: unit/unit.cpp
	g++ -std=c++11 -g -Wall -c unit/unit.cpp -ldl

%.o: %.cpp ../includes/*/*/%.hpp
	g++ -c $(G_FLAGZ) $< -o $@ - fPIC

%.o: %.cpp ../includes/*/%.hpp
	g++ -c $(G_FLAGZ) $< -o $@ -fPIC

%.o: %.cpp includes/%.hpp
	g++ -c $(G_FLAGZ) $< -o $@ -fPIC

libwscript.a: $(OBJECTS)
	ar rcs $@ $^

libwscript.so: $(OBJECTS)
	$(LINK.c) -shared $< -o $@

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o
	-rm src/*/*.o
