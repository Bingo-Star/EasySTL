RM = -rm -f
# CC = arm-hisiv300-linux-gcc
CC = g++
CFLAGS = -c -g
# -std = c++11
#LDFLAGS = -L$(MAKE_DIR)/library -loperation


MAKE_DIR := $(shell pwd)
SRC_DIR := $(MAKE_DIR)/src/
OBJ_DIR := $(MAKE_DIR)/object/
OUT_DIR := $(MAKE_DIR)/output/

INC_PTAH := -I$(MAKE_DIR)/include/

vpath %.cpp $(SRC_DIR)

SRC_FILES := $(notdir $(wildcard $(SRC_DIR)*.cpp))
OBJ_FILES := $(SRC_FILES:%.cpp=%.o)
OUT_FILES := app

all : $(OUT_FILES)

$(OUT_FILES) : $(OBJ_FILES)
	@echo "=> Generate : $@"
	$(CC) $(addprefix $(OBJ_DIR),$(notdir $^)) $(LDFLAGS) -o $(OUT_DIR)$@
	@echo "======= Make Finish ======="
	
$(OBJ_FILES) : %.o : %.cpp
	@echo "=> Compile Objects: $@"
	$(CC) $(INC_PTAH) $(CFLAGS) $< -o $(OBJ_DIR)$@
	
.PHOUX : clean
clean :
	@echo "> Cleaning $(OBJ_FILES) $(OUT_FILES)"
	@$(RM) $(OBJ_DIR)*.o
	@$(RM) $(OUT_DIR)$(OUT_FILES)
	@echo "======= Clean Finish ======="
