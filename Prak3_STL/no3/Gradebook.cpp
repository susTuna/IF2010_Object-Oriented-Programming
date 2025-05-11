#include "Gradebook.hpp"

void Gradebook::addOrUpdateStudent(const string &studentName, double grade) {
    studentGrades[studentName] = grade;
}

bool Gradebook::removeStudent(const string &studentName) {
    auto it = studentGrades.find(studentName);
    if (it == studentGrades.end()) return false;
    studentGrades.erase(it);
    return true;
}

bool Gradebook::getGrade(const string &studentName, double &grade) const {
    auto it = studentGrades.find(studentName);
    if (it == studentGrades.end()) return false;
    grade = it->second;
    return true;
}

bool Gradebook::studentExists(const string &studentName) const {
    return studentGrades.count(studentName) > 0;
}

void Gradebook::printGrades() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong\n";
        return;
    }
    size_t idx = 1;
    for (const auto &p : studentGrades) {
        cout << idx++ << ". " << p.first << ": " << p.second << '\n';
    }
}

void Gradebook::printGradesRank() const {
    if (studentGrades.empty()) {
        cout << "Gradebook kosong\n";
        return;
    }
    vector<pair<string, double>> v(studentGrades.begin(), studentGrades.end());
    sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });
    size_t idx = 1;
    for (const auto &p : v) {
        cout << idx++ << ". " << p.first << ": " << p.second << '\n';
    }
}

vector<string> Gradebook::getStudentsWithGradeAbove(double threshold) const {
    vector<string> res;
    for (const auto &p : studentGrades)
        if (p.second > threshold) res.push_back(p.first);
    sort(res.begin(), res.end());
    return res;
}

double Gradebook::getAverageGrade() const {
    if (studentGrades.empty()) return 0.0;
    double sum = 0.0;
    for (const auto &p : studentGrades) sum += p.second;
    return sum / studentGrades.size();
}

size_t Gradebook::getNumberOfStudents() const {
    return studentGrades.size();
}
