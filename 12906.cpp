#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(auto num: arr) {
        if(answer.empty() || answer[answer.size()-1]!=num) {
            answer.push_back(num);
        }
    }

    return answer;
}