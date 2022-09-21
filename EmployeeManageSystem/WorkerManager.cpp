//
//  WorkerManager.cpp
//  EmployeeManageSystem
//
//  Created by Tracy W on 2022-09-20.
//

#include "WorkerManager.hpp"

WorkerManager:: WorkerManager() {
    
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    // Situation 1: If file is not exist
    if(!ifs.is_open()) {
        cout << "File does not exist!" << endl;
        // Init employee number
        this->m_EmployeeNum = 0;
        // Init enpty file
        this->m_isFileEmpty = true;
        // Init array ptr
        this->m_EmpArray = NULL;
        // Close stream
        ifs.close();
        return;
    }

    // Situation 2: File exists but empty / no data
    char ch;
    ifs >> ch;

    if(ifs.eof()) {
        cout << "File exists but no content" << endl;
        // Init employee number
        this->m_EmployeeNum = 0;
        // Init enpty file
        this->m_isFileEmpty = true;
        // Init array ptr
        this->m_EmpArray = NULL;
        // Close stream
        ifs.close();
        return;
    }

    // Situation 3: File exists with data
    
    int num = this->get_EmployeeNum();
    this->m_EmployeeNum = num;
    // create space in heap, sizze based on employee number
    this->m_EmpArray = new Worker*[this->m_EmployeeNum];
    // init data and save to array
    this->initEmployees();
}

void WorkerManager:: showMenu() {
    cout << "*********************************************" << endl;
    cout << "*********          Welcome            *******" << endl;
    cout << "*********     0. Exit the system      *******" << endl;
    cout << "*********     1. Add Employee Info    *******" << endl;
    cout << "*********     2. Show Employee Info   *******" << endl;
    cout << "*********     3. Delete Employee Info *******" << endl;
    cout << "*********     4. Edit Employee Info   *******" << endl;
    cout << "*********     5. Find Employee Info   *******" << endl;
    cout << "*********     6. Sort Employee ID     *******" << endl;
    cout << "*********     7. Delete All Data      *******" << endl;
    cout << "*********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    cout<< "Bye-Bye!"<<endl;
    system("pause");
    exit(0);
}

void WorkerManager::addEmployee() {
    
    cout << "Enter the number of employee to add: " << endl;
    
    int addNum = 0;
    cin >> addNum;
    
    if(addNum > 0) {
        // Calculate space size
        // New space = current + new size
        int newSize = this->m_EmployeeNum + addNum;
        
        // Create a new place in Heap area
        Worker ** newspace = new Worker*[newSize];
        
        // If current Array is not null, then
        // Move the data from old space to newspace
        if(this->m_EmpArray != NULL) {
            for(int i = 0; i < this->m_EmployeeNum; i++)
            {
                newspace[i] = this->m_EmpArray[i];
            }
        }
        
        // Enter new data
        for(int j = 0; j < addNum; j++) {
            
            int id;
            string name;
            int department;
            
            
            cout<<"Please enter No. " << j + 1 << " new employee's id:" << endl;
            cin>> id;
            
            cout<<"Please enter No. " << j + 1 << " new employee's name:" << endl;
            cin>> name;
            
            cout << "Please enter this employee's department: " << endl;
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Boss" << endl;
            cin>> department;
            
            // Create diff object based on department
            Worker* worker = NULL;
            switch(department) {
                case 1 : // Normal Employee
                    worker = new Employee(id, name, 1);
                    break;
                case 2 : // Manager
                    worker = new Manager(id, name, 2);
                    break;
                case 3 : // Boss
                    worker = new Boss(id, name, 3);
                    break;
                default :
                    break;
            }
            
            // Insert to the correct position.
            // Create job description, save to array
            newspace[this->m_EmployeeNum + j] = worker;
        }
        
        // Delete old space
        delete[] this->m_EmpArray;
        
        // Update pointer's direction to new space
        this->m_EmpArray = newspace;
        
        // Update to new size
        this->m_EmployeeNum = newSize;
        
        //Once add successed, update boolean status
        this->m_isFileEmpty = false;
        
        // Notification msg
        cout<< "Success! " << addNum << " Employees are added!" << endl;
        
        // Save the data into the txt file
        this->save();
        
    } else {
        cout << "Failed! Something went wrong" << endl;
    }
    
    system("pause");
    system("cls");
}

