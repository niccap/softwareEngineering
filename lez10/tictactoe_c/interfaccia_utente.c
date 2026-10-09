/**
 * @file interfaccia_utente.c
 * @brief Implementazione delle funzioni per la gestione 
 * dell'interfaccia utente.
 */
#include <stdio.h>
#include <assert.h>
#include "interfaccia_utente.h"

/* Prototipi delle funzioni private del modulo */
static char simbolo(Cella c);
static char mostra(Cella cella[], int posizione);

/* IMPLEMENTAZIONE DELLE FUNZIONI PUBBLICHE */

Cella scegli_simbolo(void) {
    printf("Con quale simbolo vuoi giocare?\n");
    int scelta;
    do {
      printf("Inserisci 1 per <X> oppure 2 per <O>: ");
      int res=scanf("%d", &scelta);
      assert(res==1);
    } while (scelta!=1 && scelta!=2);
    return scelta==1? CELLA_X: CELLA_O;
}

int   scegli_mossa(Scacchiera *s) {
    int scelta, mossa;
    do {
        printf("Inserisci la tua mossa: ");
        int res=scanf("%d", &scelta);
        assert(res==1);
        mossa=scelta-1;
        if (mossa_valida(s, mossa))
            return mossa;
    } while (true);
}

void  visualizza_scacchiera(Scacchiera *s) {
    Cella *c=s->cella;
    printf("\n");
    printf(" %c | %c | %c \n",
           mostra(c, 0), mostra(c, 1), mostra(c, 2)); 
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",
           mostra(c, 3), mostra(c, 4), mostra(c, 5)); 
    printf("---+---+---\n");
    printf(" %c | %c | %c \n",
           mostra(c, 6), mostra(c, 7), mostra(c, 8)); 
    printf("Tocca al giocatore <%c>\n", simbolo(s->prossimo));
}

void  visualizza_risultato(Cella giocatore, Cella vincitore) {
    printf("La partita è terminata.\n");
    if (vincitore==CELLA_VUOTA)
        printf("È finita in pareggio.\n");
    else if (vincitore==giocatore)
        printf("HAI VINTO!!! Sei un vero campione!\n");
    else
        printf("Questa volta hai perso. Ritenta, sarai più fortunato.\n");
}


/* Implementazione delle funzioni private */
static char simbolo(Cella c) {
    if (c==CELLA_VUOTA)
        return ' ';
    else if (c==CELLA_X)
        return 'X';
    else if (c==CELLA_O)
        return 'O';
    else
        return '?';
}

static char mostra(Cella cella[], int posizione) {
    assert(posizione>=0 && posizione<DIMENSIONE_SCACCHIERA);
    Cella c=cella[posizione];
    if (c==CELLA_VUOTA)
        return '1'+posizione;
    else
        return simbolo(c);
}
