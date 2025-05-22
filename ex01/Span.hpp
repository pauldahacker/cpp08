/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:05:55 by pde-masc          #+#    #+#             */
/*   Updated: 2025/05/22 15:05:56 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <vector>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &other);
		~Span(void);

		const Span  &operator=(const Span &other);
	
		// member functions
		void			addNumber(int num);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			addMultiple(int *first, int *last);
		// to print for tests
		void			printContent(void);
	private:
		unsigned int		_N;
		std::vector<int>	content;
};
	
#endif
