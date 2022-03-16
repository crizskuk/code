#ifndef _STDINT
#define _STDINT
#include  <stdint.h>

#endif


#ifndef _LISTA_
#define _LISTA_

struct Nodo {
    uint16_t id;
    struct Nodo* next;
};

struct Lista {
    uint16_t cont = NULL;
    Nodo* head;
}_lista;

Nodo* CrearNodo(Lista* list, uint16_t id);
Nodo* InsertarFinalList(Lista* list, uint16_t id);
bool InfoNodos(Lista* list);
bool EliminarID(Lista* list, uint16_t id);
void ELiminarUltimo(Lista* list);

#endif