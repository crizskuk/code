#include <iostream>
#include "lista.h"

Nodo* CrearNodo(Lista* list, uint16_t id) {
	Nodo* nodo = new(Nodo);
	nodo->next = list->head;
	list->head = nodo;
	nodo->id = id;
	list->cont++;
	return nodo;
}

bool InfoNodos(Lista* list) {
	if (list->head == nullptr) {
		std::cout << "lista vacia" << std::endl;
		return false;
	}
	Nodo* tmp = list->head;
	while (tmp) {
		std::cout << "offset: " << tmp << " id: " << tmp->id << " next: " << tmp->next << std::endl;
		tmp = tmp->next;
	}
}

Nodo* InsertarFinalList(Lista* list, uint16_t id) {
	Nodo* nodo = new(Nodo);
	nodo->id = id;
	nodo->next = nullptr;
	if (list->head == nullptr) {
		nodo->next == nullptr;
		list->head = nodo;
		return nodo;
	}
	Nodo* tmp = list->head;
	while (tmp->next) {
		tmp = tmp->next;
	}
	tmp->next = nodo;
	return nodo;
}


void ELiminarUltimo(Lista* list) {
	if (list->head) {
		if (list->head->next) {
			Nodo* tmp = list->head;
			while (tmp->next->next) {
				tmp = tmp->next;
			}
		} 
	}
}
	
int main(void) {
	Nodo* v1 = CrearNodo(&_lista, 2);
	Nodo* v0 = InsertarFinalList(&_lista, 0);
	Nodo* v2 = CrearNodo(&_lista, 4);
	Nodo* v3 = CrearNodo(&_lista, 8);
	Nodo* v4 = InsertarFinalList(&_lista, 16);
	Nodo* v5 = InsertarFinalList(&_lista, 32);
	Nodo* v6 = InsertarFinalList(&_lista, 64);
	InfoNodos(&_lista);
	return 0;
}