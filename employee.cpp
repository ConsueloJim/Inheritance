#include "employee.h"

using namespace std;

//Destructor
Employee::~Employee() {
    if(salInc != NULL) {
        delete [] salInc;
    }
}

//Default Constructor
Employee::Employee():Person() {
    
    employeeDate = 0;
    CurrentAnSalary = 0;
    baseSalary = 0;
    salInc = NULL; 
}

//Copy Constructor
Employee::Employee(const Employee & copyEmp):Person(copyEmp) {
    employeeDate = copyEmp.employeeDate;
    CurrentAnSalary = copyEmp.CurrentAnSalary;
    baseSalary = copyEmp.baseSalary;
    
    if(numOfInc <= 0 )
        salInc = NULL;
    else {
        (*this).salInc = new double [numOfInc];
    }
    if(salInc == NULL) {
        cerr << "Employee::Employee(const Employee &): Memory allocation error\n";
        exit(-1); 
    }
    for(int i=0; i<numOfInc; i++){
        salInc[i] = copyEmp.salInc[i];
    }
}

//Overloaded = operator
void Employee::operator=(const Employee& Emp) {              
    (*this).Person::operator = (Emp);
    employeeDate = Emp.employeeDate;
    CurrentAnSalary = Emp.CurrentAnSalary;
    baseSalary = Emp.baseSalary;

    if(numOfInc != Emp.numOfInc){
        delete [] salInc;
        numOfInc = Emp.numOfInc;
        salInc = new double [numOfInc];
        if(salInc == NULL){
            cerr << "Employee:operator=(const Employee&): Memory allocation error\n";
            exit(-1);
        }
        for(int i=0; i<numOfInc; i++)
            salInc[i] = Emp.salInc[i];
    }
}
int Employee::get_date() const{           //Returns the employee start date
    return employeeDate;
}

int Employee::get_numOfInc() const{      //Returns number of pay increases
    return numOfInc;
}

double Employee::get_sal(int i) const {  //Gets the salary from specific element in array
    if(i<1 || i>numOfInc)
        return -1.0;
    else
        return salInc[i-1];
}

double Employee::get_base() const{       //Returns the base pay 
    return baseSalary;
}

double Employee::get_currentSal() const{        //Returns current annual salary computed after increases. 
    return CurrentAnSalary;
}

void Employee::set_currentSal(double salary){   //Sets the current annual salary computed after increaeses and pasted in by main function
    CurrentAnSalary = salary; 
}

void Employee::set_date(int startDate){        //Sets employees start date, employeeDate -> startDate
    employeeDate = startDate; 
}

void Employee::set_sal(int i, double salary){  //Sets salary increases into ADT that user enters in main function
    if(i>=1 && i<=numOfInc)
        salInc[i-1] = salary/100; 
}
void Employee::set_base(double basePay){       //Sets baseSalary -> basePay entered in main
    baseSalary = basePay; 
}

void Employee::set_numOfInc(int num) {        //Sets number of increases entered in man by user and sets size of array to numOfInc
    numOfInc = num; 
    if(num > 0) {
        salInc = new double [num];
        if(salInc == NULL) {
            cerr <<"Employee:set_numOfInc(int): Memory allocation error\n";
            exit(-1);
        }
        for(int i=0; i<num; i++)
            salInc[i] = 0.0; 
    }
}

//Standard overloaded put operator
ostream & operator << (ostream & out, const Employee& Emp){        
  DayOfYear birthday;
  birthday = Emp.get_birthday();
   
   out << "---------------------------------------------------------------------" << endl;
   out << "Employee Start Date : " << Emp.get_date() << endl; 
   //out << "Employee Birthday is : " << Emp.get_birthday() << endl; 
   out << "Base Pay = " << Emp.get_base() << endl; 
   out << "Current Annual Pay = " << Emp.get_currentSal() << endl;
   out << "Salary Increases over " << Emp.numOfInc << " years : " << endl;
   for( int i=1; i<=Emp.numOfInc; i++)
       out << "Increase[" << i << "] " << Emp.salInc[i-1] << "\n";
   
   out << endl; 
   
   
   return out;
}
