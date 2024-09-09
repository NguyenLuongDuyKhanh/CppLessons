#include<iostream>
using namespace std;
class Person {
// Data members of person 
public:
	Person(int x) { cout << "Person::Person(int ) called" << endl; }
};

class Faculty : public Person {
// data members of Faculty
public:
	Faculty(int x):Person(x) {
	cout<<"Faculty::Faculty(int ) called"<< endl;
	}
    int SampleOverlapMethod() {
        cout << "This is SampleOverlapMethod in Faculty " << endl;
    }
};

class Student : public Person {
// data members of Student
public:
	Student(int x):Person(x) {
		cout<<"Student::Student(int ) called"<< endl;
	}
    int SampleOverlapMethod() {
        cout << "This is SampleOverlapMethod in Student " << endl;
    }
};

class TA : public Faculty, public Student {
public:
	TA(int x):Student(x), Faculty(x) {
		cout<<"TA::TA(int ) called"<< endl;
	}
};

int main() {
	TA ta1(30);
    
    //ta1.SampleOverlapMethod();

    return 0;
}
