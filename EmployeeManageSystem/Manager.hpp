//
//  Manager.hpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//
#pragma once
#ifndef Manager_hpp
#define Manager_hpp

#include <iostream>
#include "Worker.hpp"
using namespace std;

class Manager: public Worker {
public:
    
    // 1. Constructor
    Manager(int id, string name, int depId);

    // 2. Rewrite virtual functions from father class
    // Show personal info
    virtual void showInfo();
    
    // Show department name
    virtual string getDepartmentName();
};

#endif /* Manager_hpp */
