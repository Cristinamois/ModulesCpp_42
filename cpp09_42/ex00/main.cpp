#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    btc<std::map<std::string, double> > *first;
    first = new btc<std::map<std::string, double> >;


    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        exit (0);
    }
    first->readCSV();
    first->readInput(av[1]);

    delete first;

    return (0);
}