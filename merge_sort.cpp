#include <iostream>
#include <cstddef>

template <typename T>
void Merge(T* arr, int first, int mid, int last){
   int n1 = mid - first + 1;
   int n2 = last - mid;
   T arr1[n1];
   T arr2[n2];
   for(int i = 0; i < n1; ++i){
      arr1[i] = arr[first + i];
   }
   for(int j = 0; j < n2; ++j) {
      arr2[j] = arr[mid + 1 +j];
   }
   int i = 0;
   int j = 0;
   int k = first;
   while(i < n1 && j < n2){
      if(arr1[i] < arr2[j]){
         arr[k] = arr1[i];
         ++i;
      }
      else {
         arr[k] = arr2[j];
         ++j;
      }
      ++k;
   }
   while(i < n1){
      arr[k] = arr1[i];
      ++i;
      ++k;
   }
   while(j < n2){
      arr[k] = arr2[j];
      ++j;
      ++k;
   }
}

template <typename T>
void Merge_sort(T* arr, int first, int last){
   if(first < last) {
      int mid = first + (last - first) / 2;
      Merge_sort(arr, first, mid);
      Merge_sort(arr, mid + 1, last);
      Merge(arr, first, mid, last);
   }
}

int main() {
   const size_t size = 7;
   char arr[size];
   for(int i = 0; i < size; ++i){
      std::cin >> arr[i];
   }
   Merge_sort<char>(arr, 0, 6);
   for(int i = 0; i < size; ++i){
      std::cout << arr[i] << " ";
   }
   std::cout << "\n";
}
