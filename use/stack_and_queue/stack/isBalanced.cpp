#include <iostream>
#include <string>
#include <stack>
#include <cassert>

bool isBalanced(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) return false;
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    // Стандартные случаи
    assert(isBalanced("({[]})") == true);
    assert(isBalanced("()[]{}") == true);
    assert(isBalanced("([)]") == false);
    assert(isBalanced("{[}]") == false);

    // Граничные случаи
    assert(isBalanced("") == true);                  // Пустая строка
    assert(isBalanced("(") == false);                 // Одна открывающая
    assert(isBalanced(")") == false);                 // Одна закрывающая
    assert(isBalanced("(((") == false);               // Только открывающие
    assert(isBalanced(")))") == false);               // Только закрывающие
    assert(isBalanced("())(()") == false);             // Несовпадение баланса
    assert(isBalanced("({[") == false);               // Незакрытые скобки
    assert(isBalanced("]}") == false);                // Лишние закрывающие
    assert(isBalanced("((({{{[[[]]]}}})))") == true);    // Глубокая вложенность

    std::cout << "isBalanced passed all tests!" << std::endl;
    return 0;
}