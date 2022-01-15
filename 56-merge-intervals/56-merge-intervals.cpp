class Solution {
public:
    

bool static sortOnA1( vector<int> &a1, vector<int> &a2) {
	if (a1[0] < a2 [0])
		return true;
	else
		return false;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int> > retVal; 
		 sort(intervals.begin(), intervals.end(), sortOnA1);
        bool mergefound = false;
	    int size = intervals.size();
	    for ( int i = 0; i < size; i++ ){
				if ( ( i < size-1 ) &&  (intervals[i][1] >= intervals[i+1][0]) ) {
                    int val = intervals[i+1][1] > intervals[i][1] ? intervals[i+1][1] : intervals[i][1];
					vector<int> temp { intervals[i][0],val };
                    retVal.push_back(temp);
					i++; 
                    mergefound = true;
				}
				else{
					retVal.push_back(intervals[i]);
                }
    	}
        if ( mergefound )
	        return merge( retVal ) ;
        else{
            return retVal;
        }
}
};