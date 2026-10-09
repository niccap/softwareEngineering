/**
 * @file stack.c
 * @brief Esempio Stack
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

/**
 * @brief Numero massimo di elementi in uno stack
 */
#define MAX_STACK_SIZE 100

/**
 * @brief Struttura dati dello stack
 * @invariant num. elementi >= 0
 * @invariant num. elementi <= MAX_STACK_SIZE
 */
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

/**
 * @brief Inizializza lo stack
 * @post lo stack è vuoto
 * @param[out] s  Lo stack
 */
void init_stack(Stack *s) {
    s->size=0;
    assert(s->size == 0); // Postcondizione
    assert(stack_invariant(s)); // Invariante
}

/**
 * @brief Restituisce true se lo stack è vuoto
 * @param[in] s  Lo stack
 * @return true se il num. di elementi 
 *         è 0, false altrimenti
 * @post non modifica lo stack
 * @see is_full()
 */
bool is_empty(Stack *s) {
    assert(stack_invariant(s)); // Invariante
    bool result=(s->size==0);
    assert((s->size==0 && result) || (s->size>0 && !result)); // Postcond.
    assert(stack_invariant(s)); // Invariante
    return result;
}
    
/**
 * @brief Restituisce true se lo stack è pieno
 * @param[in] s  Lo stack
 * @return true se il num. di elementi 
 *               è MAX_STACK_SIZE, false altrimenti
 * @post non modifica lo stack
 * @see is_empty()
 */
bool is_full(Stack *s) {
    assert(stack_invariant(s)); // Invariante
    bool result=(s->size==MAX_STACK_SIZE);
    assert((s->size==MAX_STACK_SIZE && result) || 
            (s->size<MAX_STACK_SIZE && !result)); // Postcond.
    assert(stack_invariant(s)); // Invariante
    return result;
}
   
/**
 * @brief Inserisce un elemento nello stack
 * @param[inout] s Lo stack
 * @param[in] value Il valore dell'elemento da inserire
 * @pre Lo stack non è pieno (vedi: is_full())
 * @post Il numero di elementi nello stack è 
 *       aumentato di 1
 * @post L'elemento value è aggiunto allo stack
 * @see pop()
 */
void push(Stack *s, int value) {
    assert(stack_invariant(s)); // Invariante
    assert(s->size != MAX_STACK_SIZE); // Precondizione
    int old_size=s->size;
    s->data[s->size++]=value;
    assert(s->size==old_size+1); // Postcondizione
    assert(stack_invariant(s)); // Invariante
}


/**
 * @brief Preleva un elemento dallo stack
 * @param[inout] s Lo stack
 * @return Il valore dell'elemento più recente è
 *   restituito come valore di ritorno
 * @pre  Lo stack non è vuoto (vedi is_empty())
 * @post Il numero di elementi nello stack è 
 *       diminuito di 1
 * @post L'elemento più recente viene rimosso
 *       dallo stack
 * @see push()
 */
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
