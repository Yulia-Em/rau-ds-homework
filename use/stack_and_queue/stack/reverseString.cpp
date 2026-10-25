#include <iostream>
#include <string>
#include <stack>
#include <cassert>

void reverseString(std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        st.push(c);
    }
    for (size_t i = 0; i < s.size(); ++i) {
        s[i] = st.top();
        st.pop();
    }
}

int main() {
    // Стандартный случай
    std::string s1 = "Hello";
    reverseString(s1);
    assert(s1 == "olleH");

    // Граничные случаи
    std::string empty = "";
    reverseString(empty);
    assert(empty == "");                              // Пустая строка

    std::string single = "A";
    reverseString(single);
    assert(single == "A");                            // Один символ

    std::string palindrome = "racecar";
    reverseString(palindrome);
    assert(palindrome == "racecar");                  // Палиндром

    std::string spaces = "a b c ";
    reverseString(spaces);
    assert(spaces == " c b a");                       // Содержит пробелы

    std::string special = "123!@#";
    reverseString(special);
    assert(special == "#@!321");                       // Спецсимволы и цифры

    std::cout << "reverseString passed all tests!" << std::endl;
    return 0;
}