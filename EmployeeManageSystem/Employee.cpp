//
//  Employee.cpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//

#include "Employee.hpp"
using namespace std;

Employee:: Employee(int id, string name, int depId) {
    this->m_id = id;
    this->m_name = name;
    this->m_departmentId = depId;
}

void Employee::showInfo() {
    cout << "Employee ID: " << this->m_id <<
    " \t Employee name: " << this->m_name <<
    " \t Department: " << this->getDepartmentName() <<
    " \t Job Description: Finish all the assignments on time" << endl;
}

string Employee:: getDepartmentName() {
    return string("Employee");
}
