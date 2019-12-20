#include <iostream>
#ifndef LIST_HPP
#define LIST_HPP
class ShoppingList {
  std::string* list_;
  int num_items_;
  int list_size_;
public:
  ShoppingList() : ShoppingList(10)  {}
  ShoppingList(int SIZE) : list_(new std::string[SIZE]), num_items_(0), list_size_(SIZE) {}
  ~ShoppingList() {
    delete[] list_;
    list_ = nullptr;
  }
  int num_items();
  int list_size();
  void add_item(std::string additem);
  void remove_last();
  void print_list() {
    std::cout << "Shopping List:" << '\n';
    for (int i = 0; i < num_items_; i++) {
      std::cout << i + 1 << ") " << list_[i] << '\n';
    }
  }
};
#endif
