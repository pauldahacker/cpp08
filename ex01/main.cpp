#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "---------------------" << std::endl;
    int toAdd[] = {0, -2, 1243, 88, 42, 69, 11, 6, 2003, 2000};
    Span sp1 = Span(10);
    sp1.addMultiple(toAdd, toAdd + 9);
    sp1.printContent();
    // adding this would go over N = 10
    try
    {
        sp1.addMultiple(toAdd + 4, toAdd + 8);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    sp1.addNumber(42424242);
    sp1.printContent();
    try
    {
        sp1.addNumber(42424242);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}