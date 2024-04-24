#include <iostream>
#include <limits.h>
#include <vector>
#include <omp.h>

void min_reduction(std::vector<int> &arr) {
    int min_value = INT_MAX;

#pragma omp parallel for reduction(min : min_value)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    std::cout << "Minimum value: " << min_value << std::endl;
}

void max_reduction(std::vector<int> &arr) {
    int max_value = INT_MIN;
    
#pragma omp parallel for reduction(max : max_value)
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    std::cout << "Maximum value: " << max_value << std::endl;
}

void sum_reduction(std::vector<int> &arr) {
    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    std::cout << "Sum: " << sum << std::endl;
}

void average_reduction(std::vector<int> &arr) {
    int sum = 0;
    
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    std::cout << "Average: " << (double)sum / arr.size() << std::endl;
}

int main(int argc, char** argv) {
    std::vector<int> arr = {5, 2, 9, 1, 7, 6, 8, 3, 4};

    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    average_reduction(arr);
}
