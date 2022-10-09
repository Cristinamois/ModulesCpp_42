/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:16:36 by cmois             #+#    #+#             */
/*   Updated: 2022/06/06 03:06:38 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name)
{
	this->_hitPoint = 10;
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_name = name;
	std::cout << "ClapTrap: " << "Constructor of " << this->_name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << this->_name << " Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " tried to attack but dead." << std::endl;
		return ;
	}
	if (this->_hitPoint <= 0)
	{
		std::cout << this->_name << " tried to attack but is out of energy!" << std::endl;
		return;
	}
	else
		std::cout << this->_name << " attacked "<< target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) 
{
	*this = src;
	this->_name = "Clap2";
	std::cout << this->_name << " was built and is a clone bzz bzz" << std::endl << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_energyPoints -= amount;
	std::cout << this->_name << " lost " << amount << " hp!" << std::endl;
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " died..." << std::endl;
		return ;
	}
	
	// std::cout << this->_energyPoints << " left." << std::endl; 
	if (this->_energyPoints <= 0)
		std::cout << this->_name << " died!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << this->_name << " tried to repair but is dead!" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " tried to repair but is out of energy!" << std::endl;
		return;
	}
	this->_hitPoint += amount;
	this->_energyPoints -= amount;

	std::cout << this->_name << " repaired for " << amount << " hp!" << std::endl;
}