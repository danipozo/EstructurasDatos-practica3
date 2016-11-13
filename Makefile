SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usocolas $(BIN)/usopilas_max


$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o 
$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INC)

$(BIN)/usopilas_max: $(SRC)/lista.cpp $(SRC)/VD.cpp $(INC)/lista.h $(INC)/VD.h $(SRC)/PilaMax.cpp $(INC)/Pila_max.h $(SRC)/usopilas_max.cpp
	$(CXX) $(SRC)/usopilas_max.cpp -o usopilas_max -I$(INC) -I$(SRC) -std=c++14 -D$(IMPL)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
