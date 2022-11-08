/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:19:40 by chaidel           #+#    #+#             */
/*   Updated: 2022/11/08 15:39:11 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"



Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

/*	Constructeur de copie */
Fixed::Fixed(Fixed const& cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = cpy.getRawBits();
}

/*	Convertit l'integer en fixed number */
Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = (num << Fixed::_bits);
}

/*	Convertit le float en fixed number */
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << Fixed::_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << Fixed::_bits));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

Fixed&	Fixed::operator=(Fixed const& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_value = obj.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& flux, Fixed const& num)
{
	flux << num.toFloat();
	return (flux);
}