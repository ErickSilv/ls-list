/* Linguagens de Programação 2017.1
 * Autorship: Daniel Barbosa and Erick Silva
 * 
 * Implementation of the List ADT using doubly linked list
*/

#ifndef _LIST_H_
#define _LIST_H_

namespace ls
{
	template <typename T>
	class list
	{
		// Basic definitions
		using size_type = std::size_t;

		// Node type definition
		private:
			struct Node
			{
				T data;      // Data field
				Node *prev;  // Pointer to the previous node on the list
				Node *next;  // Pointer to the next node on the list

				// Basic constructor
				Node( const T & d = T() , Node * p = nullptr , Node * n = nullptr) 
				    : data ( d ) , prev ( p ) , next ( n ) { /* Empty */ };

			};

		// Iterator and ConstIterator definitions
		public:
			class const_iterator
			{
				protected:
					Node *current;
					friend class list<T>;

				public:
					const_iterator();
					const_iterator( Node * p ) : current( p ) { /* Empty */ };

					const T & operator*() const;
					const_iterator & operator++();    // ++it;
					const_iterator operator++( int ); // it++;
					const_iterator & operator--();    // --it;
					const_iterator operator--( int ); // it--;

					bool operator== ( const const_iterator & rhs ) const;
					bool operator!= ( const const_iterator & rhs ) const;
			};

			class iterator : public const_iterator
			{
				protected:
					friend class list<T>;

				public:
					iterator( ) : const_iterator() { /* Empty */ }
					iterator( Node *p ) : const_iterator( p ) { /* Empty */ };

					T & operator*();
					iterator & operator++();    // ++it;
					iterator operator++( int ); // it++;
					iterator & operator--();    // --it;
					iterator operator--( int ); // it--;

					bool operator== ( iterator & rhs ) const;
					bool operator!= ( iterator & rhs ) const;
			};

		// Private atributes
		private:
			size_type m_size;
			Node *m_head;
			Node *m_tail;

		// Public functions
		public:
			// Constructors
			list();
			explicit list( size_type count );
			template < typename InputIt >
			list( InputIt first , InputIt last );
			list( const list & other );
			list( std::initializer_list<T> ilist );
			~list();
			list& operator=( const list& other );
			list& operator=( std::initializer_list<T> ilist );

			// Methods
			size_type size() const;
			void clear();
			bool empty();
			void push_front( const T & value );
			void push_back( const T & value );
			void pop_front();
			void pop_back();
			const T & front() const;
			const T & back() const;
			void assign( const T & value );

			// Comparison Operators
			// :: ONLY DEFINED OUTSIDE THE CLASS ::
			// bool operator==( const ls::list<T> & lhs, const ls::list<T> & rhs );
			// bool operator!=( const ls::list<T> & lhs, const ls::list<T> & rhs );

			// Iterator Related Operations
			iterator begin();
			const_iterator cbegin() const;
			iterator end();
			const_iterator cend() const;

			// Iterator Insertion Operations
			iterator insert( iterator pos , const T & value );
			template <typename InItr>
			iterator insert( iterator pos , InItr first , InItr last );
			iterator insert( iterator pos , std::initializer_list<T> ilist );
			iterator erase( iterator pos );
			iterator erase( iterator first , iterator last );

			// Const-iterator Insertion Operations
			const_iterator insert( const_iterator pos , const T & value );
			template <typename InItr>
			const_iterator insert( const_iterator pos , InItr first , InItr last );
			const_iterator insert( const_iterator pos , std::initializer_list<T> ilist );
			const_iterator erase( const_iterator pos );
			const_iterator erase( const_iterator first , const_iterator last );

			// Assign Operations
			template <typename InItr>
			void assign( InItr first, InItr last );
			void assign( std::initializer_list<T> ilist );

			
	};	

}

#include "list.inl"

#endif