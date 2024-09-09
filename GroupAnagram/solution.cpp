#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, int> m;
        int idx = 0;

        for(auto i : strs)
        {
            if(m.find(i) != m.end()) 
            {
                ret[m[i]].push_back(i);
            }
            else 
            {
                m[reverse_str(i)] = idx++;
                ret.push_back(vector<string>{i});
            }
        }    
        return ret;
    }

    string reverse_str(string& str)
    {
        string ret;
        for(auto i : str)
        {
            ret = i + ret;
        }

        return ret;
    }
};