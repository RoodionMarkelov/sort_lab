#include "sort_lab.h"
#include <vector>
#include <random>

using namespace std;

void print(std::vector<int> list) {
	cout << "Vector:" << endl;
	for (int i = 0; i < list.size(); ++i) {
		cout << list[i] << " ";
	}
	cout << endl;
}

int main()
{
	std::vector<int> list;
	srand(0);
	for (int i = 0; i < 10; ++i) {
		list.push_back(rand());
	}
	print(list);
	insertionSort(list);
	print(list);

	std::vector<int> list1;
	srand(0);
	for (int i = 0; i < 10; ++i) {
		list1.push_back(rand());
	}
	print(list1);
	quickSort(list1, 0, list1.size() - 1);
	print(list1);

	std::vector<int> list2;
	srand(0);
	for (int i = 0; i < 10; ++i) {
		list2.push_back(rand());
	}
	print(list2);
	combSort(list2);
	print(list2);

	return 0;
}
