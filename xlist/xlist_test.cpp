#include "xlist.h"

int main(){
	XList<int> xlist;
	std::cout << "Is empty: " << xlist.IsEmpty() << std::endl;
	try {
		std::cout << xlist.GetFirstValue();
	} catch (const char* error){
		std::cout << error << std::endl;
	}

	xlist.push_back(4);
	xlist.push_back(5);
	xlist.push_front(3);
	xlist.push_front(2);
	xlist.push_front(1);

	std::cout << "From beginning to ending: ";
	for (XList<int>::iterator it = xlist.begin(); it != NULL; ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
	std::cout << "From ending to beginning: ";
	for (XList<int>::iterator it = xlist.end(); it != NULL; --it) {
        std::cout << *it << ' ';
	}
	std::cout << std::endl;
	std::cout << "Size is: " << xlist.GetSize() << std::endl;
	std::cout << "Is empty: " << xlist.IsEmpty() << std::endl;
	std::cout << "First element is: " << xlist.GetFirstValue() << std::endl;
	std::cout << "Last element is: " << xlist.GetLastValue() << std::endl;
	std::cout << "Removing last element..." << std::endl;;
	xlist.RemoveLast();
	xlist.Print();
	std::cout << "\nRemoving first element..." << std::endl;;
	xlist.RemoveFirst();
	xlist.Print();
	std::cout << std::endl;
	std::cout << "Cleaning list..." << std::endl;;
	xlist.Clean();
	xlist.Print();

	XList<std::string> xlist_of_strings;
	xlist_of_strings.push_back("one");
	xlist_of_strings.push_back("two");
	xlist_of_strings.push_back("three");
	xlist_of_strings.Print();
	return 0;
}
