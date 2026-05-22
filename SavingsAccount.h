#ifndef H_SAVINGSACCOUNT_H
#define H_SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount : public Account {
private:
  double interestRate;
  static constexpr double FEE = 2.0;
  static constexpr double MAX_INIT_RATE = 5.0;
  static constexpr double MIN_INIT_RATE = 1.0;
public:
  SavingsAccount();
  SavingsAccount(std::string name, int id, double balance, double interestRate);
  virtual void deposit(double amount) override;
  virtual void withdraw(double amount) override;
  virtual void print(std::ostream& os) const override;
  virtual ~SavingsAccount() = default;
};


#endif // H_SAVINGSACCOUNT_H