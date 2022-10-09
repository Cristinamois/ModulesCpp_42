/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmois <cmois@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:21:02 by cmois             #+#    #+#             */
/*   Updated: 2022/06/23 01:36:23 by cmois            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <cmath>

class ClapTrap {
	private:
		std::string _name;
		int _energyP;
		int _hitP;
		int _attackD;
	public:
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		virtual ~ClapTrap();

		ClapTrap &operator=(const ClapTrap &src);

};

#endif