#include "BankManager.h"

void BankManager::addAccount(Account* account) {
  bankAccounts.emplace_back(account);
}

Account* BankManager::findAccount(const int id) {
  for(auto account: bankAccounts) {
    if(id == account->getId()) return account;
  }
  return nullptr;
}

BankManager::~BankManager() {
  for(auto account: bankAccounts) delete account;
  bankAccounts.clear();
}