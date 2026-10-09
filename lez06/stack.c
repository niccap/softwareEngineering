#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/* Struttura dati */
#define MAX_STACK_SIZE 100
typedef struct {
    int data[MAX_STACK_SIZE];
    int size;
} Stack;


/* Questa funzione non fa parte del contratto ma
 * è usata per semplificare il controllo dell'invariante.
 */
static bool stack_invariant(Stack *s) {
    return s->size>=0 && s->size<=MAX_STACK_SIZE;
}

/*-----------------------------------
 * Inizializza lo stack
 * Post: lo stack è vuoto
 *---------------------------------*/
void init_stack(Stack *s) {
    s->size=0;
    assert(s->size == 0); // Postcondizione
    assert(stack_invariant(s)); // Invariante
}

/*---------------------------------------
 * Restituisce true se lo stack è vuoto
 * Post:
 * - restituisce true se il num. di elementi 
 *   è 0, false altrimenti
 * - non modifica lo stack
 ---------------------------------------*/
bool is_empty(Stack *s) {
    assert(stack_invariant(s)); // Invariante
    bool result=(s->size==0);
    assert((s->size==0 && result) || (s->size>0 && !result)); // Postcond.
    assert(stack_invariant(s)); // Invariante
    return result;
}
    
/*---------------------------------------
 * Restituisce true se lo stack è pieno
 * Post:
 * - restituisce true se il num. di elementi 
 *   è MAX_STACK_SIZE, false altrimenti
 * - non modifica lo stack
 ---------------------------------------*/
bool is_full(Stack *s) {
    assert(stack_invariant(s)); // Invariante
    bool result=(s->size==MAX_STACK_SIZE);
    assert((s->size==MAX_STACK_SIZE && result) || 
            (s->size<MAX_STACK_SIZE && !result)); // Postcond.
    assert(stack_invariant(s)); // Invariante
    return result;
}
   
/*--------------------------------------
 * Inserisce un elemento nello stack
 * Pre:
 *   Lo stack non è pieno
 * Post:
 * - Il numero di elementi nello stack è 
 *   aumentato di 1
 * - L'elemento value è aggiunto allo stack
 -----------------------------------------*/
void push(Stack *s, int value) {
    assert(stack_invariant(s)); // Invariante
    assert(s->size != MAX_STACK_SIZE); // Precondizione
    int old_size=s->size;
    s->data[s->size++]=value;
    assert(s->size==old_size+1); // Postcondizione
    assert(stack_invariant(s)); // Invariante
}


/*--------------------------------------
 * Preleva un elemento dallo stack
 * Pre:
 *   Lo stack non è vuoto
 * Post:
 * - Il numero di elementi nello stack è 
 *   diminuito di 1
 * - L'elemento più recente viene rimosso
 *   dallo stack
 * - Il valore dell'elemento più recente è
 *   restituito come valore di ritorno
 -----------------------------------------*/
int pop(Stack *s) {
    assert(stack_invariant(s)); // Invariante
    assert(s->size != 0); // Precondizione
    int old_size=s->size;
    int result=s->data[--s->size];
    assert(s->size==old_size-1); // Postcondizione
    assert(stack_invariant(s)); // Invariante
    return result;
}

int main() {
    Stack s;
    init_stack(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Primo valore estratto: %d\n", pop(&s));
    printf("Secondo valore estratto: %d\n", pop(&s));
    printf("Terzo valore estratto: %d\n", pop(&s));
    printf("Quarto valore estratto: %d\n", pop(&s));
    return 0;
}
