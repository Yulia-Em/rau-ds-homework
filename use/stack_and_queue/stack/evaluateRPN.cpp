#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>

int evaluateRPN(const std::vector<std::string>& expr) {
    std::stack<int> st;
    for (const std::string& token : expr) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int val2 = st.top(); 
            st.pop();
            int val1 = st.top(); 
            st.pop();
            if (token == "+") {
                st.push(val1 + val2);
            }
            else if (token == "-") {
                st.push(val1 - val2);
            }
            else if (token == "*") {
                st.push(val1 * val2);
            }
            else if (token == "/") {
                st.push(val1 / val2);
            }
        }
        else {
            st.push(std::stoi(token));
        }
    }
    return st.top();
}

int main() {
    // Стандартные случаи
    assert(evaluateRPN({ "2", "1", "+", "3", "*" }) == 9);
    assert(evaluateRPN({ "4", "13", "5", "/", "+" }) == 6);

    // Граничные случаи
    assert(evaluateRPN({ "42" }) == 42);                               // Одно число
    assert(evaluateRPN({ "-5" }) == -5);                               // Отрицательное число
    assert(evaluateRPN({ "10", "-3", "*" }) == -30);                    // Умножение на отрицательное
    assert(evaluateRPN({ "15", "7", "-" }) == 8);                      // Вычитание
    assert(evaluateRPN({ "7", "15", "-" }) == -8);                     // Отрицательный результат
    assert(evaluateRPN({ "0", "3", "/" }) == 0);                       // Деление нуля
    assert(evaluateRPN({ "5", "1", "+", "2", "/", "4", "*" }) == 12);  // Цепочка операций

    std::cout << "evaluateRPN passed all tests!" << std::endl;
    return 0;
}