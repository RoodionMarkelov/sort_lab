#pragma once

#include <iostream>
#include <vector>

using namespace std;
struct Stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

Stats insertionSort(std::vector<int>& list) {
	Stats stats;
	for (int i = 1; i < list.size(); ++i) {
		int key = list[i];
		stats.copy_count = stats.copy_count + 1;
		int j = i - 1;
		while (j >= 0 && list[j] > key) {
			list[j + 1] = list[j];
			stats.comparison_count = stats.comparison_count
				+ 1;
			j = j - 1;
		}
		list[j + 1] = key;
	}
	return stats;
}

Stats quickSort(std::vector<int>& list, int start, int end) {
	Stats stats;
	if (start >= end) return stats;
	int pivot = list[end];
	stats.copy_count++;
	int pIndex = start;
	for (int i = start; i < end; i++)
	{
		stats.comparison_count++;
		if (list[i] <= pivot)
		{
			swap(list[i], list[pIndex]);
			stats.copy_count++;
			pIndex++;
		}
	}
	swap(list[pIndex], list[end]);
	Stats stats_left = quickSort(list, pIndex + 1, end);
	stats.comparison_count += stats_left.comparison_count;
	stats.copy_count += stats_left.copy_count;
	Stats stats_right = quickSort(list, start, pIndex - 1);
	stats.comparison_count += stats_right.comparison_count;
	stats.copy_count += stats_right.copy_count;

	return stats;
}

Stats combSort(std::vector<int>& list ) {
	Stats stats;
	float factor = 1.277f;
	int step = list.size() - 1;
	while (step >= 1) {
		for (int i = 0; i + step < list.size(); ++i) {
			stats.comparison_count++;
			if (list[i] > list[i + step]) {
				swap(list[i], list[i + step]);
				stats.copy_count++;
			}
		}
		step = step / factor;
		//step--;
	}
	return stats;
}