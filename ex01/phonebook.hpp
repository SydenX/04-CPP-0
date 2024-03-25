/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:03:19 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/25 11:01:43 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class	PhoneBook {
	private:
		Contact contacts[8];
	public:
		PhoneBook(void);
		~PhoneBook(void);

		Contact *newcontact();
		void	display();
		void	display_contact(int index);
		int		contact_size();
};

#endif