#include "SavingsAccount.h"
#include "AccountExceptions.h"
#include <stdexcept>
#include <format>
SavingsAccount::SavingsAccount() : Account{}, interestRate{0.0} {}

// Delegated the constructor of Account to construct the part of the base in the derived SavingsAccount
SavingsAccount::SavingsAccount(const std::string& name, int id, double balance, double interestRate) : Account{name, id, balance}, interestRate{interestRate} {
  if(interestRate < MIN_INIT_RATE || interestRate > MAX_INIT_RATE) {
    throw std::invalid_argument(std::format("Error: invalid interest rate ({}%). It must be greater than 0 and less than 5.", interestRate));
  }
}

// Deposit && Withdraw Methods "SavingsAccount"
void SavingsAccount::deposit(double amount) {
  amount += amount * (interestRate / 100);
  Account::deposit(amount);
}
// Specified behaviors for SavingsAccount's Withdraw
void SavingsAccount::withdraw(double amount) {
  if(getBalance() < (amount + FEE))
    throw InsufficientFundException(getBalance(), amount, FEE);
  Account::withdraw(amount);
  feeDeduct(FEE);
}

// Print Fucntion Pure Virtual must implement here
void SavingsAccount::print(std::ostream& os) const {
  Account::print(os);
  os << " | [" << "Account Type: Savings, Interest Rate: " << interestRate 
        << "%]";
} 