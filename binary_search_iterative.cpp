#include <iostream>
#include <cstddef>

template <typename T>
int binary_search_iterative(T* arr, size_t size, T target) {
   int start = 0;
   int end = size;
   while(start <= end) {
      int mid = start + (end - start) / 2;
      if(arr[mid] == target) { return mid; }
      if(arr[mid] > target) {
         end = mid - 1; 
      }
      else {
         start = mid + 1;
      }
   }
   return -1;
}

int main() {
   const size_t size = 7;
   char arr[size] = {'a', 'c', 'f', 'h', 'k', 'm', 'p'};
   char target = 'h';
   std::cout << binary_search_iterative<char>(arr, size, target) << "\n";;
}

