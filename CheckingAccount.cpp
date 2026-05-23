#include "CheckingAccount.h"
#include "Account.h"
#include "AccountExceptions.h"

CheckingAccount::CheckingAccount(const std::string& name, int id, double balance)
: Account{name, id, balance} {}


void CheckingAccount::withdraw(double amount) {
  // 500 balance
  // case 100 + 1.50 = 398.5
  // case 
  if((amount + FLAT_FEE) > getBalance())
    throw InsufficientFundException(getBalance(), amount, FLAT_FEE);
  Account::withdraw(amount);
  Account::feeDeduct(FLAT_FEE);
}

void CheckingAccount::print(std::ostream& os) const {
  Account::print(os);
  os << " | [" << "Account Type: Checking, Flat Fee: $" << FLAT_FEE << "]";
}