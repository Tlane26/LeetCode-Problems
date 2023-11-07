#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

// Complejidad O(n)
// T(n)
bool hashSetSolution(int* nums){
    unordered_set<int> myset;
    
    for(int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        if (myset.find(nums[i]) != myset.end()) {
            cout << "Se encontró un valor duplicado: " << nums[i] << endl;
            return 1;
        }
        myset.insert(nums[i]);
    }
    
    cout << "No se encontraron valores duplicados." << endl;
    return 0;
}

// Complejidad O(n log n)
bool sortingSolution(int* nums){

    vector<int> numsVec(nums, nums + (sizeof(nums) / sizeof(nums[0])));

    sort(numsVec.begin(), numsVec.end());
    for (int i = 1; i < sizeof(nums) / sizeof(nums[0]); i++) {
        if (numsVec[i] == numsVec[i - 1])
            return true;
    }

    return false;
}

int main(int argc, char const *argv[]) {
    int nums[] = {1, 2, 3, 1};
    unordered_set<int> myset;


    // Best Solution
    hashSetSolution(nums);

    // Other solutions
    sortingSolution(nums);


    return 0;
}
