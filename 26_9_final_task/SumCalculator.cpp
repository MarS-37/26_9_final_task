#include "SumCalculator.h"  //class declaration file
#include <numeric>

//class constructor
SumCalculator::SumCalculator(const std::vector<int>& arr, int threads) : array(arr), num_threads(threads), part_sums(threads, 0) {}

//method for calculating the sum of an array part
void SumCalculator::calculatePartSum(int index, std::vector<int> chunk) {
    part_sums[index] = std::accumulate(chunk.begin(), chunk.end(), 0);
}

//method for splitting an array into parts
void SumCalculator::divideArray() {
    int chunk_size = array.size() / num_threads;
    int start = 0;


    for (int i = 0; i < num_threads; ++i) {
        int end = (i == num_threads - 1) ? array.size() : start + chunk_size;
        std::vector<int> chunk(array.begin() + start, array.begin() + end);
        start = end;
        thread_pool.push_back(std::thread(&SumCalculator::calculatePartSum, this, i, std::move(chunk)));
    }
}

//method for calculating the array total amount
int SumCalculator::calculateTotalSum() {
    return std::accumulate(part_sums.begin(), part_sums.end(), 0);
}

//method for starting threads
void SumCalculator::runThreads() {
    for (auto& thread : thread_pool) {
        thread.join();
    }
}