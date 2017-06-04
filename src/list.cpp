/* Linguagens de Programação 2017.1
 * Autorship: Daniel Barbosa and Erick Silva
 * 
 * Implementation of the List ADT using doubly linked list
*/

#include <iostream>

#include "list.h"

using namespace ls;

// =========== CONST_ITERATOR THINGS ===========

// >> const_iterator operators
// Operator* (*const_iterator)
template <typename T>
const T & list<T>::const_iterator::operator*() const
{
    
}

// Operator++ (++const_iterator)
template <typename T>
typename list<T>::const_iterator & ls::list<T>::const_iterator::operator++()
{
    
}

// Operator++ (const_iterator++)
template <typename T>
typename list<T>::const_iterator ls::list<T>::const_iterator::operator++( int )
{
    
}

// Operator-- (--const_iterator)
template <typename T>
typename list<T>::const_iterator & ls::list<T>::const_iterator::operator--()
{
    
}

// Operator-- (const_iterator--)
template <typename T>
typename list<T>::const_iterator ls::list<T>::const_iterator::operator--( int )
{
    
}

// Operator==
template <typename T>
bool list<T>::const_iterator::operator== ( const const_iterator & rhs ) const
{
    // STUB IMPLEMENTATION
    return true;
}

// Operator!=
template <typename T>
bool list<T>::const_iterator::operator!= ( const const_iterator & rhs ) const
{
    // STUB IMPLEMENTATION
    return true;
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
    // STUB IMPLEMENTATION
    return true;
}

// Operator!=
template <typename T>
bool list<T>::iterator::operator!= ( iterator & rhs ) const
{
    // STUB IMPLEMENTATION
    return true;
}

// =========== LIST THINGS ===========

// >> list constructors
template <typename T>
list<T>::list()
{

}

template <typename T>
list<T>::list( typename list<T>::size_type count )
{

}

template <typename T>
template <typename InputIt>
list<T>::list( InputIt first , InputIt last )
{

}

template <typename T>
list<T>::list( const list & other )
{

}

template <typename T>
list<T>::list( std::initializer_list<T> ilist )
{

}

template <typename T>
list<T>::~list()
{

}

template <typename T>
list<T> & list<T>::list::operator=( const list& other )
{

}

template <typename T>
list<T> & list<T>::list::operator=( std::initializer_list<T> ilist )
{

}