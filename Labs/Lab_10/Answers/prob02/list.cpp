#include "list.hpp"
#include <iostream>

int ShoppingList::num_items() {
  return num_items_;
}
int ShoppingList::list_size() {
  return list_size_;
}
void ShoppingList::add_item(std::string additem) {
  if (num_items_ < list_size_ ) {
    list_[num_items_] = additem;
    num_items_++;
  } else {
    std::cout << "Error! Shopping List full!" << '\n';
  }
}
void ShoppingList::remove_last() {
  list_[num_items_] = " ";
  num_items_--;
}
