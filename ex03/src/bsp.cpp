/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:41:30 by root              #+#    #+#             */
/*   Updated: 2022/11/20 13:00:00 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

/*
 *	Binary Space Partitioning.
 *	---
 *	Calcul l'aire du parallelograme pour definir si le point est compris dans le triangle.
 *	Determinant => (Ax - Px)(By - Py) - (Ay - Py)(Bx - Px).
 *	Si les 3 vecteurs sont pos. ou neg. alors le point est compris.
 *	Sinon non compris.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	value1;
	Fixed	value2;
	Fixed	value3;

	value1 = (a.getXvalue() - point.getXvalue()) * ((b.getYvalue()) - point.getYvalue()) - ((a.getYvalue() - point.getYvalue()) * (b.getXvalue() - point.getXvalue()));
	value2 = (c.getXvalue() - point.getXvalue()) * ((a.getYvalue()) - point.getYvalue()) - ((c.getYvalue() - point.getYvalue()) * (a.getXvalue() - point.getXvalue()));
	value3 = (b.getXvalue() - point.getXvalue()) * ((c.getYvalue()) - point.getYvalue()) - ((b.getYvalue() - point.getYvalue()) * (c.getXvalue() - point.getXvalue()));
	// std::cout << "val1: " << value1 << std::endl;
	// std::cout << "val2: " << value2 << std::endl;
	// std::cout << "val3: " << value3 << std::endl;
	if (value1 >= 0 && value2 >= 0 && value3 >= 0)	return (true);
	else if (value1 <= 0 && value2 <= 0 && value3 <= 0)	return (true);
	return (false);
}