/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:19:46 by chaidel           #+#    #+#             */
/*   Updated: 2022/11/08 12:53:44 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed;

class Fixed {
	public:

		/*	Constructors/Destructor */
		Fixed();
		Fixed(Fixed const& cpy);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();

		/*	Methods*/
		float	toFloat(void) const;
		int		toInt(void) const;

		/*	Accessors */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/*	Operator overload */
		Fixed&	operator=(Fixed const& obj);
	
	private:
		int					_value;
		static const int	_bits = 8;
};

std::ostream& operator<<(std::ostream& floux, Fixed const& num);

#endif