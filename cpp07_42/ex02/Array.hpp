#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

template <class T>
class Array {
	private:
		unsigned int _size;
		T *_storage;
	public:
		Array<T>(): _size(0), _storage(NULL) {
			std::cout << "Default contructor called" << std::endl;
		}

		Array<T>(unsigned int size): _size(size) {
			std::cout << "Size contructor called" << std::endl;
			this->_storage = new T[this->_size];
		}

		Array<T>(const Array<T> &src) {
			std::cout << "Copy contructor called" << std::endl;
			*this = src;
		}

		~Array<T>() {
			std::cout << "Destructor called" << std::endl;
			if (this->_size)
				delete []this->_storage;
		}

		Array<T> &operator=(const Array<T> &src) {
			std::cout << "Assignement operator called" << std::endl;
			if (this == &src)
				return *this;
			if (this->_size > 0)
				delete []this->_storage;
			this->_storage = new T[src._size];
			this->_size = src._size;
			for (unsigned int i = 0; i < this->_size; i++)
				this->_storage[i] = src._storage[i];
			return *this;
		}

		T &operator[](const unsigned int index) {
			if (index >= this->_size || index < 0)
				throw IndexOutOfBoundsException();
			return this->_storage[index];
		}

		unsigned int size() {
			return _size;
		}

		class IndexOutOfBoundsException: public std::exception {
			virtual const char *what() const throw() {
				return "array index is too long";
			}
		};
};

#endif