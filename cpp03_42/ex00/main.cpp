/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:37:20 by cmois             #+#    #+#             */
/*   Updated: 2022/06/06 01:35:37 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{

	ClapTrap clap("Clap");
	ClapTrap clop(clap);


	clap.attack("Trap");
	clap.takeDamage(50);
	clap.beRepaired(50);
	clop.takeDamage(5);
	clop.beRepaired(20);
	clop.takeDamage(20);
	clop.takeDamage(20);
	clop.attack("Clap");

}