# Compile variable
CXX = g++
# Flags
FLAGS = -o 

# File list
SRC = main.c++   
EXE = output      

# Header files path
HEADER = .

#---------------------

build: 
	@$(CXX) -I$(HEADER) $(SRC) $(FLAGS) $(EXE)

run: build
	@.\$(EXE)

clear: 
	@del $(EXE)  
