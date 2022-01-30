class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int> power ;
        power.push_back(1);
        int val = 1;
        while( val < n ){
            val *= 3;
            power.push_back( val);
        }
        int tempsum = 0;
        for ( int i = power.size()-1; i >= 0; i-- ){
            int sum = power[i]+tempsum;
            if ( sum < n ){
                tempsum+= power[i];
            }
            else if (sum == n  ){
                return true;
            }
        }
     return false;   
    }
};
    
    