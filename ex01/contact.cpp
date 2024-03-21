/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:31:02 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/14 14:49:53 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void) {
	std::cout << "Contact initialized" << std::endl;
	this->id = -1;
	return;
}

Contact::~Contact(void) {
	std::cout << "Contact destroyed" << std::endl;
	return;
}