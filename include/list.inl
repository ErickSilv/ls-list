/* Linguagens de Programação 2017.1
 * Autorship: Daniel Barbosa and Erick Silva
 * 
 * Implementation of the List ADT using doubly linked list
*/

#include <cassert>
#include <stdexcept>

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
    // Verifica se o ponteiro é nulo
    assert(const_iterator::current != nullptr);

    // Caso não seja nulo, retorna o campo DATA do nó apontado pelo const_iterator
    return const_iterator::current->data;
}

// Operator++ (++iterator)
template <typename T>
typename list<T>::iterator & list<T>::iterator::operator++()
{
    const_iterator::current = const_iterator::current->next;
	return *this;
}

// Operator++ (iterator++)
template <typename T>
typename list<T>::iterator list<T>::iterator::operator++( int )
{
    auto temp = *this;
	const_iterator::current = const_iterator::current->next;
	return temp;
}

// Operator-- (--iterator)
template <typename T>
typename list<T>::iterator & list<T>::iterator::operator--()
{
    const_iterator::current = const_iterator::current->prev;
	return *this;
}

// Operator-- (iterator--)
template <typename T>
typename list<T>::iterator list<T>::iterator::operator--( int )
{
    auto temp = *this;
	const_iterator::current = const_iterator::current->prev;
	return temp;
}

// Operator==
template <typename T>
bool list<T>::iterator::operator== ( iterator & rhs ) const
{
    return (const_iterator::current == rhs.current);
}

// Operator!=
template <typename T>
bool list<T>::iterator::operator!= ( iterator & rhs ) const
{
    return (const_iterator::current != rhs.current);
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
    for ( /* EMPTY */ ; first != last ; first++ )
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
    for ( /* EMPTY */ ; first != last ; first++ )
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
    for ( /* EMPTY */ ; first != last ; first++ )
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
    for ( /* EMPTY */ ; first != last ; first++ )
        push_back( *first );
}

template <typename T>
list<T> & list<T>::list::operator=( std::initializer_list<T> ilist )
{
    clear();

    auto first( ilist.begin() );
    auto last ( ilist.end()   );

    // Preenche a lista com o conteúdo de ilist
    for ( /* EMPTY */ ; first != last ; first++ )
        push_back( *first );
}

// >> list methods
template <typename T>
typename list<T>::size_type list<T>::size() const
{
    return m_size;
}

template <typename T>
void list<T>::clear()
{
    // Percorrer a lista removendo seus nós
    auto first( begin() );
    auto last ( end() );

    for ( /* EMPTY */ ; first != last ; first++)
        erase( first );
}

template <typename T>
bool list<T>::empty()
{
    return (m_head->next == m_tail && m_tail->prev == m_head && m_size == 0);
}

template <typename T>
void list<T>::push_front( const T & value )
{
    // Cria um novo nó
    Node * n_node = new Node(value, m_head, m_head->next);

    // Atualiza os apontadores da lista
    m_head->next->prev = n_node;
	m_head->next = n_node;

    // Atualiza o tamanho da lista
    m_size++;
}

template <typename T>
void list<T>::push_back( const T & value )
{
    // Cria um novo nó
    Node * n_node = new Node(value, m_tail->prev, m_tail);

    // Atualiza os apontadores da lista
    m_tail->prev->next = n_node;
	m_tail->prev = n_node;

    // Atualiza o tamanho da lista
    m_size++;
}

template <typename T>
void list<T>::pop_front()
{
    erase( begin() );
}

template <typename T>
void list<T>::pop_back()
{
    auto last ( m_tail->prev );
    erase( const_iterator( last ) );
}

template <typename T>
T & list<T>::front()
{
    return (m_head->next)->data;
}

template <typename T>
T & list<T>::back()
{
    return (m_tail->prev)->data;
}

template <typename T>
const T & list<T>::front() const
{
    return (m_head->next)->data;
}

template <typename T>
const T & list<T>::back() const
{
    return (m_tail->prev)->data;
}

