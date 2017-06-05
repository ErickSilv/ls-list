/* Linguagens de Programação 2017.1
 * Autorship: Daniel Barbosa and Erick Silva
 * 
 * Implementation of the List ADT using doubly linked list
*/

#include <cassert>

#include "list.h"

using namespace ls;

// =========== CONST_ITERATOR THINGS ===========

// >> const_iterator operators
// Operator* (*const_iterator)
template <typename T>
const T & list<T>::const_iterator::operator*() const
{
    // Verifica se o ponteiro é nulo
    assert(current != nullptr);

    // Caso não seja nulo, retorna o campo DATA do nó apontado pelo const_iterator
    return current->data;
}

// Operator++ (++const_iterator)
template <typename T>
typename list<T>::const_iterator & ls::list<T>::const_iterator::operator++()
{
    current = current->next;
	return *this;
}

// Operator++ (const_iterator++)
template <typename T>
typename list<T>::const_iterator ls::list<T>::const_iterator::operator++( int )
{
    auto temp = *this;
    current = current->next;
	return temp;
}

// Operator-- (--const_iterator)
template <typename T>
typename list<T>::const_iterator & ls::list<T>::const_iterator::operator--()
{
    current = current->prev;
	return *this;
}

// Operator-- (const_iterator--)
template <typename T>
typename list<T>::const_iterator ls::list<T>::const_iterator::operator--( int )
{
    auto temp = *this;
    current = current->prev;
	return temp;
}

// Operator==
template <typename T>
bool list<T>::const_iterator::operator== ( const const_iterator & rhs ) const
{
    return (current == rhs.current);
}

// Operator!=
template <typename T>
bool list<T>::const_iterator::operator!= ( const const_iterator & rhs ) const
{
    return (current != rhs.current);
}

// =========== ITERATOR THINGS ===========

// >> iterator operators
// Operator* (*iterator)
template <typename T>
T & list<T>::iterator::operator*()
{
    
}

// Operator++ (++iterator)
template <typename T>
typename list<T>::iterator & list<T>::iterator::operator++()
{
    
}

// Operator++ (iterator++)
template <typename T>
typename list<T>::iterator list<T>::iterator::operator++( int )
{
    
}

// Operator-- (--iterator)
template <typename T>
typename list<T>::iterator & list<T>::iterator::operator--()
{
    
}

// Operator-- (iterator--)
template <typename T>
typename list<T>::iterator list<T>::iterator::operator--( int )
{
    
}

// Operator==
template <typename T>
bool list<T>::iterator::operator== ( iterator & rhs ) const
{
    return (current == rhs.current);
}

// Operator!=
template <typename T>
bool list<T>::iterator::operator!= ( iterator & rhs ) const
{
    return (current != rhs.current);
}

// =========== LIST THINGS ===========

// >> list constructors 
template <typename T>
list<T>::list() 
    : m_size( 0 )
    , m_head( new Node() )
    , m_tail( new Node() )
{
    // Configura as referências de prev e next do HEAD e TAIL
    m_head->next = m_tail;
	m_tail->prev = m_head;
}

template <typename T>
list<T>::list( typename list<T>::size_type count )
    : m_size( count )
    , m_head( new Node() )
    , m_tail( new Node() )
{
    // Configura as referências de prev e next do HEAD e TAIL
    m_head->next = m_tail;
	m_tail->prev = m_head;

	auto current( m_head );
    auto temp( count );

    // Cria N novos nós
	while(temp > 0){

        // Cria um novo nó (fora da lista)
		auto n_node = new Node(T(), current, current->next);

        // Define o PREV do nó seguinte como o novo nó criado
		current->next->prev = n_node;

        // Define o NEXT do nó atual como o novo nó criado
		current->next = n_node;

        // Define o nó atual como o novo nó criado
		current = current->next;

        temp--;
	}
}

template <typename T>
template <typename InputIt>
list<T>::list( InputIt first , InputIt last )
    : m_size( 0 )
    , m_head( new Node() )
    , m_tail( new Node() )
{
    // Configura as referências de prev e next do HEAD e TAIL
    m_head->next = m_tail;
	m_tail->prev = m_head;

    // Insere todos os elementos do intervalo na lista usando a função push_back()
    for ( /* EMPTY */ ; first < last ; first++ )
		push_back( *first );

}

template <typename T>
list<T>::list( const list & other )
    : m_size( 0 )
    , m_head( new Node() )
    , m_tail( new Node() )
{
    // Configura as referências de prev e next do HEAD e TAIL
    m_head->next = m_tail;
	m_tail->prev = m_head;

    auto first( other.cbegin() );
    auto last ( other.cend()   );

    // Copia todos os elementos da lista passada como parâmetro para a lista atual
    for ( /* EMPTY */ ; first < last ; first++ )
        push_back( *first );
}

