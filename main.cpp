/*******************************************************************************
 *      Author: Consuelo Jimenez
 *       Class: CSC340.02
 *        Date: May 15, 2015, 8:54 PM
 *      Assign: Homework 9, part 2
 * 
 * Description: This file tests the employee class interface. It is inherited by
 *              the person class and the person class by the dayOfYear class. 
 *              It consists of the employee.h, employee.cpp, main.cpp, person.h,
 *              person.cpp, dayOfYear.h and dayOfYeat.cpp files. 
 *******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>

#include "employee.h"
#include "person.h"
#include "dayOfYear.h"


using namespace std;

int main() {
    
    Employee employee;
    
    int startDate;
    double basePay;
    int numOfSalInc;
    double currentPay;
    double salary; 
    string new_name; 
    int id; 
   
    cout << "------------- This tests the Employee class interface -------------" << endl;
    
    //The following collects specified data from the user. 
    cout <<"What is the employee's name? ";
    cin >> new_name;
    employee.set_name(new_name);
    cout << endl;
    cout << "What is " << new_name << "'s ID number? ";
    cin >> id; 
    employee.set_id(id);
    cout << endl;
   
    cout << "When did " << new_name << " start? Enter year as a double.  ";
    cin >> startDate;
    employee.set_date(startDate);
    cout << endl;
    
    cout << "What was " << new_name << "'s starting pay? ";
    cin >> basePay; 
    employee.set_base(basePay);
    cout << endl;
    
    cout << "How many times has " << new_name << "'s pay increased? ";
    cin >> numOfSalInc;
    employee.set_numOfInc(numOfSalInc);
    
    //Input the salary increase rates into ADT for as many increases the user specified by calling set_sal()
    for(int i=0; i<numOfSalInc; i++) {
        cout << "What was pay increase "<< i+1 <<" in percentage? " ;
        cin >> salary;
        employee.set_sal(i+1, salary);        
        basePay += basePay*(salary/100);    //Compute the current annual salary by
                                            //Multiplying base pay by increase rate/100.
    }                                       //and adding back to base pay. 
    currentPay = basePay;                   //set current pay to base pay calculated in for loop
    employee.set_currentSal(currentPay);
    cout << employee;                       //outputs employee data
    employee.output();                      //outputs outputs data inherited from Person class
    
    return 0;
}

