#include <bits/stdc++.h>
#define nl (cout << endl)
using namespace std;

class Exam
{
private:
    string *name = nullptr;
    int *examDate = nullptr;
    double *score = nullptr;

public:
    void setName(string name)
    {
        if (!this->name)
            this->name = new string;
        *this->name = name;
    }
    void setExamDate(int examDate)
    {
        if (!this->examDate)
            this->examDate = new int;
        *this->examDate = examDate;
    }
    void setScore(double score)
    {
        if (!this->score)
            this->score = new double;
        *this->score = score;
    }
    friend ostream &operator<<(ostream &out, Exam &e);
    ~Exam()
    {
        delete name;
        delete examDate;
        delete score;
    }
};
ostream &operator<<(ostream &out, Exam &e)
{
    out << "Student Name: " << *(e.name) << endl;
    out << "Exam Date: " << *(e.examDate) << endl;
    out << "Score within Class: " << *(e.score) << endl;
    return out;
}

int main()
{
    Exam e1;
    e1.setName("Rehan the only Prhaku");
    e1.setExamDate(32082025);
    e1.setScore(101);
    Exam e2(e1);

    cout << "Before editing: " << endl;
    cout << "Exam 1:" << endl
         << e1;
    cout << "Exam 2:" << endl
         << e2;

    e2.setScore(110);

    cout << "After editing: " << endl;
    cout << "Exam 1:" << endl
         << e1;
    cout << "Exam 2:" << endl
         << e2;

    return 0;
}