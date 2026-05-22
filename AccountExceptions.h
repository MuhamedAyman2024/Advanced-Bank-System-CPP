#ifndef H_ACCOUNTEXCEPTION_H
#define H_ACCOUNTEXCEPTION_H
#include <string>
#include <exception>
#include <stdexcept>
#include <format> // C++20

class InvalidDepositException : public std::runtime_error {
private:
  double amount;
  double minDeposit;
public:
  InvalidDepositException(double amount, double minDeposit) 
  : std::runtime_error{std::format("Minimum deposit limit not met. Requested: ${:.2f}, Min required: ${:.2f}", amount, minDeposit)} {}
};

class DepositLimitExceededException : public std::runtime_error {
private:
  double amount;
  double maxDeposit;
public:
  DepositLimitExceededException(double amount, double maxDeposit) 
  : std::runtime_error{std::format("Maximum deposit limit exceeded. Requested: ${:.2f}, Max allowed: ${:.2f}", amount, maxDeposit)} {
  } 
};

class MinimumWithdrawalException : public std::runtime_error {
private:
  double amount;
  double minWithdrawal;
public:
  MinimumWithdrawalException(double amount, double minWithdrawal) 
  : std::runtime_error{std::format("Minimum withdrawal limit not met. Amount requested: ${:.2f}, Min required: ${:.2f}", amount, minWithdrawal)} {
  }
};

class MaximumWithdrawalExceededException : public std::runtime_error {
private:
  double amount;
  double maxWithdrawal;
public:
  MaximumWithdrawalExceededException(double amount, double maxWithdrawal) 
  : std::runtime_error{std::format("Maximum withdrawal limit exceeded. Amount requested: ${:.2f}, Max allowed: ${:.2f}", amount, maxWithdrawal)} {
  }
};

class AccountClosedException : public std::runtime_error {
public:
  AccountClosedException() : std::runtime_error{"Error: Cannot modify or change status. This account is permanently closed."} {}
};

class InvalidAccountStateException : public std::runtime_error {
public:
  InvalidAccountStateException() : std::runtime_error{"Error: Illegal operation. The account is currently in a state that does not allow this action."} {}
};

// SavingsAccount Exceptions
class InsufficientFundException : public std::runtime_error {
private:
  double balance;
  double amount;
  double fee;
public:
  InsufficientFundException(double balance, double amount, double fee) 
  : std::runtime_error{std::format("Error: Insufficient funds. Requested: ${:.2f}, Fee: ${:.2f}, Current Balance: ${:.2f}", amount, fee, balance)} {
  }
};

#endif // H_ACCOUNTEXCEPTION_H