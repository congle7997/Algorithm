#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    int a[n],b[m];
    int aa[n],bb[m];
    memset(aa,0,sizeof(aa));
    memset(bb,0,sizeof(bb));

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }

    int maxm[m];memset(maxm,0,sizeof(maxm));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(a[i] == b[j]){
                if(j== 0){
                    maxm[0] = 1;
                }else{
                    //j>0
                    maxm[j] = maxm[j-1] + 1;
                }
            }

            if(j>0){
                maxm[j] = max(maxm[j-1],maxm[j]);
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<maxm[i]<<" ";
    }cout<<endl;
    
    cout<<maxm[m-1];

    return 0;
}