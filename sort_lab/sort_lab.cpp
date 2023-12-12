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

void print_stats(Stats& stats) {
	cout << "Stats:" << endl;
	cout << "Comparison_count = " << stats.comparison_count << endl;
	cout << "Copy_count = " << stats.copy_count << endl;

}

vector<int> _random_vector(size_t size) {
	std::vector<int> list;
	srand(0);
	for (int i = 0; i < size; ++i) {
		list.push_back(rand());
	}
	return list;
}

int main()
{
	std::vector<int> list1 = _random_vector(10);
	print(list1);
	Stats stats1 = insertionSort(list1);
	print(list1);
	print_stats(stats1);

	std::vector<int> list2 = _random_vector(10);
	print(list2);
	Stats stats2 = quickSort(list2, 0, list2.size() - 1);
	print(list2);
	print_stats(stats2);

	std::vector<int> list3 = _random_vector(10);
	print(list3);
	Stats stats3 = combSort(list3);
	print(list3);
	print_stats(stats3);

	return 0;
}
