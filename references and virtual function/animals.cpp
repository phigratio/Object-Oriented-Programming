#include <bits/stdc++.h>
using namespace std;
class Animals
{
protected:
    string type;
    string mobility;
    string color;
    double weight;
    string sound;

public:
    Animals(string t, string m, string c, double w, string s)
        : type(t), mobility(m), color(c), weight(w), sound(s) {}

    virtual ~Animals() {}

    virtual void animalDetails() const
    {
        cout << "Type : " << type << endl;
        cout << "Mobility : " << mobility << endl;
        cout << "Color : " << color << endl;
        cout << "Weight : " << weight << endl;
        cout << "Sound : " << sound << endl;
    }

    string getType() const { return type; }
    string getMobility() const { return mobility; }
    string getColor() const { return color; }
    double getWeight() const { return weight; }
    string getSound() const { return sound; }
};

class Mammal : public Animals
{
public:
    Mammal(string t, string c, double w)
        : Animals(t, "Land", c, w, "")
    {
        type = t;
        color = c;
        weight = w;
        if (t == "Dog")
            sound = "Bark";
        else if (t == "Cat")
            sound = "Meow";
        else if (t == "Elephant")
            sound = "Trumpet";
        else if (t == "Human")
            sound = "Speech";
    }

    void animalDetails() const override
    {
        cout << "Mammal Details: " << endl;
        Animals::animalDetails();
    }
};

class Bird : public Animals
{
public:
    Bird(string t, string c, double w, string s)
        : Animals(t, "Air", c, w, "")
    {
        type = t;
        color = c;
        weight = w;
        if (t == "Eagle")
            sound = "Screech";
        else if (t == "Penguin")
            sound = "Honk";
        else if (t == "Sparrow")
            sound = "Chirp";
        else if (t == "Ostrich")
            sound = "Boom";
    }

    void animalDetails() const override
    {
        cout << "Bird Details: " << endl;
        Animals::animalDetails();
    }
};

class Fish : public Animals
{
public:
    Fish(string t, string c, double w, string s)
        : Animals(t, "Aquatic", c, w, "")
    {
        type = t;
        color = c;
        weight = w;
        if (t == "Salmon")
            sound = "Splash";
        else if (t == "Shark")
            sound = "Chomp";
        else if (t == "Goldfish")
            sound = "Bubbles";
        else if (t == "Angelfish")
            sound = "Gurgle";
    }

    void animalDetails() const override
    {
        cout << "Fish Details:" << endl;
        Animals::animalDetails();
    }
};

class Reptile : public Animals
{
public:
    Reptile(string t, string c, double w, string s)
        : Animals(t, "Land", c, w, "")
    {
        type = t;
        color = c;
        weight = w;
        if (t == "Snake")
            sound = "Hiss";
        else if (t == "Turtle")
            sound = "Grunt";
        else if (t == "Crocodile")
            sound = "Roar";
        else if (t == "Lizard")
            sound = "Chirp";
    }

    void animalDetails() const override
    {
        cout << "Reptile Details:" << endl;
        Animals::animalDetails();
    }
};

void sortAnimalWeight(Animals **animals, int n)
{
    sort(animals, animals + n, [](const Animals *a, const Animals *b)
         { return a->getWeight() > b->getWeight(); });
}

int main()
{
    const int numAnimals = 8;
    Animals *animalList[numAnimals];

    animalList[0] = new Mammal("Dog", "Brown", 50);
    animalList[1] = new Mammal("Cat", "Black", 5);
    animalList[2] = new Mammal("Elephant", "Gray", 5000);
    animalList[3] = new Mammal("Human", "Various", 70);
    animalList[4] = new Bird("Eagle", "Brown", 10, "");
    animalList[5] = new Bird("Penguin", "Black and White", 5, "");
    animalList[6] = new Fish("Salmon", "Silver", 2, "");
    animalList[7] = new Reptile("Snake", "Green", 2, "");

    cout << "Animal Details Before Sorting:" << endl;
    for (int i = 0; i < numAnimals; ++i)
    {
        animalList[i]->animalDetails();
    }
    sortAnimalWeight(animalList, numAnimals);

    cout << "\nAnimal Details After Sorting:" << endl;
    for (int i = 0; i < numAnimals; ++i)
    {
        animalList[i]->animalDetails();
    }

    for (int i = 0; i < numAnimals; ++i)
    {
        delete animalList[i];
    }

    return 0;
}
