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

struct Item {
    int val;
    int weight;

    // constructor
};

bool compare(Item a, Item b) {
    float ra =  a.val/a.weight;
    float rb =  b.val/b.weight;
    return ra>rb;
}

int knapsack_greedy( int n, Item* arr, int max ) {
    sort( arr, arr + n, compare );

    int currWeight = 0;
    int value = 0;

    for(int i=0;i<n;i++) {
        if((max - currWeight) >= arr[i].weight) {
            currWeight+=arr[i].weight;
            value += arr[i].val;
        }

        else {
            int remain = max - currWeight;
            value+= (arr[i].val * remain)/arr[i].weight;
            currWeight = max;
        }
    }

    return value;
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
    int max_weight = 10;

    int wt[n], val[n];

    for(int i=0;i<n;i++)    cin>>val[i];
    for (int i=0;i<n;i++)   cin>>wt[i];

    Item arr[n];

    for(int i=0;i<n;i++) {
        arr[i].val = val[i];
        arr[i].weight = wt[i];
    }

    cout<<knapsack_greedy(n,arr,max_weight);

    return 0;
}
