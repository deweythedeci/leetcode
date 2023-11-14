#include <algorithm>
#include <iostream>

class Solution {
public:
    string reverseWords(string s) {
        BidirectionalIterator i, j = s.begin();
        while(i != s.end()){
            j = find(i, s.end(), ' ');
            reverse(i, j);
            i = j
        }
    }
};