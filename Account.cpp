#include "Account.h"
#include "AccountExceptions.h"
#include <stdexcept>
#include <format>

// Constructors
Account::Account() : name{"Unknown"}, id{0}, balance{0.0} {}
Account::Account(const std::string& name, int id, double balance)
: name{name}, id{id}, balance{balance} {
  if(id < 0)
    throw std::invalid_argument(std::format("Error: ID [{}]. not valid", id));
  if(balance < MIN_DEPOSIT)
    throw std::invalid_argument(std::format("Error: balance ${:.2f}. Initial balance must be at least ${:.2f}", balance, MIN_DEPOSIT));
  if(balance > MAX_DEPOSIT)
  throw std::invalid_argument(std::format("Error: balance ${:.2f} Initial balance must be less than ${:.2f}", balance, MAX_DEPOSIT));
}

// Deposit && Withdraw
void Account::deposit(double amount) {
  if(status == AccountStatus::Frozen || status == AccountStatus::Closed)
    throw InvalidAccountStateException();
  if(amount < MIN_DEPOSIT)
    throw InvalidDepositException(amount, MIN_DEPOSIT);
  if (amount > MAX_DEPOSIT)
    throw DepositLimitExceededException(amount, MAX_DEPOSIT);
  balance += amount;
}
void Account::withdraw(double amount) {
  if(status == AccountStatus::Frozen || status == AccountStatus::Closed)
    throw InvalidAccountStateException();
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

// Force deduct for SavingsAccount,..etc
void Account::feeDeduct(double fee) {
  balance -= fee;
}

// Getters for Limitations to use in the UI
double Account::getMinDeposit() {
  return MIN_DEPOSIT;
}
double Account::getMaxDeposit() {
  return MAX_DEPOSIT;
}
double Account::getMinWithdrawal() {
  return MIN_WITHDRAWAL;
}
double Account::getMaxWithdrawal() {
  return MAX_WITHDRAWAL;
}

//Getters && Setters for AccountStatus
AccountStatus Account::getAccountStatus() const {
  return status;
}
void Account::setAccountStatus(AccountStatus newStatus) {
  if(status == AccountStatus::Closed)
    throw AccountClosedException();
  status = newStatus;
}

// Print function from Interface
void Account::print(std::ostream& os) const {
  os << "[Account name: " << name << " | ID: " << id << " | Balance: $" << balance << "]";
}