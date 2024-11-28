#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    vector<Node*> children;
    bool hasTerminal;

    Node() {
        children = vector<Node*>(10, nullptr);
        hasTerminal = false;
    }
};

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end(), [](const string& l, const string& r){
         return l.size()<r.size(); 
    });
    
    bool answer = true;

    Node* root = new Node();

    for(auto numStr: phone_book) {
        Node* cursor = root;
        for(int i=0; i<numStr.size(); i++) {
            int ind = numStr[i]-'0';

            if(cursor->children[ind] == nullptr) {
                cursor->children[ind] = new Node();
            }
            
            cursor = cursor->children[ind];
            if(cursor->hasTerminal) {
                answer = false;
                break;
            }
            if(i == numStr.size()-1) {
                cursor->hasTerminal = true;
            }
        }

        if(!answer) break;
    }

    return answer;
}