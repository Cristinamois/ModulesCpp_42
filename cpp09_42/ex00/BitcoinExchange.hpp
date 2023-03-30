#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>
#include <map>
#include <limits.h>
#include <cstdlib>


template<class T>
class btc
{
    private:
        T   _csv;
        std::string _cYear;
        std::string _cValue;
        T   _input;
        std::string _iYear;
        std::string _iValue;
        int year;
        int month;
        int day;
        std::string _closestDay;
    public:
        btc() {};
        ~btc() {};

        bool    checkDate()
        {
            if (this->_iYear.length() != 10)
                return (false);
            char firstSep;
            char scndSep;
            std::istringstream ss(this->_iYear);
            ss >> this->year >> firstSep >> this->month >> scndSep >> this->day;
            if (ss.fail() || firstSep != '-' || scndSep != '-' || this->year < 0 || this->month < 1 || this->day < 1 || this->month > 12 || this->day > 31 || this->year > 2023)
                return (false);
            bool bissextile = ((this->year % 4 == 0) &&(this->year % 100 != 0)) || (this->year % 400 == 0);
            if ((this->month == 2 && (bissextile ? this->day > 29 : this->day > 28)) || ((this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11) && this->day > 30))
            {
                std::cout << "Error: year is bissextile and day is greater than 28. Fix it." << std::endl;
                return (false);
            }
            return (true);
        }

        bool checkValue() 
        {
            try 
            {
                stof2_0(this->_iValue);
            }
            catch (const std::invalid_argument& e) 
            {
                return false;
            }
            return true;
        }

        bool     toDouble()
        {
            if (stod2_0(this->_iValue) < 0)
            {
                std::cout << "Error: Not a positive number." << std::endl;
                return (false);
            }
            if (stod2_0(this->_iValue) > 1000)
            {
                std::cout << "Error: too large number." << std::endl;
                return (false);
            }
            return (true);
        }

        std::string findClosestDayUnder(std::string yearToComp)
        {
            int year;
            int month;
            int day;
            sscanf(yearToComp.c_str(), "%d-%d-%d", &year, &month, &day);

            int dayBefore = day - 1;
            int monthBefore = month;
            int yearBefore = year;
            if (dayBefore == 0)
            {
                monthBefore = month - 1;
                if (monthBefore == 0)
                {
                    monthBefore = 12;
                    yearBefore = year - 1;
                    if (yearBefore < 2009)
                        return ("Error: invalid date.");
                }
                if (monthBefore == 2) 
                {
                    if (yearBefore % 4 == 0 && (yearBefore % 100 != 0 || yearBefore % 400 == 0))    //Handle Feb
                    {
                        dayBefore = 29;
                    } 
                    else 
                    {
                        dayBefore = 28;
                    }
                } 
                else if (monthBefore == 4 || monthBefore == 6 || monthBefore == 9 || monthBefore == 11) 
                {
                    dayBefore = 30;
                } 
                else 
                {
                    dayBefore = 31;
                }
            }
            std::string ret = toString2_0(yearBefore) + "-";
            if (monthBefore < 10)
                ret += "0" + toString2_0(monthBefore);
            else
                ret += toString2_0(monthBefore);
            if (dayBefore < 10)
                ret += "-0" + toString2_0(dayBefore);
            else
                ret += "-" + toString2_0(dayBefore);
            return (ret);
        }

        int compDay()
        {
            // std::map<std::string, double>::iterator i = this->_csv.equal_range(this->year);
            for (std::map<std::string, double>::iterator i = this->_csv.begin(); i != this->_csv.end(); i++)
            {
                if (this->_closestDay == i->first)
                {
                    return (1);
                }
            }
                // if (i != this->_csv.end() && this->_closestDay != i->first)
                // std::cout << "returned -1" << std::endl;
            return (-1);  
        }

        double  csvVal(std::string year)
        {
            std::map<std::string, double>::iterator i = this->_csv.find(year);
            if (i != this->_csv.end())
            {
                return (i->second);
            }
            else
            {
                this->_closestDay = findClosestDayUnder(this->_iYear);
                while (compDay() == -1)
                {
                    this->_closestDay = findClosestDayUnder(this->_closestDay);
                    // std::cout << "\t\t\t\tclosestday : " << this->_closestDay << std::endl;
                }
                if (this->_closestDay.compare("Error: invalid date."))
                    return (0);
                return csvVal(this->_closestDay);
            }
            return csvVal(this->_closestDay);
        }

