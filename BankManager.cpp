#include "BankManager.h"

void BankManager::addAccount(std::unique_ptr<Account> account) {
  bankAccounts.emplace_back(std::move(account));
}

Account* BankManager::findAccount(const int id) {
  for(const auto& account: bankAccounts) {
    if(id == account->getId()) return account.get();
  }
  return nullptr;
}

