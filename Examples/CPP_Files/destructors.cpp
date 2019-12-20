#include <iostream>

class GroceryCart {
  private:
    double* prices_;
    int current_index_;

    // this is shown as an inline member function for simplicity
    // but should be written as a regular member function
    double sum_of_prices(int index) {
      if(index == 1)
        return prices_[0];
      else
        return prices_[index-1] + sum_of_prices(index -1);
    }

  public:
    GroceryCart() : GroceryCart(10) { }
    GroceryCart(int max_items) : current_index_(0), prices_(new double[max_items]) { }
    void add_price(double price) {
      prices_[current_index_++] = price;
    }
    ~GroceryCart() {
      delete[] prices_;
      prices_ = nullptr;
    }
    void show_total() {
      std::cout << "# of items: " << current_index_ << "\n";
      std::cout << "Total price: " << sum_of_prices(current_index_)
                << "\n";
    }
};


int main() {
  GroceryCart tuffix_mart(5);

  tuffix_mart.add_price(3.89);
  tuffix_mart.add_price(2.55);
  tuffix_mart.add_price(5.12);
  tuffix_mart.add_price(1.89);
  tuffix_mart.add_price(0.58);

  tuffix_mart.show_total();
  return 0;
}
