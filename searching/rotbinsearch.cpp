#include <vector>
#include <iostream>
#include <algorithm>

int binSearch(const std::vector<int>& v){
    /**
    * Return by how many places a vector sorted in ascending
    * order was shifted, e.g. the index of the pivot in the vector.
    */
    int left = 0;
    int right = v.size() - 1;
    int middle = (right - left) / 2;
    while (v[middle] < v[middle+1]){
        if (v[middle] > v[right]){
            left = middle;
        }else if (v[middle] < v[right]){
            right = middle;
        }
        middle = left + (right - left) / 2;
    }
    return middle;

}

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> const& v){
    for (auto const& element : v)    {
        os << element << " ";
    }
    return os;
}

int main(){
    std::vector<int> v{9, 13, 16, 18, 19, 23, 28, 31, 37, 42, 1, 3, 4, 5, 7, 8};
    int rotation = binSearch(v) + 1;
    std::cout << v << std::endl;
    std::cout << "Vector was rotated by " << rotation << "." << std::endl;
    std::rotate(v.begin(), v.begin()+rotation, v.end());
    std::cout << v << std::endl;
    }

    