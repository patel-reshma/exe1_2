CC = gcc
CFLAGS = -c -fpic
FLAGS = -Wall
LDFLAGS = -shared
PWD = `pwd`
LINK = -L$(PWD)
SRC_DIR = $(PWD)/src
INC = $(PWD)/inc
BIN_DIR = $ bin
EXE = linkApi 
PTH = -rpath

all: clean binary 

binary:
	@echo "\033[0;31m"
	@echo "========================================================="
	@echo "                 Compilation started                     "
	@echo "========================================================="
	@echo "\033[0m"
	
		$(CC) $(CFLAGS) $(SRC_DIR)/library.c -I$(INC) 
		$(CC) $(LDFLAGS) -o liblink.so *.o
		$(CC) $(LINK) -Wl,$(PTH)=$(PWD) $(FLAGS) -o $(EXE) $(SRC_DIR)/main.c -I$(INC) -llink
	
	@echo "\033[0;31m"
	@echo "========================================================="
	@echo "                 Compilation Finished                    "
	@echo "========================================================="
	@echo "\033[0m"

clean :
	@echo "\033[0;31m"
	@echo "========================================================="
	@echo "                 Cleaning Started                    "
	@echo "========================================================="
	@echo "\033[0m"
	
	rm -rf $(BIN_DIR)/$(EXE)
	rm -rf $(SRC_DIR)/*.o 
	rm -rf $(SRC_DIR)/*~ 
	
	@echo "\033[0;31m"
	@echo "========================================================="
	@echo "                 Cleaning Finished                       "
	@echo "========================================================="
	@echo "\033[0m"

