#include <iostream>
#include <chrono>

template<typename T>
void print_arr(T* arr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void merge(T* arr, int start, int half, int end) {
    int length1 = half - start + 1;
    int length2 = end - half;
    int index_left_arr = 0;
    int index_right_arr = 0;
    int index_merged_arr = start;
    T* left_arr = new T[length1];
    T* right_arr = new T[length2];
    for (int i = 0; i < length1; i++) {
        left_arr[i] = arr[start + i];
    }
    for (int i = 0; i < length2; i++) {
        right_arr[i] = arr[half + 1 + i];
    }
    while (index_left_arr < length1 && index_right_arr < length2) {
        if (left_arr[index_left_arr] <= right_arr[index_right_arr]) {
            arr[index_merged_arr] = left_arr[index_left_arr];
            index_left_arr += 1;
        }
        else {
            arr[index_merged_arr] = right_arr[index_right_arr];
            index_right_arr += 1;
        }
        index_merged_arr += 1;
    }
    while (index_left_arr < length1) {
        arr[index_merged_arr] = left_arr[index_left_arr];
        index_left_arr += 1;
        index_merged_arr += 1;
    }
    while (index_right_arr < length2) {
        arr[index_merged_arr] = right_arr[index_right_arr];
        index_right_arr += 1;
        index_merged_arr += 1;
    }
    delete[] left_arr;
    delete[] right_arr;
}

template<typename T>
void merge_sort(T* arr, int start, int end) {
    if (start < end) {
        int half = (start + end) / 2;
        merge_sort(arr, start, half);
        merge_sort(arr, half + 1, end);
        merge(arr, start, half, end);
    }
    else {
        return;
    }
}

template<typename T>
T* get_rand_nums(int n) {
    srand(time(0));
    T* numbers = new T[n];
    for (int i = 0; i < n; ++i) {
        numbers[i] = rand() % 10000 + 1;
    }

    return numbers;
}

int main() {
    int length = 1000;
    int* A = get_rand_nums<int>(length);
    print_arr<int>(A, length);
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort<int>(A, 0, length - 1);
    auto end = std::chrono::high_resolution_clock::now();
    print_arr<int>(A, length);
    std::chrono::duration<double> elapsed_time = end - start;
    std::cout << "Time: " << elapsed_time.count() << std::endl;
    delete[] A;
}
