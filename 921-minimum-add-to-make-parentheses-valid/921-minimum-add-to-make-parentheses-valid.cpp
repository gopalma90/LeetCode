class Solution {
public:
    int minAddToMakeValid(string s) {
        int size =  s.size();
        stack<char> rstack;
        stack<char> lstack;
        
        for ( int i = 0; i < size; i++ ){
            if ( s.at(i) == '\('){
                rstack.push('(');
            }
            else {
                if ( rstack.size() > 0 ){
                    rstack.pop();
                }
                else{
                    lstack.push(')');
                }
                
            }
        }
     
        return lstack.size() + rstack.size();
        
    }
};