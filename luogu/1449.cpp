#include <iostream>
#include <stack>
#include <stdio.h>
using namespace std;
int main() {
  using lli = long long int;
  char character;
  lli current_number = 0;
  lli n1, n2;
  cin >> character;
  std::stack<lli> expression_stack;
  while (character != '\n') {
    if (character >= '0' && character <= '9') {
      current_number = current_number * 10 + (character - '0');
    } else if (character == '.') {
      expression_stack.push(current_number);
      current_number = 0;
    } else if (character == '@') {
      break;
    } else {
      lli result;
      n1 = expression_stack.top();
      expression_stack.pop();
      n2 = expression_stack.top();
      expression_stack.pop();
      if (character == '+') {
        result = n2 + n1;
      } else if (character == '-') {
        result = n2 - n1;
      } else if (character == '*') {
        result = n2 * n1;
      } else if (character == '/') {
        result = n2 / n1;
      }
      expression_stack.push(result);
    }
    std::cin >> character;
  }
  std::cout << expression_stack.top() << std::endl;
  return 0;
}