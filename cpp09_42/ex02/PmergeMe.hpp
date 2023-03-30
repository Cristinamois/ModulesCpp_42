#ifndef MERGE_HPP
#define MERGE_HPP

#include <iostream>
#include <cstring>
#include <algorithm>
// #include <chrono>
#include <sys/time.h>
#include <vector>
#include <deque>

#define TIME_FACTOR 1000

template<class T>
class MERGE
{
    private:
        int         _maxNbr;
        int         _argNbr;
        int rep;
        T           _tab;
        T           _final;
        // T           _fill;
        T           _final2;
        T           _dekRet;
    public:
        MERGE() : _maxNbr(3000), _argNbr(0), rep(0) {};
        ~MERGE() {};
        int getNbrOfArgs()
        {
            return (this->_argNbr);
        }
        T    getFill()
        {
            return (this->_tab);
        }
        void    printFill()
        {
            int j = this->_tab.size();
            for (int i = 0 ; i < j; i++)
            {
                std::cout << this->_tab[i] << " ";
            }
            std::cout << std::endl;
        }
        void    printTab()
        {
            int j = this->_tab.size();
            for (int i = 0; i < j; i++)
                std::cout << this->_tab[i] << " ";
            std::cout << std::endl;
        }
        void    printContWithArg(T cont)
        {
            for (int i = 0; i < cont.size(); i++)
                std::cout << cont[i] << " ";
            std::cout << std::endl;
        }
        void    putInCont(std::string str)
        {
            int res = 0;
            for (std::string::iterator i = str.begin(); i != str.end(); i++)
            {
                if (isdigit(*i))
                {
                    res = res * 10 + (*i - 48);
                }
                if (*i == ' ')
                {
                    this->_tab.push_back(res);
                    res = 0;
                }
                if (!isdigit(*i) && *i != ' ')
                {
                    std::cout << "Error: Character \"" << *i << "\" is not a Number. Please fix it." << std::endl;;
                    exit(1);
                }
            }
            this->_argNbr++;
            this->_tab.push_back(res);;
        }
            void    start(std::string str)
            {
                putInCont(str);
            }
            void    insertionSort(T &tab)
            {
                // int i;
                int j;
                int tmp;
                int n = tab.size();
                for (int i = 1; i < n; i++)
                {
                    j = i;
                    tmp = tab[i];
                    while (j > 0 && tmp < tab[j - 1])
                    {
                        tab[j] = tab[j - 1];
                        j--;
                    }
                    tab[j] = tmp;
                }
            }
            void    mergeSort(T &left, T &right, T &tab)
            {
                int lenLeft = left.size();
                int lenRight = right.size();
                int i = 0, j = 0, k = 0;

                while (j < lenLeft && k < lenRight)
                {
                    if (left[j] < right[k])
                    {
                        tab[i] = left[j];
                        j++;
                    }
                    else
                    {
                        tab[i] = right[k];
                        k++;
                    }
                    i++;
                }
                while (j < lenLeft)
                {
                    tab[i] = left[j];
                    j++;
                    i++;
                }
                while (k < lenRight)
                {
                    tab[i] = right[k];
                    k++;
                    i++;
                }
            }
            void    getRes(T toGet)
            {
                int nbr;
                nbr = this->_final.size();
                this->_final.clear();
                // std::cout << "CEST OU CE PB DE MERDE" << std::endl;
                this->_final.insert(this->_final.end(), toGet.begin(), toGet.end());
            }
            void    sort(T tabs)
            {
                if (tabs.size() <= 1)
                return ;
                int mid = tabs.size() / 2;
                T    left;
                T    right;

                for (int j = 0; j < mid; j++)
                    left.push_back(tabs[j]);
                for (size_t j = 0; j < (tabs.size() - mid); j++)
                    right.push_back(tabs[mid + j]);
                
                sort(left);
                sort(right);
                mergeSort(left, right, tabs);
                insertionSort(left);
                insertionSort(right);

                getRes(right);
                this->_final = right;
                this->_final2 = left;
            }
            
            void mergeBoth()
            {
                this->_tab = this->_final;
                this->_tab.insert(this->_tab.end(), this->_final2.begin(), this->_final2.end());
                insertionSort(this->_tab);;
            }

            
};


#endif