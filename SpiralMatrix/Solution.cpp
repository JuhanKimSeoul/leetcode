#include <vector>
#include <utility>
#include <unordered_map>

using namespace std;

// Define a custom hash function for std::pair<int, int>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0, dir = 0;
        int dx[][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<pair<int, int>, int, pair_hash> map; // Use custom hash function
        vector<int> ans;

        while(ans.size() != m*n)
        {
            ans.push_back(matrix[i][j]);
            map[make_pair(i, j)] = 1; // Corrected method to insert into map

            int next_i = i + dx[dir][0];
            int next_j = j + dx[dir][1];
            
            if( next_i >= m || 
                next_i < 0 || 
                next_j >= n || 
                next_j < 0 ||
                map.find(make_pair(next_i, next_j)) != map.end()
                )
            {
                dir = (dir+1)%4;
            }

            i += dx[dir][0];
            j += dx[dir][1];
        }
        return ans;
    }
};