#ifndef H_BANKUI_H
#define H_BANKUI_H
#include "BankManager.h"
#include "Account.h"
#include <string>
class BankUI {
private:
  BankManager bankManager;
  void displayMenu();
  void displayAccountTypeMenu();
  void displaySearchMenu();
  std::string readValidString(const std::string& prompt);
  bool isValidName(const std::string& name) const;
  int readValidInt(const std::string& prompt);
  double readValidDouble(const std::string& prompt);
  Account* createAccountUI();
  Account* findAccountUI();

public:
  void run();
};

#endif // H_BANKUI_H