/**
 * @file strategia.c
 * @brief Implementazione delle funzioni per la strategia di gioco del computer.
 */

#include <stdlib.h>
#include <assert.h>

#include "strategia.h"
#include "scacchiera.h"

/* Prototipi delle funzioni private */
static int valuta_mossa(Scacchiera *s, int mossa);

/* IMPLEMENTAZIONE DELLE FUNZIONI PUBBLICHE */

int calcola_mossa_computer(Scacchiera *s) {
    assert(s!=NULL);
    int mossa_migliore=-1;
    int valore_migliore;
    int mossa;
    for(mossa=0; mossa<DIMENSIONE_SCACCHIERA; mossa++) {
        if (mossa_valida(s, mossa)) {
            int valore=valuta_mossa(s, mossa);
            if (mossa_migliore<0 || valore>valore_migliore
                || (valore==valore_migliore &&
                    (random()&1)==0)) {
                mossa_migliore=mossa;
                valore_migliore=valore;
            }
        }
    }
    assert(mossa_migliore>=0);
    return mossa_migliore;
}

/* Valori delle mosse */
#define VINCENTE +100
#define PERDENTE -100
#define NEUTRA   0

static int valuta_mossa(Scacchiera *s, int mossa) {
    /* Lavora su una copia della scacchiera */
    Scacchiera copia=*s;
    aggiorna_scacchiera(&copia, mossa);
    Cella vincitore;
    if (partita_terminata(&copia, &vincitore)) {
            if (vincitore==CELLA_VUOTA)
                return NEUTRA;
            else
                return VINCENTE;
    }
    /* La mossa non termina la partita; valuta le
     * contromosse dell'avversario.
     */
    int contromossa;
    for(contromossa=0; contromossa<DIMENSIONE_SCACCHIERA; contromossa++) {
        if (mossa_valida(&copia, contromossa)) {
            /* Altra copia */
            Scacchiera copia2=copia;
            aggiorna_scacchiera(&copia2, contromossa);
            /* Se la contromossa fa vincere l'avversario,
             * allora la mossa viene valutata come perdente 
             */
            if (partita_terminata(&copia2, &vincitore) &&
                    vincitore!=CELLA_VUOTA)
                return PERDENTE;
        }
    }

    return NEUTRA;
}
