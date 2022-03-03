#Compilateur
CC = g++
#Falgs du compilateur
CCFLAGS = -Wall -std=c++17 -g

#Localisation des fichiers source
SOURCE = ./src
#Localization des fichiers binaires
BIN = ./bin
#Interfaces
DEPS_H = $(wildcard *.h)
#Fichiers de réalisation
DEPS_CPP = $(wildcard *.cpp)
#Fichiers binaires
OBJS = $(DEPS_CPP:.cpp=.o)
#Nom de l'éxécutable
EXE = main

$(EXE) : $(OBJS)
	@echo ">>> Edition des liens de <$@>"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o : %.cpp $(DEPS_H)
	@echo ">>> Compilation de <$<>"
	$(CC) $(CCFLAGS) -c $<

cleanbin:
	@echo "Netoyage des binaires"
	@rm -f $(OBJS)

clean:
	@echo "Netoyage des binaires et executables"
	@rm -f $(OBJS)
	@rm -f $(EXE)
