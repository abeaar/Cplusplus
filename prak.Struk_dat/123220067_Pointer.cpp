#include <iostream>
using namespace std;

int main(){
    int a;
    int b = 10;
    cout << "Nilai a\t\t: "; cin >> a;
    
    int *p = &b;
    int q = *p;

    cout << "Nilai a + b\t: " << a + b << endl;   
    cout << "Nilai q\t\t: " << q;
}