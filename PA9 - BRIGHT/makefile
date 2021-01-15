all: PA9.exe

clean:
    rm testProgGraph.o PA9.exe

PA9.exe: testProgGraph.o
    g++ -g -o PA9 testProgGraph.o

testProgGraph.o:
    g++ -c -g testProgGraph.cpp