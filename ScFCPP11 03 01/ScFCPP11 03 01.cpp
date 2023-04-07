#include <iostream>
#include <map>

int getMax(int* arr, int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

void countSort(int* arr, int n) {
    int max = getMax(arr, n);
    int* output = new int[n];
    int* count = new int[max+1];
    for (int i = 0; i < max + 1; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        for (int j = 0; j < max + 1; j++) {
            //std::cout << count[j];
        }
        //std::cout << std::endl;
    }
    int k = 0;
    for (int i = 0; i < max + 1; i++) {
        for (int j = 0; j < count[i]; j++)
        output[k++] = i;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    delete[] output;
    delete[] count;
}

void countSortByMap(int* arr, int n) {
    std::map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    int k = 0;
    for (auto const& val : count) {
        for (int i = 0; i < val.second; i++)
            //std::cout << val.first;
            arr[k++] = val.first;
    }
    //std::cout << std::endl;
}

int main()
{
    int arr[] = {3, 5, 1, 2, 1, 0, 5, -5, 25, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    countSortByMap(arr1, n);
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    countSort(arr, n);
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

}

