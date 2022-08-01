#ifndef CONTAINER_UTILS
#define CONTAINER_UTILS

#include <cstddef>

#define RED_COLOR "\033[0;31m"
#define CYAN_COLOR "\033[0;36m"
#define RESET "\033[0m"


namespace ft
{
    /* Iterator Categaorie Tags */
    struct input_iterator_tag{};
    struct output_iterator_tag{};
    struct forward_iterator_tag: public input_iterator_tag{};
    struct bidirectional_iterator_tag: public forward_iterator_tag{};
    struct random_access_iterator_tag: public bidirectional_iterator_tag{};


    template<class it>
    struct iterator_traits {
        
        public :
            typedef typename it::iterator_category	iterator_category;
            typedef typename it::value_type		    value_type;	
            typedef typename it::difference_type	difference_type;	
            typedef typename it::pointer		    pointer;	
            typedef typename it::reference		    reference;	

    };

    template<typename Tp>
    struct iterator_traits<Tp*> {

        public :
            typedef random_access_iterator_tag	iterator_category;	
            typedef Tp		                    value_type;	
            typedef std::ptrdiff_t		        difference_type;	
            typedef Tp*		                    pointer;	
            typedef Tp&		                    reference;
    };


    template<typename Tp>
    struct iterator_traits<const Tp*> {
        public :
            typedef random_access_iterator_tag	iterator_category;	
            typedef Tp		                    value_type;	
            typedef std::ptrdiff_t		        difference_type;	
            typedef const Tp*		            pointer;	
            typedef const Tp&		            reference;
    };

    struct false_type { static const bool value = false;};
    struct true_type { static const bool value = true;};

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };
    
    template <class T>   struct is_integral                     : public ft::false_type {};
    template <>          struct is_integral<bool>               : public ft::true_type {};
    template <>          struct is_integral<char>               : public ft::true_type {};
    template <>          struct is_integral<signed char>        : public ft::true_type {};
    template <>          struct is_integral<unsigned char>      : public ft::true_type {};
    template <>          struct is_integral<wchar_t>            : public ft::true_type {};
    template <>          struct is_integral<short>              : public ft::true_type {};
    template <>          struct is_integral<unsigned short>     : public ft::true_type {};
    template <>          struct is_integral<int>                : public ft::true_type {};
    template <>          struct is_integral<unsigned int>       : public ft::true_type {};
    template <>          struct is_integral<long>               : public ft::true_type {};
    template <>          struct is_integral<unsigned long>      : public ft::true_type {};
    template <>          struct is_integral<long long>          : public ft::true_type {};
    template <>          struct is_integral<unsigned long long> : public ft::true_type {};


    enum color_t { BLACK, RED };
    template<class T>
    class RedBlackTree_Node 
    {
        public:
        RedBlackTree_Node* parent;
        RedBlackTree_Node* child[2];
        enum color_t color;
        T data;

        RedBlackTree_Node(): parent(NULL), data(T()){}
        RedBlackTree_Node(T value): parent(NULL), data(value){}
    };

    /* pair + make_pair */

    	template <class T1, class T2>
		struct pair 
        {
			typedef T1		first_type;
			typedef T2		second_type;

			first_type	first;
			second_type	second;

			pair() : first(), second() {}	

			template <class U, class V>
			pair(const pair<U, V>& other) : first(other.first), second(other.second) {}

			pair(const first_type& a, const second_type& b) : first(a), second(b) {}

			pair& operator=(const pair& other) 
            {
                if (this != &other)
                {    
				    this->first = other.first;
				    this->second = other.second;
                }
				return (*this);
			}

		};

		template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return lhs.first==rhs.first && lhs.second==rhs.second; }

		template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return !(lhs==rhs); }

		template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

		template <class T1, class T2>	
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return !(rhs<lhs); }

		template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return rhs<lhs; }

		template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
			{ return !(lhs<rhs); }


		template <class T1, class T2>
        ft::pair<T1, T2> make_pair(T1 a, T2 b)
        {
            return (ft::pair<T1, T2>(a, b));
        }

    /* ft::distance --> find the differnce between 2 iterators
    only by using the ++ operator and != so this function will work with both bidirectional and radoom iterators */
    template<class InputIterator>
    size_t distance(InputIterator first, InputIterator last)
    {
        size_t i = 0;
        while (first != last)
        {
            i++;
            first++;
        }	
        return (i);
    }

    template <class iterator_one, class iterator_two>
    bool	equal(iterator_one first1, iterator_one last1, iterator_two first2)
    {
        while (first1 != last1)
        {
            if (*first1 != *first2)
                return false;
            ++first1; ++first2;
        }
        return true;
    }

    
    template<class InputIt1, class InputIt2>
    bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                                InputIt2 first2, InputIt2 last2)
    {
        for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
            if (*first1 < *first2) return true;
            if (*first2 < *first1) return false;
        }
        return (first1 == last1) && (first2 != last2);
    }
} // namespace ft

#endif