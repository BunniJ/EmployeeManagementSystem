//
//  Worker.hpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//
#pragma once
#ifndef Worker_hpp
#define Worker_hpp

#include <stdio.h>
#include <string>
using namespace std;

// Abstract class for Employee
class Worker{
public:
     // Show personal info
    virtual void showInfo() = 0;
    
    // Get job departmentName
    virtual string getDepartmentName() = 0;
    

    int m_id; // employee id
    string m_name; // employee name
    int m_departmentId; // dep. id
};

#endif /* Worker_hpp */
