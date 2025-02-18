#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <memory>
#include <vector>

template<typename T>
concept default_constructible = requires()
{
	T{};
};

namespace dl::tensor
{
	template<default_constructible T, typename alloc = std::allocator<T> >
	class Tensor {
	private:
		alloc allocator;
		T *_data;
		std::vector<size_t> _shape;
		unsigned short _dim;
		size_t _offset;
		size_t _length;

	public:
		Tensor(std::initializer_list<size_t> shape);

		~Tensor();

		const T *data() const { return _data; }
	};
}

#endif
