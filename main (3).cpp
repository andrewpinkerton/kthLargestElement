#include <iostream>
#include <vector>

using namespace std;

void heapify(int A[], int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && A[left] > A[max])
        max = left;

    if (right < n && A[right] > A[max])
        max = right;

    if (max != i) {
        int temp = A[i];
        A[i] = A[max];
        A[max] = temp;

        heapify(A, n, max);
    }
}

void buildMaxHeap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(A, n, i);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[size - 1];
}

void kthLargestElement(int A[], int k, int size)
{
    vector<int> newA;
    for (int i = 0; i < size; i++)
    {
        newA.push_back(A[i]);
    }

    buildMaxHeap(newA.data(), newA.size());

    for (int i = 0; i < k; i++)
    {
        swap(newA[0], newA[newA.size() - 1]);
        newA.pop_back();
        buildMaxHeap(newA.data(), newA.size());

        cout << "After extracting the largest element (k=" << i + 1 << "): ";
        printArray(newA.data(), newA.size());
        cout << endl << endl;
    }

    if (k == 0)
    {
        cout << "The largest number is : " << newA[0] << endl;
    }
    else
    {
        cout << "The (" << k << ") kth largest number is : " << newA[0] << endl;
    }
}

int main()
{
    const int size = 6;
    int arr[size] = { 12, 11, 13, 5, 6, 7 };
    int k = 3;

    if (k > size)
    {
        cout << "K is larger than the size of the array";
        return 1;
    }

    cout << "Given the array [";
    printArray(arr, size);
    cout << "] and k = " << k << endl << endl;

    cout << "Original Array: ";
    printArray(arr, size);
    cout << endl << endl;

    buildMaxHeap(arr, size);
    cout << "Max Heap: ";
    printArray(arr, size);
    cout << endl << endl << endl;


    kthLargestElement(arr, k, size);

    return 0;
}