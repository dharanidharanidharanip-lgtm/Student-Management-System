#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Student
{
    int roll;
    char name[50];
    char dept[50];
    float marks;
};

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{
    int choice;

    do
    {
        cout << "\n===================================";
        cout << "\n   STUDENT MANAGEMENT SYSTEM";
        cout << "\n===================================";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";
        cout << "\n===================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                cout << "\nExiting Program...";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 6);

    return 0;
}

void addStudent()
{
    Student s;

    ofstream file("students.txt", ios::app);

    cout << "\nEnter Roll Number: ";
    cin >> s.roll;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Department: ";
    cin >> s.dept;

    cout << "Enter Marks: ";
    cin >> s.marks;

    file << s.roll << " "
         << s.name << " "
         << s.dept << " "
         << s.marks << endl;

    file.close();

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents()
{
    Student s;

    ifstream file("students.txt");

    cout << "\n========== STUDENT RECORDS ==========\n";

    while(file >> s.roll >> s.name >> s.dept >> s.marks)
    {
        cout << "\nRoll Number : " << s.roll;
        cout << "\nName        : " << s.name;
        cout << "\nDepartment  : " << s.dept;
        cout << "\nMarks       : " << s.marks;
        cout << "\n-----------------------------------";
    }

    file.close();
}

void searchStudent()
{
    Student s;
    int rollNo;
    bool found = false;

    ifstream file("students.txt");

    cout << "\nEnter Roll Number to Search: ";
    cin >> rollNo;

    while(file >> s.roll >> s.name >> s.dept >> s.marks)
    {
        if(s.roll == rollNo)
        {
            cout << "\nStudent Found!";
            cout << "\nRoll Number : " << s.roll;
            cout << "\nName        : " << s.name;
            cout << "\nDepartment  : " << s.dept;
            cout << "\nMarks       : " << s.marks;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent Not Found!";
    }

    file.close();
}

void updateStudent()
{
    Student s;
    int rollNo;
    bool found = false;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Roll Number to Update: ";
    cin >> rollNo;

    while(file >> s.roll >> s.name >> s.dept >> s.marks)
    {
        if(s.roll == rollNo)
        {
            found = true;

            cout << "\nEnter New Name: ";
            cin >> s.name;

            cout << "Enter New Department: ";
            cin >> s.dept;

            cout << "Enter New Marks: ";
            cin >> s.marks;

            cout << "\nStudent Record Updated!";
        }

        temp << s.roll << " "
             << s.name << " "
             << s.dept << " "
             << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(!found)
    {
        cout << "\nStudent Not Found!";
    }
}

void deleteStudent()
{
    Student s;
    int rollNo;
    bool found = false;

    ifstream file("students.txt");
    ofstream temp("temp.txt");

    cout << "\nEnter Roll Number to Delete: ";
    cin >> rollNo;

    while(file >> s.roll >> s.name >> s.dept >> s.marks)
    {
        if(s.roll == rollNo)
        {
            found = true;
            continue;
        }

        temp << s.roll << " "
             << s.name << " "
             << s.dept << " "
             << s.marks << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found)
    {
        cout << "\nStudent Deleted Successfully!";
    }
    else
    {
        cout << "\nStudent Not Found!";
    }
}
