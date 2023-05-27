#pragma once

#include <utility>

namespace custom {

	template<class T>
	class vector {
	public:
		vector() : size_(1), capacity_(1) {
			array = new T[capacity_]();
		}
		vector(const size_t size) : size_(size), capacity_(size) {
			array = new T[capacity_]();
		}
		vector(const vector& other) : size_(other.size_), capacity_(other.capacity_) {
			array = new T[capacity_]();

			for (size_t i = 0; i < size_; ++i)
			{
				this->array[i] = other->array[i];
			}
		}
		~vector() { 
			delete[] array; 
			array = nullptr;
		}

		vector& operator=(const vector& other) {
			if (this == other) return this;

			size_ = other.size_;
			capacity_ = other.capacity_;

			delete[] array;
			array = new T[capacity_]();

			for (size_t i = 0; i < size_; ++i)
			{
				this->array[i] = other->array[i];
			}

			return this;
		}
		T at(size_t idx) const {
			if (idx >= size_) throw std::out_of_range("What is better: to be born good or to overcome your evil nature through great effort?");

			return array[idx];
		}
		T& at(size_t idx) {
			if (idx >= size_) throw std::out_of_range("What is better: to be born good or to overcome your evil nature through great effort?");
			
			return array[idx];
		}
		void push_back(const T el_to_push) {
			if (size_ == capacity_)
			{
				capacity_ = static_cast<size_t>(capacity_ * 1.5);

#pragma warning(push)
#pragma warning(disable:6386)

				T* temp_array = new T[capacity_]();
				for (size_t i = 0; i < size_; ++i)
				{
					temp_array[i] = array[i];
				}

				delete[] array;
				array = std::move(temp_array);
			}
			array[size_] = el_to_push;
			++size_;

#pragma warning(pop)
		}
		size_t size() const { return size_; }
		size_t capacity() const { return capacity_; }
	private:
		T* array;
		size_t size_;
		size_t capacity_;
	};
}
