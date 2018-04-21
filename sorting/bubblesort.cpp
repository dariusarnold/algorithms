/*
 * bubblesort.cpp
 *
 *  Created on: 21 Apr 2018
 *      Author: Darius Arnold
 */
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <class T>
void switch_values(T &value_1, T &value_2){
	T temporary = value_1;
	value_1 = value_2;
	value_2 = temporary;
}

template <class T>
void bubblesort(T array[], size_t size){
	for (uint32_t i=0; i<size-1; i++){
		for (uint32_t j=0; j<size-i-1; j++){
			if (array[i] > array[i+1]){
				switch_values<int>(array[i], array[i+1]);
			}
		}
	}
}


int main(){
	auto size_array = 100;
	int arr[size_array];
	for (auto i=0; i<size_array; i++){
		arr[i] = i;
	}
	high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
	bubblesort<int>(arr, size_array);
	high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(t2-t1).count();
	std::cout << "Runtime: " << duration << "µs"<< std::endl;
}



