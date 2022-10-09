/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:03:25 by cmois             #+#    #+#             */
/*   Updated: 2022/05/20 14:53:06 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &_Weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		std::string	getName();
		void	setName(std::string name);
		void attack();

		
};

#endif