#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000007
bool marked[100007];
int prime[mx+1],k,save[mx];

void sieve()
{
    prime[1]=1;
    for(int i=4; i<=mx; i+=2)
    {
        prime[i]=1;
    }
    int x=sqrt(mx);
    for(int i=3; i<=x; i+=2)
    {
        if(!prime[i])
        {
            for(int j=i*i; j<=mx; j+=(2*i))
                prime[j]=1;
        }
    }
    for(int i=2; i<=mx; i++)
    {
        if(prime[i]==0)
            save[k++]=i;
    }
}
int main()
{
    sieve();
    int test;cin>>test;
    for(int k=1;k<=test;k++)
    {
    ll n;
    cin>>n;
    int sq=sqrt(n);
    int res=1;
    for(int i=0;save[i]*save[i]<=n&&save[i]<=sq;i++)
    {
        if(n%save[i]==0)
        {
            int c=0;
            while(n%save[i]==0)
            {
                n/=save[i];
                c++;
            }
            sq=sqrt(n);
            c++;
            res*=c;
        }
    }
    if(n!=1)
    {
        res*=2;
    }
    res;

    //sieve(n);
    cout<<"Case "<<k<<": "<<res-1<<endl;
    //v.clear();
   // coun++;
    }
}


