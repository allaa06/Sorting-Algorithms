#include <iostream>
#include <cstddef>

template <typename T>
void swap(T& a, T& b) {
   T temp = a;
   a = b;
   b = temp;
}

template <typename T>
void selection_sort(T* arr, size_t size) {
   for(int i = 0; i < size - 1; ++i) {
      int index = i;
      for(int j = i + 1; j < size; ++j) {
         if(arr[j] < arr[index]) {
            index = j;
         }
      }
      if(index != i) {
         swap(arr[index], arr[i]);
      }
   }
}

int main() {
   const int size = 5;
   int arr[size] = {6, 2, 9, 1, 3};
   selection_sort<int>(arr, size);
   for(int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << '\n';
}
