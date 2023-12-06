#pragma once

#include <iostream>
#include <vector>

using namespace std;
struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
};

void insertionSort(std::vector<int>& list) {
	for (int i = 1; i < list.size(); ++i) {
		int key = list[i];
		int j = i - 1;
		while (j >= 0 && list[j] > key) {
			list[j+1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}

void quickSort(std::vector<int>& list, int start, int end) {
	if (start >= end) return;
	int pivot = list[end];
	int pIndex = start;
	for (int i = start; i < end; i++)
	{
		if (list[i] <= pivot)
		{
			swap(list[i], list[pIndex]);
			pIndex++;
		}
	}
	swap(list[pIndex], list[end]);
	quickSort(list, start, pIndex - 1);
	quickSort(list, pIndex + 1, end);
}

void combSort(std::vector<int>& list) {
	float factor = 1.277f;
	int step = list.size() - 1;
	while (step >= 1) {
		for (int i = 0; i + step < list.size(); ++i) {
			if (list[i] > list[i + step]) {
				swap(list[i], list[i + step]);
			}
		}
		step = step / factor;
		//step--;
	}
}