/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:30:39 by chaidel           #+#    #+#             */
/*   Updated: 2022/11/07 17:25:22 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& cpy) : _value(cpy._value)
{
	std::cout << "" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "" << std::endl;
}

Fixed	Fixed::operator=(Fixed const& obj)
{
	Fixed	cpy(obj);
	return (cpy);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}