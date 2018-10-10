#include <iostream>
#include <vector>

int main() {
  std::vector<double> temps;
  double temp;

  while(std::cin >> temp) {
    temps.push_back(temp);
    std::cout << temp << "\n";
  }

  return 0;
}
