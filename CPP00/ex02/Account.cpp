/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hluiz-ma <hluiz-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:44:41 by hluiz-ma          #+#    #+#             */
/*   Updated: 2025/03/25 21:43:10 by hluiz-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
    _accountIndex = 0;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
              << ";amount:" << _amount 
              << ";created" << std::endl;

}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout
    << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";closed"
    << std::endl;
}

int	Account::getNbAccounts( void )
{
    return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
    return _totalAmount;
}
int	Account::getNbDeposits( void )
{
    return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
    return _totalNbWithdrawals;
}
void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout
    << "accounts:" << _nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals
    << std::endl;
}
void	Account::_displayTimestamp( void )
{
    time_t now = time(NULL);
    struct tm* local_time = localtime(&now);

    std::cout << '['
              << std::setfill('0')
              << std::setw(4) << local_time->tm_year + 1900
              << std::setw(2) << local_time->tm_mon + 1
              << std::setw(2) << local_time->tm_mday
              << '_'
              << std::setw(2) << local_time->tm_hour
              << std::setw(2) << local_time->tm_min
              << std::setw(2) << local_time->tm_sec
              << "] ";
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    if (deposit <= 0)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" 
        << this->_amount << ";withdrawal:refused" << std::endl;
        return ;
    }
    else
    {
        std::cout << "index:" << this->_accountIndex
                  << ";p_amount:" << this->_amount;

        this->_nbDeposits++;
        this->_amount += deposit;
        _totalNbDeposits += 1;
        _totalAmount += deposit;
        
        std::cout << ";deposit:" << deposit << ";amount:" << this->_amount
                  << ";nb_deposits:" << this->_nbDeposits << std::endl;
    }
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    
    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

int		Account::checkAmount( void ) const
{
    return _amount;
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
              << std::endl;  
}
