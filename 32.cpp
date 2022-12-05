#include <iostream>
#include <vector>
#include <variant>
#include <tuple>
using namespace std;

int findNumEnd(string s, int idx);

// totally works but uses too much memory

int longestValidParentheses(string s) {
    cout << s << endl;
    int i = 1;
    int max = 0;
    while(i < s.length()){
        if(s[i-1] == '('){
            if(s[i] == ')'){
                s = s.substr(0,i-1) + ".2" + s.substr(i+1);
                return longestValidParentheses(s);
            }
            else if(s[i] == '.'){
                int iend = findNumEnd(s,i+1);
                if(s[iend] == '(' || s[iend] == '\0'){
                    int a = stoi(s.substr(i+1,iend));
                    if(max < a){
                        max = a;
                    }
                    i = iend;
                    continue;
                }
                if(s[iend] == ')'){
                    int a = stoi(s.substr(i+1,iend));
                    s = s.substr(0, i-1) + '.' + to_string(a+2) + s.substr(iend+1);
                    return longestValidParentheses(s);
                }
                else if(s[iend] == '.'){
                    int iend2 = findNumEnd(s,iend+1);
                    int a = stoi(s.substr(i+1,iend));
                    int b = stoi(s.substr(iend+1,iend2));
                    s = s.substr(0, i) + '.' + to_string(a+b) + s.substr(iend2);
                    return longestValidParentheses(s);
                }
            }
        }
        else if(s[i-1] == '.'){
            int iend = findNumEnd(s,i);
            if(s[iend] == '(' || s[iend] == ')' || s[iend] == '\0'){
                int a = stoi(s.substr(i,iend));
                if(max < a){
                    max = a;
                }
                i = iend;
                continue;
            }
            else if(s[iend] == '.'){
                int iend2 = findNumEnd(s,iend+1);
                int a = stoi(s.substr(i,iend));
                int b = stoi(s.substr(iend+1,iend2));
                s = s.substr(0, i-1) + '.' + to_string(a+b) + s.substr(iend2);
                return longestValidParentheses(s);
            }
        }
        i++;
    }
    return max;
}

int findNumEnd(string s, int idx){
    int iend = idx;
    while(iend < s.length()){
        if(s[iend] == '(' || s[iend] == ')' || s[iend] == '.'){
            break;
        }
        iend++;
    }
    return iend;
}

int main(int argc, char** argv){
    if(argc != 2){
        cout << "usage: " << argv[0] << " str" << endl;
        return 1;
    }
    cout << longestValidParentheses(argv[1]) << endl;
    return 0;
}