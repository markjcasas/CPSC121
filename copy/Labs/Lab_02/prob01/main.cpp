//test your code at http://cpp.sh/
#include <iostream>
#include <iomanip>
int main()
{
  float n; //meal cost in dollar amount
  float g; //tip or gratuity percentage expressed as a number

  std::cout << "Please input meal cost: ";
  std::cin >> n;




  std::cout << "Please input tip percentage: ";
  std::cin >> g;
  std::cout << '\n';




  
 const float r = 0.075; //rate of tax
 const float q = .01;





  std::cout << "Restaurant Bill" << '\n';
  std::cout << "====================" << '\n';
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  std::cout << "Subtotal: $";
  std::cout << n << '\n';
  std::cout << "Taxes: $";
  std::cout << r*n << '\n';
  std::cout << "Tip: $";
  std::cout << q*g*n << '\n';
  std::cout << "====================" << '\n';
  std::cout << "Total: $";
  std::cout << n+r*n+q*g*n << '\n';




  return 0;
}
