#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

template<typename T>
concept printable = requires(std::ostream &os, const T &value)
{
	os << value;
};

template<typename T>
concept printable_container = requires(const T &container)
{
	{ container.begin() } -> std::input_iterator;
	{ container.end() } -> std::input_iterator;

	requires printable<typename T::value_type>;
};

template<printable_container T>
void print(const T &container)
{
	std::cout << '[';

	for (auto it = container.begin(); it != container.end(); ++it) {
		std::cout << *it;

		if (std::next(it) != container.end()) {
			std::cout << ", ";
		}
	}

	std::cout << ']' << std::endl;
}

#endif
