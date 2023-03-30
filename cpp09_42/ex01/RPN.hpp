#ifndef NEWRPN_HPP
#define NEWRPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdlib.h>
#include <unistd.h>
#include <cstring>
#include <stdexcept>

template<class T>
class NRPN 
{
    private:
        int     _prevNbr;
        T       _tab;
        int     _cursor;
        bool    _isValid;
        bool    _isdigit;

    public:
        NRPN() : _prevNbr(0), _cursor(0), _isValid(true), _isdigit(true) {};
        ~NRPN() {};

        void    putInTab(char c)
        {
            this->_tab.push(c - 48);
            this->_cursor++;
        }

        void    doMaths(char c)
        {
            int nbr = this->_tab.top();
            if (c == '+')
            {
                this->_tab.pop();
                this->_tab.top() += nbr;
                }
            if (c == '-')
            {
                this->_tab.pop();
                this->_tab.top() -= nbr;
                }
            if (c == '/')
            {
                this->_tab.pop();
                this->_tab.top() /= nbr;
                }
            if (c == '*')
            {
                    this->_tab.pop();
                this->_tab.top() *= nbr;
                }
        }
        int isCalcul(char c)
        {
            return (c == '+' || c == '-' || c == '/' || c == '*');
        }

        int isMoreThan10(std::string str)
        {
            int counter = 0;
            for (std::string::iterator i = str.begin(); i != str.end(); i++)
            {
                while (*i >= '0' && *i <= '9')
                {
                    counter++;
                    i++;
                }
                if ((*i < '0' || *i > '9') && !isCalcul(*i) && counter >= 2)
                {
                    return 0;
                }
                else
                    counter = 0;
            }
            return 1;
        }

        int stringLen(std::string str)
        {
            int len = 0;
            for (std::string::iterator i = str.begin(); i != str.end(); i++)
            {
                len++;
            }
            return (len);
        }

        int noToken(std::string str)
        {
            for (std::string::iterator i = str.begin(); i != str.end(); i++)
            {
                if (*i == '+' || *i == '-' || *i == '/' || *i == '*')
                    return (0);
            }
            return (1);
        }

        void Job(std::string str)
        {
            // int rep = 0;
            if (stringLen(str) == 1 && noToken(str) == 0)
            {
                // std::cerr << "Error." << std::endl;
                this->_isValid = false;
                // std::cerr << "Error." << std::endl;
            }
            if ((stringLen(str) == 1 || noToken(str) == 1) && this->_isValid == true)
            {
                // std::cout << "goes here" << std::endl;
                if (stringLen(str) == 1)
                {
                    // std::cout << "===" << std::endl;
                    std::cout << str << std::endl;
                    this->_isdigit = true;
                }
                else if (noToken(str) == 1)
                    std::cerr << "Error" << std::endl;
                // else
                    // std::cout << str << std::endl;
                this->_isValid = false;
                // rep = 6;
                // exit (1);
            }
            else if (!isMoreThan10(str) && this->_isValid == true)
            {
                std::cout << "Error" << std::endl;
                this->_isValid = false;
                // throw (std::length_error("Error: number should be less than 10.\n"));
                // ~NRPN();
                // exit (1);
            }
            int mathcompt = 0;
            if (this->_isValid == true)
            {
                // std::cout << "goes here" << std::endl;
                for (std::string::iterator i = str.begin(); i != str.end(); i++)
                {
                    if (*i >= '0' && *i <= '9')
                        putInTab(*i);
                    // if (this->_tab.size())
                    if (isCalcul(*i) && this->_tab.size() >= 2)
                    {
                        doMaths(*i);
                        mathcompt++;
                        
                    }
                    // if (isCalcul(*i) &&this->_tab.size() < 2)
                    //     this->_isValid = false;
                    // else
                    // {
                    //     std::cout << "test" << std::endl;
                    //     this->_isValid = false;
                    // }
                    // else
                    // {
                    //     std::cerr << "Error: only one number and one sign." << std::endl;
                    //     this->_isValid = false;
                    // }
                    if (!isCalcul(*i) && *i != ' ' && !isdigit(*i))
                    {
                        std::cout << "Error" << std::endl;
                        exit (1);
                    }
                    // std::cout << "goes here" << std::endl;
                }
            }
            // return ;
        }
        void    showTab()
        {
            T tmp;
            tmp = this->_tab;
            int tabSize = tmp.size();
            int toShow = 0;
            // std::cerr << "Errorrrr." << std::endl;
            // if (this->_isValid == false)
            //     std::cout << "isvalide ? " << this->_isValid << std::endl;
            if (this->_isValid == true)
                toShow = this->_tab.top();
            // if (this->_isValid == false && tabSize < 2)
            //     std::cout << "Error." << std::endl;
            // std::cout << "tabsize : " << std::endl;
            // if (tabSize == 0)
            //     std::cout << "Error" << std::endl;
            if (tabSize >= 2)
                std::cout << "Error: Tab size >= 2." << std::endl;
            if (this->_isValid == true && tabSize < 2)
            {
                // std::cerr << "Errorrrreeeeeeeeeeeeeeer." << std::endl;
                std::cout << toShow << std::endl;
            }
            else
            {
                // std::cout << toShow << std::endl;
                if (this->_isdigit == false)
                    std::cerr << "Error." << std::endl;
            }
        }
};


#endif