void WorkerManager:: save() {
    
    // Init an output stream
    ofstream ofs;
    // open the file
    ofs.open(FILENAME, ios::out);
    
    for(int i = 0; i < this->m_EmployeeNum; i++) {
        // output each of the new employees
        ofs << this->m_EmpArray[i]->m_id << " "
        << this->m_EmpArray[i]->m_name << " "
        << this->m_EmpArray[i]->m_departmentId << endl;
    }
    
    // Finish writing, close stream
    ofs.close();
}

int WorkerManager::get_EmployeeNum() {
    
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    int id;
    string name;
    int depId;
    
    int num = 0;
    
    // read each of data items
    while(ifs >> id && ifs >> name && ifs >> depId) {
        // Record number of employees
        num++;
    }
    ifs.close();
    
    return num;
}

void WorkerManager:: initEmployees() {
    
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    
    int id;
    string name;
    int depId;
    
    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> depId) {
        // Init father pointer
        Worker * worker = NULL;
        
        // Create diff objects based on department id
        if(depId == 1) {
            // Normal Employee
            worker = new Employee(id, name, depId);
        } else if(depId == 2) {
            // Manager
            worker = new Manager(id, name, depId);
        } else {
            // Boss
            worker = new Boss(id, name, depId);
        }
        
        // save data into array
        this->m_EmpArray[index] = worker;
        index++;
    }
    
    ifs.close();
}

void WorkerManager::showEmployee() {
    
    if(this->m_isFileEmpty) {
        cout << "File not exist!" << endl;
    } else {
        for(int i = 0; i < m_EmployeeNum; i++) {
            // Use Poly to call diff api
            this->m_EmpArray[i]->showInfo();
        }
    }
    
    system("pause");
    system("cls");
}

