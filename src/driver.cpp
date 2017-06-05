/* Linguagens de Programação 2017.1
 * Autorship: Daniel Barbosa and Erick Silva
 * 
 * Implementation of the List ADT using doubly linked list
*/

// Quick compilation
// g++ src/driver.cpp -o bin/list -I include -Wall -std=c++11 

#include <iostream>
#include <cassert>

#include "list.h"

using namespace ls;

template <typename T>
void print( list<T> & v )
{
	list<T>::const_iterator b_it = v.begin();
	list<T>::const_iterator e_it = v.end();

	std::cout << "[ ";
	for ( /*empty*/; b_it != e_it; ++b_it )
		std::cout << *b_it << " ";
	std::cout << "]\n";
}

int main()
{
	// Teste construtor vazio. //
	list<int> listaVazia;
	std::cout << "Lista Vazia" << std::endl;
	print( listaVazia );


    // Criando nova lista vazia
    list<int> listaInteiros = { 2 , 5 , 7 , 8 , 9 , 11 , 15 };

    return 0;
}