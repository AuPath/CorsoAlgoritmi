
#include <iostream>
#include "corsoAlgoritmi.h"
#include "eserciziCorsoAlgoritmi.h"
#include <iostream>

int main()
{
  const int sackCapacity = 11;
  const int oSize = 5;
  int values[oSize] = {1,6,28,22,18};
  int weight[oSize] = {1,2,7,6,5};
    
  int knapSolution =
      corso::knapsack(sackCapacity, nullptr, oSize, values
		      , oSize, weight, oSize);

  std::cout << "solution to knapsack: " << knapSolution << std::endl;

          return 0;
}

