#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int main()
{
    vector<int> nums = {2,7,11,15};
    int target = 9;

    // {numero, posicion del arreglo}
    unordered_map<int, int> map;

    for(int i = 0; i < nums.size(); i++){
        if(map.find(target-nums[i]) == map.end()){
            map[nums[i]] = i;
        }
        else{
            cout << i << " " << map[target-nums[i]];
        }
    }
    
    return 0;
}
