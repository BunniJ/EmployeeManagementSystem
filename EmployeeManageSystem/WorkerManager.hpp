//
//  WorkerManager.hpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//

#pragma once
#ifndef WorkerManager_hpp
#define WorkerManager_hpp
#define FILENAME "empFile.txt"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Worker.hpp"
#include "Employee.hpp"
#include "Manager.hpp"
#include "Boss.hpp"
using namespace std;

class WorkerManager {
public:
    // Constructor
    WorkerManager();
    
    // 0. Show user menu
    void showMenu();
    
    // 1. Exit the system
    void exitSystem();
    
    // 2. Add Employee
    void addEmployee();
    
    // 2.1 Record current employee number
    int m_EmployeeNum;
    
    // 2.2 Employee Array pointer
    Worker ** m_EmpArray;
    
    // 2.3 Write data into a txt file
    void save();
    
    // 2.4 boolean if file is empty
    bool m_isFileEmpty;
    
    // 2.5 Get Empolyee number
    int get_EmployeeNum();
    
    // 2.6 Init employee Array
    void initEmployees();
    
    // 3. Show Employee
    void showEmployee();
    
    // 4. Delete Employee
    void deleteEmployee();
    
    // 4.1 check if the selected employee is exists
    int isEmployeeExist(int id);
    
    // 5. Edit Empolyee
    void editEmployee();
    
    // 6. Find an employee
    void findEmployee();
    
    // 7. Sort Employee
    void sortEmployee();
    
    // 8. Clean all data
    void cleanFile();
    
    // Destructor
    ~WorkerManager();
};

#endif /* WorkerManager_hpp */
