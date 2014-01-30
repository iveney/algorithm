// Tricky.
// See the post at: http://leetcode.com/2011/09/regular-expression-matching.html
#include <iostream>
#include <string>

using namespace std;

bool match(string target, string regex) {
  // char prev = ' ';
  // bool wildcard = false, any = false;
  int i, j;

  // be aware of empty string
  for (i = 0, j = 0; i < regex.size();) {
    char c = regex[i];
    char curr = c == '.' ? target[j] : c;

    // lookahead for '*'
    if ( i < regex.size() - 1 && regex[i+1] == '*') {
      i += 2;
      // match zero or more of curr
      while (j < target.size() && target[j] == curr) {
        ++j;
      }

      if (target.size() > 0 && j >= target.size())
        break;
    } else {
      if (target[j] != curr)
        return false;
      ++i;
      ++j;
    }

    // increment target
    if (target.size() > 0 && j >= target.size()) {
      break;
    }
  }

  if ( i == regex.size() && j == target.size() )
    return true;
  else
    return false;
}

int main(int argc, char *argv[])
{
  string regex, target;
  cout << "Enter target and regex (in two lines):" << endl;
  while (cin >> target >> regex) {
    cout << match(target, regex) << endl;
  }

  return 0;
}
