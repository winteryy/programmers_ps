#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;

    for(int i=word.size()-1; i>=0; i--) {
        char c = word[i];
        switch(c) {
            case 'A': {
                answer+=1;
                break;
            }
            case 'E': {
                
                break;
            }
            case 'I': {
                
                break;
            }
            case 'O': {
                
                break;
            }
            case 'U': {
                
                break;
            }
        }
    }
    return answer;
}