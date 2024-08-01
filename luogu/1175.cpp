#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>

int get_order(char &c) {
  switch (c) {
  case ')':
    return -1;
  case '(':
    return -1;
  case '+':
    return 0;
  case '-':
    return 0;
  case '*':
    return 1;
  case '/':
    return 1;
  case '^':
    return 2;
  default:
    return -2;
  }
}
using namespace std;
template <class T> void reverse_stack(std::stack<T> &s) {
  std::stack<T> temp_stack;
  while (!s.empty()) {
    temp_stack.push(s.top());
    s.pop();
  }
  s = std::stack<T>(std::move(temp_stack));
}
void stack_to_string(std::stack<int> &n, std::stack<char> &c) {
  auto n_copy = std::stack<int>(n);
  auto c_copy = std::stack<char>(c);
  reverse_stack(n_copy);
  std::stringstream output_stream;
  while (!n_copy.empty()) {
    output_stream << n_copy.top() << ' ';
    n_copy.pop();
  }
  while (!c_copy.empty()) {
    output_stream << c_copy.top() << ' ';
    c_copy.pop();
  }
  std::cout << output_stream.str() << std::endl;
}
void print_stack(std::stack<char> &s) {
  std::stack<int> number_stack;
  std::stack<char> cur_stack = std::stack<char>(std::move(s));
  stack_to_string(number_stack, cur_stack);
  while (!cur_stack.empty()) {
    char op = cur_stack.top();
    if (op >= '0' && op <= '9') {
      number_stack.push(op - '0');
      cur_stack.pop();
    } else {
      int n1 = number_stack.top();
      number_stack.pop();
      int n2 = number_stack.top();
      number_stack.pop();
      int number_result;
      if (op == '+') {
        number_result = n2 + n1;
      } else if (op == '-') {
        number_result = n2 - n1;
      } else if (op == '*') {
        number_result = n2 * n1;
      } else if (op == '/') {
        number_result = n2 / n1;
      } else if (op == '^') {
        number_result = static_cast<int>(std::pow(n2, n1));
      }
      number_stack.push(number_result);
      cur_stack.pop();
      stack_to_string(number_stack, cur_stack);
    }
  }
}
int main() {
  std::string expression;
  //   char character;
  std::stack<char> operator_stack;   //操作符栈
  std::stack<char> expression_stack; //中间结果栈
  std::unordered_map<char, int> calculate_order = {
      {')', -1}, {'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}, {'^', 2},
  }; //运算顺序表
  int operator_count = 0;
  std::cin >> expression;
  //   从左到右扫描表达式
  //   while (character != '\n') {
  for (char character : expression) {
    if (character >= '0' && character <= '9') {
      // 遇到操作数就直接压入中间结果zhan
      expression_stack.push(character);
    } else if (character == '+' || character == '-' || character == '*' ||
               character == '/' || character == '^') {
      // 遇到操作符
      operator_count++;
      if (operator_stack.empty() || operator_stack.top() == '(') {
        // 操作符栈为空或者操作符栈顶为左括号时都要压入操作符栈，此时意味着还不确定后续的操作符是否会对当前产生影响
        operator_stack.push(character);
      } else if ((get_order(character) > get_order(operator_stack.top())) ||
                 (get_order(character) == 2 &&
                  get_order(operator_stack.top()) == 2)) {
        // 如果当前读入的操作符优先级大于栈顶的操作符，就压入到操作符栈
        // 不直接压入中间结果栈是因为还不确定后续的操作符优先级会不会对当前操作符的顺序产生影响。
        // 由于最后一步是依次从操作符栈弹出到中间结果栈，所以操作符栈越靠近栈顶，在中间结果栈就越靠近栈底，所以运算顺序就越靠前。
        operator_stack.push(character);
      } else {
        // 出现较低或相等优先级的操作符，意味着栈中所有优先级较高的操作符都要出栈，此时出栈意味着相对于当前读入的操作符优先操作
        // 有一个问题是此时相当于蕴含了同优先级下是左结合（因为先读入的操作符先计算），需要在上一步特殊操作下
        // 不对好像不用特殊处理
        // 不对需要特殊处理 比如2^2^3
        while (!operator_stack.empty() &&
               get_order(character) <= get_order(operator_stack.top())) {
          char op = operator_stack.top();
          operator_stack.pop();
          expression_stack.push(op);
        }
        operator_stack.push(character);
      }
    } else if (character == '(') {
      //   遇到左括号直接进栈
      operator_stack.push(character);
    } else if (character == ')') {
      // 遇到右括号，依次弹出操作符栈到中间结果栈直到遇到左括号
      while (!operator_stack.empty() && operator_stack.top() != '(') {
        char op = operator_stack.top();
        expression_stack.push(op);
        operator_stack.pop();
      }
      operator_stack.pop();
    }
  }
  //   最后把操作符栈中的所有操作符弹出到中间结果栈
  while (!operator_stack.empty()) {
    expression_stack.push(operator_stack.top());
    operator_stack.pop();
  }
  //   reverse stack
  reverse_stack(expression_stack);
  print_stack(expression_stack);
  //   for (int i = 0; i <= operator_count; i++) {
  //     // int operator_calculated = 0;
  //     while (!expression.empty()) {
  //       char op = expression_stack.top();
  //       if (op >= '0' && op <= '9') {
  //         result.push(op);
  //         expression_stack.pop();
  //       } else {
  //         int n1 = result.top() - '0';
  //         result.pop();
  //         int n2 = result.top() - '0';
  //         result.pop();
  //         int number_result;
  //         if (op == '+') {
  //           number_result = n2 + n1;
  //         } else if (op == '-') {
  //           number_result = n2 - n1;
  //         } else if (op == '*') {
  //           number_result = n2 * n1;
  //         } else if (op == '/') {
  //           number_result = n2 / n1;
  //         } else if (op == '^') {
  //           number_result = static_cast<int>(std::pow(n2, n1));
  //         }
  //         result.push(number_result + '0');
  //         expression_stack.pop();
  //         caculated = true;
  //       }
  //     }
  //     std::stack<char> temp_stack(result);
  //     std::stringstream result_string_stream;
  //     while (!result.empty()) {
  //       if (expression_stack.size() == 1) {
  //         result_string_stream << temp_stack.top();
  //       } else {
  //         result_string_stream << temp_stack.top() << ' ';
  //       }
  //       temp_stack.pop();
  //     }
  //     std::string result_string = result_string_stream.str();
  //     std::reverse(result_string.begin(), result_string.end());
  //     std::cout << result_string << std::endl;
  //     caculated = false;
  //     operator_stack = std::stack<char>(std::move(result));
  //     result = std::stack<char>();
  //   }

  return 0;
}

//首先要确定的是会使用两个栈，一个栈存储操作符
//另一个栈存储整个表达式（包括操作符）。最重要的是前一个栈，因为操作符出栈的顺序就决定了运算的顺序。

// 第一次提交的时候runtime error 内存访问错误
// 怀疑只有可能是hash表会出现内存访问错误
// 改成switch之后就ac了 很离谱

// 发现问题了是hash表里面的左右括号写反了