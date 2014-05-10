#ifndef XLIST_H
#define XLIST_H

#include <stddef.h> // clang doesn't know what is NULL
#include <iostream>

template <typename T>
class XList {
private:
	template<typename _T>
	class XListElement
	{
	public:
		XListElement(_T value) : _value(value), _next(NULL), _prev(NULL) {}
		~XListElement(){};
		_T GetValue() const { return _value; }
		XListElement<_T> * GetNext() const { return _next; }
		void SetNext(XListElement<_T> * ref) { _next = ref; }
		XListElement<_T> * GetPrev() const { return _prev; }
		void SetPrev(XListElement<_T> * ref) { _prev = ref; }
	private:
		_T _value;
		XListElement<_T> * _next;
		XListElement<_T> * _prev;
	};
public:
	XList(): _size(0), _head(NULL), _tail(NULL) {};
	~XList(){ this->Clean(); };
	void push_back(const T& value);
	void push_front(const T& value);
	T GetFirstValue() const;
	T GetLastValue() const; 
	int GetSize() const { return _size; }
	bool IsEmpty() const { return (_size > 0) ? false : true ; }
	void Clean();
	void RemoveFirst();
	void RemoveLast();
	void Print();

	struct iterator {
	    XListElement<T> * ptr;
	    iterator (XListElement<T> * _ptr = 0) : ptr(_ptr) {}
	    XListElement<T> & operator*() { return *ptr; }
	    XListElement<T> * operator->() { return ptr; }
	    bool operator!=(XListElement<T> * other) const { return !(ptr == other); }
	    bool operator==(XListElement<T> * other) const { return ptr == other; }
	    XList<T>::iterator operator++(){ 
	    	ptr = ptr->GetNext();
	    	return ptr;
	    }
	    XList<T>::iterator operator--(){ 
	    	ptr = ptr->GetPrev();
	    	return ptr;
	    }
	};
	XList<T>::iterator begin() const { return _head; }
	XList<T>::iterator end() const { return _tail; }

private:
	int _size;
	XListElement<T> * _head;
	XListElement<T> * _tail;
};

template<typename T>
T XList<T>::GetFirstValue() const {
	if (_head == NULL) throw "Can't get first element of empty list";
	return _head->GetValue();
}

template<typename T>
T XList<T>::GetLastValue() const {
	if (_tail == NULL) throw "List is empty";
	return _tail->GetValue();
}

template<typename T>
void XList<T>::push_back(const T& value){
	XListElement<T> * newValue = new XListElement<T>(value);
	if (_tail) {
		_tail->SetNext(newValue);
		newValue->SetPrev(_tail);
	}
	_tail = newValue;
	if (!_head) _head = newValue;
	++_size;
}

template<typename T>
void XList<T>::push_front(const T& value){
	XListElement<T> * newValue = new XListElement<T>(value);
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
	if (_head == NULL) return;
	XListElement<T> * old_head = _head;
	_head = _head->GetNext();
	if (_head != NULL) _head->SetPrev(NULL);
	delete old_head;
	--_size;
}

template <typename T>
void XList<T>::RemoveLast(){
	if (_tail == NULL) return;
	XListElement<T> * old_tail = _tail;
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
	for (XList<T>::iterator it = _head; it != NULL; ++it) {
		std::cout << it->GetValue() << ' ';
	}
}

#endif /* XLIST_H */
