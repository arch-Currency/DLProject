#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <memory>

namespace dl::tensor {

template <typename T>
class Tensor{
	private:
		std::allocator<T> allocator;
		T*data;
};

}

#endif
