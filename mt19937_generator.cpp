#include <iostream>
#include <vector>
#include <random> 
#include <algorithm>
using namespace std;

int main() {
    static const int NUMBERS = 1'000;
    mt19937 generator;
    uniform_int_distribution<int> uniform_dist(0, 50);
    vector<int> nums;
    for (int i = 0; i < NUMBERS; ++i) {
        int random_number = uniform_dist(generator);
        nums.push_back(random_number);
    }
    sort(nums.begin(), nums.end());
    for (const auto el : nums){
       cout << el << ' ';
    }
}
// ./main >output.txt
