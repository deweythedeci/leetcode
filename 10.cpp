#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    bool isMatch(string s, string p){
        if(!p.length()){
            return !s.length();
        }
        if(p.length() > 1){
            if(p[1] == '*'){
                if(s.length()){
                    if(s[0] == p[0] || p[0] == '.'){
                        return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
                    }
                }
                return isMatch(s, p.substr(2));
            }
        }
        if(!s.length()){
            return !p.length();
        }
        if(s[0] == p[0] || p[0] == '.'){
            return isMatch(s.substr(1), p.substr(1));
        }
        return false;
    }
};

int main(int argc, char** argv){
    if(argc < 2){
        cout << "usage: " << argv[0] << " string pattern" << endl;
        return 1;
    }
    Solution* s = new Solution();
    cout << "s=" << argv[1] << " p=" << argv[2] << endl;
    cout << "isMatch=" << s->isMatch(argv[1], argv[2]) << endl;
    return 0;
}