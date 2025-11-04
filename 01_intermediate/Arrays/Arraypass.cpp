#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
void printElement(const std::vector<T>& arr, int i){
  if(i < 0  || i >= static_cast<int>(arr.size())){
    std::cout<<"Invalid Index!!\n";
  }
  else{
    std::cout<<"Elemen have value: "<<arr[static_cast<std::size_t>(i)]<<"\n";
  }

}

int main()
{
    std::vector v1 { 0, 1, 2, 3, 4 };
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}