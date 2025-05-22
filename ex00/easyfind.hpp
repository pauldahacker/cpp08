#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
/*
only these sequence containers are defined in c++98
https://cplusplus.com/reference/stl/
*/
# include <vector>
# include <deque>
# include <list>

/*
help:
https://cplusplus.com/reference/algorithm/find/
*/
template<typename T>
typename T::iterator easyfind(T &intContainer, const int val)
{
    typename T::iterator first = intContainer.begin();
    typename T::iterator last = intContainer.end();

    return (std::find(first, last, val));
}

#endif