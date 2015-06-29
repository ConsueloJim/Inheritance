
#ifndef EMPLOYEE_H
#define	EMPLOYEE_H

#include "person.h"



class Employee:public Person {
    public:
        
    Employee();    //Default constructor
    ~Employee();   //Destructor
    Employee(const Employee &copyEmp);     //Copy constructor
    
    void operator=(const Employee& Emp);
    
    int get_date() const;    //Return start date
    void set_date(int startDate);   // startDate -> employeeDate
    
    double get_sal(int i) const;    //Return employee salary
    void set_sal(int i, double salary);   // salary -> CurrentAnSalary
    
    double get_base() const;   //Return base salary
    void set_base(double basePay);  //basePay -> baseSalary
    
    int get_numOfInc() const;    //Returns number of pay increases
    void set_numOfInc(int num);  //num -> numOfInc
    
    double get_currentSal() const;       //Returns current salary calculated form pay increases
    void set_currentSal(double salary);   //salary -> currentAnSalary
    
    //Overloaded put operator
    friend std::ostream & operator << (std::ostream & out, const Employee & Emp);
    
    private:
        int employeeDate;
        int numOfInc; 
        double CurrentAnSalary;
        double baseSalary;
        double* salInc;        //Dynamic array of doubles to hold pay increases in percentages
    
      
};

#endif	/* EMPLOYEE_H */

