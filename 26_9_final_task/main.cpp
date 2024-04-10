#include <iostream>
#include <vector>

class SumCalculator
{

};

int main()
{
    const int N = 10'000'000;       //array size
    const int M = 4;                //part count
    std::vector<int> array(N);

    //filling random numbers
    std::srand(std::time(nullptr));
    for (int i = 0; i < N; ++i) {
        array[i] = std::rand() % 100;
    }

    std::cout << "Array size: " << N << std::endl;
    std::cout << "Part counts: " << M << std::endl;

	return 0;
}