/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:05:16 by pde-masc          #+#    #+#             */
/*   Updated: 2025/05/22 15:05:17 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	// subject test
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "----- outputs should be the same" << std::endl;
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);
	std::list<int>::iterator it2 = lst.begin();
	std::list<int>::iterator ite2 = lst.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::stack<int, std::list<int> > s2(lst);
	std::cout << "---------------------------------" << std::endl;

	// additional tests
	MutantStack<int> mstack2;
	for (int i = 1; i <= 42; ++i)
		mstack2.push(i);
	MutantStack<int>::reverse_iterator it3 = mstack2.rbegin();
	MutantStack<int>::reverse_iterator ite3 = mstack2.rend();
	while (it3 != ite3)
	{
		std::cout << *it3 << std::endl;
		++it3;
	}
	std::stack<int> s3(mstack2);
	
	std::cout << "----- outputs should be the same" << std::endl;
	std::deque<int> dq;
	for (int i = 1; i <= 42; ++i)
		dq.push_back(i);
	std::deque<int>::reverse_iterator it4 = dq.rbegin();
	std::deque<int>::reverse_iterator ite4 = dq.rend();
	while (it4 != ite4)
	{
		std::cout << *it4 << std::endl;
		++it4;
	}
	std::stack<int, std::deque<int> > s4(dq);
	return (0);
}
