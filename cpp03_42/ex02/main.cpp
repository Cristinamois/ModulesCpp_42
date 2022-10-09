/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:08:50 by cmois             #+#    #+#             */
/*   Updated: 2022/06/28 11:29:58 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{

		

	ClapTrap clap("clappy");
	ClapTrap claap(clap);
	ScavTrap clop("scavvy");
	ScavTrap scav("crisscross");
	FragTrap fraggy("fraggy");
	FragTrap frag("luciferoooo");

	claap.takeDamage(999);
	scav.attack("life");
	clap.attack("old man");
	clap.takeDamage(50);
	clap.beRepaired(50);
	clop.takeDamage(5);
	clop.beRepaired(20);
	clop.takeDamage(20);
	clop.takeDamage(20);
	scav.guardGate();
	clop.takeDamage(200);
	scav.guardGate();
	scav.attack("young man");
	clop.attack("wall");
	fraggy.attack("water");
	fraggy.takeDamage(50);
	fraggy.beRepaired(100);
	fraggy.takeDamage(149);
	fraggy.beRepaired(500);
	fraggy.takeDamage(999);
	fraggy.highFivesGuys();
	frag.highFivesGuys();
	frag.takeDamage(5000);
	frag.attack("air");
}