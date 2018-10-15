OS := $(shell uname)

$(info $(OS))

G_FLAGZ=-std=c++11 -Wall -g -fPIC

ifeq ($(OS), Darwin)
    FLAGZ=$(G_FLAGZ) -std=c++11 -lresourcemanager -ldl -fPIC
else
    FLAGZ=$(G_FLAGZ) -std=c++11 -lresourcemanager -ldl -fPIC
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
	    $(OBJECTS_NO_MAIN) unit.o -o test.out -ldl -fPIC

unit.o: unit/unit.cpp
	g++ -std=c++11 -g -Wall -c unit/unit.cpp -ldl -fPIC

%.o: %.cpp ../../includes/AST/builtin_objects/%.hpp
	g++ -c $(G_FLAGZ) $< -o $@

%.o: %.cpp ../includes/AST/%.hpp
	g++ -c $(G_FLAGZ) $< -o $@

%.o: %.cpp includes/%.hpp
	g++ -c $(G_FLAGZ) $< -o $@
#libwscript.a: $(OBJECTS_NO_MAIN)
#	ar rcs $@ $^

libwscript.so: $(OBJECTS_NO_MAIN)
	$(LINK.c) -shared $^ -o $@
#libwscript.so: $(OBJECTS_NO_MAIN)
#	ar rcs $@ $^

clean:
	-rm *.out
	-rm *.o
	-rm src/*.o
	-rm src/*/*.o
	-rm src/*/*/*.o
