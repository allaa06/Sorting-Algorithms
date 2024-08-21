#include <iostream>
#include <cstddef>

template <typename T>
int binary_search_recursive(T* arr, size_t start, size_t end, T target) {
   if(start > end) { return -1; }
   int mid = start + (end - start) / 2;
   if(arr[mid] == target) { return mid; }
   if(arr[mid] > target) { return binary_search_recursive(arr, start, mid - 1, target); }
   else { return binary_search_recursive(arr, mid + 1, end, target); }
}

int main() {
   const size_t size = 7;
   char arr[size] = {'a', 'd', 'e', 'f', 'g', 'i', 'l'};
   char target = 'l';
   std::cout << binary_search_recursive<char>(arr, 0, size, target) << "\n";
}
