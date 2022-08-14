class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> newstr(strs);
        for ( int i = 0; i < strs.size(); i++ ){
            sort( newstr[i].begin(), newstr[i].end() );
        }
        
        map<string, vector<string> > tempmap;
        for ( int i = 0; i < strs.size(); i++ ){
            auto it = tempmap.find(newstr[i]);
            if ( it != tempmap.end() ){
                vector<string> temp = it->second;
                temp.push_back(strs[i]);
                tempmap[newstr[i]]=temp;
            }
            else {
                vector<string> temp {strs[i]};
                tempmap[newstr[i]] = temp;
            }
        }
     
        vector<vector<string> > res;
        for ( auto it = tempmap.begin(); it!=tempmap.end(); it++ ){
            res.push_back( it->second );
        }
        return res;
    }
};