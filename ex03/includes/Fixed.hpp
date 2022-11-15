/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:35:24 by root              #+#    #+#             */
/*   Updated: 2022/11/10 20:06:52 by root             ###   ########.fr       */
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

		/*	Static methods */
		static Fixed& max(Fixed& num1, Fixed& num2);
		static Fixed& min(Fixed& num1, Fixed& num2);
		static Fixed max(Fixed const& num1, Fixed const& num2);
		static Fixed min(Fixed const& num1, Fixed const& num2);
				
		/*	Methods */
		float	toFloat(void) const;
		int		toInt(void) const;

		/*	Accessors */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/*	Assignement Operator overload */
		Fixed&	operator=(Fixed const& obj);
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

	private:
		int					_value;
		static const int	_bits = 8;
};

/*	Comparison Operator overload*/
bool	operator<(Fixed const& num1, Fixed const& num2);
bool	operator>(Fixed const& num1, Fixed const& num2);
bool	operator<=(Fixed const& num1, Fixed const& num2);
bool	operator>=(Fixed const& num1, Fixed const& num2);
bool	operator==(Fixed const& num1, Fixed const& num2);
bool	operator!=(Fixed const& num1, Fixed const& num2);

Fixed	operator-(Fixed const& num1, Fixed const& num2);
Fixed	operator+(Fixed const& num1, Fixed const& num2);

Fixed	operator*(Fixed const& num1, Fixed const& num2);
Fixed	operator/(Fixed const& num1, Fixed const& num2);

/*	Stream Operator overload */
std::ostream& operator<<(std::ostream& floux, Fixed const& num);

#endif