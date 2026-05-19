#ifndef H_ACCOUNTEXCEPTION_H
#define H_ACCOUNTEXCEPTION_H
#include <string>
#include <exception>
#include <sstream>
#include <iomanip>

class InvalidDepositException : public std::exception {
public:
  std::string message;
  double amount;
  double minDeposit;
  
  InvalidDepositException(double amount, double minDeposit): amount{amount}, minDeposit{minDeposit} {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    stream << "Minimum deposit limit not met. Requested: $" << amount << ", Min required: $" << minDeposit;
    message = stream.str();
  }
  virtual const char* what() const noexcept override {
    return message.c_str();
  }
};

class DepositLimitExceededException : public std::exception {
public:
  std::string message;
  double amount;
  double maxDeposit;

  DepositLimitExceededException(double amount, double maxDeposit) : amount{amount}, maxDeposit{maxDeposit} {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    stream << "Maximum deposit limit exceeded. Requested: $" << amount << ", Max allowed: $" << maxDeposit;
    message = stream.str();
  } 
  virtual const char* what() const noexcept override {
    return message.c_str();
  }
};

class MinimumWithdrawalException : public std::exception {
public:
  std::string message;
  double amount;
  double minWithdrawal;

  MinimumWithdrawalException(double amount, double minWithdrawal) : amount{amount}, minWithdrawal{minWithdrawal} {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    stream << "Minimum withdrawal limit not met. Amount requested: $" << amount << ", Min required: $" << minWithdrawal;
    message = stream.str();
  }
  virtual const char* what() const noexcept override {
    return message.c_str();
  }
};

class MaximumWithdrawalExceededException : public std::exception {
public:
  std::string message;
  double amount;
  double maxWithdrawal;
  
  MaximumWithdrawalExceededException(double amount, double maxWithdrawal) : amount{amount}, maxWithdrawal{maxWithdrawal} {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    stream << "Maximum withdrawal limit exceeded. Amount requested: $" << amount << ", Max allowed: $" << maxWithdrawal;
    message = stream.str();
  }
  virtual const char* what() const noexcept override {
    return message.c_str();
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

#endif // H_ACCOUNTEXCEPTION_H