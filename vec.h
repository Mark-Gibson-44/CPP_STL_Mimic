#pragma once

#include <cstdlib>
#include <iterator>
#include <iostream>
#include <cstddef>

template <typename T>
class Vector{

	T* data;
	int size{};
	int capacity{};

public:
	Vector(const int& _capacity=0, const int& _size=0, const int& default_val=0): size(_size), capacity(_capacity)
	{
		//std::cout << "Copy Constructed\n";
		data = (T*)malloc(_capacity * sizeof(T));
		for(int i = 0; i < _size; i++)
			data[i] = default_val;
	}
	Vector& operator=(const Vector& RHS){

		//std::cout << "Copy Assigned\n";
		this->size = RHS->size;
		this->capacity = RHS->capacity;
		this->data = (T*)malloc(capacity * sizeof(T));
		for(int i = 0; i < this->size; i++)
			this->data[i] = RHS[i];

		return *this;
	}
	Vector(int&& _capacity, int&& _size, int&& default_val): size(std::move(_size)), capacity(std::move(_capacity))
	{
		//std::cout << "Move constructed\n";
		data = (T*)malloc(capacity * sizeof(T));
		for(int i = 0; i < size; i++)
			data[i] = default_val;
	}
	Vector& operator=(Vector&& RHS){
		//std::cout << "Move assigned\n";
		this->size = std::move(RHS->size);
		RHS->size = nullptr;
		this-capacity = std::move(RHS->capacity);
		RHS->capacity=nullptr;
		this->data = std::move(RHS->data);
		return *this;
	}
	constexpr Vector(const Vector&)=default;
	T& operator[](const int& index) const {
		if(index > size)
			return -1;
		return this->data[index];
	}

	void push_back(const T&& value){


       		//If capacity is full;
        	if(this->size == this->capacity){
			//std::cout << "Increasing Capacity\n";
                	this->capacity++;
                	this->data = (T*)realloc(this->data, this->capacity * sizeof(T));
	
        	}
	        this->data[this->size] = value;
        	this->size++;
	}
	int get_size()const { return size;}
	
	void for_each(auto func) {
		

		for(auto a = this->begin(); a != this->end(); a++){
			func(*a);
		}
	}

	//Iterator
	struct Iterator{
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using ptr_ty = T*;
		using ref_ty = T&;
		
		Iterator(ptr_ty p) : ptr(p) {};

		//Dereference operator
		ref_ty operator*() const { return *ptr; }
		//Other deref op
		ptr_ty operator->() { return ptr; }
		
		Iterator& operator++() { ptr++; return *this; }

		Iterator& operator++(int) { Iterator tmp = *this; ++(*this); return tmp;}

		friend bool operator== (const Iterator& a, const Iterator& b) {return a.ptr == b.ptr; }
		friend bool operator!= (const Iterator& a, const Iterator& b) {return a.ptr != b.ptr; }
	private:
		T* ptr;
	};
	
	struct Reverse_Iterator{
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = T;
		using ptr_ty = T*;
		using ref_ty = T&;

		Reverse_Iterator(ptr_ty p): r_ptr(p) {};
		
		ref_ty operator*() const {return *r_ptr; }
		ptr_ty operator->() { return r_ptr; }
		Reverse_Iterator& operator++() { r_ptr--; return * this; }
		Reverse_Iterator& operator++(int) { Reverse_Iterator tmp = *this; ++(*this); return tmp; }

		friend bool operator== (const Reverse_Iterator& a, const Reverse_Iterator& b) { return a.r_ptr == b.r_ptr; }
		friend bool operator!= (const Reverse_Iterator& a, const Reverse_Iterator& b) { return a.r_ptr != b.r_ptr; }	
		
	private:
		T* r_ptr;
	};
	Iterator begin() { return Iterator(&data[0]); }

	Iterator end() { return Iterator(&data[size+1]); }

	Reverse_Iterator rbegin() { return Reverse_Iterator(&data[--size]); }
	Reverse_Iterator rend() { return Reverse_Iterator(&data[-1]); }
};
