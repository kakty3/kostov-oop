// Спроектировать и реализовать шаблонный класс XList со следующими возможностями:
//     + добавить новый элемент в начало/конец списка;
//     + получить значение первого/последнего элемента;
//     + каким-либо способом перебрать все элементы в обе стороны;
//     + узнать кол-во элементов;
//     + проверить на пустоту;
//     + очистить список.
#include <iostream>
#include <stddef.h> // clang doesn't know what is NULL
#include "xlist.h"

template<typename T>
void XList<T>::push_back(T value){
	XListValue<T> * newValue = new XListValue<T>(value);
	if (_tail) {
		_tail->SetNext(newValue);
		newValue->SetPrev(_tail);
	}
	_tail = newValue;
	if (!_head) _head = newValue;
	++_size;
}

template<typename T>
void XList<T>::push_front(T value){
	XListValue<T> * newValue = new XListValue<T>(value);
	if (_head){
		_head->SetPrev(newValue);
		newValue->SetNext(_head);
	}
	_head = newValue;
	if (!_tail) _tail = newValue;
	++_size;
}

template <typename T>
void XList<T>::RemoveFirst(){
	XListValue<T> * old_head = _head;
	_head = _head->GetNext();
	if (_head != NULL) _head->SetPrev(NULL);
	delete old_head;
	--_size;
}

template <typename T>
void XList<T>::RemoveLast(){
	XListValue<T> * old_tail = _tail;
	_tail = _tail->GetPrev();
	if (_tail != NULL )_tail->SetNext(NULL);
	delete old_tail;
	--_size;
}

template<typename T>
void XList<T>::Clean(){
	while (_size) this->RemoveFirst();
}

template<typename T>
void XList<T>::Print(){
	for (XList<int>::iterator it = _head; it != NULL; ++it) {
		std::cout << it->GetValue() << ' ';
	}
}

int main(){
	XList<int> xlist;
	std::cout << "\nIs empty: " << xlist.IsEmpty();

	xlist.push_back(4);
	xlist.push_back(5);
	xlist.push_front(3);
	xlist.push_front(2);
	xlist.push_front(1);

	std::cout << "\nFrom beginning to ending: ";
	for (XList<int>::iterator it = xlist.begin(); it != NULL; ++it) {
		std::cout << it->GetValue() << ' ';
	}
	std::cout << "\nFrom ending to beginning: ";
	for (XList<int>::iterator it = xlist.end(); it != NULL; --it) {
		std::cout << it->GetValue() << ' ';
	}
	std::cout << "\nSize is: " << xlist.size();
	std::cout << "\nIs empty: " << xlist.IsEmpty();
	std::cout << "\nFirst element is: " << xlist.GetFirstValue();
	std::cout << "\nLast element is: " << xlist.GetLastValue();
	std::cout << "\nRemoving last element...\n";
	xlist.RemoveLast();
	xlist.Print();
	std::cout << "\nRemoving first element...\n";
	xlist.RemoveFirst();
	xlist.Print();
	std::cout << "\nCleaning list...\n";
	xlist.Clean();
	xlist.Print();
	return 0;
}
