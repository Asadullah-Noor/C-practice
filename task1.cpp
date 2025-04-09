#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream file("StudentInfo.txt);
    for (int i = 1; i <= 5; i++) {
        string registrationNumber, firstName, lastName, program, contactNumber;
        double cgpa;


        cout << "Enter Registration Number: ";
        cin >> registrationNumber;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Last Name: ";
        cin >> lastName;
        cout << "Enter Program: ";
        cin >> program;
        cout << "Enter CGPA: ";
        cin >> cgpa;
        cout << "Enter Contact Number: ";
        cin >> contactNumber;


        file << registrationNumber << "," << firstName << "," << lastName << "," << program << "," << cgpa << "," << contactNumber << "\n";
    }


    file.close();

    return 0;
}
