//Name: Terence Lim Jian Yuan
//Partner Name: Ng Yaw Kuan
//Matric Number: A25CS0364
//Partner Matric Number: A25CS0292
//Set Number: 1
//Date: 2/1/2026

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void displayLine(ofstream&);
int findIndWinner(int[]);
int findTeamWinner(int[]);

int main(){

    int marks[12][7];
    int totalParticipantMarks[12] = {0};
    int totalTeamMarks[3] = {0};
    int indWinner=0, teamWinner=0;

    ifstream inFile;
    inFile.open("input.txt");

    if(!inFile){
        cout << "Sorry, input file does not exist!" << endl;
        system("pause");
        exit(1);
    }

    for (int row=0; row<12; row++){
        for (int column=0; column<7; column++){
            inFile >> marks[row][column];
        }
    }

    for (int row=0;row<12;row++){
        for(int column=2;column<7;column++){
            totalParticipantMarks[row] += marks[row][column];
            totalTeamMarks[(marks[row][0]-1)] += marks[row][column];
        }
    }

    inFile.close();

    indWinner = findIndWinner(totalParticipantMarks);
    teamWinner = findTeamWinner(totalTeamMarks);

    ofstream outFile;
    outFile.open("output.txt");

    displayLine(outFile);
    outFile << left;
    outFile << setw(12) << "Id" << setw(7) << "E1" << setw(7) << "E2" << setw(7) << "E3" << setw(7) << "E4" << setw(7) << "E5" << setw(10) << "Total" << endl;
    displayLine(outFile);

    for (int team=1; team<=3; team++){
        outFile << "TEAM " << team << endl;

        for (int row=0; row<12; row++){
            if (team == marks[row][0]){
                outFile << setw(12) << marks[row][1];

                for (int column = 2; column<7 ; column++){
                    outFile << setw(7) << marks[row][column];
                }

                outFile << totalParticipantMarks[row] << endl;
            }
        }

        outFile << setw(47) << "TOTAL" << totalTeamMarks[team-1] << endl;
        displayLine(outFile);
    }

    outFile << endl << "Winner for Individual Category: " << marks[indWinner][1] << " (Team " << marks[indWinner][0] << ")" << endl;
    outFile << "Winner for Group Category: Team " << teamWinner+1 << " (Score = " << totalTeamMarks[teamWinner] << ")" << endl;

    outFile.close();

    return 0;
}

void displayLine(ofstream &outFile){
    for (int i=0;i<52;i++){
        outFile << "-";
    }
    outFile << endl;
}

int findIndWinner(int totalParticipantMarks[]){
    int indIndex = 0;
    int max=0;
    for (int i=0;i<12;i++){
        if (totalParticipantMarks[i] > max){
            max = totalParticipantMarks[i];
            indIndex = i;
        }
    }

    return indIndex;

}

int findTeamWinner(int totalTeamMarks[]){
    int teamIndex = 0;
    int max=0;
    for (int i=0;i<3;i++){
        if (totalTeamMarks[i] > max){
            max = totalTeamMarks[i];
            teamIndex = i;
        }
    }

    return teamIndex;
}