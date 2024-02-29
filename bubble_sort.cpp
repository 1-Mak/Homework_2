

#include <iostream>
#include <chrono>


void bubble_sort(int* arr, int length) {
    int i;
    int j;
    int swap;
    for (int i = 0; i < length - 1; i++) {
        swap = false;
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swap = true;

            }
        }
        if (swap == false) {
            break;
        }
    }
}

void print_arr(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
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
    bubble_sort(A,length);
    auto end = std::chrono::high_resolution_clock::now();
    print_arr(A, length);
    std::chrono::duration<double> elapsed_time = end - start;;
    std::cout << "Time: " << elapsed_time.count() << std::endl;
    delete[] A;
}

