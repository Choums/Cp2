/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:41:05 by root              #+#    #+#             */
/*   Updated: 2022/11/20 13:00:09 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

# include "./Fixed.hpp"

class Point;

class Point {
	public:
		/*	Constructors/Destructors */
		Point();
		Point(float const x, float const y);
		Point(Point const& cpy);
		~Point();
		
		/*	Assignement Oerator overload */
		Point&	operator=(Point const& obj);

		/*	Accessors */
		Fixed	getXvalue(void) const;
		Fixed	getYvalue(void) const;

	private:
		Fixed	_x;
		Fixed	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif