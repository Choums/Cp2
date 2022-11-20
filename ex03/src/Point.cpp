/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:41:07 by root              #+#    #+#             */
/*   Updated: 2022/11/17 12:43:59 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/*	Constructors/Destructors */
Point::Point() : _x(0), _y(0)
{}

Point::Point(float const x, float const y) : _x(x), _y(y)
{}

Point::Point(Point const& cpy)
{
	this->_x = cpy.getXvalue();
	this->_y = cpy.getYvalue();
}

Point::~Point()
{};

/*	Accessors */
Fixed	Point::getXvalue(void) const
{
	return (this->_x);
}

Fixed	Point::getYvalue(void) const
{
	return (this->_y);
}

/*	Assignement Oerator overload */
Point& Point::operator=(Point const& obj)
{
	if (this != &obj)
	{
		this->_x = obj.getXvalue();
		this->_y = obj.getYvalue();
	}
	return (*this);
}