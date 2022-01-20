OBJS = ./src/*.cpp
CC = g++
COMPILER_FLAGS = -g -Wall
LINKER_FLAGS = -L ./lib -lmingw32 -lSDL2main -lSDL2
INCLUDES = -I ./include
OBJ_NAME = Pong

run: all
	@echo Running...
	@./bin/Pong

all : $(OBJS)
	@echo Compiling...
	@$(CC) $(OBJS) $(COMPILER_FLAGS) $(INCLUDES) $(LINKER_FLAGS) -o ./bin/$(OBJ_NAME)

clean:
	@echo Clean...
	@rm ./bin/Pong