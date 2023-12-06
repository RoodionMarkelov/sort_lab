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
	list1.push_back(10);
	srand(0);

	for (int i = 0; i < 10; ++i) {
		list1.push_back(10-i);
	}
	print(list1);
	quickSort(list1, 0, list.size() - 1);
	print(list1);

	return 0;
}
