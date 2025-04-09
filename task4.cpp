#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
void displayHighEarningEmployees(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }
    string line;
    getline(file, line);

    while (getline(file, line)) {
        int empId, deptId;
        char empName[50], empJoiningDate[50], contact[50], maritalStatus[50];
        double salary;
        sscanf(line.c_str(), "%d,%s,%s,%d,%s,%lf,%s",
               &empId, empName, empJoiningDate, &deptId, contact, &salary, maritalStatus);
        if (salary >= 1500000) {
            cout << "Employee Name: " << empName << endl;
            cout << "Salary: " << salary << endl;
            cout << "-------------------------------\n";
        }
    }
    file.close();
}

int main() {
    displayHighEarningEmployees("employee.txt");

    return 0;
}
