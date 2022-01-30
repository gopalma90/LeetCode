class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int i , j;
        for ( i = 0, j = height.size()-1; i < j;  ){
            int minval = (height[i] <= height[j]) ? height[i]: height[j];
            int range = j - i;
           // cout << "range = " << range <<endl;
            
            //cout << "minval = " << minval <<endl;
            if ( max < range*minval ){
                max = range*minval;
            }
            if ( minval == height[i])
                i++;
            else if ( minval == height[j])
                j--;
        }
        return max;
    }
};