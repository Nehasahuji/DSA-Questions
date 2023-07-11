#include<iostream>

using namespace std;

void call(int n){
    
    if(n==0) return;
    
    
    cout << n <<" ";
    call(n-1);
    cout << n << " ";
    call(n-1);
    cout << n << " ";
}

int main()  {
    // YOUR CODE GOES HERE
    // Please take input and print output to standard input/output (stdin/stdout)
    // E.g. 'cin' for input & 'cout' for output
    int n;
    cin >> n;
    call (n);
    
    return 0;
}