#ifndef H_ACCOUNT_H
#define H_ACCOUNT_H
#include <string>
#include "IPrintable.h"
class Account : public IPrintable {
private:
  std::string name;
  int id;
  double balance;
  static constexpr double MIN_DEPOSIT = 20.00;
  static constexpr double MAX_DEPOSIT = 50000.00;
  static constexpr double MIN_WITHDRAWAL = 20.00;
  static constexpr double MAX_WITHDRAWAL = 800.00;
public:
  Account();
  Account(const std::string& name, int id, double balance);
  virtual void deposit(double amount);
  virtual void withdraw(double amount) = 0;
  std::string getName() const;
  int getId() const;
  double getBalance() const;
  // Getters for Limitations to use in the UI
  double getMinDeposit() const;
  double getMaxDeposit() const;
  double getMinWithdrawal() const;
  double getMaxWithdrawal() const;
  virtual void print(std::ostream& os) const override;
  virtual ~Account() = default;
};


#endif // H_ACCOUNT_H