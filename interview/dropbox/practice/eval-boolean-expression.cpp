/* Write a function called eval, which takes a string and returns a boolean.
This string is allowed 6 different characters: 0, 1, &, |, (, and ). Eval should
evaluate the string as a boolean expression, where 0 is false, 1 is true, & is
an and, and | is an or. An example string might look like "(0 | (1 | 0)) & (1 &
((1 | 0) & 0)))
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void eval_stack(stack<char> &result) {
  int s = result.top() - '0';
  result.pop();
  char op = result.top();
  result.pop();
  int r = result.top() - '0';
  result.pop();
  int res = op == '|' ? (s | r) : (s & r);
  result.push(res + '0');
}

bool eval(string expr) {
  stack<char> result;
  int left = 0;
  for (int i = 0; i < expr.size(); ++i) {
    if (expr[i] == ' ') {
      continue;
    }
    else if (expr[i] == '(') {
      ++left;
    } else if (expr[i] == ')') {
      --left;
      eval_stack(result);
    } else {
      // opcode or operand
      result.push(expr[i]);
    }
  }

  // clear the stack
  while (result.size() > 1) {
    eval_stack(result);
  }
  return (bool) (result.top() - '0');
}

int main(int argc, char const *argv[])
{
  vector<string> exprs = {
   "(0 | (1 | 0)) & (1 & ((1 | 0) & 0))",
   "0 | 1",
   " 0 ",
   " 1 ",
  };
  for (auto expr : exprs) {
    cout << eval(expr) << "\n";
  }
  return 0;
}