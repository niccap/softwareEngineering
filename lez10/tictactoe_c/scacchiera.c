/**
 * @file scacchiera.c
 * @brief Implementazione delle funzioni per 
 *        gestire la scacchiera del gioco.
 */

#include <assert.h>
#include <stddef.h>
#include "scacchiera.h"

/* Dati privati del modulo */

/*
 * I possibili modi di fare tris
 */
static const int tris[][3] = {
    /* In orizzontale */
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},

    /* In verticale */
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    
    /* In diagonale */
    {0, 4, 8},
    {2, 4, 6},
};

/* Numero di modi di fare tris */
#define NUMERO_TRIS (sizeof(tris)/sizeof(tris[0]))


/* IMPLEMENTAZIONE DELLE FUNZIONI PUBBLICHE */

void inizializza_scacchiera(Scacchiera *s) {
    assert(s!=NULL);
    int i;
    for(i=0; i<DIMENSIONE_SCACCHIERA; i++)
        s->cella[i]=CELLA_VUOTA;
    s->prossimo=CELLA_X;
}

bool mossa_valida(Scacchiera *s, int mossa) {
    assert(s!=NULL);
    return mossa>=0 && mossa<DIMENSIONE_SCACCHIERA &&
        s->cella[mossa]==CELLA_VUOTA;
}

void aggiorna_scacchiera(Scacchiera *s, int mossa) {
    assert(s!=NULL);
    assert(mossa>=0 && mossa<DIMENSIONE_SCACCHIERA &&
        s->cella[mossa]==CELLA_VUOTA);
    s->cella[mossa]=s->prossimo;
    s->prossimo=(s->prossimo==CELLA_X)? CELLA_O: CELLA_X;
}

bool partita_terminata(Scacchiera *s, Cella *vincitore) {
    assert(s!=NULL);
    assert(vincitore!=NULL);

    /* Verifica se c'è un tris */
    int i, j;
    for(i=0; i<NUMERO_TRIS; i++) {
        int num_x=0;
        int num_o=0;
        for(j=0; j<3; j++) {
            int k=tris[i][j];
            if (s->cella[k]==CELLA_X)
                num_x++;
            else if (s->cella[k]==CELLA_O)
                num_o++;
        }
        if (num_x==3) {
            *vincitore = CELLA_X;
            return true;
        } else if (num_o==3) {
            *vincitore = CELLA_O;
            return true;
        }
    }

    /* Verifica se c'è una cella vuota */
    for(i=0; i<DIMENSIONE_SCACCHIERA; i++)
        if (s->cella[i]==CELLA_VUOTA)
            return false;

    /* Altrimenti, è finita in pareggio */
    *vincitore=CELLA_VUOTA;
    return true;
}




