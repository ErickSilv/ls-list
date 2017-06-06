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

		private:
			/*!	@brief Declaration of a node struct
			 *
			 * @attribute data is a param to guard the value at a T type in the node
			 * @attribute next is a pointer to sucessor 'neighbor' node. 
			 * @attribute prev is a pointer to antecessor 'neighbor' node. 
			 *
			 */
			struct Node
			{
				T data;
				Node *prev;
				Node *next;

				// Default constructor without arguments
				Node( const T & d_ = T() , Node * p_ = nullptr , Node * n_ = nullptr) 
				    : data ( d_ ) , prev ( p_ ) , next ( n_ ) { /* Empty */ };

			};

		public:
			/*! Declaration of a const_iterator class
		 	*/
			class const_iterator
			{
				protected:
					Node *current;
					friend class list<T>;

				public:
					const_iterator();
					const_iterator( Node * p_ ) : current( p_ ) { /* Empty */ };

					const T & operator*() const;
					const_iterator & operator++();    // ++it;
					const_iterator operator++( int ); // it++;
					const_iterator & operator--();    // --it;
					const_iterator operator--( int ); // it--;

					bool operator== ( const const_iterator & rhs ) const;
					bool operator!= ( const const_iterator & rhs ) const;
			};

			/*! Declaration of a iterator class as a const_iterator instance.
		 	*/
			class iterator : public const_iterator
			{
				protected:
					friend class list<T>;

				public:
					iterator( ) : const_iterator() { /* Empty */ }
					iterator( Node *p_ ) : const_iterator( p_ ) { /* Empty */ };

					T & operator*();
					iterator & operator++();    // ++it;
					iterator operator++( int ); // it++;
					iterator & operator--();    // --it;
					iterator operator--( int ); // it--;

					bool operator== ( iterator & rhs ) const;
					bool operator!= ( iterator & rhs ) const;
			};

		/*! @brief Private attributes of a list class
		 *
		 * @attribute m_size size of the list
		 * @attribute m_head pointer to a node as had a beginning node of the list.
		 * @attribute m_tail pointer to a note as had a end node of the list.
		 *
		 */
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

			//Destructor
			~list();

			//Overcharging
			list& operator=( const list& other );
			list& operator=( std::initializer_list<T> ilist );

			/*! @brief Function to get the list size
			 *
			 * @return int size of the list
			 *
			 */
			size_type size() const;

			/*! @brief Clear all the element of the list except head and tail
		 	 *
		 	 */
			void clear();

			/*! @brief Function who verify if the list is empty
			 *
			 *  @return true the list are empty or false if the list are not empty.
			 *
			 */
			bool empty();


			/*! @brief Function to push a element in the beginning of the list.
			 *
			 * @param value const reference to a value to be pushed.
			 *
			 */
			void push_front(const T & value);
			
			/*! @brief Function to push a element in the ending of the list.
			 *
			 * @param value const reference to a value to be pushed.
			 *
			 */
			void push_back(const T & value);
			
			/*! @brief Function to pop the first element in the list.
			 *
			 */
			void pop_front();
			
			/*! @brief Function to pop the last element in the list.
			 *
			 */
			void pop_back();
			
			
			/*! @brief Function to get a first element of the list.
			 *
			 *  @return a reference to a T type first element of the list.
			 *
			 */
			T & front();
			
			/*! @brief Function to get a first element of the list.
			 *
			 *  @return a const reference to a T type first element of the list.
			 *
			 */
			const T & front() const;
			
			/*! @brief Function to get a last element of the list.
			 *
			 *  @return a reference to a T type last element of the list.
			 *
			 */
			T & back();
			
			/*! @brief Function to get a last element of the list.
			 *
			 *  @return a reference to a T type last element of the list.
			 *
			 */
			const T & back() const;

			/*! @brief Function to substitute all the elements of the list
			 *   to the value's copy.
			 *
			 *  @param value to be put on list
			 *
			 */
			void assign( const T & value );

			// Comparison Operators
			// :: ONLY DEFINED OUTSIDE THE CLASS ::
			// bool operator==( const ls::list<T> & lhs, const ls::list<T> & rhs );
			// bool operator!=( const ls::list<T> & lhs, const ls::list<T> & rhs );

			// Iterator Related Operations

			/*! @brief Function to get a iterator to first element of the list.
			 *
			 *  @return a iterator to the first element of the list.
			 *
			 */
			iterator begin();

			/*! @brief Function to get a const_iterator to first element of the list.
			 *
			 *  @return a const_iterator to the first element of the list.
			 *
			 */
			const_iterator cbegin() const;

			/*! @brief Function to get a iterator to a tail of the list.
			 *
			 *  @return a iterator to the tail of the list.
			 *
			 */
			iterator end();

			/*! @brief Function to get a const_iterator to a tail of the list.
			 *
			 *  @return a const_iterator to the tail of the list.
			 *
			 */
			const_iterator cend() const;

			/*! @brief Insert a node in a list before 'pos' with m_data = value.
			 *
			 *  @param pos iterator to position after who a node to be inserted.
			 *  @param value = m_data
			 *
			 *  @return iterator to a node inserted.
			 */
			iterator insert( iterator pos , const T & value );

			/*! @brief Insert 'n' ( n is a number of values in range [first, last) ) nodes in a list before 'pos' with m_data = value.
			 *
			 *  @param pos iterator to position after who a node to be inserted.
			 *  @param first begin of the range
			 *	@param last  end of the range
			 *
			 *  @return iterator to a last node inserted.
			 */
			template <typename InItr>
			iterator insert( iterator pos , InItr first , InItr last );

			/*! @brief Insert 'n' ( n is a number of size the initilizer list ) nodes in a list before 'pos' with m_data = ilist[ i ].
			 *
			 *  @param pos iterator to position after who the nodes to be inserted.
			 *  @param ilist initializer list with values to be inserted
			 *
			 *  @return iterator to a last node inserted.
			 */
			iterator insert( iterator pos , std::initializer_list<T> ilist );
			
			/*! @brief Erase the value of iterator pos
			 *
			 *  @param pos iterator to position after who a node to be erased.
			 *
			 *  @return iterator to a next node after the erased.
			 */
			iterator erase( iterator pos );

			/*! @brief Erase the value of iterator pos
			 *
			 *  @param first iterator to beginning of range to be erased.
			 *  @param last iterator ending of range to be erased.
			 *
			 *  @return iterator to a next node after the erased.
			 */
			iterator erase( iterator first , iterator last );

			// Const-iterator Insertion Operations
			const_iterator insert( const_iterator pos , const T & value );
			template <typename InItr>
			const_iterator insert( const_iterator pos , InItr first , InItr last );
			const_iterator insert( const_iterator pos , std::initializer_list<T> ilist );
			
			const_iterator erase( const_iterator pos );
			const_iterator erase( const_iterator first , const_iterator last );

			/*! @brief Function to substitute all the elements of the list
			 *   to the value's copy in the [first, last) range.
			 *
			 *  @param first, begin of the range.
			 *  @param last,  end of the range.
			 *
			 */
			template <typename InItr>
			void assign( InItr first, InItr last );

			/*! @brief Function to substitute all the elements of the list
			 *   to the ilist value's copy.
			 *
			 *  @param ilist list to be used as value to insert on list.
			 *
			 */
			void assign( std::initializer_list<T> ilist );

	};	

}

#include "list.inl"

#endif