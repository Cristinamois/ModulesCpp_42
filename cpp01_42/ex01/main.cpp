/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:06:14 by cmois             #+#    #+#             */
/*   Updated: 2022/06/22 17:47:38 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

	
int main()
{
//	Zombie stack_default;
//	Zombie stack_name("stack_Zombie");
//
//	stack_default.announce();
//

	int qty = 8;
//	stack_name.announce();
//	int qty = 5;
	//Zombie *horde = zombieHorde(qty, "Momo");
	Zombie *heap_zombie = zombieHorde(qty, "Zombax oukoi");

	// randomChump("stack Zombie");

//	delete heap_zombie;
	for (int i = 0; i < qty; i++)
		heap_zombie[i].announce();

	delete []heap_zombie;
	return 0;
}
