
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:27:41 by cmois             #+#    #+#             */
/*   Updated: 2022/05/10 16:17:42 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		void announce();

		Zombie();
		Zombie(std::string name);
		Zombie* newZombie(std::string name);

		~Zombie();
};

Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif // ZOMBIE_HPP