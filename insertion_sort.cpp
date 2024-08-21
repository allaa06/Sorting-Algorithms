#include <iostream>
#include <cstddef>

template <typename T>
void insertion_sort(T* arr, size_t size) {
   for(int i = 1; i < size; ++i) {
      T key = arr[i];
      int j = i - 1;
      while(j  >= 0 && key < arr[j]) {
         arr[j + 1] = arr[j];
         --j;
      }
      arr[j + 1] = key;
   }
}

int main() {
   const size_t size = 5;
   char arr[size] = { 'd', 'g', 'a', 'b', 'i'};
   insertion_sort<char>(arr, size);
   for(int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
   }
   std::cout << '\n';
}
