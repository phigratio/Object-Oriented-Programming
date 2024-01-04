// Let employee information system of an institution keeps the records of
// every employee’s name, date of birth and their respective salaries.
// Create a class called employee that will allow you to store all these
// information regarding an employee.
// Write getter and setter functions for all the member variables. (getter
// function return the value and setter function assign the value from the
// parameter to the member variables). Before setting any value to the
// member variables you need to check for these
// Name: The length has to be more than two. Otherwise assign the default
// name John Doe
// Date of Birth: Every employee has an age higher than 18. If an invalid
// value is given assign 1 January 2002.
// Salaries: The salary has to be in between BDT 10000 to BDT 100000. If
// an invalid value is given assign BDT 10000.
// Define setInfo() function which will call all the setter functions to
// set the necessary information of an employee object.
// Define a function named getInfo() which will display all the stored
// information belonging an employee object using the return value of the
// getter function.

#include<bits/stdc++.h>
using namespace std;
class Employee{
    private:
    string name;
    string dateOfBirth;
    double salary;

    public:
    Employee():name("Abdul Muqtadir"),dateOfBirth("2002-02-11"),salary(100000.0){}
    string getName() const
    {
        return name;
    }
    string getDateOfBirth() const
    {
        return dateOfBirth;
    }
    double getSalary() const
    {
        return salary;
    }

    void setName(const string&n)
    {
        if(n.length()>2)
        {
            name=n;
        }
    }
    void setDateOfBirth(const string &dob)
    {
        if(isValidDate(dob) and calculateAge(dob)>=18)
        {
            dateOfBirth=dob;
        }
    }
    void setSalary(double s)
    {
        if(s>=100000.0)
        {
            salary=s;
        }
    }

    void setInfo(const string&n,const string dob,double s)
    {
        setName(n);
        setDateOfBirth(dob);
        setSalary(s);
    }

    void getInfo() const
    {
        cout<<"Name: "<<getName()<<endl;
        cout<<"Date of Birth: "<<getDateOfBirth()<<endl;
        cout<<"Salary: BDT "<<getSalary()<<endl;
    }
    bool isValidDate(const string &date)const
    {
        return (date.length()==10);
    }

    int calculateAge(const string& dob)const
    {
        int birthYear=stoi(dob.substr(0,4));
        int currentYear=2023;
        return currentYear-birthYear;
    }
};

int main()
{
    Employee emp1;
    emp1.setInfo("Muqtu","1990-03-20",200000.0);
    emp1.getInfo();

    return 0;
}