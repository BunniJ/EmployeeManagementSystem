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
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.addEmployee();
                break;
            case 2:
                wm.showEmployee();
                break;
            case 3:
                wm.deleteEmployee();
                break;
            case 4:
                wm.editEmployee();
                break;
            case 5:
                wm.findEmployee();
                break;
            case 6:
                wm.sortEmployee();
                break;
            case 7:
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
