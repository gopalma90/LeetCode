class Solution {
public:
    string maxValue(string &n, int x) {
        bool inserted = false;
        int size = n.length();
        if ( n.at(0) == '-' ){
            
                for ( int i =1; i < size ; i++ ){
                    int c = n.at(i) - '0';
                    if ( c<= x )
                        continue;
                    else{
                        inserted = true;
                        n.insert( n.begin()+i, (x+'0')); break;
                    }
                }
            if ( !inserted ){
              n.insert( n.begin()+size, (x+'0') );

            }
        }
        else{
            for ( int i = 0; i < size; i++ ){
                int c = n.at(i) - '0';
                if ( c >= x)
                    continue;
                else{
                    inserted = true;
                    n.insert( n.begin()+i, (x+'0')); break;
                }
            }
            if ( !inserted )
                n.insert( n.begin()+size, (x+'0') );
        }
        
        
        return n;
    }
   
};
