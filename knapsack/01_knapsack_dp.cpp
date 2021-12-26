/*
Author - Vedant Daigavane
*/
#include<bits/stdc++.h>
#include <sys/wait.h>
#include <unistd.h>

//datatypes
#define ld long double
#define ll long long int
#define uld unsigned long double
#define ul unsigned long long int
//other
#define nl cout<<endl;
//vectors
#define vl vector<ll>
#define vi vector<int>
#define vii vector<vi>
#define vll vector<vl>
#define vc vector<char>
#define pb push_back
//loops
#define w(t)  while(t--)
#define f(i,s,n) for(ll i=s;i<=n;i++)
//sorting
#define saa(a) sort(a,a+a.size());
#define sva(v) sort(v.begin(),v.end());
#define sad(a) sort(a,a+n,greater<int>());
#define svd(v) sort(v.begin(),v.end(),greater<int>());
using namespace std;

int knapsack(int* val, int* wt, int n, int weight){

    // base condition
    if(n <= 0 || weight <= 0){
        return 0;
    }

    // choice code
    if( wt[n-1] <= weight ){
        return max( val[n-1] + knapsack(val,wt, n-1, weight - wt[n-1]), knapsack(val,wt, n-1, weight) );
    }
    else {
        return knapsack(val,wt, n-1, weight);
    }
}


int main() {

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);    

    
    int n;
    cin>>n;
    int max_weight = 2;

    int wt[n], val[n];

    for(int i=0;i<n;i++)    cin>>val[i];
    for (int i=0;i<n;i++)   cin>>wt[i];

    cout<<knapsack(val, wt, n, max_weight);

    return 0;
}