void WorkerManager::deleteEmployee() {
    
    int id = 0;
    
    if(this->m_isFileEmpty) {
        cout << "File does not exist or empty!" << endl;
    } else {
        // Delete based on uset input id
        cout << "Please enter the employee id that you wish to delete: " << endl;
        cin >> id;
        
        int index = this->isEmployeeExist(id);
        
        if(index != -1) {
            // Means the target employee exists, then delete
            for(int i = index; i < this->m_EmployeeNum - 1; i++) {
                // move each item 1 step back
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            // update employee total num
            this->m_EmployeeNum--;
            
            //update txt file
            this->save();
            
            cout << "Successed!" << endl;
            
        } else {
            cout << "Failed! Not found" << endl;
        }
    }
    
    system("pause");
    system("cls");
}

int WorkerManager::isEmployeeExist(int id) {
    // check if the selected employee is exists, if so
    // return its position in array, if not return -1
    int index = -1;
    
    for(int i = 0; i < this->m_EmployeeNum; i++) {
        if(this->m_EmpArray[i]->m_id == id) {
            index = i;
            break;
        }
    }
    
    return index;
}

void WorkerManager::editEmployee() {
    
    if(this->m_isFileEmpty) {
        cout << "File not found or empty!" << endl;
    } else {
        cout << "Please enter the employee's id that you would like to modify: " << endl;
        
        int id;
        cin >> id;
        
        int index = this->isEmployeeExist(id);
        if(index != -1) {
            
            // Modify target employee's info
            // 1. Delete old info
            delete this->m_EmpArray[index];
            
            // Init new info
            int newId = 0;
            string newName = "";
            int newDepId = 0;
            
            cout << "Find No." << id << " employee, please enter new id: " << endl;
            cin >> newId;
            
            cout << "Please enter a new name: " << endl;
            cin >> newName;
            
            cout << "Please enter a new department: " << endl;
            cout << "1. Employee" << endl;
            cout << "2. Manager" << endl;
            cout << "3. Boss" << endl;
            cin >> newDepId;
            
            Worker * worker = NULL;
            switch (newDepId) {
                case 1:
                    worker = new Employee(newId, newName, newDepId);
                    break;
                case 2:
                    worker = new Manager(newId, newName, newDepId);
                    break;
                case 3:
                    worker = new Boss(newId, newName, newDepId);
                    break;
                default:
                    break;
            }
            
            // Update data to array
            this->m_EmpArray[index] = worker;
            
            cout << "Modification Successed! "<< this->m_EmpArray[index]->m_departmentId << endl;
            
            // save new data into txt file
            this->save();
            
        } else {
            cout << "Failed! Not found" << endl;
        }
    }
    
    system("pause");
    system("cls");
}

void WorkerManager::findEmployee() {
    if(this->m_isFileEmpty) {
        cout << "File does not exists or empty!" << endl;
    } else {
        cout << "Please choose the way to search: " << endl;
        cout << "1. By Employee's id: " << endl;
        cout << "2. By Employee's name: " << endl;
        
        int choice = 0;
        cin >> choice;
        
        if(choice == 1) {
            // search by id
            int id;
            cout << "Please enter the id you want to search for: " << endl;
            cin >> id;
            
            int result = this->isEmployeeExist(id);
            if(result != -1) {
                cout << "Found! Please check the employee's info: " << endl;
                this->m_EmpArray[result]->showInfo();
            } else {
                cout << "Failed! Not found" << endl;
            }
        } else if(choice == 2) {
            // Search by name
            string name;
            cout << "Please enter the name you want to search for: " << endl;
            cin >> name;
            
            bool isFound = false;
            for(int i = 0; i < this->m_EmployeeNum; i++) {
                if(this->m_EmpArray[i]->m_name == name) {
                    cout << "Found! Please check " << this->m_EmpArray[i]->m_name <<  "'s info: " << endl;
                    this->m_EmpArray[i]->showInfo();
                    isFound = true;
                }
            }
            if(isFound == false) {
                cout << "Not Found the person!" << endl;
            }
        } else {
            cout << "Failed!" << endl;
        }
    }
    
    system("pause");
    system("cls");
}

void WorkerManager::sortEmployee() {
    
    if(this->m_isFileEmpty) {
        cout << "File does not exists or empty!" << endl;
        system("pause");
        system("cls");
    } else {
        
        cout << "Please choose the way you would like to sort: " << endl;
        cout << "1. Employee id: Ascending" << endl;
        cout << "2. Employee id: Descending" << endl;
        
        int choice = 0;
        cin >> choice;
        for(int i = 0; i < this->m_EmployeeNum; i++) {
            
            // Let the init pos at i
            int curr = i;
            
            // Two pointers: j is one step ahead of i
            for(int j = i + 1; j < this->m_EmployeeNum; j++) {
                if(choice == 1) {
                    // Ascending
                    if(this->m_EmpArray[curr]->m_id > m_EmpArray[j]->m_id) {
                        curr = j;
                    }
                } else {
                    // Descending
                    if(m_EmpArray[curr]->m_id < m_EmpArray[j]->m_id) {
                        curr = j;
                    }
                }
            }
            
            if(i != curr) {
                // do swap
                Worker * temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[curr];
                this->m_EmpArray[curr] = temp;
            }
        }
        
        cout << "Sort Finished! result is: " << endl;
        // Update result in txt file
        this->save();
        
        //Display sorted data
        this->showEmployee();
    }
    
    system("pause");
    system("cls");
}

void WorkerManager::cleanFile() {
    cout << "ATTENTION: Are you sure to delete all the data in this file?" << endl;
    cout << "1. YES" << endl;
    cout << "2. NO" << endl;
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        
        // Open mode ios::trunc
        // Delete the old file and create a new one
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        
        if(this->m_EmpArray != NULL) {
            // if array not null, then first we delete data from heap
            for(int i = 0; i < this->m_EmployeeNum; i++) {
                if(this->m_EmpArray[i] != NULL) {
                    // Delete each employee object
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            
            // Delete array
            this->m_EmployeeNum = 0;
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            // File is empty now
            this->m_isFileEmpty = true;
        }
        
        cout << "Successed! File has now cleaned!" << endl;
    }
    
    system("pause");
    system("cls");

}


WorkerManager:: ~WorkerManager() {
    // Manually release data in heap area
    if(this->m_EmpArray != NULL){
        for(int i = 0; i < this->m_EmployeeNum; i++) {
            // if array not null, delete each of the items from heap
            if(this->m_EmpArray[i] != NULL) {
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
