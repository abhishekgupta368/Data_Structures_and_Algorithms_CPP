#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include <string>
long long MOD = 1000000007;
long long MOD2 = 1000000207;
using namespace std;
int main() {
    int n,k;
    cin>>n;
    cin>>k;
    char h[n];
    scanf(" %[^\n]",h);
    unordered_map<long long,long long> M1;
    unordered_map<long long,long long> M2;
    long long p1=1;
    long long p2=1;
    for (int i = 0; i < k - 1; i++) {
        p1 = (67 * p1) % MOD;
        p2 = (67 * p2)%MOD2;
    }
    long long h1=0;
    long long h2 =0;
    for (int i = 0; i < k; i++) {
        h1 = (67 * h1 + h[i]) % MOD;
        h2 = (67 * h2 + h[i]) % MOD2;
    }
    M1[h1] = 1;
    M2[h2] = 1;
    long long cur_best = 0;
    long long a=-1;
    long long h3,h4;
    for(int j=1;j<=n-k;j++){
        h3=h1;
        h4=h2;
        for (int i = j; i <= n - k; i++) {
            //cout<<"h1: "<<h1<<endl;
            h3 = (((h3 - p1* h[i - 1]) * 67) + h[i + k - 1]) % MOD;
            h4 = (((h4 - p2* h[i - 1]) * 67) + h[i + k - 1]) % MOD2;
            //cout<<"h1: "<<h1<<endl;
            M1[h3]++;
            
            
            M2[h4]++;
        }
        
        //cout<<endl<<endl;
        //cout<<M1[h1]<<endl;
        if(cur_best<= M1[h1]&&M1[h1]==M2[h2]){
            //cout<<M1[h1]<<endl;
            cur_best = M1[h1];
            a=j-1;
        }
       /* h1 = h3;
        h2=h4;*/
        //M1.clear();
        h1 = (((h1 - p1* h[j - 1]) * 67) + h[j + k - 1]) % MOD;
        h2 = (((h2 - p2* h[j - 1]) * 67) + h[j + k - 1]) % MOD2;
        while(M1.count(h1)!=0){
            if(M1[h1]==cur_best){
                a=j;
            }
            j++;
            h1 = (((h1 - p1* h[j - 1]) * 67) + h[j + k - 1]) % MOD;
            h2 = (((h2 - p1* h[j - 1]) * 67) + h[j + k - 1]) % MOD2;
        }
        /*while(M2.count(h2)!=0){
            j++;
            h2 = ((((h2 - p1* h[j - 1]) * 257) + h[j + k - 1]) % MOD+MOD)%MOD;
        }*/
        //M1[h1] = 1;
    }  
    //cout<<a;
    for(int i=0;i<k;i++){
        printf("%c",h[i+a]);
    }
    return 0;
}