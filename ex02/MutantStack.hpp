#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>
# include <list>
# include <deque>
# include <stack>

/*
https://en.cppreference.com/w/cpp/container/stack
std::stack has a protected object, c, which is its underlying container

std::stack is a container adaptor, meaning:
default construction will use a std::deque and set it in c OR
an existing container is passed for construction, and is copied in c

so it's not hard to make MutantStack inherit from std::stack:
default construction uses default std::stack construction,
copy construction uses std::stack copy construction. This works because
we are in the child and only need to copy the std::stack parent info.
*/
template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack(void) : std::stack<T, Container>()  {}
        MutantStack(const MutantStack &other) : std::stack<T, Container>(other) {}
        ~MutantStack(void) {}

        const MutantStack  &operator=(const MutantStack &other)
        {
            if (this != &other)
                std::stack<T, Container>::operator=(other);
            return (*this);
        }
        // iterators
        typedef typename Container::iterator iterator;
        typedef typename Container::reverse_iterator reverse_iterator;

        iterator begin(void)
        {
            return (this->c.begin());
        }
        iterator end(void)
        {
            return (this->c.end());
        }
        reverse_iterator rbegin(void)
        {
            return (this->c.rbegin());
        }
        reverse_iterator rend(void)
        {
            return (this->c.rend());
        }
};

#endif