template <typename T>
void list<T>::assign( const T & value )
{
    // Percorrer a lista removendo seus nós
    auto first( begin() );
    auto last ( end() );

    for ( /* EMPTY */ ; first != last ; first++)
        *first = value;
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
    return list<T>::iterator(m_head->next);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const
{
    return list<T>::const_iterator(m_head->next);
}

template <typename T>
typename list<T>::iterator list<T>::end()
{
    return list<T>::iterator(m_tail);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const
{
    return list<T>::const_iterator(m_tail);
}

// >> list iterator insertion operations
template <typename T>
typename list<T>::iterator list<T>::insert( typename list<T>::iterator pos , const T & value )
{
    // Cria um novo nó a ser inserido
    Node * n_node = new Node(value, pos.current->prev, pos.current);

    // Atualiza as referências da lista para incluirem o novo nó
    (pos.current->prev)->next = n_node;
    pos.current->prev = n_node;

    // Atualiza o tamanho da lista
    m_size++;

    return list<T>::iterator(n_node);
}

template <typename T>
template <typename InItr>
typename list<T>::iterator list<T>::insert( typename list<T>::iterator pos , InItr first , InItr last )
{
    // Insere todos os elementos do intervalo na lista
    for ( /* EMPTY */ ; first != last ; first++)
        insert( pos, *first );

    return pos;
}

template <typename T>
typename list<T>::iterator list<T>::insert( list<T>::iterator pos , std::initializer_list<T> ilist )
{
    for(const auto &e : ilist)
		insert(pos, e);

    return list<T>::iterator(pos.current);
}

template <typename T>
typename list<T>::iterator list<T>::erase( typename list<T>::iterator pos )
{
    // Verifica se a lista está vazia
    if(empty())
		throw std::out_of_range("[erase()] The list is empty.");

	auto after(pos.current->next );

    // Remove o nó da lista
    // :: Atualiza PREV e NEXT dos nós seguinte e anterior, respectivamente ::
	after->prev = pos.current->prev;
	pos.current->prev->next = after;

    // Apaga o nó (já removido da lista)
	delete pos.current;

    // Atualiza o tamanho da lista
	m_size--;

    // Retorna um iterator para o elemento seguinte a POS original
	return list<T>::iterator(after);
}

template <typename T>
typename list<T>::iterator list<T>::erase( typename list<T>::iterator first , typename list<T>::iterator last )
{
    // Verifica se a lista está vazia
    if(empty())
		throw std::out_of_range("[erase()] The list is empty.");

    // Remove os elementos do intervalo
    for ( /* EMPTY */ ; first != last ; first++ )
        erase( first.current->next );

    return last;
}

// >> list const-iterator insertion operations

// :: COMO REALIZAR ALTERAÇÕES EM UM ITERADOR CONSTANTE?? ::
template <typename T>
typename list<T>::const_iterator list<T>::insert( typename list<T>::const_iterator pos , const T & value )
{
    // :: SOLVE THIS ::
}

// :: COMO REALIZAR ALTERAÇÕES EM UM ITERADOR CONSTANTE?? ::
template <typename T>
template <typename InItr>
typename list<T>::const_iterator list<T>::insert( typename list<T>::const_iterator pos , InItr first , InItr last )
{
    // :: SOLVE THIS ::
}

// :: COMO REALIZAR ALTERAÇÕES EM UM ITERADOR CONSTANTE?? ::
template <typename T>
typename list<T>::const_iterator list<T>::insert( typename list<T>::const_iterator pos , std::initializer_list<T> ilist )
{
    // :: SOLVE THIS ::
}

template <typename T>
typename list<T>::const_iterator list<T>::erase( typename list<T>::const_iterator pos )
{
    // Verifica se a lista está vazia
    if(empty())
		throw std::out_of_range("[erase()] The list is empty.");

	auto after( pos.current->next );

    // Remove o nó da lista
    // :: Atualiza PREV e NEXT dos nós seguinte e anterior, respectivamente ::
	after->prev = pos.current->prev;
	pos.current->prev->next = after;

    // Apaga o nó (já removido da lista)
	delete pos.current;

    // Atualiza o tamanho da lista
	m_size--;

    // Retorna um iterator para o elemento seguinte a POS original
	return list<T>::const_iterator(after);
}

template <typename T>
typename list<T>::const_iterator list<T>::erase( typename list<T>::const_iterator first , typename list<T>::const_iterator last )
{
    // Verifica se a lista está vazia
    if(empty())
		throw std::out_of_range("[erase()] The list is empty.");

    // Remove os elementos do intervalo
    for ( /* EMPTY */ ; first != last ; first++ )
        erase( first.current->next );

    return last;
}

// >> list assign operations

template <typename T>
template <typename InItr>
void list<T>::assign( InItr first, InItr last )
{
    // Remove todos os elementos da lista
    clear();

    // Insere todos os elementos do intervalo first-last
    for ( /* EMPTY */ ; first != last ; first++ )
        push_back( *first );
}

template <typename T>
void list<T>::assign( std::initializer_list<T> ilist )
{
    // Remove todos os elementos da lista
    clear();

    // Insere todos os elementos de ilist
    for(const auto &e : ilist)
        push_back( e );
}