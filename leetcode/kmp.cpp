#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1st method: from CLRS. Looks clearer for me.
// partial[i] should be interpreted as the *length* of the proper prefix that
// matches to the proper suffix that ends at i Thus, the ending index of this
// prefix is (partial[i] - 1)
vector<int> compute_partial_match_clrs(const string &pattern) {
  int n = pattern.size();
  vector<int> partial(n);
  if (n == 0) return partial;

  int next = 0; // the next character to match for the prefix
  partial[0] = 0;     // first char cannot be a proper suffix nor proper prefix
  for (int i = 1; i < n; ++i) {
    // not a match: fall back until match or the 1st char (index = 0)
    while (next > 0 && pattern[next] != pattern[i])
      next = partial[next-1];

    // match to the current char of prefix
    if (pattern[next] == pattern[i])
      ++next;

    partial[i] = next;
  }

  return partial;
}

// 2nd method: from wikipedia
vector<int> compute_partial_match_wiki(const string &pattern) {
  int n = pattern.size();
  vector<int> partial(n);
  if (n == 0) return partial;

  int next = 0; // the next character to match for the prefix
  partial[0] = 0;     // first char cannot be a proper suffix nor proper prefix
  int i = 1;
  while (i < n) {
    if (pattern[next] == pattern[i]) {
      // case 1: match the next char in prefix
      ++next;
      partial[i] = next;
      ++i;
    }
    else if (next > 0) {
      // case 2: not a match, but we can fall back (until to 1st char)
      next = partial[next-1];
    }
    else {
      // case 3: fall back to 1st char, next == 0 here
      partial[i] = 0;
      ++i;
    }
  } // while
  return partial;
}

void test_partial_match(const vector<string> &pattern) {
  for (auto t : pattern) {
    auto T1 = compute_partial_match_clrs(t);
    auto T2 = compute_partial_match_wiki(t);
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

// finds all the matches, set the toggle 'first' to true to return at the first
// match. Again, this is from CLRS and it looks like very simple to the partial
// match computation, but this time instead of comparing against itself,  the
// pattern is comparing to target. 

// I thus modified the outer loop, using the explanation here:
// http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
vector<int> kmp(const string &target, const string &pattern, bool first = false) {
  vector<int> pos;

  if (target == "" || pattern == "") return pos;

  vector<int> partial = compute_partial_match_clrs(pattern);
  int n = target.size(), m = pattern.size();
  int next = 0;  // points to next char of prefix in the pattern

  for (int i = 0; i < n; ++i) {
    // current char in the target does not match next char in prefix: fall back
    while (next > 0 && target[i] != pattern[next])
      next = partial[next-1];

    // cout << "match at " << i << " " << next << ": " << target[i] << " " << pattern[next] << '\n';
    if (target[i] == pattern[next]) {
      ++next;
    }

    // already reaches the end of pattern
    if (next == m) {
      pos.push_back(i+1-m);
      if (first)  // if we only need the first occurence
        return pos;
      // set it back to the longest proper suffix
      // we can imagine this as a 'mismatch' at m, which is pattern.end()
      next = partial[next-1];
    }
  } // for

  return pos;
}

int main(int argc, char const *argv[])
{
  vector<string> target {
    "",
    "abc",
    "",
    "bacbababaabcbab",
    "ABC ABCDAB ABCDABCDABDE",
    "ABABCABCABC"
  };
  vector<string> pattern {
    "",
    "",
    "abc",
    "abababca",
    "ABCDABD",
    "ABC",
  };

  // test_partial_match(pattern);

  for (int i = 0; i < target.size(); ++i) {
    auto pos = kmp(target[i], pattern[i]);
    copy(pos.begin(), pos.end(), 
      ostream_iterator<decltype(pos)::value_type>(cout, " "));
    cout << '\n';
  }

  return 0;
}