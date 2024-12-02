#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    brown-=4;
    for(int i=yellow; i>=1; i--) {
        if(yellow%i==0 && i*2+(yellow/i)*2==brown) {
            answer.push_back(i+2);
            answer.push_back(yellow/i+2);
            break;
        }
    }
    return answer;
}