//
//  Manager.cpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//

#include "Manager.hpp"

Manager:: Manager(int id, string name, int depId) {
    this->m_id = id;
    this->m_name = name;
    this->m_departmentId = depId;
}

void Manager::showInfo() {
    cout << "Employee ID: " << this->m_id <<
    " \t Employee name: " << this->m_name <<
    " \t Department: " << this->getDepartmentName() <<
    " \t Job Description: Assign works to employees" << endl;
}

string Manager:: getDepartmentName() {
    return string("Manager");
}
