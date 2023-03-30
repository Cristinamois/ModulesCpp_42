
// #include "RPN.hpp"
#include "RPN.hpp"
#include <limits.h>

// void    applyMath(RPN *rpn, char operation)
// {
//     if (operation == '+')
// }


int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error." << std::endl;
    }

    NRPN<std::stack<int> > first;
    // first = new NRPN<std::stack<int> >;

    first.Job(av[1]);
    // std::cout  << "tab : ";
    // std::cout << "SHOWs" << std::endl;
    first.showTab();
    // std::cout << "SHOWs" << std::endl;

    // delete first;

}