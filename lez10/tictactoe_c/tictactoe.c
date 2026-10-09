/**
 * @file tictactoe.c
 * @brief Main del gioco.
 */
#include <stdlib.h>
#include <time.h>

#include "scacchiera.h"
#include "interfaccia_utente.h"
#include "strategia.h"


int main() {
    /* Inizializza il generatore di numeri casuali */
    srandom(time(NULL));

    Cella giocatore=scegli_simbolo();
    Cella vincitore;
    Scacchiera s;
    inizializza_scacchiera(&s);
    bool terminata=false;
    while (!terminata) {
        visualizza_scacchiera(&s);
        int mossa;
        if (s.prossimo==giocatore) {
            mossa=scegli_mossa(&s);
        } else {
            mossa=calcola_mossa_computer(&s);
        }
        aggiorna_scacchiera(&s, mossa);
        terminata=partita_terminata(&s, &vincitore);
    }
    visualizza_scacchiera(&s);
    visualizza_risultato(giocatore, vincitore);
    return 0;
}
