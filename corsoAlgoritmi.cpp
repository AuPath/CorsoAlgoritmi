#include "corsoAlgoritmi.h"
#include <iostream>
#include <list>

int lis(int sequence[], int size){
  int l[size];
  std::list<int> p;
  for (int i = 0; i < size; ++i) {
    l[i] = 0;
  }
  
  l[1] = 1;
  
  int maxTot = 0;
  
  for (int i = 1; i < size; i++) {
    int max = 0;
    for (int j = 0; j <= i-1; j++) {
      if(sequence[j]<sequence[i] && l[j] > max){
	max = l[j];
	l[i] = max + 1;
      }      
    }

    if(l[i] > maxTot){
      maxTot = l[i];
      p.push_back(sequence[i]);
    }

  }

  std::cout << "LIS: ";
  for(auto x: p) {std::cout << x << " ";}
  std::cout << std::endl;
  return maxTot;

}

int lcs(int seq1[], int size1, int seq2[], int size2){

  int rows = size1+1;
  int columns = size2+1;
  int matrix[rows][columns];

  std::cout << "columns: " << columns << std::endl;
  std::cout << "rows: " << rows << std::endl;

  for(int i=0; i < rows; ++i)
    for(int j= 0; j < columns; ++j)
      matrix[i][j] = 0;
  
  std::cout <<std::endl << "after: " << std::endl << std::endl;

  for (int i = 1; i < rows; ++i)
    for (int j = 1; j < columns; ++j){
      if(seq1[i-1] == seq2[j-1])
	matrix[i][j] = matrix[i-1][j-1] + 1;
      else if (matrix[i-1][j] > matrix[i][j-1])
	matrix[i][j] = matrix[i-1][j];
      else
	matrix[i][j] = matrix[i][j-1];
    }
  
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < columns; ++j)
      std::cout << matrix[i][j] << " ";
    std::cout << std::endl;
  }
  
  return matrix[rows-1][columns-1];

}

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

  
