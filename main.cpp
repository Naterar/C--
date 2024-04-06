#include <iostream>
using namespace std;

int main() {
  char operation;
  double num1, num2;

  cout << "Enter an operator (+, -, *, /): ";
  cin >> operation;

  cout << "Enter two operands: ";
  cin >> num1 >> num2;

  switch(operation) {
    case '+':
      cout << num1 << " + " << num2 << " = " << num1 + num2;
      break;
    case '-':
      cout << num1 << " - " << num2 << " = " << num1 - num2;
      break;
    case '*':
      cout << num1 << " * " << num2 << " = " << num1 * num2;
      break;
    case '/':
      if(num2 != 0.0)
        cout << num1 << " / " << num2 << " = " << num1 / num2;
      else
        cout << "Divide by zero situation.";
      break;
    default:
      cout << "Error! operator is nor correct";
      break;
  }
  return 0;
}