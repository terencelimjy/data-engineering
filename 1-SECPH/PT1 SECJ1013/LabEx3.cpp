//Name: Terence Lim Jian Yuan
//Matric No: A25CS0364
//Date: 19/12/2025

#include <iostream>
using namespace std;

void dispStatus (int);
void getInput(int&, int&, int&, int&);
void dispOutput (int);
int calcAverage(int,int);

int main(){
    int average,activeCases,totalCases,newCases,death,recovered,totalActive=0,count=0,max=0;
    string maxState,stateName;
    char status='\n';

    while(status == '\n'){
        cout << "<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>" << endl;
        cout << "State name\t: ";
        getline(cin,stateName);
        getInput(totalCases,newCases,death,recovered);
        count++;
        cout << endl;
        
        activeCases = totalCases+newCases-death-recovered;
        cout << "<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>" << endl;
        dispOutput(activeCases);

        totalActive+=activeCases;
        if (activeCases > max){
            max = activeCases;
            maxState = stateName;
        }

        //Why do we need to know Module 6 stuff to do this??????
        cin.ignore(1000, '\n');
        cout << "Press <ENTER> to continue...";
        status = cin.get();
        cout << endl;
    }

    average = calcAverage(count,totalActive);

    cout << "<<<<<<<<< ACTIVE CASES >>>>>>>>>" << endl;
    cout << "Total\t: " << totalActive << endl;
    cout << "Highest : " << max << "(" << maxState << ")" << endl;
    cout << "Average for " << count << " states: " << average << endl;
    
    return 0;

}

void dispStatus(int activeCases){
    string status;
    if (activeCases > 40){
        status = "Red";
    }
    else if (activeCases > 20 && activeCases <= 40){
        status = "Orange";
    }
    else if (activeCases > 0 && activeCases <= 20){
        status = "Yellow";
    }
    else{
        status = "Green";
    }
    cout << "Status\t\t: " << status << " zone" << endl;
}
void getInput(int& totalCases, int& newCases, int& death, int& recovered){
    cout << "Total cases\t: " ;
    cin >> totalCases;
    cout << "New cases\t: ";
    cin >> newCases;
    cout << "Total death\t: ";
    cin >> death;
    cout << "Total recovered\t: ";
    cin >> recovered;  
}

void dispOutput (int activeCases){
    cout << "Active cases\t: " << activeCases << endl;
    dispStatus(activeCases);
}

int calcAverage(int countStates, int totalActive){
    return static_cast<int>(totalActive/countStates);
}