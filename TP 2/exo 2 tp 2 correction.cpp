#include <iostream>
#include <vector>
#include <cmath>

int main(int, char**)
{
  srand(time(NULL));

  std::vector<float> data(20);

  // Q1
  for(auto& d : data)
  {
      float r = std::rand();
      d = 1 + (r/RAND_MAX)*19;
  }

  // Q2
  for(auto e: data)
    std::cout << e << " ";
  std::cout << "\n";

  // Q3
  std::size_t idx = 0;
  std::vector<std::size_t> index;

  for(auto const& e : data)
  {
    if(e > 15)
      index.push_back(idx);
    idx++;
  }

  // Q4
  for(auto e: index)
    std::cout << e << " ";
  std::cout << "\n";

  return 0;
}