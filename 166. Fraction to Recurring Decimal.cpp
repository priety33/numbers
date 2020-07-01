class Solution {
public:
    string fractionToDecimal(int num, int den) {
        unordered_map <int, int> rem;
        string ans="";
        if(num==0 || den==0) return "0";
        
        if((num<0)^(den<0)) ans+="-";
        long n= abs((long)num); //because INT_MIN * -1, gives overfloe, therefore make it long.
        long d= abs((long)den);
        
        ans+= to_string(n/d);
        long r= n%d;
        
        if(!r) return ans;
        ans+= ".";
        
        while(r) {
            if(rem.find(r)!=rem.end()) {
                ans.insert(rem[r], 1, '(');
                ans+=")";
                break;
            }
            rem[r]= ans.size();
            r= r*10;
            ans+= to_string(r/d);
            r= r%d;
        }
        return ans;
    }
};
