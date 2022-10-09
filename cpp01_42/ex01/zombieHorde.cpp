/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:56:35 by cmois             #+#    #+#             */
/*   Updated: 2022/06/22 17:44:44 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Zombie* newZombie(std::string name)
// {
// 	std::cout << "newZombie called" << std::endl;
// 	Zombie *newOne = newZombie(name);
// 	std::cout << "??" << std::endl;
// 	return (newOne);
// }

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newOne = new Zombie[N];

	for (int i = 0; i < N; i++)
		newOne[i].setName(name);

	return (newOne);
}