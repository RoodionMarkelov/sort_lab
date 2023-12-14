#include "sort_lab.h"
#include <vector>
#include <random>
#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void print(std::vector<T> list) {
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

vector<int> _random_vector(int size) {
	std::vector<int> list;
	srand(time(0));
	for (int i = 0; i < size; ++i) {
		list.push_back(rand());
	}
	return list;
}

vector<int> _sorted_vector(int size) {
	std::vector<int> list;
	for (int i = 0; i < size; ++i) {
		list.push_back(i);
	}
	return list;
}

vector<int> _reverse_vector(int size) {
	std::vector<int> list;
	for (int i = 0; i < size; ++i) {
		list.push_back(size - 1 - i);
	}
	return list;
}

template<typename T>
vector<T> create_vector(int size, T min_value, T max_value) {
	std::vector<T> vector(size);
	for (int i(0); i < size; ++i) {
		vector[i] = (T)((double)min_value + (double)(rand()) / RAND_MAX * (max_value - min_value));
	}
	return vector;
}

vector<MyPairClass> create_vector(int size) {
	std::vector<MyPairClass> vector(size);
	srand(time(0));
	for (int i(0); i < size; ++i) { 
		vector[i] = MyPairClass(rand(), rand());
	}
	return vector;
}

int main()
{
	//std::vector<int> list1 = _random_vector(1000);
	//Stats stats1 = insertionSort(list1);
	//print_stats(stats1);

	//std::vector<int> list2 = _random_vector(10000);
	//Stats stats2 = quickSort(list2, 0, list2.size() - 1);
	//print_stats(stats2);

	//std::vector<int> list3 = _random_vector(10000);
	//Stats stats3 = combSort(list3);
	//print_stats(stats3);

	//std::vector<int> list4 = _sorted_vector(10000);
	//Stats stats4 = insertionSort(list4);
	//print_stats(stats4);

	//std::vector<int> list5 = _sorted_vector(10000);
	//Stats stats5 = quickSort(list5, 0, list5.size() - 1);
	//print_stats(stats5);

	//std::vector<int> list6 = _sorted_vector(10000);
	//Stats stats6 = combSort(list6);
	//print_stats(stats6);

	//std::vector<int> list7 = _reverse_vector(10000);
	//Stats stats7 = insertionSort(list7);
	//print_stats(stats7);

	//std::vector<int> list8 = _reverse_vector(1000);
	//Stats stats8 = quickSort(list8, 0, list8.size() - 1);
	//print_stats(stats8);

	//std::vector<int> list9 = _reverse_vector(10000);
	////print(list9);
	//Stats stats9 = combSort(list9);
	////print(list9);
	//print_stats(stats9);

	//===========================================================
	//After example
	//===========================================================

	/*Stats stats_insertion_sort_random{0, 0};
	Stats stats_quick_sort_random{ 0, 0 };
	Stats stats_comb_sort_random{ 0, 0 };

	int vector_count = 100;
	int length = 100000;

	for (int i = 0; i < vector_count; ++i) {
		vector<int> vec = _random_vector(length);

		vector<int> vector1 = vec;
		Stats insert_sort_random = insertionSort(vector1);
		stats_insertion_sort_random.comparison_count += insert_sort_random.comparison_count;
		stats_insertion_sort_random.copy_count += insert_sort_random.copy_count;

		vector<int> vector2 = vec;
		Stats quick_sort_random = quickSort(vector2, 0, vector2.size() - 1);
		stats_quick_sort_random.comparison_count += quick_sort_random.comparison_count;
		stats_quick_sort_random.copy_count += quick_sort_random.copy_count;

		vector<int> vector3 = vec;
		Stats comb_sort_random = combSort(vector3);
		stats_comb_sort_random.comparison_count += comb_sort_random.comparison_count;
		stats_comb_sort_random.copy_count += comb_sort_random.copy_count;
		cout << i << endl;
	}

	vector<int> sorted_vector = _sorted_vector(length);
	Stats stats_insertion_sort_sorted{ 0, 0 };
	Stats insert_sort_sorted = insertionSort(sorted_vector);
	stats_insertion_sort_sorted.comparison_count += insert_sort_sorted.comparison_count;
	stats_insertion_sort_sorted.copy_count += insert_sort_sorted.copy_count;

	Stats quick_sort_sorted = quickSort(sorted_vector, 0, sorted_vector.size() - 1);
	Stats stats_quick_sort_sorted{ 0, 0 };
	stats_quick_sort_sorted.comparison_count += quick_sort_sorted.comparison_count;
	stats_quick_sort_sorted.copy_count += quick_sort_sorted.copy_count;

	Stats comb_sort_sorted = combSort(sorted_vector);
	Stats stats_comb_sort_sorted{ 0, 0 };
	stats_comb_sort_sorted.comparison_count += comb_sort_sorted.comparison_count;
	stats_comb_sort_sorted.copy_count += comb_sort_sorted.copy_count;

	vector<int> reverse_vector = _reverse_vector(length);
	Stats stats_insertion_sort_reverse{ 0, 0 };
	vector<int> reverse_vector1 = reverse_vector;
	Stats insert_sort_reverse = insertionSort(reverse_vector1);
	stats_insertion_sort_reverse.comparison_count += insert_sort_reverse.comparison_count;
	stats_insertion_sort_reverse.copy_count += insert_sort_reverse.copy_count;

	vector<int> reverse_vector2 = reverse_vector;
	Stats stats_quick_sort_reverse{ 0, 0 };
	Stats quick_sort_reverse = quickSort(reverse_vector2, 0, reverse_vector2.size() - 1);
	stats_quick_sort_reverse.comparison_count += quick_sort_reverse.comparison_count;
	stats_quick_sort_reverse.copy_count += quick_sort_reverse.copy_count;

	vector<int> reverse_vector3 = reverse_vector;
	Stats comb_sort_reverse = combSort(reverse_vector3);
	Stats stats_comb_sort_reverse{ 0, 0 };
	stats_comb_sort_reverse.comparison_count += comb_sort_reverse.comparison_count;
	stats_comb_sort_reverse.copy_count += comb_sort_reverse.copy_count;


	Stats insert_sort_random_average{
		insert_sort_random_average.comparison_count = (stats_insertion_sort_random.comparison_count / vector_count),
		insert_sort_random_average.copy_count = (stats_insertion_sort_random.copy_count / vector_count)
	};

	Stats quick_sort_random_average{
		quick_sort_random_average.comparison_count = (stats_quick_sort_random.comparison_count / vector_count),
		quick_sort_random_average.copy_count = (stats_quick_sort_random.copy_count / vector_count)
	};

	Stats comb_sort_random_average{
		comb_sort_random_average.comparison_count = (stats_comb_sort_random.comparison_count / vector_count),
		comb_sort_random_average.copy_count = (stats_comb_sort_random.copy_count / vector_count)
	};

	cout << "Vector_lengths = " << length << endl;
	cout << endl;

	==========================================================================
	Random
	==========================================================================
	cout << "Random===============================================================" << endl;
	cout << "Random_vectors - Insertion Sort Average Stats:" << endl;
	print_stats(insert_sort_random_average);
	cout << endl;

	cout << "Random_vectors - Quick Sort Average Stats:" << endl;
	print_stats(quick_sort_random_average);
	cout << endl;

	cout << "Random_vectors - Comb Sort Average Stats:" << endl;
	print_stats(comb_sort_random_average);
	cout << endl;


	==========================================================================
	Sorted
	==========================================================================
	cout << "Sort===============================================================" << endl;
	cout << "Sorted_vector - Insertion Sort A Stats:" << endl;
	print_stats(stats_insertion_sort_sorted);
	cout << endl;

	cout << "Sorted_vector - Quick Sort Stats:" << endl;
	print_stats(stats_quick_sort_sorted);
	cout << endl;

	cout << "Sorted_vector - Comb Sort Stats:" << endl;
	print_stats(stats_comb_sort_sorted);
	cout << endl;

	==========================================================================
	Reverse
	==========================================================================
	cout << "Reverse===============================================================" << endl;
	cout << "Reverse_vector - Insertion Sort Stats:" << endl;
	print_stats(stats_insertion_sort_reverse);
	cout << endl;

	cout << "Reverse_vector - Quick Sort Stats:" << endl;
	print_stats(stats_quick_sort_reverse);
	cout << endl;

	cout << "Reverse_vector - Comb Sort Stats:" << endl;
	print_stats(stats_comb_sort_reverse);
	cout << endl;
	bool res = (reverse_vector3 == sorted_vector);
	cout << res << endl;*/

	//================================================================
	//After stats
	//================================================================

	cout << "FLOAT===============================================================" << endl;
	vector<float> vec1 = create_vector<float>(20, -40.5f, 40.5f);
	print(vec1);

	vector<float> vector1 = vec1;
	Stats stats1 = insertionSort(vector1);
	print(vector1);
	vector<float> vector2 = vec1;
	Stats stats2 = insertionSort(vector2);
	print(vector2);
	vector<float> vector3 = vec1;
	Stats stats3 = insertionSort(vector3);
	print(vector3);

	cout << "Double===============================================================" << endl;
	vector<double> vec2 = create_vector<double>(20, -40.5f, 40.5f);
	print(vec2);

	vector<double> vector11 = vec2;
	Stats stats11 = insertionSort(vector11);
	print(vector11);
	vector<double> vector22 = vec2;
	Stats stats22 = insertionSort(vector22);
	print(vector22);
	vector<double> vector33 = vec2;
	Stats stats33 = insertionSort(vector33);
	print(vector33);

	cout << "MyClass===============================================================" << endl;
	vector<MyPairClass> vec3 = create_vector(20);
	print(vec3);

	vector<MyPairClass> vector111 = vec3;
	Stats stats111 = insertionSort(vector111);
	print(vector111);
	vector<MyPairClass> vector222 = vec3;
	Stats stats222 = insertionSort(vector222);
	print(vector222);
	vector<MyPairClass> vector333 = vec3;
	Stats stats333 = insertionSort(vector333);
	print(vector333);

	cout << "String===============================================================" << endl;
	vector<string> vec_string = {"adc", "abc", "a", "s", "v", "t", "a", "i", "s", "d", "aaa"};
	print(vec_string);

	vector<string> vec_string1 = vec_string;
	Stats stats_s1= insertionSort(vec_string1);
	print(vec_string1);

	vector<string> vec_string2 = vec_string;
	Stats stats_s2 = insertionSort(vec_string2);
	print(vec_string2);

	vector<string> vec_string3 = vec_string;
	Stats stats_s3 = insertionSort(vec_string3);
	print(vec_string3);

	return 0;
}
