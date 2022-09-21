//
//  Boss.cpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//

#include "Boss.hpp"

Boss:: Boss(int id, string name, int depId) {
    this->m_id = id;
    this->m_name = name;
    this->m_departmentId = depId;
}

void Boss::showInfo() {
    cout << "Employee ID: " << this->m_id <<
    " \t Employee name: " << this->m_name <<
    " \t Department: " << this->getDepartmentName() <<
    " \t Job Description: Manage Everything" << endl;
}

string Boss:: getDepartmentName() {
    return string("Boss");
}
