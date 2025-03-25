
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit );
Account::~Account( void );


int	Account::getNbAccounts( void );
int	Account::getTotalAmount( void );
int	Account::getNbDeposits( void );
int	Account::getNbWithdrawals( void );
void	Account::displayAccountsInfos( void );


void	Account::makeDeposit( int deposit );
bool	Account::makeWithdrawal( int withdrawal );
int		Account::checkAmount( void ) const;
void	Account::displayStatus( void ) const;