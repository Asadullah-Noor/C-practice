#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
    string registrationNumber;
    string firstName;
    string lastName;
    string program;
    double cgpa;
    string contactNumber;
};
string* split(const string &s, char delim, int &numTokens) {
    stringstream ss(s);
    string item;
    numTokens = 0;
    string *tokens = new string[6];
    while (getline(ss, item, delim)) {
        tokens[numTokens++] = item;
    }
    return tokens;
}

int main() {

    ifstream file("StudentInfo.txt");
    Student students[5];
    string line;
    int numTokens;
    while (getline(file, line)) {
        string *tokens = split(line, ',', numTokens);
        Student &student = students[numTokens - 1];
        student.registrationNumber = tokens[0];
        student.firstName = tokens[1];
        student.lastName = tokens[2];
        student.program = tokens[3];
        student.cgpa = stod(tokens[4]);
        student.contactNumber = tokens[5];
        delete[] tokens;
    }

    file.close();

    for (const auto &student : students) {
        if (student.cgpa >= 3.5) {
            cout << student.firstName << " " << student.lastName << endl;
        }
    }

    return 0;
}
