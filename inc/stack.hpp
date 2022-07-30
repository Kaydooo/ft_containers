#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"


namespace   ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {   
        public:
        typedef Container   container_type;
        typedef typename    Container::value_type       value_type;
        typedef typename    Container::size_type        size_type;
        typedef typename    Container::reference        reference;
        typedef typename    Container::const_reference  const_reference;

        explicit stack( const Container& cont = Container() ): c(cont){}
        stack( const stack& other ): c(other.c) {}
        stack& operator=( const stack& other )
        {
            if(this != &other)
                c = other.c;
            return *this;
        }
        ~stack(){}

        reference top(){ return c.back(); }
        const_reference top() const{ return c.back(); }
        bool empty() const{ return c.empty(); }
        size_type size() const{ return c.size(); }
        void push( const value_type& value ){ c.push_back(value); }
        void pop(){ c.pop_back(); }

    template< class U, class Cont >
    friend bool operator==( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

    template< class U, class Cont >
    friend bool operator!=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

    template< class U, class Cont >
    friend bool operator<( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

    template< class U, class Cont >
    friend bool operator<=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

    template< class U, class Cont >
    friend bool operator>( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

    template< class U, class Cont >
    friend bool operator>=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs );

        protected:
        container_type  c;
    };

    template< class U, class Cont >
    bool operator==( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs )
    {return lhs.c == rhs.c;}

    template< class U, class Cont >
    bool operator!=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs )
    {return lhs.c != rhs.c;}

    template< class U, class Cont >
    bool operator<( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs )
    {return lhs.c < rhs.c;}

    template< class U, class Cont >
    bool operator<=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs )
    {return lhs.c <= rhs.c;}

    template< class U, class Cont >
    bool operator>( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs )
    {return lhs.c > rhs.c;}

    template< class U, class Cont >
    bool operator>=( const ft::stack<U,Cont>& lhs, const ft::stack<U,Cont>& rhs )
    {return lhs.c >= rhs.c;}

}//end of namespace ft


#endif