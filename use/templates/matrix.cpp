#include <iostream>
#include <cassert>
#include <stdexcept>
#include <string>

template <typename T, size_t N, size_t M>
class Matrix {
private:
    T data[N][M]{};

public:
    Matrix() {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                data[i][j] = T();
            }
        }
    }

    void set(int row, int col, T value) {
        if (row < 0 || static_cast<size_t>(row) >= N || col < 0 || static_cast<size_t>(col) >= M) {
            throw std::out_of_range("Matrix coordinates out of range");
        }
        data[row][col] = value;
    }

    T get(int row, int col) const {
        if (row < 0 || static_cast<size_t>(row) >= N || col < 0 || static_cast<size_t>(col) >= M) {
            throw std::out_of_range("Matrix coordinates out of range");
        }
        return data[row][col];
    }

    void print() const {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                std::cout << data[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }

    Matrix<T, N, M> operator+(const Matrix<T, N, M>& other) const {
        Matrix<T, N, M> result;
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }
};

void test_matrix() {
    // 1. Обычный случай: наполнение и сложение матриц 2x2
    Matrix<int, 2, 2> m1;
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    assert(m1.get(0, 0) == 1);
    assert(m1.get(1, 1) == 4);

    Matrix<int, 2, 2> m2;
    m2.set(0, 0, 10);
    m2.set(0, 1, 20);
    m2.set(1, 0, 30);
    m2.set(1, 1, 40);

    Matrix<int, 2, 2> sum = m1 + m2;
    assert(sum.get(0, 0) == 11);
    assert(sum.get(0, 1) == 22);
    assert(sum.get(1, 0) == 33);
    assert(sum.get(1, 1) == 44);

    // --- КРАЙНИЕ СЛУЧАИ ---

    // 2. Матрица минимального размера 1x1
    Matrix<int, 1, 1> m1x1_a;
    Matrix<int, 1, 1> m1x1_b;
    m1x1_a.set(0, 0, 42);
    m1x1_b.set(0, 0, 8);
    Matrix<int, 1, 1> sum1x1 = m1x1_a + m1x1_b;
    assert(sum1x1.get(0, 0) == 50);

    // 3. Выход за границы матрицы (проверка перехвата std::out_of_range)
    bool caught = false;
    try {
        m1.get(-1, 0); // отрицательный индекс строки
    }
    catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    caught = false;
    try {
        m1.set(2, 0, 100); // строка за границами (row >= N)
    }
    catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    caught = false;
    try {
        m1.get(0, -1); // отрицательный индекс столбца
    }
    catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    caught = false;
    try {
        m1.set(0, 2, 100); // столбец за границами (col >= M)
    }
    catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    // 4. Проверка инициализации элементов по умолчанию (все элементы = 0)
    Matrix<int, 2, 2> m_default;
    assert(m_default.get(0, 0) == 0);
    assert(m_default.get(0, 1) == 0);
    assert(m_default.get(1, 0) == 0);
    assert(m_default.get(1, 1) == 0);

    // 5. Сложение с отрицательными числами (получение нулевой матрицы)
    Matrix<int, 2, 2> m_neg;
    m_neg.set(0, 0, -1);
    m_neg.set(0, 1, -2);
    m_neg.set(1, 0, -3);
    m_neg.set(1, 1, -4);

    Matrix<int, 2, 2> zero_matrix = m1 + m_neg;
    assert(zero_matrix.get(0, 0) == 0);
    assert(zero_matrix.get(0, 1) == 0);
    assert(zero_matrix.get(1, 0) == 0);
    assert(zero_matrix.get(1, 1) == 0);

    // 6. Работа шаблона со строковым типом std::string (сложение = конкатенация)
    Matrix<std::string, 1, 2> ms1;
    Matrix<std::string, 1, 2> ms2;
    ms1.set(0, 0, "Hello ");
    ms1.set(0, 1, "Matrix ");
    ms2.set(0, 0, "World!");
    ms2.set(0, 1, "Class!");

    Matrix<std::string, 1, 2> ms_sum = ms1 + ms2;
    assert(ms_sum.get(0, 0) == "Hello World!");
    assert(ms_sum.get(0, 1) == "Matrix Class!");

    std::cout << "test_matrix passed " << std::endl;
}

int main() {
    test_matrix();
    return 0;
}