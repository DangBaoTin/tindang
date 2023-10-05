#include <iostream>
#include <string>
#include <vector>

using namespace std;

//----------------------------------------------------------------
/*
 Continue with Exercise 2 
 - Add a property Id to Person, add a get-set method for Id 
 - Modify the constructor of Student and Staff by adding new parameter Id 
 - Create a new class called "Course" with the following properties:
    + courseID: string 
    + courseName: string 
    + courseDescription: string 
    + noCredit: int 
    + studentList: Student[] 
    + staffList: Staff[] 
   and the following methods: 
        addStudent(Student student_id); 
        removeStudent(Student student_id); 
        addStaff(Staff staff_id); 
        removeStaff(Staff staff_id); 
        toString(): String
 */

class Person {
protected:
    string name_;
    string address_;
    int ID_;

public:
    Person(string name, string address, int ID) : name_(name), address_(address), ID_(ID) {}
    ~Person() {}
    string getName() const { return name_; }
    string getAddress() const { return address_; }
    int getID() const { return ID_; }
    void setId(int id) { ID_ = id; }
    void setAddress(string address) { address_ = address; }
    
    virtual string toString() { return "Person[" + name_ + ", " + address_ + ", " + to_string(ID_) + "]"; }
};

class Student : public Person {
private:
    string program_;
    int year_;
    double fee_;

public:
    Student(string name, string address, int ID, string program, int year, double fee) : 
        Person(name, address, ID), program_(program), year_(year), fee_(fee) {}
    ~Student() {}
    string getProgram() const { return program_; }
    void setProgram(string program) { program_ = program; }
    int getYear() const { return year_; }
    void setYear(int year) { year_ = year; }
    double getFee() const { return fee_; }
    void setFee(double fee) { fee_ = fee; }
    string toString() { 
        return "Student[" + getName() + ", " + getAddress() + ", " + to_string(getID()) + ", " + program_ + ", " +  to_string(year_) + ", " + to_string(fee_) + "]";
    }
};

class Staff : public Person {
private:
    string school_;
    double pay_;

public:
    Staff(string name, string address, int ID, string school, double pay) : Person(name, address, ID), school_(school), pay_(pay) {}
    ~Staff() {}
    string getSchool() const { return school_; }
    void setSchool(string school) { school_ = school; }
    double getPay() const { return pay_; }
    void setPay(double pay) { pay_ = pay; }
    string toString() { return "Staff[" + getName() + ", " + getAddress() + ", " + to_string(getID()) + ", " + school_ + ", " +  to_string(pay_) + "]"; }
};

class Course {
private:
    int courseID_;
    string courseName_;
    string courseDescription_;
    int noCredit_;
    vector<Student*> studentList;
    vector<Staff*> staffList;

public:
    Course(int courseID, string courseName, string courseDescription, int noCredit)
        : courseID_(courseID), courseName_(courseName), courseDescription_(courseDescription), noCredit_(noCredit) {}
    ~Course() {}
    void addStudent(Student* studentIn) { studentList.push_back(studentIn); }
    void removeStudent(Student* studentOut) { studentList.erase(find(studentList.begin(), studentList.end(), studentOut)); }
    void addStaff(Staff* staff) { staffList.push_back(staff); }
    void removeStaff(Staff* staff) { staffList.erase(find(staffList.begin(), staffList.end(), staff)); }
    string toString() {
        string result = "Course ID: \t\t" + to_string(courseID_) + "\n";
        result += "Course Name: \t\t" + courseName_ + "\n";
        result += "Course Description: \t" + courseDescription_ + "\n";
        result += "Credit Hours: \t\t" + to_string(noCredit_) + "\n";
        result += "Student List:\n";
        for (Student* student : studentList) {
            result += "\t" + student->toString() + "\n";
        }
        result += "Staff List:\n";
        for (Staff* staff : staffList) {
            result += "\t" + staff->toString() + "\n";
        }
        return result;
    }
};

// class SchoolBusinessTest {
// public:
//     void doMain() {
//         Course* course = new Course(1, "DSA", "Data Structure and Algorithm", 3);
//         Student* student1 = new Student("Dang Bao Tin", "497 Hoa Hao", 2152313, "OISP", 2021, 33000000);
//         Student* student2 = new Student("Cao Chanh Tri", "Bach Khoa University", 2151234, "OISP", 2021, 33000000);
//         Student* student3 = new Student("Arthur Morgan", "Saint Denis", 1234567, "CQ", 1897, 35000000);
//         Staff* staff = new Staff("Dutch Van Der Linde", "Black Water", 5678, "Massachusetts Institute of Technology", 1000);
//         course->addStudent(student1);
//         course->addStudent(student2);
//         course->addStudent(student3);
//         course->addStaff(staff);
//         cout << course->toString() << endl;
//         cout << "----------------------------------------------------------------" << endl;
//         course->removeStudent(student2);
//         cout << "AFTER REMOVE STUDENT 2: \n" << course->toString();
//     }
// };

// int main() {
//     SchoolBusinessTest* test = new SchoolBusinessTest();
//     test->doMain();
//     return 0;
// }