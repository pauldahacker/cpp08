/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:05:48 by pde-masc          #+#    #+#             */
/*   Updated: 2025/05/22 15:05:49 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &other) : _N(other._N), content(other.content)
{
}

Span::~Span(void)
{
	content.clear();
}

const Span  &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->content = other.content;
	}
	return (*this);
}

void	Span::addNumber(int num)
{
	if (content.size() == _N)
		throw (std::out_of_range("Can't add more numbers to Span!"));
	content.push_back(num);
}
unsigned int	Span::shortestSpan(void)
{
	if (content.size() <= 1)
		throw (std::out_of_range("Span should contain 2 or more elements!"));
	std::vector<int> sorted = content;
	std::sort(sorted.begin(), sorted.end());
	unsigned int	tmpSpan;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		if (i == 1 || static_cast<unsigned int>(sorted[i] - sorted[i - 1]) < tmpSpan)
			tmpSpan = sorted[i] - sorted[i - 1];
	}
	return (tmpSpan);
}

unsigned int	Span::longestSpan(void)
{
	if (content.size() <= 1)
		throw (std::out_of_range("Span should contain 2 or more elements!"));
	std::vector<int> sorted = content;
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

void	Span::addMultiple(int *first, int *last)
{
	int nToAdd = std::distance(first, last);
	if (nToAdd < 0)
		throw (std::invalid_argument("Iterator range incorrect!"));
	if (content.size() + nToAdd > _N)
		throw (std::out_of_range("Can't add that many numbers to Span!"));
	content.insert(content.end(), first, last);
}

void	Span::printContent(void)
{
	std::cout << "Span has " << content.size() << " out of "
		<< _N << " capacity and contains:" << std::endl;
	for (size_t i = 0; i < content.size(); ++i)
		std::cout << "[" << content[i] << "] ";
	std::cout << std::endl;
}
