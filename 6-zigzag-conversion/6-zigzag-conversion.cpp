class Solution {
public:
    string convert(string s, int numRows) {
           int rows = numRows;
        if ( rows < 2 ) return s;
    int mid = rows -2 ;
    int size = s.length();
    
    int limit = rows;

    vector< vector<char> > splitstring;
    for (int i = 0; i < size ; ){
        vector<char> values;
        for ( int j = i; j < i+limit && j < size ; j++ ){
            values.push_back(s.at(j));
        }
        
        i+=limit;
        if ( limit == rows ) limit = mid;
        else { 
            limit = rows; 
            values.emplace(values.begin(), '#'); 
            while ( values.size () < rows )
                values.push_back( '#');   

            reverse(values.begin(), values.end());
        }  
        if ( values.size() < rows )
            while ( rows - values.size() > 0 ){
                values.push_back('#');
            }
        splitstring.push_back(values );

    }

    string res;
    
    for ( int i =0; i < rows; i++ ){
    for ( int j=0; j < splitstring.size(); j++ ){
        

            vector<char> temp = splitstring[j];
            if ( temp[i] != '#' )
                res.push_back(temp[i]);
        }
    }
    return res;
    }
};