#pragma once
#include <vector>

using namespace std;
struct Stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

class MyPairClass {
	int value1;
	int value2;
public:
	MyPairClass() : value1(0), value2(0) {};
	MyPairClass(int val1, int val2) : value1(val1), value2(val2) {};
	int get_value1() const {
		return this->value1;
	}
	int get_value2() const {
		return this->value2;
	}

	MyPairClass operator=(const MyPairClass& pair) {
		this->value1 = pair.get_value1();
		this->value2 = pair.get_value2();
		return *this;
	}

	bool operator>(const MyPairClass& pair) {
		if (this->value1 > pair.get_value1()) return true;
		if (this->value1 < pair.get_value1()) return false;
		else {
			if (this->value2 > pair.get_value2()) return true;
			if (this->value2 <= pair.get_value2()) return false;
		}
	}

	bool operator<(const MyPairClass& pair) {
		return !(*this > pair);
	}

	bool operator<=(const MyPairClass& pair) {
		if (this->value1 > pair.get_value1()) return false;
		if (this->value1 < pair.get_value1()) return true;
		else {
			if (this->value2 <= pair.get_value2()) return true;
			if (this->value2 > pair.get_value2()) return false;
		}
	}
	
	bool operator>=(const MyPairClass& pair) {
		return !(*this <= pair);
	}
};

Stats insertionSort(std::vector<int>& list) {
	Stats stats{0, 0};
	for (int i = 1; i < list.size(); ++i) {
		int key = list[i];
		stats.copy_count++;
		int j = i - 1;
		stats.comparison_count++;
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			stats.copy_count++;
			stats.comparison_count++;
			j = j - 1;
		}
		list[j + 1] = key;
	}
	return stats;
}

Stats quickSort(std::vector<int>& list, int start, int end) {
	Stats stats{0, 0};
	if (start >= end) return stats;
	int pivot = list[end];
	int pIndex = start;
	for (int i = start; i < end; i++)
	{
		stats.comparison_count++;
		if (list[i] <= pivot)
		{
			swap(list[i], list[pIndex]);
			stats.copy_count += 3;
			pIndex++;
		}
	}
	swap(list[pIndex], list[end]);
	stats.copy_count += 3;
	Stats stats_left = quickSort(list, pIndex + 1, end);
	stats.comparison_count += stats_left.comparison_count;
	stats.copy_count += stats_left.copy_count;
	Stats stats_right = quickSort(list, start, pIndex - 1);
	stats.comparison_count += stats_right.comparison_count;
	stats.copy_count += stats_right.copy_count;

	return stats;
}

Stats combSort(std::vector<int>& list ) {
	Stats stats{0,0};
	float factor = 1.277f;
	int step = list.size() - 1;
	while (step >= 1) {
		for (int i = 0; i + step < list.size(); ++i) {
			stats.comparison_count++;
			if (list[i] > list[i + step]) {
				swap(list[i], list[i + step]);
				stats.copy_count = stats.copy_count + 3;
			}
		}
		step = step / factor;
		//step--;
	}
	return stats;
}