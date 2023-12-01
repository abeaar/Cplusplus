#include<iostream>
using namespace std;
int main()
{
    //declare variables
    int number=1244423;
    int digit[4];

    //defining a loop for splitting the number
    for(int i=0; i<4 ; i++)
    {
        digit[i]=number%10;
        number=number/10;
    }
    //for reading the digits stored in digits array
    cout <<"digits are"<<endl;
    for(int j=3 ; j>=0 ; j-- )
    {
        cout<<digit[j]<<", ";
}


}