

#include <iostream>
#include <cstdlib>
#include <chrono>

void print_arr(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int separation(int* list, int start, int end) {
	
	int pivot = list[end];
	int i = start - 1;

	for (int j = start; j <= end - 1; j++) {
		if (list[j] <= pivot) {
			i += 1;
			std::swap(list[i], list[j]);

		}
	}
	
	std::swap(list[i + 1], list[end]);
	return i + 1;
}

int random_separation(int* arr, int start, int end) {
	srand(time(0));
	int random_index = start + rand() % (end - start);
	std::swap(arr[random_index], arr[end]);
	return separation(arr, start, end);
}
void quick_sort(int arr[], int start, int end) {

	if (start < end) {
		int sep = random_separation(arr, start, end);
		quick_sort(arr, start, sep - 1);
		quick_sort(arr, sep + 1, end);
	}
	else {
		return;
	}

}
int* get_rand_nums(int n) {
	srand(time(0));
	int* numbers = new int[n];
	for (int i = 0; i < n; ++i) {
		numbers[i] = rand() % 10000 + 1;
	}

	return numbers;
}

int main()
{
	
	int length = 1000;
	int* A = get_rand_nums(length);
	print_arr(A, length);
	auto start = std::chrono::high_resolution_clock::now();
	quick_sort(A, 0, length - 1);
	auto end = std::chrono::high_resolution_clock::now();
	print_arr(A, length);
	std::chrono::duration<double> elapsed_time = end - start;;
	std::cout << "Time: " << elapsed_time.count() << std::endl;
	delete[] A;
}

