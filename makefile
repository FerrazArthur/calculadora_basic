CC = g++
CFLAGS= -w -std=c++14

calculadora:
	$(CC) $(CFLAGS) -o calculadora calculadora.cpp
clean:
	\rm calculadora
