/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:39:17 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/28 14:26:01 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

int	read(std::string *buff){
	std::cin >> *buff;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if ((*buff).empty() || !std::cin)
		return 0;
	return 1;
}

int	main(void){
	PhoneBook pb;
	std::string	buff[6];
	std::cout << "-----------------------" << std::endl;
	std::cout << "--- Contact Manager ---" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Please enter a command: ADD, SEARCH (index), EXIT : ";
		if (!read(&buff[0]))
			return 1;
		if (buff[0].compare("ADD") == 0){
			Contact	*newcontact = pb.newcontact();
			std::cout << "New Contact Setup," << std::endl;
			std::cout << "First name : ";
			if (!read(&buff[1]))
				return 1;
			newcontact->setFirstname(buff[1]);
			std::cout << "Last name : ";
			if (!read(&buff[2]))
				return 1;
			newcontact->setLastname(buff[2]);
			std::cout << "Nickname : ";
			if (!read(&buff[3]))
				return 1;
			newcontact->setNickname(buff[3]);
			std::cout << "Phone number : ";
			while (!is_number(buff[4])) {
				if (!read(&buff[4]))
					return 1;
				if (is_number(buff[4]))
					break;
				std::cout << buff[4] << " is not a valid number." << std::endl;
				buff[4].clear();
			}
			newcontact->setPhone(buff[4]);
			buff[4] = "";
			std::cout << "Darkest secret : ";
			if (!read(&buff[5]))
				return 1;
			newcontact->setSecret(buff[5]);
		} else if (buff[0].compare("SEARCH") == 0){
			pb.display();
			if (pb.contact_size() > 0){
				while (!is_number(buff[0])) {
					std::cout << "Enter contact index to display, use EXIT to go back: ";
					if (!read(&buff[0]))
						return 1;
					if (is_number(buff[0]) || !buff[0].compare("EXIT"))
						break;
					std::cout << buff[0] << " is not a valid index." << std::endl;
					buff[0].clear();
				}
				if (is_number(buff[0])){
					try {
						int index = stoi(buff[0]);
						pb.display_contact(index);
					} catch (std::out_of_range &e) { 
						std::cout << "Integer Overflow, please use an integer as index." << std::endl; }
				}
			}
		} else if (buff[0].compare("EXIT") == 0)
			break;
	}
	std::cout << std::endl << "---- See you soon! ----" << std::endl;
	std::cout << "-----------------------" << std::endl;
	return 0;
}