#include "eserciziCorsoAlgoritmi.h"
#include <iostream>
#include <string>

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

  bool interleaving(std::string x, std::string y, std::string w){

    // X is on the row
    int rows = x.length() + 1;
    // Y is on the column
    int columns = y.length() + 1;
    
    bool matrix[rows][columns];
    matrix[0][0] = true;

    
    for(int i = 1; i < rows; ++i)
      matrix[i][0] = (x.at(i-1) == w.at(i-1));
      
    for(int j = 1; j < columns; ++j)
            matrix[0][j] = (y.at(j-1) == w.at(j-1));

    for(int i = 1; i < rows; ++i)
      for(int j = 1; j < columns; ++j)
	if(x.at(i-1) == w.at(i + j -1))
	  matrix[i][j] = matrix[i-1][j];
	else if(y.at(j-1) == w.at(i + j - 1))
	  matrix[i][j] = matrix[i][j-1];
	else
	  matrix[i][j] = false;
      
    

    std::cout << std::endl;
    for(int i = 0; i < rows; ++i){
      for(int j = 0; j < columns; ++j)
	std::cout << matrix[i][j] << " ";
      std::cout << std::endl;
    }
	
    return matrix[x.length()][y.length()];
    
  }

  int lcs_3(int seq1[], int size1, int seq2[], int size2, int seq3[], int size3){

    const int d1 = size1 + 1;
    const int d2 = size2 + 1;
    const int d3 = size3 + 1;

    // 3 dimensional support structure
    int support[d1][d2][d3];

    // initialize
    for(int i = 0; i < d1; ++i)
      support[i][0][0] = 0;
    for(int i = 0; i < d2; ++i)
      support[0][i][0] = 0;
    for(int i = 0; i < d3; ++i)
      support[0][0][1] = 0;

    for(int i = 1; i < d1; ++i)
      for(int j = 1; j < d2; ++j)
	for(int k = 1; k < d3; ++k)
	  if(seq1[i-1] == seq2[j-1] && seq2[j-1] == seq3[k-1])
	    support[i][j][k] = 1 + support[i-1][j-1][k-1];
	  else
	    support[i][j][k] = std::max(std::max(support[i-1][j][k], support[i][j-1][k]),  support[i][j][k-1]);

    return support[d1-1][d2-1][d3-1];
   
  }

}
