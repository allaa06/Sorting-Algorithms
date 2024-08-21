#include <iostream>
#include <cstddef>

template <typename T>
void counting_sort(T* arr, size_t size) {
   T max =arr[0];
   T* output = new T[size];
   for(int i = 1; i < size; ++i){
      if(arr[i] > max) {
         max = arr[i];
   }
   }
   T* counting = new T[max + 1];
   for(int i = 0; i < size; ++i) {
      counting[arr[i]]++;
   }
   for(int i = 1; i <= max; ++i) {
      counting[i] += counting[i - 1];
   }
   for(int i = size - 1; i >= 0; --i) {
      output[counting[arr[i]] - 1] = arr[i];
      --counting[arr[i]];
   }
   for(int i = 0; i < size; ++i) {
      arr[i] = output[i];
   }
   delete[] counting;
   delete[] output;
}


int main() {
   const size_t size = 8;
   char arr[size] = {'b', 'b', 'a', 'b', 'a', 'a', 'e', 'c'};
   counting_sort<char>(arr, size);
   for(int i = 0; i < size; ++i) {
      std::cout << arr[i] << " ";
   }
}
