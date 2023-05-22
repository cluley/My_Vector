#include <iostream>

#include "vector.h"

using namespace std;

int main(int argc, char** argv) {
	custom::vector<int> vec1(4);
	cout << "size: " << vec1.size() << '\n' << "capacity: " << vec1.capacity() << endl;

	for (unsigned i = 0; i < vec1.size(); ++i) {
		cout << vec1.at(i) << ' ';
	}
	cout << '\n' << endl;

	cout << "size: " << vec1.size() << '\n' << "capacity: " << vec1.capacity() << endl;

	vec1.at(3) = 12;

	for (unsigned i = 0; i < vec1.size(); ++i) {
		cout << vec1.at(i) << ' ';
	}
	cout << '\n' << endl;

	cout << "size: " << vec1.size() << '\n' << "capacity: " << vec1.capacity() << endl;

	vec1.push_back(69);
	vec1.push_back(69);
	vec1.push_back(69);
	vec1.push_back(69);

	for (unsigned i = 0; i < vec1.size(); ++i) {
		cout << vec1.at(i) << ' ';
	}
	cout << '\n' << endl;

	cout << "size: " << vec1.size() << '\n' << "capacity: " << vec1.capacity() << endl;

	return 0;
}