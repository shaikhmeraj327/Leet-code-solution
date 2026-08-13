#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int maxLen, preLen, sufLen, sz;
    char preChar, sufChar;

    Node() : maxLen(0), preLen(0), sufLen(0), sz(0), preChar('\0'), sufChar('\0') {}
    Node(char c) : maxLen(1), preLen(1), sufLen(1), sz(1), preChar(c), sufChar(c) {}
};

class SegmentTree {
    vector<Node> tree;
    int n;

    Node merge(const Node& L, const Node& R) {
        Node res;
        res.sz = L.sz + R.sz;
        res.preChar = L.preChar;
        res.sufChar = R.sufChar;
        
        res.maxLen = max(L.maxLen, R.maxLen);
        res.preLen = L.preLen;
        res.sufLen = R.sufLen;

        // If characters in the middle match, join them
        if (L.sufChar == R.preChar) {
            res.maxLen = max(res.maxLen, L.sufLen + R.preLen);
            if (L.preLen == L.sz) res.preLen = L.sz + R.preLen;
            if (R.sufLen == R.sz) res.sufLen = R.sz + L.sufLen;
        }
        return res;
    }

public:
    SegmentTree(string& s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void build(string& s, int v, int tl, int tr) {
        if (tl == tr) tree[v] = Node(s[tl]);
        else {
            int tm = (tl + tr) / 2;
            build(s, 2 * v, tl, tm);
            build(s, 2 * v + 1, tm + 1, tr);
            tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
        }
    }

    void update(int v, int tl, int tr, int pos, char ch) {
        if (tl == tr) tree[v] = Node(ch);
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2 * v, tl, tm, pos, ch);
            else update(2 * v + 1, tm + 1, tr, pos, ch);
            tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
        }
    }

    int query() { return tree[1].maxLen; }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryIndices.size();
        SegmentTree st(s);
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            st.update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(st.query());
        }
        return ans;
    }
};