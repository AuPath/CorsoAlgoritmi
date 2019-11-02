#include "corsoAlgoritmi.h"
#include <iostream>
#include <list>

namespace corso{

int lis(int sequence[], int size){

  // support array, at pos i will hold longest lis including i
  int l[size]; 
  int max_length = 1;
  l[0] = 1;

  for(int i = 1; i < size; ++i)
    {
      int max = 0;
      for(int j = 0; j <= i-1; ++j)
	if(sequence[i] > sequence[j] && l[j] > max)
	  max = l[j];

      l[i] = 1 + max;
      if(l[i] > max_length)
	max_length = l[i];
    }
  
  return max_length;
}

int lcs(int seq1[], int size1, int seq2[], int size2){
  
  int rows = size1+1;
  int columns = size2+1;
  int matrix[rows][columns];

  //initialize matrix
  for(int i=0; i < rows; ++i)
    for(int j= 0; j < columns; ++j)
      matrix[i][j] = 0;

  for (int i = 1; i < rows; ++i)
    for (int j = 1; j < columns; ++j){
      if(seq1[i-1] == seq2[j-1])
	matrix[i][j] = matrix[i-1][j-1] + 1;
      else if (matrix[i-1][j] > matrix[i][j-1])
	matrix[i][j] = matrix[i-1][j];
      else
	matrix[i][j] = matrix[i][j-1];
    }
     
  return matrix[rows-1][columns-1];
}

int glcs(int seq1[], int size1, int seq2[], int size2){

  int columns = size1; // first string at columns
  int rows = size2; // second string at rows

  // at position i,j has the glcs of seq1 up to j and seq2 up to i
  int matrix[rows][columns];
  int max_length = 0;
  
  for(int i = 0; i < rows; ++i)
    for(int j = 0; j < columns; ++j)
      {
	if(seq1[j] != seq2[i])
	  matrix[i][j] = 0;
	else
	  {
	    int max = 0;
	    for(int a = 0; a <= i-1; ++a)
	      for(int b = 0; b <= j-1; ++b)
		if(matrix[a][b] > max && seq2[a] < seq2[i])
		  max = matrix[a][b];

	    matrix[i][j] = max + 1;
	    
	    if(matrix[i][j] > max_length)
	      max_length = matrix[i][j];
	  }	
      }

  std::cout << std::endl;
  for(int i = 0; i < rows; ++i)
    {
      for(int j = 0; j < columns; ++j)
	std::cout << matrix[i][j] << " ";
      std::cout << std::endl;
    }
  
  return max_length;
}

}
  
