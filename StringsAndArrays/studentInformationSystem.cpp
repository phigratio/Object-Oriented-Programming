#include<bits/stdc++.h>
using namespace std;
class Student{
    private:
    string name;
    string dateOfBirth;
    int id;
    float cgpa;
    public:
    Student():name(""),dateOfBirth(""),id(0),cgpa(0.0){}

    void setName(const string& n){name=n;}
    void setDateofBirth(const string& dob){dateOfBirth=dob;}
    void setId(int studentId){id=studentId;}
    void setCGPA(float studentCGPA){cgpa=studentCGPA;}

    string getName() const{return name;}
    string getDateOfBirth()const{return dateOfBirth;}
    int getId()const{return id;}
    float getCGPA()const {return cgpa;}

    void getInfo() const{
        cout<<"Name: "<<getName()<<endl;
        cout<<"Date of Birth: "<<getDateOfBirth()<<endl;
        cout<<"ID: "<<getId()<<endl;
        cout<<"CGPA: "<<getCGPA()<<endl;
    }

    int getAge(const string& currentDate)const{
        int currentYear=stoi(currentDate.substr(0,4));
        int birthYear=stoi(dateOfBirth.substr(0,4));

        return currentYear-birthYear;
    }

    bool isValidDate(const string& date)const{
        if(date.length()!=10)
        {
            return false;
        }

        try{
            stoi(date.substr(0,4));
            stoi(date.substr(5,2));
            stoi(date.substr(8,2));
        }
        catch(const exception& e)
        {
            return false;
        }

        return true;
    }
};