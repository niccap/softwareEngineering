/**
 * @file interfaccia_utente.h
 * @brief Funzioni per la gestione dell'interfaccia utente.
 */
#ifndef INTERFACCIA_UTENTE_H
#define INTERFACCIA_UTENTE_H

#include "scacchiera.h"

/**
 * @brief Chiede al giocatore se vuole giocare con la 'X' o con la 'O'.
 * @return CELLA_X oppure CELLA_O, a seconda della scelta del giocatore.
 */
Cella scegli_simbolo(void);

/**
 * @brief Chiede al giocatore di scegliere quale mossa vuole
 *        effettuare.
 * @param[in] s La scacchiera.
 * @return La mossa scelta (da 0 a DIMENSIONE_SCACCHIERA-1).
 *         La mossa restituita è valida (vedi mossa_valida()).
 * @pre
 * La scacchiera corrente è già stata visualizzata.
 * @pre
 * La partita non è terminata.
 */
int   scegli_mossa(Scacchiera *s);

/**
 * @brief Visualizza la scacchiera sullo schermo.
 * @param[in] s La scacchiera.
 * @post
 * La scacchiera viene visualizzata sullo schermo.
 */
void  visualizza_scacchiera(Scacchiera *s);

/**
 * @brief Comunica all'utente il risultato della partita
 *        quando è terminata.
 * @param[in] giocatore Il simbolo con cui sta giocando l'utente
 *                      (CELLA_X o CELLA_O).
 * @param[in] vincitore Il simbolo del vincitore della partita,
 *                      oppure CELLA_VUOTA in caso di pareggio.
 * @post
 * Viene visualizzato un messaggio che comunica l'esito della
 * partita.
 * @see partita_terminata()
 */
void  visualizza_risultato(Cella giocatore, Cella vincitore);

#endif
