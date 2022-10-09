/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:55:43 by cmois             #+#    #+#             */
/*   Updated: 2022/06/22 17:43:55 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string _name;
	public:
		void announce();
		const std::string &getName() const;
		void setName(const std::string &name);
		virtual ~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif