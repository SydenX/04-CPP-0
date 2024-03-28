/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtollena <jtollena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 11:44:28 by jtollena          #+#    #+#             */
/*   Updated: 2024/03/28 14:23:50 by jtollena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void){
	time_t now;
	time(&now);
	struct tm * timeinfo = std::localtime(&now);
	char buffer[80];
	std::strftime(buffer,sizeof(buffer),"%Y%m%d_%H%M%S",timeinfo);
	std::string str(buffer);
	std::cout << "[" << str << "]";
}

Account::Account(int initial_deposit) {
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	return;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	return;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
	return;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
	return;
}

void Account::makeDeposit(int deposit) {
	int prev = _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << prev << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
	return;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (_amount - withdrawal < 0){
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
		return 0; }
	int prev = _amount;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << prev << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return 1;
}