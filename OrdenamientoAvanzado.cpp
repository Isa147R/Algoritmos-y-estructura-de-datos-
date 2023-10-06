#include <iostream>
#include <vector>
using namespace std;

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Quicksort
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// Heapsort
void heapify(int arr[], int n, int i);
void heapsort(int arr[], int n);

// Radix Sort
void countingSort(vector<int>& arr, int exp);
void radixSort(vector<int>& arr);

// Bucket Sort
void bucketSort(vector<float>& arr);

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right);
void mergeSort(vector<int>& arr, int left, int right);

int main() {
    // Selection Sort
    int arr_selection_sort[] = {64, 25, 12, 22, 11};
    int n_selection_sort = sizeof(arr_selection_sort) / sizeof(arr_selection_sort[0]);
    selectionSort(arr_selection_sort, n_selection_sort);
    cout << "Selection Sort: ";
    for (int i = 0; i < n_selection_sort; ++i) {
        cout << arr_selection_sort[i] << " ";
    }
    cout << endl;

    // Insertion Sort
    int arr_insertion_sort[] = {64, 25, 12, 22, 11};
    int n_insertion_sort = sizeof(arr_insertion_sort) / sizeof(arr_insertion_sort[0]);
    insertionSort(arr_insertion_sort, n_insertion_sort);
    cout << "Insertion Sort: ";
    for (int i = 0; i < n_insertion_sort; ++i) {
        cout << arr_insertion_sort[i] << " ";
    }
    cout << endl;

    // Bubble Sort
    int arr_bubble_sort[] = {64, 25, 12, 22, 11};
    int n_bubble_sort = sizeof(arr_bubble_sort) / sizeof(arr_bubble_sort[0]);
    bubbleSort(arr_bubble_sort, n_bubble_sort);
    cout << "Bubble Sort: ";
    for (int i = 0; i < n_bubble_sort; ++i) {
        cout << arr_bubble_sort[i] << " ";
    }
    cout << endl;

    // Quicksort
    int arr_quicksort[] = {64, 25, 12, 22, 11};
    int n_quicksort = sizeof(arr_quicksort) / sizeof(arr_quicksort[0]);
    quicksort(arr_quicksort, 0, n_quicksort - 1);
    cout << "Quicksort: ";
    for (int i = 0; i < n_quicksort; ++i) {
        cout << arr_quicksort[i] << " ";
    }
    cout << endl;

    // Heapsort
    int arr_heapsort[] = {64, 25, 12, 22, 11};
    int n_heapsort = sizeof(arr_heapsort) / sizeof(arr_heapsort[0]);
    heapsort(arr_heapsort, n_heapsort);
    cout << "Heapsort: ";
    for (int i = 0; i < n_heapsort; ++i) {
        cout << arr_heapsort[i] << " ";
    }
    cout << endl;

    // Radix Sort
    vector<int> arr_radix_sort = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr_radix_sort);
    cout << "Radix Sort: ";
    for (int i = 0; i < arr_radix_sort.size(); ++i) {
        cout << arr_radix_sort[i] << " ";
    }
    cout << endl;

    // Bucket Sort
    vector<float> arr_bucket_sort = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};
    bucketSort(arr_bucket_sort);
    cout << "Bucket Sort: ";
    for (int i = 0; i < arr_bucket_sort.size(); ++i) {
        cout << arr_bucket_sort[i] << " ";
    }
    cout << endl;

    // Merge Sort
    vector<int> arr_merge_sort = {64, 25, 12, 22, 11};
    mergeSort(arr_merge_sort, 0, arr_merge_sort.size() - 1);
    cout << "Merge Sort: ";
    for (int i = 0; i < arr_merge_sort.size(); ++i) {
        cout << arr_merge_sort[i] << " ";
    }
    cout << endl;

    return 0;
}

// Resto de las funciones de ordenamiento

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void countingSort(vector<int>& arr, int exp) {
    const int n = arr.size();
    vector<int> output(n, 0);
    vector<int> count(10, 0);

    for (int i = 0; i < n; ++i) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        --count[(arr[i] / exp) % 10];
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int max_element = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }

    for (int exp = 1; max_element / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

void bucketSort(vector<float>& arr) {
    const int n = arr.size();
    vector<vector<float>> buckets(n);

    for (int i = 0; i < n; ++i) {
        int index = n * arr[i];
        buckets[index].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        int bucket_size = buckets[i].size();
        for (int j = 1; j < bucket_size; ++j) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && key < buckets[i][k]) {
                buckets[i][k + 1] = buckets[i][k];
                --k;
            }
            buckets[i][k + 1] = key;
        }
    }

    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr[index++] = buckets[i][j];
        }
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
