#include <iostream>
#include "Problems.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cctype>
#include <sstream>


using namespace std;


int main (){

    //cout << "Problem12: " << Problem12() << endl;
    vector<int> factors;
    for(int i = 1; i <= 10; i++){
        if(10%i == 0) {
            factors.push_back(i);
            cout << i << " ";
        }
    }
    
    cout<<" \n Hello World \n";
    
    //sort(factors.rbegin(), factors.rend());
    
    for(int i = 1; i <= factors.size(); i++){
        cout << " " << factors.at(i);
    }
    return 0;
}

/*
The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

 1: 1
 3: 1,3
 6: 1,2,3,6
10: 1,2,5,10
15: 1,3,5,15
21: 1,3,7,21
28: 1,2,4,7,14,28
We can see that 28 is the first triangle number to have over five divisors.

What is the value of the first triangle number to have over five hundred divisors?


*/
long long Problem12(){
    int count = 0;
    long long number;
    for (long long i = 1; i < INT_FAST64_MAX; i++){
        number+=i;
        // cout << number << endl;
        if(countDivisors(number) >= 500 ){
            return number;
        }
    }
    return number;
}

int countDivisors(long long number){
    int nod = 0;
    int sqrt = (int) sqrtl(number);
 
    for(int i = 1; i<= sqrt; i++){
        if(number % i == 0){
            nod += 2;
        }
    }
    //Correction if the number is a perfect square
    if (sqrt * sqrt == number) {
        nod--;
    }
 
    return nod;
}

bool IsPrime(long long n){

    if (n == 2 || n == 3) return true;
    
    for (size_t i = 2; i * i <= n; i ++) { //in any factorization of n, at least one of the factors must be smaller than the square root of n
        if (n % i == 0) return false;
    }

    return true;
}