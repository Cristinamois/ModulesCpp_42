/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:23:00 by cmois             #+#    #+#             */
/*   Updated: 2022/05/20 14:56:31 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA(std::string name, Weapon &weapon)
// {
// 	// std::string tmpWeapon;
// 	// this->_name = name;
// 	// std::cout << "HumanA created, name is : " << this->_name << std::endl;
// 	// tmpWeapon = weapon.Weapon::getType();
// 	// weapon.Weapon::setType(tmpWeapon);
// 	// this->_Weapon = weapon.this->_type;
// 	this->_name = name;
// 	weapon = this->_Weapon;
// }

HumanA::HumanA( std::string Name, Weapon &Weapon ): _name(Name), _Weapon(Weapon){}

HumanA::~HumanA()
{
	std::cout << "Destructor for " << this->_name << " called" << std::endl;
}

std::string HumanA::getName()
{
	return (this->_name);
}

void HumanA::setName(std::string name)
{
	this->_name = name;
}

void HumanA::attack()
{
	// this->_Weapon = NULL;
	// this->_Weapon = weapon.Weapon::getType();
	std::string type;

	type = _Weapon.getType();
	std::cout << this->_name << " attacks with their " << type << std::endl;
	
}