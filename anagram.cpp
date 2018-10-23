class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<string,std::vector<string>> anagram_map;
        for(int i=0;i<strs.size();i++){
            string count;
            for(int j=0;j<26;j++){
                count.push_back('0');
            }
            for(int j=0;j<strs[i].size();j++){
                count[strs[i][j] - 'a']++;
            }
            if(anagram_map.count(count)){
                anagram_map[count].push_back(strs[i]);
            }
            else{
                vector<string> a(1,strs[i]);
                anagram_map[count] = a;
            }
        }
        vector<vector<string>> s;
        for(std::map<string,std::vector<string>>::iterator it=anagram_map.begin();it!=anagram_map.end();it++){
            s.push_back(it->second);
        }
        return s;
    }
};
