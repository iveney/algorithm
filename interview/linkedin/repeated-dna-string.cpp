// Given a DNA string (alphabet: ATCG), find all substrings of length 10
// that appeared more that one time and output them alphabetically

// The idea is that the whole space of possible substrings of length 10 is 
// limited: 4^10 = 2^20, it suffice to store them in a bitmap
// note that to save space, we can use two bits to count:
// 00: never appeared
// 01: appeared once
// 10: appeared more than once
//
// if we encode the string according to alphabetic order, we can then decode
// the substring in the bitmap in order and thus alphabetically

// for simplicity, assume the substring has length 4

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
using namespace std;

const int L = 4;
const int N = 1 << (2*L);

int char2int(char c) {
  switch(c) {
    case 'A':
      return 0;
    case 'T':
      return 1;
    case 'C':
      return 2;
    case 'G':
      return 3;
  }
  return -1;
}

char int2char(int n) {
  char m[] = "ATCG";
  return m[n];
}

// "AT" => 0 + 1 = 1
template <typename Container>
int encode(const Container &w) {
  int code = 0;
  for (char c : w) {
    int v = char2int(c);
    code = code * 4 + v;
  }
  return code;
}

string decode(int code) {
  string s(L, ' ');
  int i = L-1;
  while (i >= 0) {
    int d = code % 4;
    code /= 4;
    char c = int2char(d);
    s[i--] = c;
  }
  return s;
}

vector<string> repeatingSubstring(const string &s) {
  int count[N] = {0};
  vector<string> result;
  if (s.size() < L) return result;

  list<char> w(s.begin(), s.begin()+L);
  ++count[encode(w)];
  for (int i = L; i < s.size(); ++i) {
    w.pop_front();
    w.push_back(s[i]);
    // cout << "Window: ";
    // copy(w.begin(), w.end(), 
    //   ostream_iterator<decltype(w)::value_type>(cout, ""));
    // cout << " Code: " << setw(4) << encode(w) << "\n";
    ++count[encode(w)];
  }

  for (int i = 0; i < N; ++i) {
    if (count[i] > 1) {
      result.push_back(decode(i));
    }
  }
  return result;
}

void testCoding() {
  vector<string> strs {
    "ATCG",
    "GCTA",
    "AAAA",
    "CCCC",
  };
  for (auto &s : strs) {
    auto code = encode(s);
    auto decd = decode(code);
    cout << s << " Encode: " << setw(4) << setfill('0');
    cout << code << " Decode: " << decd << "\n";
  }
}

int main(int argc, char const *argv[]) {
  // testCoding();
  vector<string> strs {
    "AAAAA",
    "ATCGATCGA",
  };

  for (auto &s : strs) {
    cout << "string: " << s << "\n";
    auto result = repeatingSubstring(s);
    cout << "result: \n";
    copy(result.begin(), result.end(), 
      ostream_iterator<decltype(result)::value_type>(cout, "\n"));
    cout << endl;
  }
  return 0;
}