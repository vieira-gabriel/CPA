#O compilador
COMPILER = g++
# Comando para remover pastas
RMDIR = rm -rdf
#Comando para remover arquivos
RM = rm -f

# main: Lista1.o
# 	$(COMPILER) Lista1.o -o main

# Lista1.o: Lista1.cpp
# 	$(COMPILER) -c Lista1.cpp


q1: q1_lista1a.o
	$(COMPILER) q1_lista1a.o -o q1

q1_lista1a.o: q1_lista1a.cpp
	$(COMPILER) -c q1_lista1a.cpp

# q2: q2_lista1a.o
# 	$(COMPILER) q2_lista1a.o -o q2

# q2_lista1a.o: q2_lista1a.cpp
# 	$(COMPILER) -c q2_lista1a.cpp

# q3: q1_lista1a.o
# 	$(COMPILER) q3_lista1a.o -o q3

# q3_lista1a.o: q1_lista1a.cpp
# 	$(COMPILER) -c q3_lista1a.cpp

clean:
	rm *.o q1 q2 q3 main