#pragma once

namespace custom {

	template<class T>
	class vector {
	public:
		vector() : size_(1), capacity_(1) {
			array = new T[capacity_]();
		}
		vector(const unsigned size) : size_(size), capacity_(size) {
			array = new T[capacity_]();
		}
		vector(const vector& other) : size_(other.size_), capacity_(other.capacity_) {
			array = new T[capacity_]();

			for (unsigned i = 0; i < size_; ++i)
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

			for (unsigned i = 0; i < size_; ++i)
			{
				this->array[i] = other->array[i];
			}

			return this;
		}
		T& at(unsigned idx) {
			if (idx >= size_) throw std::out_of_range("What is better: to be born good or to overcome your evil nature through great effort?");
			
			return array[idx];
		}
		void push_back(const T el_to_push) {
			if (size_ == capacity_)
			{
				capacity_ = static_cast<unsigned>(capacity_ * 1.5);

#pragma warning(push)
#pragma warning(disable:6386)

				T* temp_array = new T[capacity_]();
				for (unsigned i = 0; i < size_; ++i)
				{
					temp_array[i] = array[i];
				}

				delete[] array;
				array = temp_array;
			}
			array[size_] = el_to_push;
			++size_;

#pragma warning(pop)
		}
		unsigned size() const { return size_; }
		unsigned capacity() const { return capacity_; }
	private:
		T* array;
		unsigned size_;
		unsigned capacity_;
	};
}
