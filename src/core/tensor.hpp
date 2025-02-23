#ifndef TENSOR_HPP
#define TENSOR_HPP

#include <iterator>
#include <memory>
#include <vector>

template <typename T>
concept default_constructible = requires() { T{}; };

namespace dl::tensor
{
	template <default_constructible T, typename alloc = std::allocator<T>>
	class Tensor
	{
	private:
		alloc allocator;
		T* _data;
		std::vector<size_t> _shape;
		unsigned short _dim;
		size_t _offset;
		size_t _length;
		bool _on_device;

	public:
		Tensor(std::initializer_list<size_t> shape);
		~Tensor();
		const T* data() const { return _data; }
		T* mut_data() const { return _data; }

		// iterator definition
		class iterator
		{
		private:
			T* ptr;

		public:
			explicit iterator(T* p) : ptr{p} {}
			T& operator*() const { return *ptr; }
			T* operator->() const { return ptr; }
			iterator& operator++()
			{
				++ptr;
				return *this;
			}
			iterator operator++(int)
			{
				iterator copy = *this;
				++ptr;
				return copy;
			}
			bool operator==(const iterator& other) const { return ptr == other.ptr; }
			bool operator!=(const iterator& other) const { return ptr != other.ptr; }

			using iterator_category = std::input_iterator_tag;
			using value_type = T;
			using pointer = T*;
			using reference = T&;
			using difference_type = std::ptrdiff_t;
		};

		iterator begin() const { return iterator{_data}; }
		iterator end() const { return iterator{_data + _length}; }

		using value_type = T;
	};
} // namespace dl::tensor

#endif
