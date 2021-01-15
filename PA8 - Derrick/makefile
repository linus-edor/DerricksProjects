all: PA8.exe

clean:
    rm testProgram.o PA8.exe

PA8.exe: testProgram.o
    g++ -g -o PA8 testProgram.o

testProgram.o:
    g++ -c -g testProgram.cpp