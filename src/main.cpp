#include <iostream>
#include "tensor.hpp"

int main()
{
	const dl::tensor::Tensor<int> tensor{2, 5};
	std::cout << tensor.data()[0];
	return 0;
}
