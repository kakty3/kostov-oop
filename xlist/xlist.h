#ifndef XLIST_H
#define XLIST_H

#include <stddef.h> // clang doesn't know what is NULL
#include <iostream>

template <typename T>
class XList {
private:
	template<typename _T>
	class XListValue
	{
	public:
		XListValue(_T value) : _value(value), _next(NULL), _prev(NULL) {}
		~XListValue(){};
		_T GetValue() const { return _value; }
		XListValue<_T> * GetNext() const { return _next; }
		void SetNext(XListValue<_T> * ref) { _next = ref; }
		XListValue<_T> * GetPrev() const { return _prev; }
		void SetPrev(XListValue<_T> * ref) { _prev = ref; }
	private:
		_T _value;
		XListValue<_T> * _next;
		XListValue<_T> * _prev;
	};
public:
	XList(): _size(0), _head(NULL), _tail(NULL) {};
	~XList(){ this->Clean(); };
	void push_back(T value);
	void push_front(T value);
	T GetFirstValue() const;
	T GetLastValue() const; 
	int GetSize() const { return _size; }
	bool IsEmpty() const { return (_size > 0) ? false : true ; }
	void Clean();
	void RemoveFirst();
	void RemoveLast();
	void Print();

	struct iterator {
	    XListValue<T> * ptr;
	    iterator (XListValue<T> * _ptr = 0) : ptr(_ptr) {}
	    XListValue<T> & operator*() { return *ptr; }
	    XListValue<T> * operator->() { return ptr; }
	    bool operator!=(XListValue<T> * other) const { return !(ptr == other); }
	    bool operator==(XListValue<T> * other) const { return ptr == other; }
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
	XListValue<T> * _head;
	XListValue<T> * _tail;
};

#endif /* XLIST_H */
