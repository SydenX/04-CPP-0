/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:06:02 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/25 11:57:03 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact {
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
		int			id;
	public:
		Contact(void);
		~Contact(void);
		void	setFirstname(std::string name);
		void	setLastname(std::string name);
		void	setNickname(std::string name);
		void	setPhone(std::string name);
		void	setSecret(std::string name);
		void	setId(int id);

		std::string	getFirstname();
		std::string	getLastname();
		std::string	getNickname();
		std::string	getPhone();
		std::string	getSecret();
		int			getId();
};

#endif