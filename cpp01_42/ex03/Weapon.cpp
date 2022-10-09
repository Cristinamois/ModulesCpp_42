/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:06:18 by cmois             #+#    #+#             */
/*   Updated: 2022/05/20 14:48:46 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}

std::string const &Weapon::getType()
{
	std::cout << "type here is : " << this->_type << std::endl;
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}