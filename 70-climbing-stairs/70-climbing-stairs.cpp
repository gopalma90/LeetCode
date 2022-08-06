class Solution {
public:
    int climbStairs(int n) {
        vector<int> arr (n,0 );
         if ( n <=3 ) return n;
        arr[0] = 1;
        arr[1] = 2;
       
        for ( int i = 2; i < n; i++ ){
            arr[i] = arr[i-1] + arr[i-2];
        }
        
     //   cout << " ways = "<< arr[n-1];
        return arr[n-1];
    }
};