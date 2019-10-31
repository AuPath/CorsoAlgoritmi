#include <iostream>
#include "corsoAlgoritmi.h"
#include <iostream>

int main()
{
  const int size1 = 5;
  int array1[size1] = {1,2,3,4,5};


  const int size2 = 5;
  int array2[size2] = {1,2, 3, 4, 5};
  
  std::cout << "lcs: " << lcs(array1,size1,array2,size2) << std::endl;

  return 0;
}

