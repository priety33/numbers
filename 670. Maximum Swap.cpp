class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        int ans=num;
        while(num)
        {
            v.insert(v.begin(), num%10);
            num=num/10;
        }
        int n=v.size();
        vector<int> ng(n, -1); //next greater
        stack<int> s;
        s.push(n-1);
        for(int i=n-2; i>=0; i--)
        {
            while(!s.empty() && v[s.top()]<=v[i]) s.pop();
            if(!s.empty()) ng[i]=s.top();
            s.push(i);
        }
        int i=0;
        while(i<n && ng[i]==-1) i++; 
        if(i==n) return ans;
        
        int j=i+1; //finding the maximum digit on its right
        int in=j, m=v[j];
        for(j; j<n; j++)
        {
            if(v[j]>=m && v[j]>v[i])
            {
                m=v[j];
                in=j;
            }
        }
        swap(v[i], v[in]);
        
        ans=v[0];
        for(int i=1;i<n;i++) ans= ans*10 + v[i];
        return ans;
    }
};
