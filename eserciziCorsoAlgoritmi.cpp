#include "eserciziCorsoAlgoritmi.h"
#include <iostream>

int hateville(int donation[], int size){

  //fill previous compatible array
  int p[size + 1]; // p[i] is the max compatible house before i
  p[0] = 0;
  p[1] = donation[0];

  for (int i = 0; i < size; ++i) {
    std::cout << donation[i] << " ";
  }

  std::cout << std::endl;
  
  for(int i = 2; i <= size; ++i){
    p[i] = std::max(p[i-1], p[i-2] + donation[i-1]);
  }

  for (auto x : p) {std::cout << x << " ";}
  std::cout << std::endl;
  return p[size];
}

void print_hateville_solution(int set[], int size){
  if(size == 0)
    std::cout << "empty set" << std::endl;
  else if (size == 1)
    std::cout << set[size] << " ";

}
