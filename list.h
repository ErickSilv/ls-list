

namespace ls
{

template<typename T>
	class list
	{

		using difference_type = std::ptrdiff_t;

	
	private:
		/*!	Declaration of a node struct
		 * @attribute data is a param to guard the value at a T type in the node
		 * @attribute next is a pointer to sucessor 'neighbor' node. 
		 * @attribute prev is a pointer to antecessor 'neighbor' node. 
		 */
		struct node
		{
			T data;
			node * next;
			node * prev;

			//Default constructor to a build with no arguments.
			node( const T & d_= T() , node * n_ = nullptr, node * p_ = nullptr )                 
				: data ( d_ )                 
				, next ( n_ )                 
				, prev ( p_ )             
			{ /* empty */ }



		};
	private:
		
		/*! Private attributes of a list class
		 * @attribute m_size size of the list
		 * @attribute m_head pointer to a node as had a beginning node of the list.
		 * @attribute m_tail pointer to a note as had a end node of the list.
		 */
		int m_size;
		node * m_head;
		node * m_tail;

	public:
	
		/*! Declaration of a const_iterator class
		 */
		class const_iterator
		{
				public:
					//Default constructor
					const_iterator();
					
					//Overcharging of operators to a const_iterator
					const Object & operator*() const;
					const_iterator & operator++();
					const_iterator operator++( int );
					const_iterator & operator--();
					const_iterator operator--( int );
					bool operator==( const const_iterator & rhs ) const;
					bool operator!=( const const_iterator & rhs ) const;

				protected:
					//Attribute to a node with const_iterator keep
					Node *current;
					
					//Default construct of a const_iterator. 
					const_iterator(Node * p)
						: current(p);
					friend class List<Object>;

		};

		/*! Declaration of a iterator class as a const_iterator 
		 *   instance.
		 */
		class iterator : public const_iterator
		{

			public:
				iterator()
					: const_iterator()
				{/* Empty */}
				
				//Overcharging of operators to a iterator
				const Object & operator*() const;
				Object & operator*();
				iterator * operator++();
				iterator operator++( int );
				iterator & operator--();
				iterator operator--( int );

			protected:
				//Default construct of a iterator. 
				iterator( Node * p )
					: const_iterator( p );
				friend class List< Object >;
		};

		//Constructors of a list
		list();
		list(const list &);
		list(list &&);
		
		//Desctrutor of a list.
		~list();
		
		//Overcharging of operator to a list.
		list & operator=(const list &);
		list & operator=(list &&);

		//Functions to a instanciate a iterator.
		iterator begin();
		const_iterator cbegin() const;
		iterator end();
		const_iterator cend() const;

		/*! Function to get the list size
		 * @return int size of the list
		 */
		int size() const;
		
		/*! Function who verify if the list is empty
		 *  @return true the list are empty or false if the list are not empty.
		 */
		bool empty() const;
		
		/*! Clear the element of the list except head and tail
		 */
		void clear();
		
		/*! Function to get a first element of the list.
		 *  @return a reference to a T type first element of the list.
		 */
		T & front();
		
		/*! Function to get a first element of the list.
		 *  @return a const reference to a T type first element of the list.
		 */
		const T & front() const;
		
		/*! Function to get a last element of the list.
		 *  @return a reference to a T type last element of the list.
		 */
		T & back();
		
		/*! Function to get a last element of the list.
		 *  @return a reference to a T type last element of the list.
		 */
		const T & back() const;

		/*! Function to push a element in the beginning of the list.
		 * @param value const reference to a value to be pushed.
		 */
		void push_front(const T & value);
		
		/*! Function to push a element in the ending of the list.
		 * @param value const reference to a value to be pushed.
		 */
		void push_back(const T & value);
		
		/*! Function to pop the first element in the list.
		 */
		void pop_front();
		
		/*! Function to pop the last element in the list.
		 */
		void pop_back();
		
		/*! Function to substitute all the elements of the list
		 *   to the value's copy.
		 *  @param value to be put on list
		 */
		void assign(const T & value);

		/*! Function to substitute all the elements of the list
		 *   to the value's copy in the [first, last) range.
		 *  @param first, begin of the range.
		 *  @param last,  end of the range.
		 */
		template<class InItr>
		void assign(InItr first, InItr last);
		
		/*! Function to substitute all the elements of the list
		 *   to the ilist value's copy.
		 *  @param ilist list to be used as value to insert on list.
		 */
		void assign(std::initializer_list<T> ilist);

		/*! Function to insert an element in the position before pos
		 *  @param pos, const_iterator to the node as to be used to insert a node before than.
		 *  @param value, value to be insersed on the node.
		 *  @return iterator to a insersed node.
		 */
		iterator insert(const_iterator pos, const T & value);
		
		/*! Function to insert an initializer list in the position before pos
		 *  @param pos, const_iterator to the node as to be used to insert (ilist.size()) nodes before than.
		 *  @param ilist, initializer list with the element to be inserted.
		 *  @return iterator to a last insersed node.
		 */
		iterator insert(const_iterator pos, std::initializer_list<T> ilist);
		
		/*! Function to erase an element in the position pos
		 *  @param pos, const_iterator to the node as to be erased a node.
		 *  @return iterator to a next node after the erase.
		 */
		iterator erase(const_iterator pos);
		
		/*! Function to erase an element in the position pos
		 *  @param first, const_iterator to the beginning node of the range [first, last) as to be erased a node.
		 *  @param last, const_iterator to the end of the range [first, last) to be erased.
		 *  @return iterator to a next node after the erase.
		 */
		iterator erase(const_iterator first, const_iterator last);
		
		/*! Function to erase an element in the position pos
		 *  @param value, T type value to be searched on the list.
		 *  @return const_iterator to a node finded.
		 */
		template <typename T> 
		const_iterator find(const T & value) const;



	};


}