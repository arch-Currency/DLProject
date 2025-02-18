#include "tensor.hpp"
#include <numeric>

namespace dl::tensor
{
	template <default_constructible T, typename alloc>
	Tensor<T, alloc>::Tensor(const std::initializer_list<size_t> shape):
		_shape{shape}, _dim{static_cast<unsigned short>(shape.size())}, _offset{0}
	{
		_length = std::accumulate(_shape.begin(), _shape.end(), 1, std::multiplies());
		_data = allocator.allocate(_length);
		std::uninitialized_default_construct(_data, _data + _length);
	}

	template <default_constructible T, typename alloc>
	Tensor<T, alloc>::~Tensor()
	{
		for (size_t i = 0; i < _length; ++i)
		{
			std::allocator_traits<alloc>::destroy(allocator, &_data[i]);
		}
		allocator.deallocate(_data, _length);
	}

	template class Tensor<int>;
}
