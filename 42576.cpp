#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    unordered_map<string, int> um;

    for(auto name: participant) {
        um[name]++;
    }
    for(auto name: completion) {
        um[name]--;
    }    
    for(auto p: um) {
        if(p.second!=0) {
            return p.first;
        }
    }
}