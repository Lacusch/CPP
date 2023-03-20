#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

/*===============================================*
*                Class Variables                 *
*================================================*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*===============================================*
*                    Getters                     *
*================================================*/

int	Account::getNbAccounts() {
	return _nbAccounts;
}

int	Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp() {
	std::time_t result = std::time(nullptr);
    std::cout<<'['<<std::put_time(std::localtime(&result), "%Y%m%d_%H%M%S") <<"] ";
}

void::Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
	<< ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:"
	<< _totalNbWithdrawals << std::endl;
}

/*===============================================*
*            Constractor + Destructor            *
*================================================*/

Account::Account (int initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts ++;
	_totalAmount += initial_deposit;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << initial_deposit << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
	<< "amount:" << _amount << ";closed" << std::endl;
	_nbAccounts --;
}

/*===============================================*
*                      Utils                     *
*================================================*/

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	<< ";amount:" << _amount << ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< _amount << ";deposit:" << deposit << ";amount:" 
	<< _amount + deposit << ";nb_deposits:" << (_nbDeposits + 1)
	<< std::endl;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount = _amount + deposit;
	_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"
	<< _amount << ";withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	std::cout << withdrawal << ";amount:"
	<< _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals + 1
	<< std::endl;
	_amount = _amount - withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	return true;
}
