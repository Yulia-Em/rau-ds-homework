#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>

std::vector<std::string> generateBinaryNumbers(int N) {
    std::vector<std::string> result;
    if (N <= 0) return result;
    std::queue<std::string> q;
    q.push("1");
    while (result.size() < static_cast<size_t>(N)) {
        std::string current = q.front();
        q.pop();
        result.push_back(current);
        q.push(current + "0");
        q.push(current + "1");
    }
    return result;
}

int main() {
    // Стандартный случай
    std::vector<std::string> expected5 = { "1", "10", "11", "100", "101" };
    assert(generateBinaryNumbers(5) == expected5);

    // Граничные случаи
    assert(generateBinaryNumbers(0).empty());                       // N = 0
    assert(generateBinaryNumbers(-5).empty());                      // Отрицательное N

    std::vector<std::string> expected1 = { "1" };
    assert(generateBinaryNumbers(1) == expected1);                  // N = 1

    std::cout << "generateBinaryNumbers passed all tests!" << std::endl;
    return 0;
}