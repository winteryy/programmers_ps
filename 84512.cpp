#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = 0;

    for(int i=word.size()-1; i>=0; i--) {
        char c = word[i];
        int curPosNum; 
        switch(i) {
            case 4: {
                curPosNum = 1;
                break;
            }
            case 3: {
                curPosNum = 6;
                break;
            }
            case 2: {
                curPosNum = 31;
                break;
            }
            case 1: {
                curPosNum = 156;
                break;
            }
            case 0: {
                curPosNum = 781;
                break;
            }            
        }
        
        switch(c) {
            case 'A': {
                answer+=curPosNum*0+1;
                break;
            }
            case 'E': {
                answer+=curPosNum*1+1;
                break;
            }
            case 'I': {
                answer+=curPosNum*2+1;                
                break;
            }
            case 'O': {
                answer+=curPosNum*3+1;                
                break;
            }
            case 'U': {
                answer+=curPosNum*4+1;                
                break;
            }
        }
    }
    return answer;
}