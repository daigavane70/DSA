//============================================================================
// Name        : CP-Mathematics.cpp
// Author      : Vedant Daigavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#include<stack>
#include<string>
using namespace std;

//to find the primes less than n, returns an array whose true value index are prime numbers
bool sieve(int n,bool isPrime[]){

	isPrime[0]=isPrime[1]=false;

	for(int i=2;i<n;i++){
		if(isPrime[i]){
			for(int j=2 ; i*j < n; j++){
				isPrime[i*j]=false;
			}
		}
	}

	return *isPrime;
}

// returns the GCD of two integers
int GCD(int a, int b){
	return ( a ? GCD (b%a,a) : b);
}

int nonRecGCD(int a,int b){
	while(b) {
		a=a%b;

		a=a+b;
		b=a-b;
		a=a-b;
	}

	return a;
}

int LCM(int a,int b){
	return (a*b)/GCD(a,b);
}

// to calculate n ^ power
int binPow(int n, int power){
	if(power==0) return 1;

	int res=binPow(n,power/2);

	if(power%2)	return res*res*n;
	else return res*res;
}

//to calculate n ^ power
int nonRecBinPow(int n, int power){

	if(power==0) return 1;

	int  result=n;

	while(power > 1){

		result*=n;

		if(power%2) result*=n;

		n*=n;

		power/=2;
	}

	return result;
}

int main(){

	return 0;

}
