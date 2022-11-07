/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaidel <chaidel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:07:22 by chaidel           #+#    #+#             */
/*   Updated: 2022/11/07 17:23:05 by chaidel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed;

class Fixed {
	public:

		/*	Constructors/Destructor */
		Fixed();
		Fixed(Fixed const& cpy);
		~Fixed();

		/*	Accessors */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/*	Operator overload */
		Fixed operator=(Fixed const& obj);

	private:
		int					_value;
		static const int	_bits;
};


#endif