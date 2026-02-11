//Name: Terence Lim Jian Yuan
//Partner Name: Ng Yaw Kuan
//Matric Number: A25CS0364
//Partner Matric Number: A25CS0292
//Date: 26/12/2025
//Set Number: 1


#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

string returnComma(int);
double calcBMR(int,char,double,double);
void output(double);

int main(){

    int age;
    double height,weight,BMR;
    char gender,choice;

    do{
    cout << "Basal Metabolic Rate(BMR) Calculator" << endl;

    do{
    cout << "Age [15 - 80]: ";
    cin >> age;
    }while (age < 15 || age > 80);

    do{
    cout << "Gender [F @ M]: ";
    cin >> gender;
    gender = toupper(gender);
    }while (gender != 'F' && gender != 'M');

    cout << "Height (cm): ";
    cin >> height;
    cout << "Weight (kg): ";
    cin >> weight;
    BMR = calcBMR(age,gender,height,weight);
    cout << endl;

    cout << showpoint;
    cout << "BMR = " << BMR <<" Calories/ day (using Mifflin-St Jeor Equation)" << endl << endl;

    output(BMR);

    cout <<"Do you want to enter other data [Y@N]: ";
    cin >> choice;
    choice = toupper(choice);

    }while (choice == 'Y');

    cout << endl << "Thank you :)";


    return 0;
}

double calcBMR(int age, char gender,double height,double weight){
    double BMR;

    if (gender == 'M'){
        BMR = (10 * weight) + (6.25 * height) - (5 * age) + 5;
    }
    else if (gender == 'F'){
        BMR = (10 * weight) + (6.25 * height) - (5 * age) - 161;
    }

    return BMR;
}

//To standardise the output which is shown in question WITH A COMMA
string returnComma(int number){
    if (number ==0){
        return "0";
    }
    
    int temp = number,numberDigit=0, currentPosition=0,divisor=1;
    string output = "";

    while (temp>=10){
        temp/=10;
        divisor *=10;
        numberDigit++;
    }

    currentPosition = numberDigit + 1;

    while (divisor > 0){
        int digit = number / divisor;
        output += to_string(digit);
        number %= divisor;
        divisor /= 10;
        currentPosition--;

        if(currentPosition > 0 && currentPosition%3==0){
            output += ",";
        }

    }

    return output;   
}

void output(double BMR){
    int sedentary = round(BMR * 1.2);
    int lowEx = round(BMR * 1.375);
    int highEx = round(BMR * 1.465);
    int dailyEx = round(BMR * 1.55);
    int intenseEx = round(BMR * 1.725);
    int veryIntenseEx = round(BMR * 1.9);

    cout << "Daily calorie needs based on activity level" << endl << endl;
    cout << "Activity Level\t\t\t\t\t\tCalorie" << endl;
    cout << "Sedentary: little or no exercise\t\t\t" << returnComma(sedentary) << endl;
    cout << "Exercise 1-3 times/week\t\t\t\t\t" << returnComma(lowEx) << endl;
    cout << "Exercise 4-5 times/week\t\t\t\t\t" << returnComma(highEx) << endl;
    cout << "Daily exercise or intense exercise 3-4 times/week\t" << returnComma(dailyEx) << endl;
    cout << "Intense exercise 6-7 times/week\t\t\t\t" << returnComma(intenseEx) << endl;
    cout << "Very intense exercise daily, or physical job\t\t" << returnComma(veryIntenseEx) << endl << endl;
    cout << "Exercise: 15-30 minutes of elevated heart rate activity." << endl;
    cout << "Intense exercise: 45-120 minutes of elevated heart rate activity." << endl;
    cout << "Very intense exercise: 2+ hours of elevated heart rate activity." << endl << endl;
}