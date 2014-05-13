#ifndef XLIST_H
#define XLIST_H

#include <stddef.h> // clang doesn't know what is NULL
#include <iostream>

template <typename T>
class XList {
private:
	// template <typename _T>
	struct XListElement {
	public:
		XListElement(T data) : _data(data), _next(NULL), _prev(NULL) {}
		~XListElement(){};
		T GetData() const { return _data; }
		XListElement * GetNext() const { return _next; }
		void SetNext(XListElement * ref) { _next = ref; }
		XListElement * GetPrev() const { return _prev; }
		void SetPrev(XListElement * ref) { _prev = ref; }
        operator T() { return _data; }
	private:
        T _data;
		XListElement * _next;
		XListElement * _prev;
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
	    XListElement * ptr;
	    iterator (XListElement * _ptr = 0) : ptr(_ptr) {}
	    T operator*() const { 
            return (*ptr).GetData(); 
        }
	    XListElement * operator->() const { return ptr; }
	    bool operator!=(XListElement * other) const { return !(ptr == other); }
	    bool operator==(XListElement * other) const { return ptr == other; }
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
	XListElement * _head;
	XListElement * _tail;
};

template<typename T>
T XList<T>::GetFirstValue() const {
	if (_head == NULL) throw "Can't get first element of empty list";
	return _head->GetData();
}

template<typename T>
T XList<T>::GetLastValue() const {
	if (_tail == NULL) throw "List is empty";
	return _tail->GetData();
}

template<typename T>
void XList<T>::push_back(const T& value){
	XListElement * newValue = new XListElement(value);
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
	XListElement * newValue = new XListElement(value);
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
	XListElement * old_head = _head;
	_head = _head->GetNext();
	if (_head != NULL) _head->SetPrev(NULL);
	delete old_head;
	--_size;
}

template <typename T>
void XList<T>::RemoveLast(){
	if (_tail == NULL) return;
	XListElement * old_tail = _tail;
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
		std::cout << it->GetData() << ' ';
	}
}

#endif /* XLIST_H */
