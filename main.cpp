#include <iostream>
#include "corsoAlgoritmi.h"

int main()
{
  const int size1 = 5;
  int array1[size1] = {6,7,4,2,3};

  int maxD = hateville(array1, size1);
  std::cout << "max donation: " << maxD << std::endl;  
  
  return 0;
}


