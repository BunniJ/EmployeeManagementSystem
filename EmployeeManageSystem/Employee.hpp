//
//  Employee.hpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//
#pragma once
#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>
#include <iostream>
#include "Worker.hpp"
using namespace std;

class Employee: public Worker {
public:
    
    // 1. Constructor
    Employee(int id, string name, int depId);

    // 2. Rewrite virtual functions from father class
    // Show personal info
    virtual void showInfo();
    
    // Show department name
    virtual string getDepartmentName();
};

#endif /* Employee_hpp */
