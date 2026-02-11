//Name: Terence Lim Jian Yuan
//Matrics Number: A25CS0364
//Date: 9/1/2026

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void readFile(string,double[],int&);
void computeC(double[],double[],int);
double average(double[],int);
char grade(double);
void writeFile(double[],double[],int);

int main(){
    const int SIZE = 100;
    double farenheit[SIZE],celcius[SIZE];
    double averageTemp;
    int count=0;
    int hCount=0,mCount=0,lCount=0;

    readFile("farenheit.txt",farenheit,count);
    computeC(farenheit,celcius,count);
    averageTemp = average(celcius,count);
    for (int i=0; i<count; i++){
        char g = grade(celcius[i]);
        switch (g){
            case 'H': hCount++; break;
            case 'M': mCount++; break;
            case 'L': lCount++; break;
            default: break;
        }
    }

    cout << fixed << setprecision(1);
    cout << "Average of the temperature in Celcius: " << averageTemp << endl;
    cout << "Number of high temperature: " << hCount << endl;
    cout << "Number of medium temperature: " << mCount << endl;
    cout << "Number of low temperature: " << lCount << endl;

    writeFile(farenheit,celcius,count);



    return 0;
}

void readFile(string filename, double numbers[], int &count){
    ifstream inFile;
    inFile.open(filename);
    
    if(!inFile){
        cout << "Input file does not exist!" << endl;
        system("pause");
        exit(1);
    }

    count = 0;
    while (!inFile.eof()){
        inFile >> numbers[count];
        count ++;
    }


}

void computeC(double farenheit[], double celcius[], int count){
    for (int i=0; i<count; i++){
        celcius[i]= (5.0/9.0)*(farenheit[i]-32);
    }
}

double average(double array[],int count){
    double sum=0;

    for (int i=0; i<count; i++){
        sum+=array[i];
    }

    return sum/count;
}

char grade(double temperature){
    if (temperature >= 35){
        return 'H';
    }
    else if ((temperature < 35) && (temperature >= 20)){
        return 'M';
    }
    else{
        return 'L';
    }
}

void writeFile(double farenheit[], double celcius[], int count){
    ofstream outFile;
    outFile.open("temperatureOutput.txt");
    outFile << fixed << setprecision(2);
    outFile << left << setw(15) << "C(Celcius)" << setw(15) << "F(Farenheit)" << setw(15) << "Description" << endl;
    outFile << setw(15) << "==========" << setw(15) << "============" << setw(15) << "===========" << endl;
    for (int i=0; i<count; i++){
        outFile << right << setw(8) << celcius[i] << setw(15) << farenheit[i] << setw(12) << grade(celcius[i]) << endl;
    }
    outFile.close();
}