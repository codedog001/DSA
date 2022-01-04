#include<bits/stdc++.h>
using namespace std;
#define d double
#define pd pair<double, double>

double findDistance(d x1, d y1, d x2, d y2){
    double X = (x2-x1) * (x2-x1);
    double Y = (y2-y1) * (y2-y1);
    
    double sum = X + Y;
    double distance = sqrt(sum);
    
    return distance;
}

int main(){
    
    int te;
    cin >> te;
    
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    
    while(te--){
        int n;
        cin>> n;
        
        vector<pair<pd, d>> a(n+1);
        a.push_back({{0,0},0});
        
        for(int i=1; i<=n; i++){
            d x, y, z;
            cin >> x >> y >> z;
            
            a[i] = {{x,y},z};
        }
        
        if(n==1){
            cout << a[1].second << endl;
            continue;
        }
        
        //t contains maximum happiness until this city}
        vector<d> t(n+1);
        t[0] = 0;
        t[1] = a[1].second;
        
        double dist = 0;
        
        for(int i=2; i<=n; i++){
            d maxHappiness = INT_MIN;
            for(int j=i-1; j>=1; j--){
                dist = findDistance(a[i].first.first, a[i].first.second, a[j].first.first, a[j].first.second);
            	d happinessFromThisCity = (t[j]+a[i].second) - dist;
                maxHappiness = max(maxHappiness, happinessFromThisCity);
            }
            t[i] = maxHappiness;
        }
        
        cout << t[n] << endl;
    }
    
}