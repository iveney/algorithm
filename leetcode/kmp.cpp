#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1st method: from CLRS
// T[i] should be interpreted as the *length* of the proper prefix that matches to
// the proper suffix that ends at i
// Thus, the ending index of this prefix is T[i] - 1
vector<int> compute_partial_match(const string &target) {
  int n = target.size();
  vector<int> T(n);
  if (n == 0) return T;

  int next = 0; // the next character to match for the prefix
  T[0] = 0;     // first char cannot be a proper suffix nor proper prefix
  for (int i = 1; i < n; ++i) {
    // not a match: fall back until match or the 1st char (index = 0)
    while (next > 0 && target[next] != target[i])
      next = T[next];

    // match to the current char of prefix
    if (target[next] == target[i])
      ++next;

    T[i] = next;
  }

  return T;
}

// 2nd method: from wikipedia
vector<int> compute_partial_match_alt(const string &target) {
  int n = target.size();
  vector<int> T(n);
  if (n == 0) return T;

  int next = 0; // the next character to match for the prefix
  T[0] = 0;     // first char cannot be a proper suffix nor proper prefix
  int i = 1;
  while (i < n) {
    if (target[next] == target[i]) {
      // case 1: match the next char in prefix
      ++next;
      T[i] = next;
      ++i;
    }
    else if (next > 0) {
      // case 2: not a match, but we can fall back (until to 1st char)
      next = T[next];
    }
    else {
      // case 3: fall back to 1st char, next == 0 here
      T[i] = 0;
      ++i;
    }
  } // while
  return T;
}

void test_partial_match(vector<string> &target) {
  for (auto t : target) {
    auto T1 = compute_partial_match(t);
    auto T2 = compute_partial_match_alt(t);
    int n = t.size();
    cout << t << '\n';
    for (int i = 0; i < n; ++i) {
      cout << i;
    }
    cout << '\n';
    copy(T1.begin(), T1.end(), 
      ostream_iterator<decltype(T1)::value_type>(cout, ""));
    cout << '\n';
    copy(T2.begin(), T2.end(), 
      ostream_iterator<decltype(T2)::value_type>(cout, ""));
    cout << '\n';
  }
}

int main(int argc, char const *argv[])
{
  vector<string> target {
    "",
    "abababca",
    "ABCDABD",
  };
  return 0;
}