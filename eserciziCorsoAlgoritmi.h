#ifndef eserciziCorsoAlgoritmi_H
#define eserciziCorsoAlgoritmi_H

#include <string>

namespace esercizi{

  // solution to the hateville problem
  int hateville(int donation[], int size);

  // alternating lcs (alternating between even and odd)
  int lcs_a(int seq1[], int size1, int seq2[], int size2);

  // interleaving
  bool interleaving(std::string x, std::string y, std::string w);

  // LCS between 3 sequences
  int lcs_3(int seq1[], int size1, int seq2[], int size2, int seq3[], int size3);

  int lcs_limit(int seq1[], int size1, int seq2[], int size2, unsigned int limit);
}
#endif
  
