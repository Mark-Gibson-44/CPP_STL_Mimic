#include "vec.h"

template <typename T>
void Vector::push_back(const T&& value){
	

	//If capacity is full;
	if(this->size == this->capacity){
		this->capacity++;
		this->data = (T*)realloc(this->capacity * sizeof(T));
		
	} 

	this->data[this->size] = value;
	this->size++;
	
	
}

