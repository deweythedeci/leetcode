#include <iostream>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    vector<int> digits = vector<int>();
    for(long place = 1; place <= x; place *= 10){
        digits.push_back((x / place) % 10);
    }
    for(int i = 0; i < digits.size() / 2; i++){
        if(*(digits.begin()+i) != *(digits.end()-i-1)) return false;
    }
    return true;
}

int main(int argc, char** argv){
    if(argc < 2) return 0;
    int x = stoi(argv[1]);
    cout << isPalindrome(x) << endl;
    return 0;
}