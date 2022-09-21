//
//  main.cpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//

#include <iostream>
#include "WorkerManager.hpp"
#include "Worker.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    WorkerManager wm;
    int choice = 0;
    
    while(true) {
        wm.showMenu();
        cout << "Please enter your choice: " << endl;
        cin>> choice;

        switch(choice) {
            case 0: // Exit the system
                wm.exitSystem();
                break;
            case 1: // Add New Employee
                wm.addEmployee();
                break;
            case 2: // Show the Employee
                wm.showEmployee();
                break;
            case 3: // Delete the Employee
                wm.deleteEmployee();
                break;
            case 4: // Edit the Employee
                wm.editEmployee();
                break;
            case 5: // Search the Employee
                wm.findEmployee();
                break;
            case 6: // Sort the Employee
                wm.sortEmployee();
                break;
            case 7: // Delete All
                wm.cleanFile();
                break;
            default:
                system("cls");
                break;
        }
    }
    
    system("pause");
    return 0;
}
