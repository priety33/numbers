class Solution {
public:
    double angleClock(int hour, int minutes) {
        //hour-> 0.5 deg per min
        //min-> 6 deg per min
        double h= 0.5, m=6.0;
        int th=(hour*60)+minutes; //total minutes passed till now, for hour clock
        h=th*h;
        m=minutes*m; cout<<m<<" "<<h;
        double ans= abs(h-m);
        return min(ans, 360-ans);
    }
};
