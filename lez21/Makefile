COMP = gcc -c
LINK = gcc -o

all: tictactoe html
	
clean:
	rm *.o

tictactoe: tictactoe.o scacchiera.o strategia.o interfaccia_utente.o
	$(LINK) $@ $^

tictactoe.o: tictactoe.c scacchiera.h strategia.h interfaccia_utente.h
	$(COMP) $<

scacchiera.o: scacchiera.c scacchiera.h
	$(COMP) $<

strategia.o: strategia.c strategia.h scacchiera.h
	$(COMP) $<

interfaccia_utente.o: interfaccia_utente.c interfaccia_utente.h scacchiera.h
	$(COMP) $<
	
html: Doxyfile
	doxygen