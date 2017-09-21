# Makefile du projet Le7
# ----------------------
#

CC = g++
ARGS = -std=c++17

# Conf_Portable
# -------------
# PRG_HOME = /cygdrive/c/Users/Public/Tools/Cygwin64/home/Jacques
  PRG_HOME = /cygdrive/c/Users/Jacques/GitHubRepository/Le7

# Conf_DeskTop
# ------------
# PRG_HOME = /cygdrive/c/Users/Jacques/GitHubRepository/Le7

# -----------------------------------------------------------------------------

EXE_DIR = .

# --

CMN_DIR = $(PRG_HOME)/Src/Common
CMN_SRC = $(CMN_DIR)/C
CMN_HDR = $(CMN_DIR)/H

PRG_DIR = $(PRG_HOME)/Src
SRC_DIR = $(PRG_DIR)/C
HDR_DIR = $(PRG_DIR)/H

HDR_LST = $(HDR_DIR)/Joueur.h $(HDR_DIR)/Le7.h $(HDR_DIR)/Saisies.h $(CMN_HDR)/UI_distribution_randomizer.h $(HDR_DIR)/LeDe.h
SRC_LST = $(SRC_DIR)/Joueur.c $(SRC_DIR)/Le7.c $(SRC_DIR)/Saisies.c $(CMN_SRC)/UI_distribution_randomizer.c $(SRC_DIR)/LeDe.c

$(EXE_DIR)/Le7.exe : $(HDR_LST) $(SRC_LST)
	$(CC) $(ARGS) -o $(EXE_DIR)/Le7.exe $(SRC_LST) -I $(HDR_DIR) -I $(CMN_HDR)

clean :
	rm -f $(EXE_DIR)/Le7.exe
