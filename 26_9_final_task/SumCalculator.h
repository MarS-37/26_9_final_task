#ifndef SUM_CALCULATOR_H
#define SUM_CALCULATOR_H

#include <vector>
#include <thread>

class SumCalculator {
private:
    std::vector<int> array;                 //array for sum calculation
    int num_threads;                        //number of streams
    std::vector<int> part_sums;             //sums of the array parts
    std::vector<std::thread> thread_pool;   //stream pool

    //method for calculating the sum of an array part
    void calculatePartSum(int index, std::vector<int> chunk);

public:
    //class constructor, accepts array and number of threads
    SumCalculator(const std::vector<int>& arr, int threads);

    //method for splitting an array into parts
    void divideArray();

    //method for calculating the array total amount
    int calculateTotalSum();

    //method for starting threads
    void runThreads();
};

#endif