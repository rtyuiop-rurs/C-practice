#include <iostream>
#include <vector>
#include <algorithm>



int main() {
    std::vector<int> arr {12, 78, 23, 45, 99, 10, 5};
    
    // Create a max-heap
    std::make_heap(arr.begin(), arr.end());
    
    int add_heap{0};
    std::cout << "Enter a number to put in the heap: ";
    std::cin >> add_heap;
    
    // Add to heap
    arr.push_back(add_heap);
    std::push_heap(arr.begin(), arr.end());
    
    std::cout << "Heap elements (max-heap order): ";
    for (auto e : arr) {
        std::cout << e << " ";
    }
    std::cout << "\n\n";

    while(!arr.empty()){
        std::pop_heap(arr.begin(),arr.end());
        std::cout<<arr.back()<<" ";
        arr.pop_back();
    }
    
    return 0;
}