        double findData()
        {
            double res = -1;

            for (std::map<std::string, double>::iterator i = this->_csv.begin(); i != this->_csv.end(); i++)
            {
                if (this->_closestDay == i->first)
                    {
                        // std::cout << "\t\t\t\t\t\t i->first :" << i->first << std::endl;
                        res = i->second;
                        // std::cout << "\t\t\t\t\t\t i->second : " << i->second << std::endl;
                        return (res);
                    }
            }
            return (res);
        }

        void    readInput(char *filename)
        {
            std::ifstream file(filename);
            if (!file)
            {
                std::cerr << "Error: Could not open file." << std::endl;
                exit (1);
            }
            std::string first;
            std::getline(file, first);
            std::string line;
            while (std::getline(file, line))
            {
                std::istringstream  iss(line);
                char    sep;
                if (!(iss >> this->_iYear >> sep >> this->_iValue) || sep != '|')
                    std::cout << "Error: Bad input => " << this->_iYear << std::endl;
                else if (!checkDate() || !checkValue())
                    std::cout << "Error: Bad input => " << this->_iYear << std::endl;

                else if (stod2_0(this->_iValue) < 0)
                {
                    std::cout << "Error: Not a positive number." << std::endl;
                }
                else if (stod2_0(this->_iValue) > 1000)
                {
                    std::cout << "Error: too large number." << std::endl;
                }
                else if (stod2_0(this->_iValue) < 1000 || stod2_0(this->_iValue) > 0)
                {
                    double res;
                    double csvValres = csvVal(this->_closestDay);
                    double ret;

                    this->_closestDay = this->_iYear;
                    res = /*stod2_0(this->_cValue) **/ csvVal(this->_closestDay);
                    double csvData = findData();
                    res = (stod2_0(this->_iValue) * csvData);
                    ret = res;
                
                    res = csvValres * stod2_0(this->_iValue);
                    std::cout << this->_iYear << " => " << this->_iValue << " = " << ret << std::endl;
                }
                else
                    std::cout << "Error: bad input => " << this->_iYear << std::endl;
            }
            if (file.is_open())
                file.close();
        }

        void   readCSV()
        {
            std::ifstream file("data.csv");
            std::string line;
            std::getline(file, line);   //skip data,exchange_rate
            while (std::getline(file, line))
            {
                std::stringstream   ss(line);
                std::getline(ss, this->_cYear, ',');
                std::getline(ss, this->_cValue, ',');
                this->_csv[this->_cYear] = stod2_0(this->_cValue);
            }
        }
        double stod2_0(const std::string& str) 
        {
            const size_t n = str.size();

            size_t i = 0;
            while (i < n && std::isspace(str[i])) 
            {
                ++i;
            }
            int sign = 1;
            if (i < n && str[i] == '+') 
            {
                ++i;
            } else if (i < n && str[i] == '-') 
            {
                sign = -1;
                ++i;
            }
            double result = 0.0;
            while (i < n && std::isdigit(str[i])) 
            {
                result = result * 10.0 + (str[i] - '0');
                ++i;
            }
            if (i < n && str[i] == '.') 
            {
                ++i;
                double fraction = 0.0;
                double div = 1.0;
                while (i < n && std::isdigit(str[i])) 
                {
                    fraction = fraction * 10.0 + (str[i] - '0');
                    div *= 10.0;
                    ++i;
                }
                result += fraction / div;
            }
            return (result * sign);
        }

        float stof2_0(const std::string& str) 
        {
            const size_t n = str.size();
            size_t i = 0;
            while (i < n && std::isspace(str[i])) 
            {
                ++i;
            }
            int sign = 1;
            if (i < n && str[i] == '+') 
            {
                ++i;
            } else if (i < n && str[i] == '-') 
            {
                sign = -1;
                ++i;
            }
            double result = 0.0;
            while (i < n && std::isdigit(str[i])) 
            {
                result = result * 10.0 + (str[i] - '0');
                ++i;
            }
            if (i < n && str[i] == '.') 
            {
                ++i;
                double fraction = 0.0;
                double div = 1.0;
                while (i < n && std::isdigit(str[i])) 
                {
                    fraction = fraction * 10.0 + (str[i] - '0');
                    div *= 10.0;
                    ++i;
                }
                result += fraction / div;
            }
            return (result * sign);
        }

        template <typename A>
        std::string toString2_0(const A& value) 
        {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }

};

#endif
