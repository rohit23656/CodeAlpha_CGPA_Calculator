#include <iostream>
#include <vector>
#include <iomanip>  
using namespace std;
class Course {
public:
    string name;
    double grade;
    int credits;
    Course(string name, double grade, int credits) {
        this->name = name;
        this->grade = grade;
        this->credits = credits;
    }
};
double calculateGPA(const vector<Course>& courses) {
    double totalPoints = 0;
    int totalCredits = 0;
    for (const auto& course : courses) {
        totalPoints += course.grade * course.credits;
        totalCredits += course.credits;
    }
    return totalPoints / totalCredits;
}
void displayCourses(const vector<Course>& courses) {
    cout << fixed << setprecision(2);
    cout << "Courses:\n";
    for (const auto& course : courses) {
        cout << "Name: " << course.name << ", Grade: " << course.grade << ", Credits: " << course.credits << endl;
    }
}
int main() {
    int numSemesters;
    cout << "Enter the number of semesters: ";
    cin >> numSemesters;
    vector<double> gpas;
    int totalCredits = 0;
    double totalGradePoints = 0;
    for (int i = 0; i < numSemesters; ++i) {
        int numCourses;
        cout << "Enter the number of courses for semester " << (i + 1) << ": ";
        cin >> numCourses;
        vector<Course> courses;
        for (int j = 0; j < numCourses; ++j) {
            string name;
            double grade;
            int credits;
            cout<<"Enter course name: ";
            cin>>name;
            cout<<"Enter grade for "<<name<< ": ";
            cin>>grade;
            cout<<"Enter credits for " <<name<< ": ";
            cin>>credits;
            courses.emplace_back(name, grade, credits);
        }
        displayCourses(courses);
        double gpa = calculateGPA(courses);
        gpas.push_back(gpa);
        cout<<"GPA for semester "<<(i + 1)<<": "<< gpa << endl;
        for (const auto& course : courses) {
            totalCredits += course.credits;
            totalGradePoints += course.grade * course.credits;
        }
    }
    double cgpa = totalGradePoints / totalCredits;
    cout << fixed << setprecision(2);
    cout << "Total Credits: "<<totalCredits<<endl;
    cout << "Total Grade Points: "<<totalGradePoints<<endl;
    cout << "CGPA: "<<cgpa<<endl;
    return 0;
}
