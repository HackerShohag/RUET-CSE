#include <bits/stdc++.h>

using namespace std;

class Department
{
    public:
        string name;
        int students, teachers;
        Department(string name, int teachers, int students) {
            this->name = name;
            this->students = students;
            this->teachers = teachers;
        }
        virtual double equipment_Index() = 0;
        void Display() {
            cout << "Name: " << this->name
                << "\nTotal teachers: " << this->teachers
                << "\nTotal students: " << this->students << endl;
        }
};

class CSE : public Department{   
    public:
        int computers;
        CSE(string name, int teachers, int students, int computers):Department(name, teachers, students) {
            this->computers = computers;
        }
        double equipment_Index() {
            double result = 0;
            try
            {
               if(this->students == 0) throw "Divide by zero";
               else result = (double)this->computers/this->students;
            }
            catch(char const* e)
            {
                std::cerr << e << "\t";
                return -1;
            }
            return result;
        }
        void Display() {
            Department::Display();
            cout << "Total computers: " << this->computers
                << "\nComputer index: " << this->equipment_Index() << endl;
        }
        int total() {
            return this->computers;
        }
};

class EEE : public Department{
    public:
        int machines;
        EEE(string name, int teachers, int students, int machines):Department(name, teachers, students) {
            this->machines = machines;
        }
        double equipment_Index() {
            double result = 0;
            try
            {
               if(this->students == 0) throw "Divide by zero";
               else result = (double)this->machines / this->students;
            }
            catch(char const* e)
            {
                std::cerr << e << "\t";
                return -1;
            }
            return result;
        }
        void Display() {
            Department::Display();
            cout << "Total machines: " << this->machines 
                << "\nMachines index: " << this->equipment_Index() << endl;

        }
        int total() {
            return this->machines;
        }
};

class ECE : public Department {
    public:
        int computers, machines;
        ECE(string name, int teachers, int students, int machines, int computers):Department(name, teachers, students) {
            this->machines = machines;
            this->computers = computers;
        }
        double equipment_Index() {
            double result = 0;
            try
            {
               if(this->students == 0) throw "Divide by zero";
               else result = ((double)this->computers + (double) this->machines) / this->students;            }
            catch(char const* e)
            {
                std::cerr << e << "\t";
                return -1;
            }
            return result;
        }
        void Display() {
            Department::Display();
            cout << "Total computers: " << this->computers
                << "\nTotal machines: " << this->machines 
                << "\nComputer+Machine index: " << this->equipment_Index() << endl;
        }
        int total() {
            return this->computers + this->machines;
        }
};

int main () {
    EEE eee("EEE", 50, 1000, 50);
    CSE cse("CSE",30,1200,200);
    ECE ece("ECE", 30, 1200, 25, 100);
    eee.Display();
    cse.Display();
    ece.Display();
    cout <<"Total equipments=" << eee.total() + cse.total() + ece.total() << endl;
    cout << "End of program" << endl;
    return 0;
}