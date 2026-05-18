#include "Account.h"
#include "AccountExceptions.h"

// Constructors
Account::Account() : name{"Unknown"}, id{0}, balance{0.0} {}
Account::Account(const std::string& name, int id, double balance)
: name{name}, id{id}, balance{balance} {}

// Deposit && Withdraw
void Account::deposit(double amount) {
  if(amount < MIN_DEPOSIT)
    throw InvalidDepositException(amount, MIN_DEPOSIT);
  if (amount > MAX_DEPOSIT)
    throw DepositLimitExceededException(amount, MAX_DEPOSIT);
  balance += amount;
}
void Account::withdraw(double amount) {
  if(amount < MIN_WITHDRAWAL)
    throw MinimumWithdrawalException(amount, MIN_WITHDRAWAL);
  if(amount > MAX_WITHDRAWAL) 
    throw MaximumWithdrawalExceededException(amount, MAX_WITHDRAWAL);
  balance -= amount;
}

// Getters
std::string Account::getName() const {
  return name;
}
int Account::getId() const {
  return id;
}
double Account::getBalance() const {
  return balance;
}

// Getters for Limitations to use in the UI
double Account::getMinDeposit() const {
  return MIN_DEPOSIT;
}
double Account::getMaxDeposit() const {
  return MAX_DEPOSIT;
}
double Account::getMinWithdrawal() const {
  return MIN_WITHDRAWAL;
}
double Account::getMaxWithdrawal() const {
  return MAX_WITHDRAWAL;
}

// Print function from Interface
void Account::print(std::ostream& os) const {
  os << "Account name: " << name << " | ID: " << id << " | Balance: " << balance;
}