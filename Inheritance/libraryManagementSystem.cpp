// Task 3:

// You are asked to develop Library Management System using OOP. In
// order to complete it you need Library class.
// The members of Library classes are: name, location, working hours.
// Library class has a list of Books and a list of Members. Each Book
// has information as follows: title, author, publication date, and
// ISBN, Edition. Each member has information as follows: name, postal
// mail address, phone number, email address, and membership status
// (Staff Member, Faculty Member, Student Member, Guest).
// Create setter and getter function for each information.
// In main class create a library with 10 books with information and
// 5 members information. Display all the information.

#include <bits/stdc++.h>
using namespace std;
class Member
{
private:
    string name;
    string address;
    string phoneNumber;
    string emailAddress;
    string membershipStatus;

public:
    Member(string n, string addr, string phone, string email, string status)
        : name(n), address(addr), phoneNumber(phone), emailAddress(email), membershipStatus(status) {}
    string getName() const { return name; }
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmailAddress() const { return emailAddress; }
    string getMembershipStatus() const { return membershipStatus; }
};
class Book
{
private:
    string title;
    string author;
    string publicationDate;
    string ISBN;
    string edition;

public:
    Book(string t, string a, string date, string isbn, string ed)
        : title(t), author(a), publicationDate(date), ISBN(isbn), edition(ed) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getPublicationDate() const { return publicationDate; }
    string getISBN() const { return ISBN; }
    string getEdition() const { return edition; }
};

class Library
{
private:
    string name;
    string location;
    string workingHours;
    vector<Book> books;
    vector<Member> members;

public:
    Library(string n, string loc, string hours)
        : name(n), location(loc), workingHours(hours) {}

    void addBook(const Book &book) { books.push_back(book); }
    void addMember(const Member &member) { members.push_back(member); }
    string getName() const { return name; }
    string getLocation() const { return location; }
    string getWorkingHours() const { return workingHours; }
    const vector<Book> &getBooks() const { return books; }
    const vector<Member> &getMembers() const { return members; }
};

int main()
{

    Library myLibrary("City Library", "123 Main Street", "9:00 AM - 5:00 PM");
    myLibrary.addBook(Book("The Catcher in the Rye", "J.D. Salinger", "1951", "978-0-316-76948-0", "First Edition"));
    myLibrary.addBook(Book("To Kill a Mockingbird", "Harper Lee", "1960", "978-0-06-112008-4", "Fiftieth Anniversary Edition"));

    myLibrary.addMember(Member("aulia hasman", "456 Oak Street", "555-1234", "aulia@example.com", "Student Member"));
    myLibrary.addMember(Member("deulia rashtro", "789 Maple Avenue", "555-5678", "deulia@example.com", "Faculty Member"));

    cout << "Library Information:" << endl;
    cout << "Name: " << myLibrary.getName() << endl;
    cout << "Location: " << myLibrary.getLocation() << endl;
    cout << "Working Hours: " << myLibrary.getWorkingHours() << endl;

    cout << "\nBooks in the Library:" << endl;
    for (const auto &book : myLibrary.getBooks())
    {
        cout << "Title: " << book.getTitle() << endl;
        cout << "Author: " << book.getAuthor() << endl;
        cout << "Publication Date: " << book.getPublicationDate() << endl;
        cout << "ISBN: " << book.getISBN() << endl;
        cout << "Edition: " << book.getEdition() << endl;
        cout << "------------------------" << endl;
    }

    cout << "\nMembers of the Library:" << endl;
    for (const auto &member : myLibrary.getMembers())
    {
        cout << "Name: " << member.getName() << endl;
        cout << "Address: " << member.getAddress() << endl;
        cout << "Phone Number: " << member.getPhoneNumber() << endl;
        cout << "Email Address: " << member.getEmailAddress() << endl;
        cout << "Membership Status: " << member.getMembershipStatus() << endl;
        cout << "------------------------" << endl;
    }

    return 0;
}