template <typename T>
list<T>::list( std::initializer_list<T> ilist )
    : m_size( 0 )
    , m_head( new Node() )
    , m_tail( new Node() )
{
    // Configura as referências de prev e next do HEAD e TAIL
    m_head->next = m_tail;
	m_tail->prev = m_head;

    auto first( ilist.begin() );
    auto last ( ilist.end()   );

    // Copia todos os elementos de ilist para a lista atual
    for ( /* EMPTY */ ; first < last ; first++ )
        push_back( *first );

}

template <typename T>
list<T>::~list()
{
    clear();
    delete m_head;
    delete m_tail;
}

template <typename T>
list<T> & list<T>::list::operator=( const list& other )
{
    // Verifica se as listas já são iguais
    if (this == &other) return *this;

    clear();

    auto first( other.cbegin() );
    auto last ( other.cend()   );

    // Preenche a lista com o conteúdo de other
    for ( /* EMPTY */ ; first < last ; first++ )
        push_back( *first );
}

template <typename T>
list<T> & list<T>::list::operator=( std::initializer_list<T> ilist )
{
    clear();

    auto first( ilist.begin() );
    auto last ( ilist.end()   );

    // Preenche a lista com o conteúdo de ilist
    for ( /* EMPTY */ ; first < last ; first++ )
        push_back( *first );
}

// >> list methods
template <typename T>
typename list<T>::size_type list<T>::size() const
{
    // STUB IMPLEMENTATION
    return 0;
}

template <typename T>
void list<T>::clear()
{
    
}

template <typename T>
bool list<T>::empty()
{
    // STUB IMPLEMENTATION
    return true;
}

template <typename T>
void list<T>::push_front( const T & value )
{

}

template <typename T>
void list<T>::push_back( const T & value )
{
    
}

template <typename T>
void list<T>::pop_front()
{
    
}

template <typename T>
void list<T>::pop_back()
{
    
}

template <typename T>
const T & list<T>::front() const
{
    
}

template <typename T>
const T & list<T>::back() const
{
    
}

template <typename T>
void list<T>::assign( const T & value )
{
    
}

// >> list comparison operators
template <typename T>
bool operator==( const ls::list<T> & lhs, const ls::list<T> & rhs )
{
    if( lhs.size() != rhs.size() ) 
        return false;
    else
    {
        auto lhs_it( lhs.cbegin() );
		auto rhs_it( rhs.cbegin() );

        for ( /* EMPTY */ ; lhs_it != lhs.cend(); lhs_it++, rhs_it++ )
			if( *lhs_it != *rhs_it ) 
                return false;
    }

    return true;

}

template <typename T>
bool operator!=( const ls::list<T> & lhs, const ls::list<T> & rhs )
{
    if( lhs.size() != rhs.size() ) 
        return true;
    else
    {
        auto lhs_it( lhs.cbegin() );
		auto rhs_it( rhs.cbegin() );

        for ( /* EMPTY */ ; lhs_it != lhs.cend(); lhs_it++, rhs_it++ )
			if( *lhs_it != *rhs_it ) 
                return true;
    }

    return false;
}

// >> list iterator-related operations
template <typename T>
typename list<T>::iterator list<T>::begin()
{

}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const
{

}

template <typename T>
typename list<T>::iterator list<T>::end()
{

}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const
{

}

// >> list iterator insertion operations
template <typename T>
typename list<T>::iterator list<T>::insert( typename list<T>::iterator pos , const T & value )
{

}

template <typename T>
template <typename InItr>
typename list<T>::iterator list<T>::insert( typename list<T>::iterator pos , InItr first , InItr last )
{
    
}

template <typename T>
typename list<T>::iterator list<T>::insert( list<T>::iterator pos , std::initializer_list<T> ilist )
{

}

template <typename T>
typename list<T>::iterator list<T>::erase( typename list<T>::iterator pos )
{

}

template <typename T>
typename list<T>::iterator list<T>::erase( typename list<T>::iterator first , typename list<T>::iterator last )
{

}

// >> list const-iterator insertion operations
template <typename T>
typename list<T>::const_iterator list<T>::insert( typename list<T>::const_iterator pos , const T & value )
{

}

template <typename T>
template <typename InItr>
typename list<T>::const_iterator list<T>::insert( typename list<T>::const_iterator pos , InItr first , InItr last )
{

}

template <typename T>
typename list<T>::const_iterator list<T>::insert( typename list<T>::const_iterator pos , std::initializer_list<T> ilist )
{

}

template <typename T>
typename list<T>::const_iterator list<T>::erase( typename list<T>::const_iterator pos )
{

}

template <typename T>
typename list<T>::const_iterator list<T>::erase( typename list<T>::const_iterator first , typename list<T>::const_iterator last )
{

}

// >> list assign operations

template <typename T>
template <typename InItr>
void list<T>::assign( InItr first, InItr last )
{

}

template <typename T>
void list<T>::assign( std::initializer_list<T> ilist )
{

}