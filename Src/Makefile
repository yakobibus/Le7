# Makefile du projet Le7
# ----------------------
#

CC = g++
ARGS = -std=c++17

PRG_HOME = C:/Users/Public/Tools/Cygwin64/home/Jacques

CMN_DIR = $(PRG_HOME)/Prog/C/CppInAction/Versions.Le7/Src/Common
CMN_SRC = $(CMN_DIR)/Src
CMN_HDR = $(CMN_DIR)/Hdr

PRG_DIR = $(PRG_HOME)/Prog/C/CppInAction/Versions.Le7/Src
EXE_DIR = $(PRG_DIR)/../Exe
SRC_DIR = $(PRG_DIR)/C
HDR_DIR = $(PRG_DIR)/H

HDR_LST = $(HDR_DIR)/Joueur.h $(HDR_DIR)/Le7.h 
SRC_LST = $(SRC_DIR)/Joueur.c $(SRC_DIR)/Le7.c

$(EXE_DIR)/Le7.exe : $(HDR_LST) $(SRC_LST)
	$(CC) $(ARGS) -o $(EXE_DIR)/Le7.exe $(SRC_LST) -I $(HDR_DIR) -I $(CMN_HDR)

clean :
	rm -f $(EXE_DIR)/Le7.exe


