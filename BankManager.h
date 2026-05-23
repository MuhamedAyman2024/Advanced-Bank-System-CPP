#ifndef H_BANKMANAGER_H
#define H_BANKMANAGER_H
#include "Account.h"
#include <vector>
#include <memory>

class BankManager {
private:
  std::vector<std::unique_ptr<Account>> bankAccounts;
public:
  BankManager() = default;
  void addAccount(std::unique_ptr<Account> account);
  Account* findAccount(const int id);
  ~BankManager() = default;
};

#endif // H_BANKMANAGER_H