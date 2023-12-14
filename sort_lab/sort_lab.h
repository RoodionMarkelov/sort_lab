#pragma once
#include <vector>
#include <iostream>

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

	friend std::ostream& operator<<(std::ostream& stream, MyPairClass& pair) {
		MyPairClass temp = pair;
		stream << "(" << temp.get_value1() << "; " << temp.get_value2() << ")" << endl;
		return stream;
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

template<typename T>
Stats insertionSort(std::vector<T>& list) {
	Stats stats{0, 0};
	for (int i = 1; i < list.size(); ++i) {
		T key = list[i];
		stats.copy_count++;
		int j = i - 1;
		stats.comparison_count++;
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			stats.comparison_count++;
			stats.copy_count++;
			j = j - 1;
		}
		stats.copy_count++;
		list[j + 1] = key;
	}
	return stats;
}

template<typename T>
Stats quickSort(vector<T>& vec, int start, int end) {
	Stats stats;

	int i = start;
	int j = end;
	T middle = vec[(start + end) / 2];

	do {
		while (vec[i] < middle) {
			stats.comparison_count++;
			i++;
		}
		while (vec[j] > middle) {
			stats.comparison_count++;
			j--;
		}

		if (i <= j) {
			swap(vec[i], vec[j]);
			i++;
			j--;
			stats.copy_count += 3;
		}
	} while (i <= j);

	if (j > start) {
		Stats left_stats = quickSort(vec, start, j);
		stats.comparison_count += left_stats.comparison_count;
		stats.copy_count += left_stats.copy_count;
	}
	if (i < end) {
		Stats right_stats = quickSort(vec, i, end);
		stats.comparison_count += right_stats.comparison_count;
		stats.copy_count += right_stats.copy_count;
	}

	return stats;
}

template<typename T>
Stats combSort(std::vector<T>& list ) {
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