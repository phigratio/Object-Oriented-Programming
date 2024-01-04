#include <bits/stdc++.h>
using namespace std;
class Product
{
protected:
    string title;
    string authorOrDirector;
    int id;

    static int totalProducts;

public:
    Product(const string &t, const string &aod, int i)
    {
        title = t;
        authorOrDirector = aod;
        id = i;

        totalProducts++;
    }

    virtual ~Product() {}

    virtual void displayInfo() const = 0;

    static int getTotalProducts()
    {
        return totalProducts;
    }

    bool operator<(const Product &other) const
    {
        return id < other.id;
    }

    Product &operator=(const Product &other)
    {
        if (this != &other)
        {
            title = other.title;
            authorOrDirector = other.authorOrDirector;
            id = other.id;
        }

        return *this;
    }
};

int Product::totalProducts = 0;

class Book : public Product
{
public:
    Book(const string &t, const string &author, int i) : Product(t, author, i) {}
    void displayInfo() const
    {
        cout << "Book - ID: " << id << ", Title: " << title
             << ", Author: " << authorOrDirector << endl;
    }
};

class DVD : public Product
{
public:
    DVD(const string &t, const string &director, int i)
        : Product(t, director, i) {}

    void displayInfo() const override
    {
        cout << "DVD - ID: " << id << ", Title: " << title
             << ", Director: " << authorOrDirector << endl;
    }
};

int main()
{
    vector<Product *> inventory;
    inventory.push_back(new Book("Book1", "Author1", 101));
    inventory.push_back(new DVD("DVD1", "Director1", 102));
    inventory.push_back(new Book("Book2", "Author2", 103));
    inventory.push_back(new DVD("DVD2", "Director2", 104));
    inventory.push_back(new Book("Book3", "Author3", 105));

    cout << "Product Information : " << endl;
    for (const auto &product : inventory)
    {
        product->displayInfo();
    }

    cout << endl
         << "Total number of Products: " << Product::getTotalProducts() << endl;
    if (*inventory[0] < *inventory[1])
    {
        cout << "Product 0 has a smaller ID than Product 1." << endl;
    }
    else
    {
        cout << "Product 0 does not have a smaller ID than Product 1." << endl;
    }
    Book book1("Book4", "Author4", 106);
    Book book2("Book5", "Author5", 107);
    Book copyInitializedBook = book1;
    Book assignedBook("Book6", "Author6", 108);
    assignedBook = book2;
    for (const auto &product : inventory)
    {
        delete product;
    }

    return 0;
}