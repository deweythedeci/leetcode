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
    while(j <= s.length()){
        cout << "i=" << i;
        cout << ",j=" << j;
        cout << ",count=" << count;
        cout << ",curr=" << curr;
        cout << ",max=" << max;
        cout << ",bool=" << up;
        cout << endl;
        if(up){
            if(s[j] == '('){
                count++;
                j++;
            }
            else{
                up = false;
            }
        }
        else{
            if(!count){
                curr += j-i;
                i = j;
                max = curr > max ? curr : max;
            }
            else if(count < 0){
                count = 0;
                curr = 0;
                i = j;
            }
            else if(s[j] == ')'){
                count--;
                j++;
            }
            else{
                up = true;
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