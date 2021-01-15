all: play

play:play.o referee.o player.o
	
play.o: 
	cc play.c -o play	

referee.o: 
	cc referee.c -o referee.o	

player.o: 
	cc player.c -o player.o	

clean:
	rm -rf *.o play	

