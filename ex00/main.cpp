/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:06:03 by pde-masc          #+#    #+#             */
/*   Updated: 2025/05/22 15:06:09 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>
#include "easyfind.hpp"

int main(void)
{
	int ints[] = {1, 88, 42, INT_MIN, INT_MAX};
	// Vector
	std::cout << "-----------------------------------------" << std::endl;
	std::vector<int> vec(ints, ints + 5);
	std::vector<int>::iterator found1 = easyfind(vec, 42);
	if (found1 != vec.end())
		std::cout << "found " << *found1 << " in vector" << std::endl;
	found1 = easyfind(vec, -42);
	if (found1 == vec.end())
		std::cout << "cannot find -42 in vector" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	// Deque
	std::deque<int> dq(ints, ints + 5);
	std::deque<int>::iterator found2 = easyfind(dq, 42);
	if (found2 != dq.end())
		std::cout << "found " << *found2 << " in deque" << std::endl;
	found2 = easyfind(dq, -42);
	if (found2 == dq.end())
		std::cout << "cannot find -42 in deque" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	// List
	std::list<int> lst(ints, ints + 5);
	std::list<int>::iterator found3 = easyfind(lst, 42);
	if (found3 != lst.end())
		std::cout << "found " << *found3 << " in list" << std::endl;
	found3 = easyfind(lst, -42);
	if (found3 == lst.end())
		std::cout << "cannot find -42 in list" << std::endl;
	return (0);
}
