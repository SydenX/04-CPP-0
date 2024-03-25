/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:31:02 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/25 11:57:10 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void) {
	// std::cout << "Contact initialized" << std::endl;
	this->id = -1;
	return;
}

Contact::~Contact(void) {
	// std::cout << "Contact destroyed" << std::endl;
	return;
}

void	Contact::setFirstname(std::string name){ this->firstname = name; }
std::string	Contact::getFirstname(){ return this->firstname;}

void	Contact::setLastname(std::string name){ this->lastname = name; }
std::string	Contact::getLastname(){ return this->lastname;}

void	Contact::setNickname(std::string name){ this->nickname = name; }
std::string	Contact::getNickname(){ return this->nickname;}

void	Contact::setPhone(std::string name){ this->phone = name; }
std::string	Contact::getPhone(){ return this->phone;}

void	Contact::setSecret(std::string name){ this->secret = name; }
std::string	Contact::getSecret(){ return this->secret;}

void	Contact::setId(int id){ this->id = id; }
int	Contact::getId(){ return this->id; }