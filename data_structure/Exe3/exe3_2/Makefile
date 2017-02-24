CC = gcc
PWD = `pwd`
SRC_DIR = $(PWD)/src
INC = $(PWD)/inc
BIN_DIR = $ bin
EXE = task

all: clean binary 

binary:
	@echo "\033[0;31m"
	@echo "========================================================="
	@echo "                 Compilation started                     "
	@echo "========================================================="
	@echo "\033[0m"
	
		$(CC) $(SRC_DIR)/*.c -I$(INC) -o $(EXE) 
	
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


