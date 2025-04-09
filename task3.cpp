#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Department {
    int deptId;
    string deptName;
};

struct Employee {
    int empId;
    string empName;
    string empJoiningDate;
    int deptId;
    string contact;
    double salary;
    string maritalStatus;
};
vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}
void readDepartmentData(vector<Department> &departments) {
    
    ifstream file("department.txt");
    string line;
    vector<string> tokens;
    while (getline(file, line)) {
        tokens = split(line, ',');
        Department department;
        department.deptId = stoi(tokens[0]);
        department.deptName = tokens[1];
        departments.push_back(department);
    }

    // Close the file
    file.close();
}

// Function to read the employee data from the employee.csv file
void readEmployeeData(vector<Department> &departments, vector<Employee> &employees) {
    // Open the file in read mode
    ifstream file("employee.csv");

    // Loop to read the file line by line
    string line;
    vector<string> tokens;
    while (getline(file, line)) {
        // Split the line by comma
        tokens = split(line, ',');

        // Create an employee object and add it to the vector
        Employee employee;
        employee.empId = stoi(tokens[0]);
        employee.empName = tokens[1];
        employee.empJoiningDate = tokens[2];
        employee.deptId = stoi(tokens[3]);
        employee.contact = tokens[4];
        employee.salary = stod(tokens[5]);
        employee.maritalStatus = tokens[6];
        Department department = find_if(departments.begin(), departments.end(), [&employee](const Department &d) {
            return d.deptId == employee.deptId;
        })->second;
        if (department.deptName == "Research") {
            cout << employee.empId << "," << employee.empName << "," << employee.empJoiningDate << "," << department.deptName << endl;
        }
    }

    file.close();
}

int main() {

    vector<Department> departments;
    vector<Employee> employees;

    readDepartmentData(departments);
    readEmployeeData(departments, employees);

    return 0;
}
