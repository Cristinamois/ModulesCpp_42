/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:23:43 by cmois             #+#    #+#             */
/*   Updated: 2022/06/22 17:53:39 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "str : " <<  &str << std::endl;
	std::cout << "strPTR : " << &stringPTR << std::endl;
	std::cout << "strREF : " << &stringREF << std::endl << std::endl;;

	std::cout << "str : " << str << std::endl;
	std::cout << "strPTR : " << *stringPTR << std::endl;
	std::cout << "strREF : " << stringREF << std::endl;


}