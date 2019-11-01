#include "eserciziCorsoAlgoritmi.h"
#include <iostream>

namespace esercizi {

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

int lcs_a(int seq1[], int size1, int seq2[], int size2){

  int columns = size1;
  int rows = size2;
  int matrix[rows][columns];
  int max_length = 0;

  for(int i=0; i < rows; ++i)
    for(int j=0; j < columns; ++j)
      {
	if(seq1[j] != seq2[i])
	  matrix[i][j] = 0;
	else
	  {
	    int max = 0;
	    for(int a = 0; a <= i-1; ++a)
	      for(int b = 0; b <= j-1; ++b)
		if(matrix[a][b] > max && (seq1[a] % 2 != seq1[i] % 2))
		  max = matrix[a][b];

	    matrix[i][j] = 1 + max;
	    if(matrix[i][j] > max_length)
	      max_length = matrix[i][j];
	  }
      }

  std::cout << std::endl;
  for(int i=0; i<rows; ++i)
    {
      for(int j = 0; j < rows; ++j)
	std::cout << matrix[i][j] << " ";
      std::cout << std::endl;
    }
  return max_length;  
}

}
