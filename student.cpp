#include <iostream>    // for input and output (cin, cout)
#include <vector>      // for vector (dynamic array)
#include <string>      // for inputting string 

using namespace std;   // avoids writing std::

// Base Class (Abstraction)
class Person {
protected:
    string name;   // stores name of person
    int age;       // stores age

public:
    // Constructor to initialize name and age
    Person(string n, int a) {
        name = n;
        age = a;
    }

    // Virtual function (used for polymorphism)
    virtual void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Virtual destructor (good practice)
    virtual ~Person() {}
};

// Derived Class (Inheritance from Person)
class Student : public Person {
private:
    int rollNo;    // student roll number (private = encapsulation)
    float marks;   // student marks

public:
    // Constructor (calls base class constructor)
    Student(string n, int a, int r, float m) : Person(n, a) {
        rollNo = r;
        marks = m;
    }

    // Function overriding (polymorphism)
    void display() override {
        Person::display();  // call base class function
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
    }

    // Friend function declaration (can access private data)
    friend void showGrade(Student s);
};

// Friend Function Definition
void showGrade(Student s) {
    // Accessing private member 'marks'
    if (s.marks >= 90)
        cout << "Grade: A\n";
    else if (s.marks >= 75)
        cout << "Grade: B\n";
    else if (s.marks >= 50)
        cout << "Grade: C\n";
    else
        cout << "Grade: F\n";
}

// Derived Class from Student (Multilevel Inheritance)
class GraduateStudent : public Student {
private:
    string specialization;  // extra field for graduate student

public:
    // Constructor
    GraduateStudent(string n, int a, int r, float m, string spec)
        : Student(n, a, r, m) {
        specialization = spec;
    }

    // Override display again
    void display() override {
        Student::display();  // call parent class display
        cout << "Specialization: " << specialization << endl;
    }
};

// Main Function
int main() {

    vector<Person*> students;   // vector storing base class pointers

    int n;  // number of students
    cout << "Enter number of students: ";
    cin >> n;   // user input

    // Loop to take input for each student
    for (int i = 0; i < n; i++) {

        int type;
        cout << "\nEnter 1 for Normal Student, 2 for Graduate Student: ";
        cin >> type;

        string name;
        int age, rollNo;
        float marks;

        // Taking common inputs
        cout << "Enter Name: ";
        cin.ignore();  // clear input buffer
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Roll No: ";
        cin >> rollNo;

        cout << "Enter Marks: ";
        cin >> marks;

        // If normal student
        if (type == 1) {
            // Create Student object and store pointer in vector
            students.push_back(new Student(name, age, rollNo, marks));
        } 
        else {
            // Extra input for graduate student
            string spec;
            cout << "Enter Specialization: ";
            cin.ignore();  // clear input buffer
            getline(cin, spec);

            // Create GraduateStudent object
            students.push_back(new GraduateStudent(name, age, rollNo, marks, spec));
        }
    }

    // Display all student details
    cout << "\n--- Student Details ---\n";
    for (auto s : students) {
        s->display();   // polymorphism (calls correct function)
        cout << "-------------------" << endl;
    }

    // Display grades
    cout << "\n--- Grades ---\n";
    for (auto s : students) {

        // Convert base pointer to Student pointer
        Student* st = dynamic_cast<Student*>(s);

        if (st != nullptr) {  // if conversion successful
            showGrade(*st);   // call friend function
        }
    }

    // Free dynamically allocated memory
    for (auto s : students) {
        delete s;
    }

    return 0;   // program ends
}