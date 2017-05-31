

namespace ls
{

template<typename T>
	class list
	{

		using difference_type = std::ptrdiff_t;

	private:
		struct node
		{
			T data;
			node * next;
			node * prev;


			node( const T & d_= T() , node * n_ = nullptr, node * p_ = nullptr )                 
				: data ( d_ )                 
				, next ( n_ )                 
				, prev ( p_ )             
			{ /* empty */ }



		};
	private:
		
		int m_size;
		node * m_head;
		node * m_tail;

	public:

		class const_iterator
		{

				public:
					const_iterator();
					const Object & operator*() const;
					const_iterator & operator++();
					const_iterator operator++( int );
					const_iterator & operator--();
					const_iterator operator--( int );
					bool operator==( const const_iterator & rhs ) const;
					bool operator!=( const const_iterator & rhs ) const;

				protected:
					Node *current;
					const_iterator(Node * p)
						: current(p);
					friend class List<Object>;

		};

		class iterator : public const_iterator
		{

			public:
				iterator()
					: const_iterator()
				{/* Empty */}
				const Object & operator*() const;
				Object & operator*();

				iterator * operator++();
				iterator operator++( int );
				iterator & operator--();
				iterator operator--( int );

			protected:
				iterator( Node * p )
					: const_iterator( p );
				friend class List< Object >;
		};

		list();
		~list();
		list(const list &);
		list(list &&);
		list & operator=(const list &);
		list & operator=(list &&);

		iterator begin();
		const_iterator cbegin() const;
		iterator end();
		const_iterator cend() const;

		int size() const;
		bool empty() const;
		void clear();
		T & front();
		const T & front() const;
		T & back();
		const T & back() const;

		void push_front(const T & value);
		void push_back(const T & value);
		void pop_front();
		void pop_back();
		void assign(const T & value);

		template<class InItr>
		void assign(InItr first, InItr last);
		void assign(std::initializer_list<T> ilist);

		iterator insert(const_iterator itr, const T & value);
		iterator insert(const_iterator pos, std::initializer_list<T> ilist);
		iterator erase(const_iterator itr);
		iterator erase(const_iterator first, const_iterator last);
		const_iterator find(const T & value) const;



	};


}