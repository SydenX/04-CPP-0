/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:39:17 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/26 10:56:54 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void	read(std::string *buff){
	std::cin >> *buff;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int	main(void){
	PhoneBook pb;
	std::string	buff[6];
	std::cout << "-----------------------" << std::endl;
	std::cout << "--- Contact Manager ---" << std::endl << std::endl;
	while (1)
	{
		std::cout << "Please enter a command: ADD, SEARCH (index), EXIT : ";
		read(&buff[0]);
		if (buff[0].compare("ADD") == 0){
			Contact	*newcontact = pb.newcontact();
			std::cout << "New Contact Setup," << std::endl;
			std::cout << "First name : ";
			read(&buff[1]);
			newcontact->setFirstname(buff[1]);
			std::cout << "Last name : ";
			read(&buff[2]);
			newcontact->setLastname(buff[2]);
			std::cout << "Nickname : ";
			read(&buff[3]);
			newcontact->setNickname(buff[3]);
			std::cout << "Phone number : ";
			while (!is_number(buff[4])) {
				read(&buff[4]);
				if (is_number(buff[4]))
					break;
				std::cout << buff[4] << " is not a valid number." << std::endl;
			}
			newcontact->setPhone(buff[4]);
			buff[4] = "";
			std::cout << "Darkest secret : ";
			read(&buff[5]);
			newcontact->setSecret(buff[5]);
		} else if (buff[0].compare("SEARCH") == 0){
			pb.display();
			if (pb.contact_size() > 0){
				while (!is_number(buff[0])) {
					std::cout << "Enter contact index to display, use EXIT to go back: ";
					read(&buff[0]);
					if (is_number(buff[0]) || !buff[0].compare("EXIT"))
						break;
					std::cout << buff[0] << " is not a valid index." << std::endl;
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