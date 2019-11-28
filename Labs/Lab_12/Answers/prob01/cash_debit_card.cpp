#include "cash_debit_card.hpp"
#include <iomanip>
#include <iostream>
void CashCard::charge(double amt) {
  if (balance_ < amt) {
    std::cout << "Insufficient funds" << '\n';
  } else {
    charge_balance(amt);
  }
}

void DebitCard::charge(double debit_amt) {
  if (balance() < debit_amt) {
    charge_balance(debit_amt + 30);
    std::cout << "Overdraft Fee of $30.00 Incurred" << '\n';
  } else {
    charge_balance(debit_amt);
  }
}
