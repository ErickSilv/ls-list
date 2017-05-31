#include "list.h"


// ================================================================== //
// ====================== Iterators methods ========================= //

/*! The  *it operator.
 *  Supports: *it = XXXX or XXXX = *it.
 *  \return A reference to the object this iterator points to.
 */
//node_t::value_type & operator*()
typename T::value_type  & operator*()
{
    assert( m_ptr != nullptr );
    return m_ptr->data;
}

/*! The ++it operator.
 *  \return The calling object.
 */
self_type operator++()
{
    m_ptr = m_ptr->next;
    return *this;
}

/*! The it++ operator.
 *  \return The calling object.
 */
self_type operator++(int)
{
    self_type temp = *this;
    m_ptr = m_ptr->next;
    return temp;
}

/*! The --it operator.
 *  \return The calling object.
 */
self_type operator--()
{
    m_ptr = m_ptr->prev;
    return *this;
}

/*! The it-- operator.
 *  \return The calling object.
 */
self_type operator--(int)
{
    self_type temp = *this;
    m_ptr = m_ptr->prev;
    return temp;
}

/// The it == it2 operator.
bool operator==( const self_type & rhs_ ) const
{
    return m_ptr == rhs_.m_ptr;
}

/// The it != it2 operator.
bool operator!=( const self_type & rhs_ ) const
{
    return m_ptr != rhs_.m_ptr;
}

// ==================================================
/* Other methods that you might wanto to implement. */
// ==================================================

/// it += 3; // Go back  3 positions within the container. 
self_type operator+=( difference_type step_ ) ;

/// it -= 3; // Go back  3 positions within the container. 
self_type operator-=(  difference_type step_ ) ;

/// it->method()
pointer operator->( void ) const
{
    assert( m_ptr );
    return *m_ptr;
}

/// it1 - it2
difference_type operator-( const self_type & rhs_ ) const ;

// ====================== End of Iterators methods ========================= //
// ================================================================== //

list()
    : m_size( 0 )
    , m_head( new node() )
    , m_tail( new node() )
{
    m_head->next = m_tail;
    m_tail->prev = m_head;
}

// Copy constructor
list( const list & clone_ )
    : m_size( 0 )
    , m_head( new node_t() )
    , m_tail( new node_t() )
{
    // TODO: copiar os dados de clone para this.
    for ( auto it( clone_.begin() ) ; it != clone_.end() ; ++it )
        push_back( *it );
}

~list()
{
    clear();
    delete m_head;
    delete m_tail;
}


//=== Public interface
iterator begin()
{
    return iterator( m_head->next );
}

iterator end()
{
    return iterator( m_tail );
}

const_iterator cbegin() const
{
    return const_iterator( m_head->next );
}

const_iterator cend() const
{
    return const_iterator( m_tail );
}

int size( ) const
{
    return m_size;
}

bool empty ( ) const
{
    return m_size == 0;
}

void clear ( ) 
{
}

iterator insert( const_iterator pos, const T & value )
{
    node * novo ( new node ( *pos ) );

    novo->prev = pos->prev;
    novo->next = pos;

    (pos->prev)->next = novo;
    pos->prev = novo;

    return iterator ( novo );
}

iterator insert( const_iterator pos, std::initializer_list< T > ilist )
{

    auto sz = ilist.size();

    for ( auto i(0ul); i < sz; ++i )
    {
        pos_ = insert( pos_, ilist[i] );
    }

    return iterator ( pos_->prev );

}

template < typename InItr >
iterator insert( const_iterator pos, InItr first, InItr last )
{
    for ( auto it( first ); it != last; ++it )
    {
        pos = insert( pos, *it );
    }

    return iterator( pos->prev );
}


iterator erase( const_iterator pos )
{

    (pos->prev)->next = pos->next;
    (pos->next)->prev = pos->prev;

    return iterator( pos->next );


}

iterator erase( const_iterator first, const_iterator last )
{
    while ( first != last )
    {
        first = erase( first );
    }
    return iterator( last );
}




int main( void )
{
    ls::list< int > v; // Criar um vector com 10 elementos

    for( auto i(0) ; i < 10 ; ++i )
        v.push_back( i+1 );

    return 0;
}