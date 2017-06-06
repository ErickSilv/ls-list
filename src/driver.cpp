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

template <typename T>
void print( ls::list<T> & li )
{
	typename ls::list<T>::const_iterator first = li.begin();
	typename ls::list<T>::const_iterator last = li.end();

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
		ls::list<int> listaVazia;
		std::cout << "Lista Vazia" << std::endl;
		print( listaVazia );
	}
	//Fim teste costructor vazio. //

	//Teste construtor com tamanho inicial //
	{
		std::cout << "\n>>> Teste constructor lista vazia mas com tamanho inicial > 0 <<< " << std::endl;
		ls::list< std::string > listaTamanho( 4 );
		std::cout << "Tamanho : " << listaTamanho.size() << std::endl;
		std::cout << "Lista = ";
		print ( listaTamanho );
	}
	//Fim do teste de constructor com tamanho definido. //

	//Teste de construtor com range. //
	{
		std::cout << "\n>>> Teste de construtor com range. <<<" << std::endl;
		ls::list< std::string > listaBaseRange = { "abc", "def", "ghi", "jkl" };
		std::cout << "Lista base para constructor com ranges = ";
		print( listaBaseRange ); 
		
		ls::list< std::string > listaRange ( listaBaseRange.cbegin(), listaBaseRange.cend() );
		std::cout << "Lista cópia da listaBaseRange = ";
		print ( listaRange );

		list<std::string> listaVazia;
		ls::list< std::string > listaRangeVazia ( listaVazia.cbegin(), listaVazia.cend() );
		std::cout << "Lista cópia da listaVazia = ";
		print ( listaRangeVazia );

		std::cout << "\n";
	}
	//Fim do teste de constructor com range //

	//Teste constructor cópia //
	{
		std::cout << "\n>>> Teste constructor cópia <<< " << std::endl;
		ls::list<int> listaBaseCopia = { 1, 2, 3, 4, 5, 6, 7 };
		std::cout << "Base = ";
		print( listaBaseCopia );

		ls::list<int> listaCopia ( listaBaseCopia );
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
		ls::list<int> listaBaseCopia ( {1, 2, 3, 4, 5, 6, 7} );

		ls::list<int> listaTestOperator = listaBaseCopia;
		std::cout << "Lista copiada = ";
		print ( listaTestOperator );
	}	
	//Fim do teste do operator= //

	//Teste sobrecarga do operator= para initiliazer list //
	{
		std::cout << "\n>>>Teste sobrecarga do 'operator=' para initiliazer list <<<\n";
		ls::list<int> listaBaseCopiaIList ( {1, 2, 3, 4, 5, 6, 7} );

		ls::list<int> listaTestOperator = listaBaseCopiaIList;
		std::cout << "Lista copiada = ";
		print ( listaTestOperator );
	}
	//Fim do teste do operator= //

	//Teste push_back, pop_back, erase( dentro do pop_back ) back //
	{
		ls::list<int> lista; //Lista vazia

		std::cout << "\n>>> Teste adicionando, elemento à elemento, do intervalo [1, 10] (push_back) " << std::endl;
		for ( auto i(1); i <= 10; ++i )
		{
			std::cout << "Adicionando " << i << " ao final da lista. \n";
			lista.push_back( i );

			print( lista );
		}

		std::cout << "\n>>> Teste retirando todos os elementos, cada vez retirando o último (pop_back)" << std::endl;

		while ( lista.size() > 0 )
		{
			std::cout << " Retirando o elemento " << lista.back() << " da lista. " << std::endl; 
			print( lista );
			lista.pop_back();
		}

		std::cout << "Lista vazia após todos os pop_backs\n";
		print ( lista );

	}
	//Fim dos testes push_back, pop_back, erase( dentro do pop_back ) e back //

	//Teste push_front, pop_front, erase ( dentro do pop_front) e front //
	{
		ls::list< int > lista; //Lista vazia

		std::cout << "\n>>> Teste adicionando, elemento à elemento, do intervalo [1, 10] (push_front) " << std::endl;
		for ( auto i(1); i <= 10; ++i )
		{
			std::cout << "Adicionando " << i << " ao inicio da lista. \n";
			lista.push_front( i );

			print( lista );
		}

		std::cout << "\n>>> Teste retirando todos os elementos, cada vez retirando o primeiro (pop_front)" << std::endl;

		while ( lista.size() > 0 )
		{
			std::cout << " Retirando o elemento " << lista.front() << " da lista. " << std::endl; 
			print( lista );
			lista.pop_front();
		}

		std::cout << "Lista vazia após todos os pop_fronts\n";
		print ( lista );

	}
	//Fim dos testes push_front, pop_front, erase (dentro do pop_front) e front //

	//Teste do clear //
	{
		ls::list< std::string > lista = { "abc", "def", "ghi", "jkl" };
		lista.clear();

		std::cout << "Lista após clear() = ";
		print( lista );

	}
	//Fim do teste do clear //

	//Teste empty() //
	{
		ls::list< std::string > lista = { "abc", "def", "ghi", "jkl" };
		assert ( lista.empty() == false );

		lista.clear();

		assert ( lista.empty() == true );
	}
	//Fim dos teste do empty() //

	//Teste assign //
	{
		std::cout << "\n>>> Testes assing:\n";
		ls::list<int> lista = { 1, 2, 3, 4, 5 };
		std::cout << "Lista: ";
		print( lista );
			
		std::cout << " Assign por um só número \n";
		lista.assign( 0 );
		std::cout << "Lista1 = ";
		print(lista);
			
		std::cout << " Assign com iterator.\n";
		ls::list<int> listaIL = { 1, 2 };
		lista.assign( listaIL.cbegin(), listaIL.cend() );
		std::cout << "Lista2 = ";
		print( lista );
	
		std::cout << " Assign com initializer list \n";
		lista.assign( { 3, 4 } );
		std::cout << "Lista3 = ";
		print( lista );
	}
	//Fim dos testes do assign //



	//Testes insert //
	{
		std::cout << "\n>>> Inserindo elementos na lista anteriormente vazia <<< \n";
		ls::list<int> listToInsertInto = { 0 , 5 , 10 , 15 , 20 };
		std::cout << "\nPrimeira Lista =";
		print ( listToInsertInto );

		ls::list<int> listToBeInserted = { 1 , 2 ,  3 ,  4 , 5  };
		std::cout << "\nSegunda Lista = ";
		print ( listToBeInserted );

		std::cout << "\n Post insertion with ranges, segunda lista antes da primeira, = ";
		listToInsertInto.insert( listToInsertInto.begin(), listToBeInserted.begin() , listToBeInserted.end() ); 
		std::cout << "\n Nova lista = ";
		print( listToInsertInto );


		std::cout << "\nTerceira Lista = [ 21, 22, 23, 24, 25, 26 ]";
		listToInsertInto.insert( listToInsertInto.end(), { 21, 22, 23, 24, 25, 26 } );
		std::cout << "\nLista Final = "; 
		print ( listToInsertInto );

	}
	//Fim dos testes insert //


	//Testes erase //
	{
		std::cout << "\n>>> Erase testes <<< \n";
		ls::list<int> listToBeErased = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		std::cout << "\nErase first element \n";
		listToBeErased.erase( listToBeErased.cbegin() );
		std::cout << "Lista = ";
		print( listToBeErased );
		
		std::cout << "\nErase all list by range\n";	
		listToBeErased.erase( listToBeErased.cbegin(), listToBeErased.cend() );
		std::cout << "Lista = ";
		//assert( listToBeErased.empty() == true );	
		print( listToBeErased );

	}
	//Fim dos testes erase //
    
    return EXIT_SUCCESS;
}