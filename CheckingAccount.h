#ifndef H_CHECKINGACCOUNT_H
#define H_CHECKINGACCOUNT_H

#include "Account.h"
#include <ostream>
#include <string>


class CheckingAccount : public Account {
private:
  static constexpr double FLAT_FEE = 1.50;
public:
  CheckingAccount() = default;
  CheckingAccount(const std::string& name, int id, double balance);
  virtual void withdraw(double amount) override;
  virtual void print(std::ostream& os) const override;
  virtual ~CheckingAccount() = default;
};

#endif // H_CHECKINGACCOUNT_H