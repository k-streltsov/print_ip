#include <type_traits>
#include <iostream>
#include <string>
#include <vector>
#include <list>

template<typename T>
std::enable_if_t<std::is_integral_v<T>>
print_ip(const T& integral)
{
    for (auto byte_num = sizeof(integral) - 1; byte_num > 0; --byte_num) {
        std::cout << std::to_string(((integral >> (byte_num * 8)) & 0xFF));
        std::cout << '.';
    }

    std::cout << std::to_string(integral & 0xFF) << std::endl;
}

void print_ip(const std::string& string)
{
    std::cout << string << std::endl;
}

template<typename T>
decltype(cbegin(std::declval<T>()), cend(std::declval<T>()), void())
print_ip(const T& container)
{
    for (auto it = std::cbegin(container); it != std::end(container); ++it) {
        if (it == std::cbegin(container))
            std::cout << *it;
        else
            std::cout << '.' << *it;
    }

    std::cout << std::endl;
}

int main()
{
    print_ip(char{-1});
    print_ip(short{0});
    print_ip(2130706433);
    print_ip(8875824491850138409);
    print_ip(std::string{"trololo"});
    print_ip(std::vector{1, 2, 3, 4});
    print_ip(std::list{5, 6, 7, 8});
}