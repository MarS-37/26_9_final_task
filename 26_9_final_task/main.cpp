#include "SumCalculator.h" //class declaration file
#include <iostream>
#include <numeric>
#include <cstdlib>
#include <vector>
#include <ctime>



int main() {
    const int N = 10'000'000;       //array size
    const int M = 4;                //part count
    std::vector<int> array(N);

    //filling random numbers
    std::srand(std::time(nullptr));
    for (int i = 0; i < N; ++i) {
        array[i] = std::rand() % 100;
    }



    //creating an instance of SumCalculator class and passing
    //the array and number of threads to the constructor
    SumCalculator calculator(array, M);

    //multithreaded part
    std::clock_t start_time = std::clock(); //start time
    calculator.divideArray();               //splitting an array into parts
    calculator.runThreads();                //starting threads
    int total_sum = calculator.calculateTotalSum(); //calculating the total amount
    std::clock_t end_time = std::clock();   //end time

    std::cout << "Total sum of array elements: " << total_sum << std::endl;
    std::cout << "Execution time using multiple threads: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << std::endl;

    //single-stream part
    start_time = std::clock();  //start time
    int single_thread_sum = std::accumulate(array.begin(), array.end(), 0);
    end_time = std::clock();    //end time

    std::cout << "\nTotal sum of array elements in one thread: " << single_thread_sum << std::endl;
    std::cout << "Execution time in one thread: " << (double)(end_time - start_time) / CLOCKS_PER_SEC << " seconds" << std::endl;

    return 0;
}