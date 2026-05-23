#ifndef H_ACCOUNT_H
#define H_ACCOUNT_H
#include <string>
#include "IPrintable.h"

enum class AccountStatus {Active, Closed, Frozen};

class Account : public IPrintable {
private:
  std::string name;
  int id;
  double balance;
  static constexpr double MIN_DEPOSIT = 20.00;
  static constexpr double MAX_DEPOSIT = 50000.00;
  static constexpr double MIN_WITHDRAWAL = 20.00;
  static constexpr double MAX_WITHDRAWAL = 800.00;
  AccountStatus status {AccountStatus::Active};

public:
  Account();
  Account(const std::string& name, int id, double balance);
  virtual void deposit(double amount);
  virtual void withdraw(double amount) = 0;
  std::string getName() const;
  int getId() const;
  double getBalance() const;
  void feeDeduct(double fee);
  // Getters for Limitations to use in the UI and the derived Accounts
  static double getMinDeposit();
  static double getMaxDeposit();
  static double getMinWithdrawal();
  static double getMaxWithdrawal();
  // Print function
  virtual void print(std::ostream& os) const override;
  // Account status Getters && Setters
  AccountStatus getAccountStatus() const;
  void setAccountStatus(AccountStatus newStatus);
  virtual ~Account() = default;
};


#endif // H_ACCOUNT_H