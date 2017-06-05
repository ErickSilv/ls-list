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

int main()
{
    // Criando nova lista vazia
    list<int> listaInteiros = { 2 , 5 , 7 , 8 , 9 , 11 , 15 };

    assert(listaInteiros.front() == 2);

    listaInteiros.erase( listaInteiros.begin() );

    assert(listaInteiros.front() == 5);

    assert(listaInteiros.size() == 6);

    std::cout << ">>> FUNCIONA =D" << std::endl;

    return 0;
}