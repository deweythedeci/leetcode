#include <iostream>

using namespace std;

class Solution {
public:
    bool isFascinating(int n) {
        int a = 0, b;
        for(int j = n; j <= n * 3; j += n){
            for(int i = 1; i < 1000; i *= 10){
                b = (int) ((j / i) % 10);
                //cout << a << " " << b << endl;
                if(!b) { return false; }
                if((a >> (b - 1)) % 2){ return false; }
                else {
                    a += (1 << (b - 1));
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv){
    if(argc < 2) { return 1; }
    Solution s;
    cout << s.isFascinating(stoi(argv[1])) << endl;
}