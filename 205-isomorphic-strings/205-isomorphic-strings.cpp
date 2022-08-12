class Solution {
public:
    bool isIsomorphic(string s, string t) {
          map<char,char> tempmap1;
                  map<char,char> tempmap2;
    for ( int i = 0; i < s.size(); i++ ){
        auto it1 = tempmap1.find( t.at(i) );
        
        auto it2 = tempmap2.find( s.at(i) );
        if ( it1 == tempmap1.end() )
            tempmap1 [ t.at(i) ] = s.at(i);
        else{
            if ( s.at(i) != it1->second ) return false;
        }
        
         if ( it2 == tempmap2.end() )
            tempmap2 [ s.at(i) ] = t.at(i);
        else{
            if ( t.at(i) != it2->second ) return false;
        }
        
        
    }

    for ( int i = 0; i < s.size(); i++ ){
        if ( tempmap1[ t.at(i) ] != s.at(i) ){
            return false;
        }
        if ( tempmap2[s.at(i)] != t.at(i))
            return false;
    }
    return true;
    }
};