#include <algorithm>

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        struct Row {
            int index;
            int n_soldier;
            Row(int i, int n) : index(i), n_soldier(n) {}
            bool operator<(const Row& a){ return (n_soldier == a.n_soldier) ? index < a.index : n_soldier < a.n_soldier; }
        };
        // calculate n of soldiers per row
        vector<Row> rows = vector<Row>();
        for(int i = 0; i < mat.size(); i++) rows.push_back(Row(i, accumulate(mat[i].begin(), mat[i].end(), 0)));
        // sort rows by n of soldiers
        sort(rows.begin(), rows.end());
        // generate returned matrix
        vector<int>* ret = new vector<int>();
        for(int i = 0; i < k; i++) ret->push_back(rows[i].index);
        return *ret;
    }
};