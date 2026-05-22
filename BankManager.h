#ifndef H_BANKMANAGER_H
#define H_BANKMANAGER_H
#include "Account.h"
#include <vector>

class BankManager {
private:
  std::vector<Account*> bankAccounts;
public:
  BankManager() = default;
  void addAccount(Account* account);
  Account* findAccount(const int id);
  ~BankManager();
};

#endif // H_BANKMANAGER_H