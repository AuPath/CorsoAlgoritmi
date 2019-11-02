#ifndef corsoAlgoritmi_H
#define corsoAlgoritmi_H

// contains all algorithms show in class (Zandron)
namespace corso{

  // longest increasing subsequence
  int lis(int sequence[], int size);

  // longest common subsequence
  int lcs(int seq1[], int size1, int seq2[], int size2);

  // growing longest common subsequence
  int glcs(int seq1[], int size1, int seq2[], int size2);

  // knapsack algorithm
  int knapsack(int sackCapacity, char objects[], int oSize, int values[], int vSize, int weigth[], int wSize);
  
}
#endif
