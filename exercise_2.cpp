#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name_;
    string address_;

public:
    Person(string name, string address) : name_(name), address_(address) {}
    ~Person() {}
    string getName() const { return name_; }
    string getAddress() const { return address_; }
    void setAddress(string address) { address_ = address; }
    
    virtual string toString() { return "Person[" + name_ + ", " + address_ + "]"; }
};

class Student : public Person {
private:
    string program_;
    int year_;
    double fee_;

public:
    Student(string name, string address, string program, int year, double fee) : 
        Person(name, address), program_(program), year_(year), fee_(fee) {}
    ~Student() {}
    string getProgram() const { return program_; }
    void setProgram(string program) { program_ = program; }
    int getYear() const { return year_; }
    void setYear(int year) { year_ = year; }
    double getFee() const { return fee_; }
    void setFee(double fee) { fee_ = fee; }
    string toString() { return "Student[" + getName() + ", " + getAddress() + ", " + program_ + ", " +  to_string(year_) + ", " + to_string(fee_) + "]"; }
};

class Staff : public Person {
private:
    string school_;
    double pay_;

public:
    Staff(string name, string address, string school, double pay) : Person(name, address), school_(school), pay_(pay) {}
    ~Staff() {}
    string getSchool() const { return school_; }
    void setSchool(string school) { school_ = school; }
    double getPay() const { return pay_; }
    void setPay(double pay) { pay_ = pay; }
    string toString() { return "Staff[" + getName() + ", " + getAddress() + ", " + school_ + ", " +  to_string(pay_) + "]"; }
};

class SchoolBusinessTest {
public:
    void doMain() {
        Student** list = new Student * [5];
        for (int i = 0; i < 5; i++) {
            list[i] = new Student("", "", "", 2023, 0);
        }
        for (int i = 0; i < 5; i++) {
            cout << list[i]->toString() << "\n";
        }
        Staff* newStaff = new Staff("", "Bach Khoa University", "", 0);
    }
};

int main() {
    SchoolBusinessTest* test = new SchoolBusinessTest();
    test->doMain();
    return 0;
}