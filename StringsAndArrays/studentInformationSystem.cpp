#include <bits/stdc++.h>
using namespace std;
class Student
{
private:
    string name;
    string dateOfBirth;
    int id;
    float cgpa;

public:
    Student() : name(""), dateOfBirth(""), id(0), cgpa(0.0) {}

    void setName(const string &n) { name = n; }
    void setDateofBirth(const string &dob) { dateOfBirth = dob; }
    void setId(int studentId) { id = studentId; }
    void setCGPA(float studentCGPA) { cgpa = studentCGPA; }

    string getName() const { return name; }
    string getDateOfBirth() const { return dateOfBirth; }
    int getId() const { return id; }
    float getCGPA() const { return cgpa; }

    void getInfo() const
    {
        cout << "Name: " << getName() << endl;
        cout << "Date of Birth: " << getDateOfBirth() << endl;
        cout << "ID: " << getId() << endl;
        cout << "CGPA: " << getCGPA() << endl;
    }

    int getAge(const string &currentDate) const
    {
        int currentYear = stoi(currentDate.substr(0, 4));
        int birthYear = stoi(dateOfBirth.substr(0, 4));

        return currentYear - birthYear;
    }

    bool isValidDate(const string &date) const
    {
        if (date.length() != 10)
        {
            return false;
        }

        istringstream iss(date);
        int year, month, day;
        char delimiter1, delimiter2;
        if (!(iss >> year >> delimiter1 >> month >> delimiter2 >> day) ||
            delimiter1 != '-' || delimiter2 != '-')
        {
            return false;
        }
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    Student student;

    student.setName("John Doe");
    student.setDateofBirth("2000-01-15");
    student.setId(12345);
    student.setCGPA(3.8);

    student.getInfo();

    string currentDate = "2023-11-30";
    if (student.isValidDate(currentDate))
    {
        int age = student.getAge(currentDate);
        cout << "Age: " << age << " years" << endl;
    }
    else
    {
        cout << "Invalid date format." << endl;
    }

    return 0;
}
