#include "Account.hpp"

#include <iostream>
#include <ctime>

// Static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
//

void Account::_displayTimestamp(void)
{
    std::time_t now;
    std::time(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", std::localtime(&now));
    
    std::cout << buffer << " ";
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";"
              << "total:" << getTotalAmount() << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Getters
int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

int Account::checkAmount(void) const
{
    return _amount;
}
//

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts)
    , _amount(initial_deposit)
    , _nbDeposits(0)
    , _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "created" << std::endl;
}

Account::~Account(void)
{
    --_nbAccounts;
    _totalAmount -= _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "deposit:" << deposit << ";";

    _amount += deposit;
    _totalAmount += deposit;
    ++_nbDeposits;
    ++_totalNbDeposits;

    std::cout << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "withdrawal:";

    if (_amount < withdrawal)
    {
        std::cout << "refused" << std::endl;
        return false;
    }
    std::cout << withdrawal << ";";

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    ++_nbWithdrawals;
    ++_totalNbWithdrawals;

    std::cout << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals << std::endl;

    return true;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}