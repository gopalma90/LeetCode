class Solution {
public:
    bool isSubsequence(string s, string t) {
        
       bool found = false;
    int j = 0;
    for ( int i =0; i < s.size(); i++ ){
        found = false;

        while( j<t.size() ){
            if ( s.at(i) == t.at(j) ){
                j++ ;
                found = true;
                break;
            }
            else{
                j++;
            }
        }
        if ( !found ) return false;

        if ( j > t.size() && i< s.size() ) return false;
    }
        return true;
    }
};