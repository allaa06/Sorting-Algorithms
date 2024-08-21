#include <iostream>
#include <cstddef>

template <typename T>
void heapify(T* arr, size_t i, size_t size) {
   size_t max_ind = i;
   size_t left = i * 2 + 1;
   size_t right = i * 2 + 2;
   if(left < size && arr[i] < arr[left]) {
            max_ind = left;
   }
   if(right < size && arr[right] > arr[max_ind]) {
      max_ind = right;
   }
   if(i != max_ind) {
      std::swap(arr[i], arr[max_ind]);
      heapify(arr, max_ind, size);
   }
}

template <typename T>
void Build_Max_Heap(T* arr, size_t size) {
   for(int i = (size / 2) - 1; i >= 0; --i) {
      heapify(arr, i, size );
      
   }
}

template <typename T>
void Heap_sort(T* arr, size_t size) {
   Build_Max_Heap(arr, size);
   for(int i = size - 1; i > 0; --i) {
      std::swap(arr[0], arr[i]);
      heapify(arr, 0, i);
   }
}


int main() {
   const size_t size = 10;
   int arr[size] = {7, -1, 8, 12, 15, -9, 12, 20, 30, -25};
   Heap_sort(arr, size);
   std::cout  << "Sorted max heap\n";
   for(int i = 0;  i < size; ++i) {
      std::cout << arr[i] << " ";
   }
   
}
