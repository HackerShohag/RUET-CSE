#include <bits/stdc++.h>

using namespace std;

class Manager;
class EmployeeList;
class Employee;

class EmployeeList {
    public:
        Employee* data;
        EmployeeList* next;
};

class Employee
{
    public:
        int ID;
        string name;
        int salary;
        int age;
        Manager* manager;

        Employee(string name, int ID, int salary, int age){
            this->name = name;
            this->ID = ID;
            this->salary = salary;
            this->age = age;
        }
        void printDelaits() {
            cout << "Name of the employee is " << this->name << "\nSalary: " << this->salary << "\nAge: " << this->age << endl;
        }
        void setManager(Manager* manager) {
            this->manager = manager;
        }
};

class Manager : public Employee {
    public:
        EmployeeList* employees;
        EmployeeList* tmp;
        int employeeCount = 0;
        int maxEmployeeCount = 10;

        Manager(string name, int ID, int salary, int age) : Employee(name, ID, salary, age) {}
        void printDelaits() {
            cout << "Name of the employee is " << this->name << "\nSalary: " << this->salary << "\nAge: " << this->age << endl;
            cout << "Employees supervised under " << this->name << endl;
            tmp = this->employees;
            for (int i = 0; i < employeeCount; i++)
            {
                cout << i+1 << ": " << tmp->data->name << endl;
                tmp = tmp->next;
            }
        }

        void addEmployee(Employee* employee) {
            tmp = this->employees;
            for (int i = 0; i < employeeCount; i++) tmp = tmp->next;
            EmployeeList *tmpL = new EmployeeList();
            tmp->next = tmpL;
            tmp->data = employee;
            employeeCount++;
        }

        void deleteEmployee(Employee* employee) {
            tmp = this->employees;
            for (int i = 0; i < employeeCount; i++)
            {
                if (tmp->next->data == employee) {
                    tmp->next = tmp->next->next;
                    employeeCount--;
                }
                tmp = tmp->next;
            }
        }
};


int main() {
    Employee *emp1 = new Employee("Farhan", 20, 1500, 23);
    Employee *emp2 = new Employee("Mehedi", 21, 1500, 23);
    Employee *emp3 = new Employee("Tonmoy", 22, 1500, 23);
    Employee *emp4 = new Employee("Emon", 23, 1500, 23);
    

    Manager manager("Shohag", 23, 1500, 23);

    emp1->setManager(&manager);
    emp2->setManager(&manager);
    emp3->setManager(&manager);
    emp4->setManager(&manager);
    
    manager.addEmployee(emp1);
    manager.addEmployee(emp2);
    manager.addEmployee(emp3);
    manager.addEmployee(emp4);
    manager.printDelaits();

    manager.deleteEmployee(emp4);
    manager.printDelaits();
}