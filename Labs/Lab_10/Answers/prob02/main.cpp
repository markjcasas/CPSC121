#include "list.hpp"
#include <iostream>

int main() {
  // Create an instance of the ShoppingList object
  ShoppingList shopping;
  // Call the shopping.add_item member function to shopping.add the 6 items into the shopping list
  shopping.add_item("Milk");
  shopping.add_item("Eggs");
  shopping.add_item("Flour");
  shopping.add_item("Sugar");
  shopping.add_item("Cocoa Powder");
  shopping.add_item("Vanilla");
  // Call the print_list member function to display the list
  shopping.print_list();
  return 0;
}
