/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:03:21 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/25 12:03:24 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void) {
	// std::cout << "PhoneBook initialized" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "PhoneBook destroyed" << std::endl;
	return;
}

std::string	print_table(std::string str)
{
	std::string newstr = str;
	if (newstr.size() > 10){
		newstr[9] = '.';
		newstr.erase(10, newstr.size());
	}
	return newstr;
}

int		PhoneBook::contact_size(){
	int k = 0;
	for(int j = 0; j < 8; j++){
		int	toDisplay = j;
		for(int i = 0; i < 8; i++)
			if (this->contacts[i].getId() == toDisplay + 1)
				k++;
	}
	return k;
}

void	PhoneBook::display(void){
	if (this->contact_size() == 0){
		std::cout << "No contact found." << std::endl;
		return;
	}
	std::cout << "- | ---------- | ---------- | ---------- |" << std::endl;
	for(int j = 0; j < 8; j++){
		int	toDisplay = j;
		for(int i = 0; i < 8; i++)
			if (this->contacts[i].getId() == toDisplay + 1)
				std::cout << ((this->contacts[i].getId() - 1) % 8) + 1 << " | " << std::setw(10) << print_table(this->contacts[i].getFirstname()) << " | " << std::setw(10) << print_table(this->contacts[i].getLastname()) << " | " << std::setw(10) << print_table(this->contacts[i].getNickname()) << " |" << std::endl;
		toDisplay++;
	}
	std::cout << "- | ---------- | ---------- | ---------- |" << std::endl;
}

void	PhoneBook::display_contact(int index){
	for(int j = 0; j < 8; j++){
		if (this->contacts[j].getId() == index){
			std::cout << "--- Contact Informations : " << index << " --- " <<std::endl;
			std::cout << "Firstname: " << this->contacts[j].getFirstname() << std::endl;
			std::cout << "Lastname: " << this->contacts[j].getLastname() << std::endl;
			std::cout << "Nickname: " << this->contacts[j].getNickname() << std::endl;
			std::cout << "Phone Number: " << this->contacts[j].getPhone() << std::endl;
			std::cout << "Darkest Secret: " << this->contacts[j].getSecret() << std::endl;
			return;
		}
	}
	std::cout << "Contact with index " << index << " not found." << std::endl;
}

Contact *PhoneBook::newcontact(void) {
	Contact *toreturn;
	for(int i = 0; i < 8; i++)
		if (this->contacts[i].getId() == -1)
			toreturn = &this->contacts[i];

	int lastId = 0;
	for(int i = 0; i < 8; i++)
		if (this->contacts[i].getId() > lastId)
			lastId = this->contacts[i].getId();
			
	if (toreturn == NULL){
		int firstId = lastId;
		int firstContactId = 0;
		for(int i = 0; i < 8; i++){
			if (this->contacts[i].getId() < firstId){
				firstId = this->contacts[i].getId();
				firstContactId = i;
			}
		}
		toreturn = &this->contacts[firstContactId];
		toreturn->setId(lastId + 1);
		for(int i = 0; i < 8; i++)
			this->contacts[i].setId(this->contacts[i].getId() - 1);
	} else 
		toreturn->setId(lastId + 1);
	return toreturn;
}
