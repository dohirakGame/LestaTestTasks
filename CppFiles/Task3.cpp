#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class RadixSort {
private:
    int GetMax(const vector<int>& arr) {
        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    void CountingSort(vector<int>& arr, int exp) {
        vector<int> output(arr.size()); 
        int count[10] = { 0 };

        for (int num : arr) {
            int digit = (num / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
public:
    void radixSort(vector<int>& arr) {
        int max = GetMax(arr);

        for (int exp = 1; max / exp > 0; exp *= 10) {
            CountingSort(arr, exp);
        }
    }
};
class QuickSort {
private:
    void SwapElement(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int Division(vector<int>& arr, int left, int last) {
        int pivot = arr[last];
        int i = left - 1;

        for (int j = left; j < last; j++) {
            if (arr[j] <= pivot) {
                i++;
                SwapElement(arr[i], arr[j]);
            }
        }
        SwapElement(arr[i + 1], arr[last]);
        return i + 1;
    }
public:
    void quickSort(vector<int>& arr, int left, int last) {
        if (left < last) {
            int pi = Division(arr, left, last);

            quickSort(arr, left, pi - 1);
            quickSort(arr, pi + 1, last);
        }
    }
};

int main() {
    vector<int> arr1 = { 170, 45, 75, 90, 802, 24, 2, 66 , 123, 543, 96, 1, 23, 12378};
    RadixSort rs;
    rs.radixSort(arr1);

    cout << "Sorted array: ";
    for (int num : arr1) {
        cout << num << " ";
    }
    cout << endl;
    
    vector<int> arr2 = { 170, 45, 75, 90, 802, 24, 2, 66 , 123, 543, 96, 1, 23, 12378 };
    int n = arr2.size();
    QuickSort qs;
    qs.quickSort(arr2, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    return 0;
}