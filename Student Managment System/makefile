CXX = g++
CXXFLAGS = -Wall -g 

SOURCES = main.cpp Student.cpp BasePerson.cpp Func.cpp
HEADERS = Student.h BasePerson.h Func.h

ifeq ($(OS),Windows_NT)
    EXECUTABLE = Student_v1.0.exe
    RM = del
else
    EXECUTABLE = Student_v1.0.elf
    RM = rm -f
endif

build: 
	@echo Please wait, The build process is currently in progress...........
	@$(CXX) $(CXXFLAGS)  -o $(EXECUTABLE) $(SOURCES)

run:
	@if [ "$(OS)" = "Windows_NT" ]; then \
        .\$(EXECUTABLE); \
    else \
        ./$(EXECUTABLE); \
    fi

clean:
	@$(RM) $(EXECUTABLE)

rebuild: clean build
