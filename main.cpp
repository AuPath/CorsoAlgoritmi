#include <iostream>
#include "corsoAlgoritmi.h"
#include "eserciziCorsoAlgoritmi.h"
#include <iostream>

int main()
{
  const int size1 = 5;
  int array1[size1] = {5,4,3,2,1};


  const int size2 = 5;
  int array2[size2] = {2,3,4,5,6};
    
  std::cout << "LIS: " << corso::lis(array1, size1) << std::endl;
  
  return 0;
}

