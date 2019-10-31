#include "corsoAlgoritmi.h"
#include <iostream>
#include <list>

int lis(int sequence[], int size){

  // support array, at pos i will hold longest lis including i
  int l[size]; 
  int max_tot = 1;
  l[0] = 1;

  for(int i = 1; i < size; ++i)
    {
      int max = 0;      
      for(int j = 0; j < i; ++j)
	{
	  if(sequence[j] < sequence[i] && l[j] > max)
	    {
	      max = l[j];
	      l[i] = 1 + max;
	    }
	  else
	    l[i] = max;
	}
      
      if(l[i] > max_tot)
	max_tot = l[i];
    }

  return max_tot;

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

    int rows = size1+1;
    int columns = size2+1;
    int matrix[rows][columns];

    for(int i = 0; i < rows; ++i)
      for(int j = 0; j < columns; ++j)
	matrix[i][j] = 0;

    return 0;
}
  
