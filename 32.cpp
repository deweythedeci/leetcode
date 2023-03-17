#include <iostream>
using namespace std;

// incomplete

int longestValidParentheses(string s) {
    int i = 0;
    int j = 0;
    int max = 0;
    int count = 0;
    int curr = 0;
    while(j <= s.length()){
        cout << i << ' ' << j << ' ' << count << ' ' << curr << endl;
        if(!count && (j-i)){
            curr += (j-i);
            i = j;
            max = curr > max ? curr : max;
        }
        else if(count < 0){
            i = j;
            curr = 0;
            count = 0;
        }
        else{
            if(s[j] == '(') count++;
            else if(s[j] == ')') count--;
            j++;  
        }
    }
    while(i <= s.length()){
        
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