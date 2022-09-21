//
//  Boss.hpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//

#ifndef Boss_hpp
#define Boss_hpp

#include <stdio.h>
#include <iostream>
#include "Worker.hpp"
using namespace std;

class Boss: public Worker {
public:
    
    // 1. Constructor
    Boss(int id, string name, int depId);

    // 2. Rewrite virtual functions from father class
    // Show personal info
    virtual void showInfo();
    
    // Show department name
    virtual string getDepartmentName();
};

#endif /* Boss_hpp */
