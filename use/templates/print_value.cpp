#include <iostream>
#include <string>

template <typename T>
void printValue(const T& val) {
    std::cout << val << std::endl;
}

template <>
void printValue<bool>(const bool& val) {
    std::cout << (val ? "true" : "false") << std::endl;
}

template <>
void printValue<const char*>(const char* const& val) {
    if (val) {
        std::cout << "[" << val << "]" << std::endl;
    }
    else {
        std::cout << "[null]" << std::endl;
    }
}

template <>
void printValue<char*>(char* const& val) {
    printValue<const char*>(val);
}

void test_print_value() {

    // 1. Базовый шаблон (int, double, std::string)
    std::cout << "int (42): ";
    printValue(42);

    std::cout << "double (3.14): ";
    printValue(3.14);

    std::cout << "std::string (\"hello\"): ";
    printValue(std::string("hello"));

    // 2. Специализация для bool
    std::cout << "bool (true): ";
    printValue(true);

    std::cout << "bool (false): ";
    printValue(false);

    // 3. Специализация для C-строк (const char* и char*)
    const char* cstr = "Hello C-string";
    std::cout << "const char*: ";
    printValue(cstr);

    char mutable_str[] = "Mutable C-string";
    char* p_mutable = mutable_str;
    std::cout << "char*: ";
    printValue(p_mutable);

    // 4. Крайний случай: нулевой указатель
    const char* null_str = nullptr;
    std::cout << "null const char*: ";
    printValue(null_str);

    std::cout << "_print_value test passed" << std::endl;
}

int main() {
    test_print_value();
    return 0;
}