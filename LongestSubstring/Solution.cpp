#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char, int> map;
        int i = 0, j = 0, max_len = 0;
        while(j < s.size()){
            if(map.find(s[j]) != map.end()){
                i = max(i, map[s[j]] + 1);
            }
            map[s[j]] = j;
            max_len = max(max_len, j - i + 1);
            j++;
        }
        return max_len;
    }
};

int main(){
    Solution sol;
    string s = "abcabaaaaacbb";
    int result = sol.lengthOfLongestSubstring(s);
    printf("Result: %d\n", result);
    return 0;
}