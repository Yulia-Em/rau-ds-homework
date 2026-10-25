#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

int timeRequiredToBuy(const std::vector<int>& tickets, int k) {
    std::queue<std::pair<int, int>> q;
    for (size_t i = 0; i < tickets.size(); ++i) {
        q.push({ static_cast<int>(i), tickets[i] });
    }

    int time = 0;
    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int person_idx = current.first;
        int remaining_tickets = current.second - 1;
        time++;

        if (person_idx == k && remaining_tickets == 0) {
            return time;
        }

        if (remaining_tickets > 0) {
            q.push({ person_idx, remaining_tickets });
        }
    }
    return time;
}

int main() {
    // Стандартные случаи
    assert(timeRequiredToBuy({ 2, 3, 2 }, 2) == 6);
    assert(timeRequiredToBuy({ 5, 1, 1, 1 }, 0) == 8);

    // Граничные случаи
    assert(timeRequiredToBuy({ 3 }, 0) == 3);                         // Один человек
    assert(timeRequiredToBuy({ 1, 1, 1 }, 1) == 2);                   // По 1 билету (середина)
    assert(timeRequiredToBuy({ 1, 1, 1 }, 0) == 1);                   // 0-я позиция с 1 билетом
    assert(timeRequiredToBuy({ 1, 1, 1 }, 2) == 3);                   // Последняя позиция с 1 билетом
    assert(timeRequiredToBuy({ 8, 2, 2 }, 2) == 6);                   // k заканчивает раньше начала

    std::cout << "timeRequiredToBuy passed all tests!" << std::endl;
    return 0;
}