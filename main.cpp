#include <iostream>
#include "corsoAlgoritmi.h"


int main()
{
  const int size1 = 5;
  int array1[size1] = {1,2,44,40,45};
  int num = lis(array1, size1);
  std::cout << "lis: " << num << std::endl;
  
  return 0;
}


