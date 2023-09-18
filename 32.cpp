#include <iostream>
using namespace std;

// incomplete

int longestValidParentheses(string s) {
    int i = 0;
    int j = 0;
    int max = 0;
    int count = 0;
    int curr = 0;
    bool up = true;
    while(i < s.length()){
        if(up){
            if(j == s.length()){
                break;
            }
            else if(s[j] == '('){
                count++;
                j++;
            }
            else{
                up = false;
            }
        }
        else{
            if(count < 0){
                i = j;
                curr = 0;
                count = 0;
            }
            if(!count){
                up = true;
                curr += (j-i);
                i = j;
                max = curr > max ? curr : max;
            }
            else if(j == s.length() || s[j] == '('){
                up = true;
                i = j;
                curr = 0;
                count = 0;
            }
            else if(s[j] == ')'){
                count--;
                j++;
            }
        }
    }
    return max;
}

int main(int argc, char** argv){
    if(argc != 2){
        cout << "usage: " << argv[0] << " str" << endl;
        return 1;
    }
    cout << longestValidParentheses(argv[1]) << endl;
    return 0;
}