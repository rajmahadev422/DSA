#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    struct Block {
        char type;
        int start;
        int end;
        int len;
    };

    struct SegmentTree {
        int n;
        vector<int> tree;

        void init(int size) {
            n = size;
            if (n > 0) tree.assign(4 * n, 0);
        }

        void build(const vector<int>& arr, int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];
                return;
            }
            int mid = start + (end - start) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = max(tree[2 * node], tree[2 * node + 1]);
        }

        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) return 0;
            if (l <= start && end <= r) return tree[node];
            int mid = start + (end - start) / 2;
            return max(query(2 * node, start, mid, l, r),
                       query(2 * node + 1, mid + 1, end, l, r));
        }

        int queryMax(int l, int r) {
            if (l > r || n == 0) return 0;
            return query(1, 0, n - 1, l, r);
        }
    };

public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.length();
        int total_ones = 0;
        
        vector<Block> blocks;
        vector<int> block_id(n);
        
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            
            blocks.push_back({s[i], i, j - 1, j - i});
            int b_idx = blocks.size() - 1;
            
            for (int k = i; k < j; ++k) {
                block_id[k] = b_idx;
                if (s[k] == '1') total_ones++;
            }
            i = j;
        }
        
        int num_blocks = blocks.size();
        
        vector<int> gain_arr(num_blocks, 0);
        for (int k = 1; k < num_blocks - 1; ++k) {
            if (blocks[k].type == '1') {
                gain_arr[k] = blocks[k - 1].len + blocks[k + 1].len;
            }
        }
        
        SegmentTree st;
        st.init(num_blocks);
        if (num_blocks > 0) {
            st.build(gain_arr, 1, 0, num_blocks - 1);
        }
        
        vector<int> ans;
        ans.reserve(queries.size());
        
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            int b_l = block_id[l];
            int b_r = block_id[r];
            
            if (b_r - b_l <= 1) {
                ans.push_back(total_ones);
            } else {
                int max_gain = 0;
                
                int k1 = b_l + 1;
                if (blocks[k1].type == '1') {
                    int left_len = blocks[k1 - 1].end - l + 1;
                    int right_len = (k1 + 1 == b_r) ? r - blocks[k1 + 1].start + 1 : blocks[k1 + 1].len;
                    max_gain = max(max_gain, left_len + right_len);
                }
                
                int k2 = b_r - 1;
                if (blocks[k2].type == '1') {
                    int left_len = (k2 - 1 == b_l) ? blocks[k2 - 1].end - l + 1 : blocks[k2 - 1].len;
                    int right_len = r - blocks[k2 + 1].start + 1;
                    max_gain = max(max_gain, left_len + right_len);
                }
                
                if (b_l + 2 <= b_r - 2) {
                    max_gain = max(max_gain, st.queryMax(b_l + 2, b_r - 2));
                }
                
                ans.push_back(total_ones + max_gain);
            }
        }
        
        return ans;
    }
};