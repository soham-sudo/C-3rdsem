#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    string name;
    string designation;
    double basic_pay;

public:
    // Constructor
    Employee()
    {

    }
    Employee(int id, string name, string designation, double basic_pay) {
        this->id = id;
        this->name = name;
        this->designation = designation;
        this->basic_pay = basic_pay;
    }

    // Getter methods
    int getId() {
        return id;
    }

    string getName() {
        return name;
    }

    string getDesignation() {
        return designation;
    }

    double getBasicPay() {
        return basic_pay;
    }

    // Setter methods
    void setId(int id) {
        this->id = id;
    }

    void setName(string name) {
        this->name = name;
    }

    void setDesignation(string designation) {
        this->designation = designation;
    }

    void setBasicPay(double basic_pay) {
        this->basic_pay = basic_pay;
    }

    // Input function
    virtual void inputEmployeeDetails() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();  // Consume the newline character
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Designation: ";
        getline(cin, designation);
        cout << "Enter Employee Basic Pay: ";
        cin >> basic_pay;
    }

    // Display function
    void displayEmployeeDetails() {
        cout << "Employee ID: " << id << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Designation: " << designation << endl;
        cout << "Employee Basic Pay: " << basic_pay << endl;
    }
    virtual void calculate() = 0;
};
class permanent:public Employee
{
    private:
    double salary;
    public:
    permanent()
    {

    }
    void  inputEmployeeDetails()
    {
        Employee::inputEmployeeDetails();
    }
    void calculate()
    {

        salary = basic_pay + (1.1)*basic_pay;
        Employee::displayEmployeeDetails();
        cout << "salary for permanent is :" << salary << "\n";
    }

};
class contractual:public Employee
{
    private:
    double allowance;
    double salary;
    public:
    contractual()
    {

    }
    void  inputEmployeeDetails()
    {
        Employee::inputEmployeeDetails();
        cout << "enter allowance\n";
        cin >> allowance;
    }
    void calculate()
    {

        salary = basic_pay + allowance;
        Employee::displayEmployeeDetails();
        cout << "salary for contractual is :" << salary << "\n";
    }

};
int main() {
    Employee* p;
    permanent obj;
    p = &obj;
    p->inputEmployeeDetails();
    p->calculate();

    return 0;
}
