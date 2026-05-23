#include "BankUI.h"
#include "Account.h"
#include "SavingsAccount.h"
#include <iostream>
#include <limits>
#include <cctype>

void BankUI::displayMenu() {
  std::cout << "\n=======================================\n";
  std::cout << "        Bank Management System        \n";
  std::cout << "=======================================\n";
  std::cout << "[1] Open New Account\n";
  std::cout << "[2] Find Existing Account\n";
  std::cout << "[0] Exit Program\n";
}

void BankUI::displayAccountTypeMenu() {
  std::cout << "\n================================\n"
            << "        Choose Account Type       \n"
            << "================================\n";
  std::cout << "[1] Savings Account\n"
            << "[2] Checking Account\n"
            << "[0] Back to main menu\n";
}

void BankUI::displaySearchMenu() {
  std::cout << "\n[1] Find account via ID" << std::endl;
  std::cout << "[0] Back to main menu" << std::endl;
}

bool BankUI::isValidName(const std::string& name) const {
  for(char c: name) {
    if(!std::isalpha(c) && !std::isspace(c))
      return false;
  }
  return true;
}

std::string BankUI::readValidString(const std::string& prompt) {
  std::string value;
  while(true) {
    std::cout << prompt;
    std::getline(std::cin >> std::ws, value);
    if(value.empty() || !isValidName(value))
      std::cerr << "Name \"" << value << "\" is not valid\n";
    else {
      break;
    }
  }
  return value;
}

double BankUI::readValidDouble(const std::string& prompt) {
  double value{};
  while(true) {
    std::cout << prompt;
    std::cin >> value;
    if(std::cin.fail()) {
      std::cout << "Invalid number try again\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else if(std::cin.peek() != '\n') {
      std::cout << "Invalid number try again\n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }
  return value;
}

int BankUI::readValidInt(const std::string& prompt) {
  int value{};
  while(true)
  {
    std::cout << prompt;
    std::cin >> value;
    if(std::cin.fail()) {
      std::cerr << "Invalid number try again\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else if(std::cin.peek() != '\n') {
      std::cerr << "Invalid number try again\n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }
  return value;
}

Account* BankUI::createAccountUI() {
  displayAccountTypeMenu();
  int accountTypeChoice = readValidInt("Enter choice: ");
  switch (accountTypeChoice)
  {
  case 1:
  {
    std::string name = readValidString("Enter name (Letters & spaces only): ");
    int id = readValidInt("Enter ID (Positive number > 0): ");
    double balance = readValidDouble("Initial balance ($20 - $50,000): ");
    double interestRate = readValidDouble("Enter Interest rate (1.0% - 5.0%): ");
    return new SavingsAccount{name, id, balance, interestRate};
  }
  case 0:
    break;
  default:
    std::cout << "Invalid choice try again." << std::endl;
    break;
  }
  return nullptr;
}

Account* BankUI::findAccountUI() {
  displaySearchMenu();
  int userChoice{};
  do
  {
    userChoice = readValidInt("Enter choice: ");
    switch (userChoice)
    {
    case 1:
    {
      int userID = readValidInt("Enter account ID: ");
      Account* accountFound = bankManager.findAccount(userID);
      if(accountFound)
        return accountFound;
      else {
        std::cout << "Account does not exist." << std::endl;
        displaySearchMenu();
      }
      break;
    }
    case 0:
      std::cout << "Search cancelled. Returning to main menu..." << std::endl;
      break;
    default:
      std::cout << "Invalid choice try again." << std::endl;
      continue;
    }
  } while (userChoice != 0);
  return nullptr;
}

void BankUI::run() {
  int generalChoice{0};
  do
  {
    displayMenu();
    generalChoice = readValidInt("Enter choice: ");

    switch (generalChoice) {
      case 1:
      {
        try
        {
          Account* newAccount = createAccountUI();
          if(newAccount != nullptr) {
            bankManager.addAccount(newAccount);
            std::cout << "Account: " << *newAccount 
                      << " Created Successfully!" 
                      << std::endl;
          } else {
            std::cout << "Account creation cancelled." << std::endl;
          }

        }
        catch(const std::exception& e)
        {
          std::cerr << e.what() << '\n';
        }
        break;
      }
      case 2:
      {
        Account* accountFound = findAccountUI();
        if(accountFound != nullptr)
          std::cout << "Account " << *accountFound << " Found Successfully!" << std::endl;
        break;
      }
      default:
        break;
    }
  } while (generalChoice != 0);
  
}