#include <vector>
#include <customIterator.hpp>
#include <memory>


namespace ft
{
    /* My Iterator Class */
    template<class vector>
    class   Iterator:
    {
        public:
            using value_type = vector::value_type;
            using pointer_type = vector::pointer;
            using reference_type = vector::reference;
        private:
            pointer_type    itPtr;
    };


    /* My Vector Class */
    template<class Type>
    class vector
    {
        public:
        //Typedefs for shorter and more readable code.
            typedef std::allocator<Type>            allocator;
            typedef Iterator<Type>                  iterator;
            typedef Iterator<const Type>            const_iterator;
            typedef allocator::value_type           value_type;
            typedef allocator::size_type            size_type;
            typedef allocator::difference_type      difference_type;
            typedef allocator::pointer              pointer;
            typedef allocator::const_pointer        const_pointer;
            typedef allocator::reference            reference;
            typedef allocator::const_reference      const_reference;

        private:
            pointer     vectorData;
            size_type   vectorSize;
            size_type   vectorCapacity;



    };


}