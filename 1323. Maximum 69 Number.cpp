class Solution {
public:
    int maximum69Number (int num) {
        int pos=-1, place=0;
        int a=num;
        while(a)
        {
            if(a%10==6) pos=place;
            place++;
            a=a/10;
        }
        if(place!=-1)
        {
            num=num+(3*pow(10,pos));
        }
        return num;
    }
};
