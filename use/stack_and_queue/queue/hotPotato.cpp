#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cassert>

std::string hotPotato(const std::vector<std::string>& players, int K) {
    if (players.empty()) return "";
    std::queue<std::string> q;
    for (const auto& player : players) {
        q.push(player);
    }
    while (q.size() > 1) {
        for (int i = 0; i < K; ++i) {
            std::string front = q.front();
            q.pop();
            q.push(front);
        }
        q.pop();
    }
    return q.front();
}

int main() {
    // Стандартный случай
    std::vector<std::string> players = { "Alice", "Bob", "Charlie", "David" };
    assert(hotPotato(players, 7) == "Charlie");

    // Граничные случаи
    assert(hotPotato({}, 5) == "");                                 // Пустой список игроков
    assert(hotPotato({ "Alice" }, 10) == "Alice");                    // Один игрок
    assert(hotPotato({ "Alice", "Bob" }, 0) == "Bob");                // K = 0
    assert(hotPotato({ "Alice", "Bob", "Charlie" }, 1) == "Charlie");     // K = 1
    assert(hotPotato({ "Alice", "Bob" }, 100) == "Bob");            // Большое K при 2 игроках

    std::cout << "hotPotato passed all tests!" << std::endl;
    return 0;
}