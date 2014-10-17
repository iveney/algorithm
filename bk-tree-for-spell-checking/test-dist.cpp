#include <iostream>
using namespace std;

#include "levenshtein_distance.h"

int main(int argc, char const *argv[])
{
  cout << levenshtein_distance("wat", "cook") << endl;
  cout << levenshtein_distance("wat", "book") << endl;
  cout << levenshtein_distance("wat", "books") << endl;
  cout << levenshtein_distance("wat", "what") << endl;
  cout << levenshtein_distance("wat", "water") << endl;
  cout << levenshtein_distance("cook", "book") << endl;
  cout << levenshtein_distance("cook", "books") << endl;
  cout << levenshtein_distance("what", "water") << endl;
  return 0;
}