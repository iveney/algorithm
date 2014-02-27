// Idea: for each position, randomly select a remaining card to put in
// Proof:
// we want to prove for every card, the prob at every slot is the same: 1/n
// say n cards, clearly in the 1st position every card has 1/n prob to get in
// now say we put some card in, then there are (n-1) cards left
// for any remaining card x, the prob of staying at the 2nd slot is:
// P(x not chosen in 1st slot) * P(x chosen in 2nd slot) = (n-1) / n * 1 / (n-1) = 1/n
// we can prove by induction, for kth slot, the prob of remaining cards will be
// (n-1) / n * (n-2) / (n-1) * ... * (n-k) / (n-k+1) * 1 / (n-k) = 1/n

#include <cstdlib>
#include <iostream>
#include <unordered_map>
using namespace std;

void random_shuffle(string& deck) {
  int n = deck.size();
  for (int i = n-1; i >= 0; --i) {
    int r = rand() % n;
    swap(deck[i], deck[r]);
  }
}

int main(int argc, char const *argv[])
{
  // initialize the deck
  int n = 3;
  string deck(n, 'A');
  for (int i = 0; i < n; ++i) {
    deck[i] = 'A' + i;
  }

  unordered_map<string, int> stat;
  int N = 1000000;
  for (int i = 0; i < N; ++i) {
    random_shuffle(deck);
    ++stat[deck];
  }

  for (auto kv : stat) {
    printf("%s: %3d (%lf%%)\n", kv.first.c_str(), kv.second, 100.0 * kv.second / N);
  }

  return 0;
}