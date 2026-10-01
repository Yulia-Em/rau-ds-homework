#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput() {
    std::vector<int> vec;
    int i;
  
    while (std::cin >> i) {
        if (i == 0) {
            break;
        }
        vec.push_back(i);
    }
    return vec;
}

void test_create_vector_from_input() {
    std::vector<int> result = createVectorFromInput();

    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Проверка базового правила: элемент 0 не должен попасть в результирующий вектор
    for (int val : result) {
        assert(val != 0);
    }

    std::cout << "createVectorFromInput passed" << std::endl;
}

int main() {
    test_create_vector_from_input();
    return 0;
}