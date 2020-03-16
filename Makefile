
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/test_arytm_zesp
	${TRGDIR}/test_arytm_zesp  latwy

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/Statystyka.o\
                      ${OBJ}/WyrazenieZesp.o  ${OBJ}/BazaTestu.o ${OBJ}/BazaTestu.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/LZespolona.o ${OBJ}/Statystyka.o\
                      ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: src/main.cpp inc/LZespolona.hh inc/BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o src/LZespolona.cpp

${OBJ}/Statystyka.o: src/Statystyka.cpp inc/Statystyka.hh
	g++ -c ${FLAGS} -o ${OBJ}/Statystyka.o src/Statystyka.cpp

${OBJ}/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp

${OBJ}/WyrazenieZesp.o: src/WyrazenieZesp.cpp inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o src/WyrazenieZesp.cpp

${OBJ}/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZesp.hh\
                       inc/LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp





clear:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
