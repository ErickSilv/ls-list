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
void print( list<T> & li )
{
	typename list<T>::const_iterator first = li.begin();
	typename list<T>::const_iterator last = li.end();

	std::cout << "[ ";
	for ( /* EMPTY */; first != last; ++first )
		std::cout << *first << " ";
	std::cout << "]\n";
}

int main()
{
	// Teste constructor vazio. //
	{
		std::cout << "\n>>> Teste constructor vazio <<<" << std::endl;
		list<int> listaVazia;
		std::cout << "Lista Vazia" << std::endl;
		print( listaVazia );
	}
	//Fim teste costructor vazio. //

	//Teste construtor com tamanho inicial //
	{
		std::cout << "\n>>> Teste constructor lista vazia mas com tamanho inicial > 0 <<< " << std::endl;
		list< std::string > listaTamanho( 4 );
		std::cout << "Tamanho : " << listaTamanho.size() << std::endl;
		std::cout << "Lista = ";
		print ( listaTamanho );
	}
	//Fim do teste de constructor com tamanho definido. //

	//Teste de construtor com range. //
	{
		std::cout << "\n>>> Teste de construtor com range. <<<" << std::endl;
		list< std::string > listaBaseRange = { "abc", "def", "ghi", "jkl" };
		std::cout << "Lista base para constructor com ranges = ";
		print( listaBaseRange ); 
		
		list< std::string > listaRange ( listaBaseRange.cbegin(), listaBaseRange.cend() );
		std::cout << "Lista cópia da listaBaseRange = ";
		print ( listaRange );

		list<std::string> listaVazia;
		list< std::string > listaRangeVazia ( listaVazia.cbegin(), listaVazia.cend() );
		std::cout << "Lista cópia da listaVazia = ";
		print ( listaRangeVazia );

		std::cout << "\n";
	}
	//Fim do teste de constructor com range //

	//Teste constructor cópia //
	{
		std::cout << "\n>>> Teste constructor cópia <<< " << std::endl;
		list<int> listaBaseCopia = { 1, 2, 3, 4, 5, 6, 7 };
		std::cout << "Base = ";
		print( listaBaseCopia );

		list<int> listaCopia ( listaBaseCopia );
		std::cout << "Copia = ";
		print( listaCopia );
	}
	//Fim do teste constructor cópia //

	//Teste com initializer list //
	{
		std::cout << "\n>>> Teste constructor com initializer list <<<" << std::endl;
		list <int> listComIList ( { 2, 4, 6, 8, 10 } );

		std::cout << "Lista construída = ";
		print( listComIList );

	} 
	// FIm do teste coo initializer list //

	//Teste sobrecarga do operator= para cópia //
	{
		std::cout << "\n>>>Teste sobrecarga do 'operator=' para copia <<<\n";
		list<int> listaBaseCopia ( {1, 2, 3, 4, 5, 6, 7} );

		list<int> listaTestOperator = listaBaseCopia;
		std::cout << "Lista copiada = ";
		print ( listaTestOperator );
	}	
	//Fim do teste do operator= //

	//Teste sobrecarga do operator= para initiliazer list //
	{
		std::cout << "\n>>>Teste sobrecarga do 'operator=' para initiliazer list <<<\n";
		list<int> listaBaseCopiaIList ( {1, 2, 3, 4, 5, 6, 7} );

		list<int> listaTestOperator = listaBaseCopiaIList;
		std::cout << "Lista copiada = ";
		print ( listaTestOperator );
	}
	//Fim do teste do operator= //

	// Inserindo elementos na lista anteriormente vazia
	list<int> listToInsertInto = { 0 , 5 , 10 , 15 , 20 };
	list<int> listToBeInserted = { 1 , 2 ,  3 ,  4 , 5  };
	listToInsertInto.insert( listToInsertInto.begin(), listToBeInserted.begin() , listToBeInserted.end() ); 
	print( listToInsertInto );

    // Criando nova lista vazia
    list<int> listaInteiros = { 2 , 5 , 7 , 8 , 9 , 11 , 15 };

    return 0;
}