#include <iostream>
#include <cstddef>

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
int partition(T* arr, int f, int e)
{
    T pivot = arr[e];
    int i = f;
    int j = e - 1;
    while(i <= j)
    {
    while(arr[i] < pivot)
    {
       ++i;
    }
    while(arr[j] >= pivot)
    {
       --j;
    }
    if(i < j)
    {
       swap(arr[i], arr[j]);
    
    }
    }
    swap(arr[i], arr[e]);
    return i;
}

template <typename T>
void quick_sort(T* arr, int f, int e)
{
    if(e > f)
    {
        int ind = partition(arr, f, e);
        quick_sort(arr, f, ind -1);
        quick_sort(arr, ind + 1, e);
    }
}

int main()
{
    const size_t size = 8;
    int arr[size];
    std::cout << "Enter the elements\n";
    for(int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    quick_sort<int>(arr, 0, size - 1);
    std::cout << "The result is `\n";
    for(int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << " ";
}


