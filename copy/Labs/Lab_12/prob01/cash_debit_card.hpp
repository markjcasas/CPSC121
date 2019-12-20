#include <iomanip>
#include <iostream>
#ifndef CASH_DEBIT_CARD
#define CASH_DEBIT_CARD
class CashCard {
  double balance_;
  std::string name_;
protected:
  void charge_balance(double amount_) { balance_ -= amount_; }
public:
  CashCard() : CashCard(100, "Alex Amarnani") {}
  CashCard(double bal, std::string nm) : balance_(bal), name_(nm) {}
  void set_name(const std::string &name) { name_ = name; }
  void set_balance(double balance) { balance_ = balance; }
  std::string name() { return name_; }
  double balance() { return balance_; }
  void charge(double amt);
};
class DebitCard : public CashCard {
public:
  DebitCard() : CashCard(100, "Sidney Lee") {}
  DebitCard(double debit_bal, std::string debit_nm) : CashCard(debit_bal, debit_nm) {}
  void charge(double debit_amt);
};
#endif
