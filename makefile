program: vista.o controlador.o modelo.o main.o
	gcc  -g -o program vista.o controlador.o modelo.o main.o -lm

vista.o: vista.c vista.h estructuras.h
	gcc -c vista.c

controlador.o: controlador.c controlador.h estructuras.h
	gcc -c controlador.c 

modelo.o: modelo.c modelo.h estructuras.h
	gcc -c modelo.c -lm

main.o: main.c modelo.h vista.h estructuras.h
	gcc -c main.c

clean:
	del *.o
	echo "Clean done"
 
