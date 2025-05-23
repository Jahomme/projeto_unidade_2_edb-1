OBJS = exe\main.o exe\prato.o exe\fila.o exe\lista.o exe\cardapio.o
INCLUDE = include\cardapio.h include\fila.h include\lista.h include\prato.h
CARDAPIO = src\cardapio.c
MAIN = src\main.c
FILA = src\fila.c
PRATO = src\prato.c
LISTA = src\lista.c
PROG = exe\executavel.exe

$(PROG): $(OBJS)
	gcc -o $(PROG) $(OBJS)

exe\main.o: $(MAIN)
	gcc -c $(MAIN) -o exe\main.o

exe\lista.o: $(LISTA) $(INCLUDE)
	gcc -c $(LISTA) -o exe\lista.o

exe\fila.o: $(FILA) $(INCLUDE)
	gcc -c $(FILA) -o exe\fila.o

exe\cardapio.o: $(CARDAPIO) $(INCLUDE)
	gcc -c $(CARDAPIO) -o exe\cardapio.o

exe\prato.o: $(PRATO) $(INCLUDE)
	gcc -c $(PRATO) -o exe\prato.o

run: $(PROG)
	.\$(PROG)

clean:
ifeq ($(OS),Windows_NT)
	del /f /q $(OBJS) $(PROG)
else
    rm -f $(OBJS) $(PROG)
endif