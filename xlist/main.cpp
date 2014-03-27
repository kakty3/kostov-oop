#include "xlist.h"

int main(){
	XList<int> xlist;
	std::cout << "\nIs empty: " << xlist.IsEmpty();
	try {
		std::cout << xlist.GetFirstValue();
	} catch (const char* error){
		std::cout << "\nEXCEPTION RAISED: "  << error << '\n';
	}

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
	std::cout << "\nSize is: " << xlist.GetSize();
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

	XList<std::string> xlist_of_strings;
	xlist_of_strings.push_back("one");
	xlist_of_strings.push_back("two");
	xlist_of_strings.push_back("three");
	xlist_of_strings.Print();
	return 0;
}
