/* Linguagens de Programação 2017.1
 * Autorship: Daniel Barbosa and Erick Silva
 * 
 * Implementation of the List ADT using doubly linked list
*/

// Quick compilation
// g++ src/list.cpp src/driver.cpp -o bin/list -I include -Wall -std=c++11 

#include <iostream>

#include "list.h"

using namespace ls;

int main()
{
    // Criando nova lista vazia
    // :: ERRO: REFERÊNCIA INDEFINIDA ::
    list<int> listaInteiros;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}