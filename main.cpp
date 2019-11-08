
#include <iostream>
#include "corsoAlgoritmi.h"
#include "eserciziCorsoAlgoritmi.h"
#include <iostream>
#include <string>

int main()
{
  const int s1 = 3;
  const int s2 = 4;
  const int s3 = 2;

  int seq1[s1] =
  { 1,
    2,
    3 };

  int seq2[s2] =
  { 1,
    2,
    3,
    7};

  std::cout << "lcs_limit: " << esercizi::lcs_limit(seq1, s1, seq2, s2, 6);

  return 0;
}

