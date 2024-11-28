#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{   
    unordered_map<int, int> um;
    for(auto num: nums) {
        um[num]++;
    }

    return um.size()>=nums.size()/2 ? nums.size()/2 : um.size();
}