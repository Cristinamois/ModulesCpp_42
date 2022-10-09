/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:13:16 by cmois             #+#    #+#             */
/*   Updated: 2022/06/28 10:37:48 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	// ClapTrap::ClapTrap();
	this->_hitPoint = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Scavtrap: " << name << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap: "  << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " tried to attack but dead" << std::endl;
		return ;
	}
	if (this->_hitPoint <= 0)
	{
		std::cout << this->_name << " tried to attack but is out of energy." << std::endl;
	}
	std::cout << this->_name << " attacked " << target << " causing " << this->_attackDamage << " points of damage " << std::endl;
	
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap has entered in Gate keeper mode." << std::endl;
}