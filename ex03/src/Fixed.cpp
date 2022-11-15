/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:35:37 by root              #+#    #+#             */
/*   Updated: 2022/11/10 20:07:46 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

/*	Constructeur de copie */
Fixed::Fixed(Fixed const& cpy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_value = cpy.getRawBits();
}

/*	Convertit l'integer en fixed number */
Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = (num << Fixed::_bits);
}

/*	Convertit le float en fixed number */
Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(num * (1 << Fixed::_bits));
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

/*	Static Methods */

/*	Return ref. sur le plus grand num*/
Fixed& Fixed::max(Fixed& num1, Fixed& num2)
{
	if (num1 > num2) return (num1);
	else return (num2);
}

/*	Return ref. sur le plus petit num*/
Fixed& Fixed::min(Fixed& num1, Fixed& num2)
{
	if (num1 < num2) return (num1);
	else return (num2);
}

/*	 */
Fixed Fixed::max(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp;
	if (num1 > num2)
		tmp = num1;
	else
		tmp = num2;
	return (tmp);
}

/*	 */
Fixed Fixed::min(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp;
	if (num1 < num2)
		tmp = num1;
	else
		tmp = num2;
	return (tmp);
}

/*	Methods */

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
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/*	Operator Overload */

/*	Comparison */
/*
 *	num1 < num2
*/
bool	operator<(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp(num1 - num2);
	if (tmp.getRawBits() < 0)
		return (true);
	return (false);
}

bool	operator<=(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp(num1 - num2);
	if (tmp.getRawBits() <= 0)
		return (true);
	return (false);
}

bool	operator>(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp(num1 - num2);
	if (tmp.getRawBits() > 0)
		return (true);
	return (false);
}

bool	operator>=(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp(num1 - num2);
	if (tmp.getRawBits() >= 0)
		return (true);
	return (false);
}

bool	operator==(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp(num1 - num2);
	if (tmp.getRawBits() == 0)
		return (true);
	return (false);
}

bool	operator!=(Fixed const& num1, Fixed const& num2)
{
	Fixed	tmp(num1 - num2);
	if (tmp.getRawBits() != 0)
		return (true);
	return (false);
}

/*	Assignement */

Fixed&	Fixed::operator=(Fixed const& obj)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->_value = obj.getRawBits();
	return (*this);
}

Fixed	operator-(Fixed const& num1, Fixed const& num2)
{
	Fixed	sub;
	sub.setRawBits(num1.getRawBits() - num2.getRawBits());
	return (sub);
}

Fixed	operator+(Fixed const& num1, Fixed const& num2)
{
	Fixed	add;
	add.setRawBits(num1.getRawBits() + num2.getRawBits());
	return (add);
}

Fixed	operator*(Fixed const& num1, Fixed const& num2)
{
	Fixed	mul(num1.toFloat() * num2.toFloat());
	return (mul);
}

Fixed	operator/(Fixed const& num1, Fixed const& num2)
{
	Fixed	div(num1.toFloat() / num2.toFloat());
	return (div);
}

/*	Past incr */
Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

/*	Past incr */
Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

/*	Post incr */
Fixed	Fixed::operator++(int)
{
	Fixed	num(*this);
	++(*this);
	return (num);
}

/*	Post decr */
Fixed	Fixed::operator--(int)
{
	Fixed	num(*this);
	--(*this);
	return (num);
}

/*	Stream */

std::ostream&	operator<<(std::ostream& flux, Fixed const& num)
{
	flux << num.toFloat();
	return (flux);
}