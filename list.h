#pragma once
#include <iostream>

template <typename T>
class List{

	T data;
	List* next{nullptr};
	

	public:
	List()=default;
	List(const T& data) : data(data) {}
	List(const List& l){
		
		this->data = l.data;
		this->next = l.next;
	}
	List& operator=(const List&)=default;
	List(T&& _data): data(std::move(_data)) {};
	List& operator=(List&& l){
		
		this->data = std::move(l->data);
		this->next = std::move(l->next);
	}

	void append(T&& _data){
		auto iter = this->next;
		while(iter != nullptr){
			iter = iter->next;
		}
		iter = new List(std::forward<T>(_data));

			
	}

	void emplace(List<T>* l){
		auto iter = this->next;
		while(iter != nullptr){
			iter = iter->next;
		}
		iter = l;
	}
	
};
