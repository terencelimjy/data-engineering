//Name: Terence Lim Jian Yuan
//Matrics Number:A25CS0364
//Date: 11/11/2025
//Set Number: 1

#include <iostream>
using namespace std;

int main() {

    int num ;
    cout << "Enter an integer number: " ;
    cin >> num;

    int digit=0, sum=0;

    do{

        digit = num % 10;
        cout << digit ;
        sum += digit;
        if (num >= 10)
            cout << " + ";
        num = num / 10;

    } while (num > 0);

    cout << " = " << sum << endl;

    if ((sum % 3 == 0) && (sum % 4 == 0) && (sum % 5 == 0))
         cout << sum << " is multiples of 3, 4 and 5." << endl;
    
    else if ((sum % 3 == 0) && (sum % 4 == 0))
        cout << sum << " is multiples of 3 and 4." << endl;

    else if ((sum % 3 == 0) && (sum % 5 == 0))
        cout << sum << " is multiples of 3 and 5." << endl;

    else if ((sum % 4 == 0) && (sum % 5 == 0))
        cout << sum << " is multiples of 4 and 5." << endl;

    else if ((sum % 3 == 0) )
        cout << sum << " is multiples of 3." << endl;

    else if ((sum % 4 == 0))
        cout << sum << " is multiples of 4." << endl;
    
    else if ((sum % 5 == 0))
        cout << sum << " is multiples of 5." << endl; 

    else
        cout << sum << " is not multiples of 3, 4 and 5." << endl;

    return 0;
}