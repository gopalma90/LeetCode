class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len  = s.length();
        if ( len < 1 )
            return 0;
        int currcount = 1;
        int lastindexchkd = 1;
        int count ;
        bool foundsame = false;
        for ( int i = 0; i < len-1 ; i++) {
            count = 1;
            foundsame = false;
            if ( lastindexchkd >len-1 )
                break;
            for ( int j = lastindexchkd-1 ; j >= i; j--  ){
                if ( s.at(lastindexchkd ) != s.at(j) ){
                    count++;
                }
                else{
                    foundsame = true;
                    break;
                }
            }
           
            if ( !foundsame ){
                i--;
                lastindexchkd++;
            }
            if ( count > currcount )
                currcount = count;
        }
        return currcount;

    }
};