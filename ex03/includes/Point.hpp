/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:41:05 by root              #+#    #+#             */
/*   Updated: 2022/11/13 17:11:50 by root             ###   ########.fr       */
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

		/*	Methods */

		
		/*	Assignement Oerator overload */
		Point&	operator=(Point const& obj);

		/*	Accessors */
		Fixed	getXvalue(void);
		Fixed	getYvalue(void);

	private:
		Fixed	_y;
		Fixed	_x;
};

#endif