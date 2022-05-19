#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum Spec { CS, IT, ME, PhIT, TR };

string strSpec[] = { "����'�����i �����", "I����������", "���������� �� ������i��", "�i���� �� i����������", "������� ��������" };

struct Student {
    string lname;
    int kurs;
    Spec spec;
    int physics;
    int math;
    union {
        int progr;
        int numb;
        int ped;
    };
};

void create(Student* s, int amSt) {
    int sp;
    for (int i = 0; i < amSt; i++) {
        cout << "��i�����: ";
        cin >> s[i].lname;
        cout << "����: ";
        cin >> s[i].kurs;
        cout << "����i����i��� (0 - ����'�����i �����, 1 - I����������, 2 - ���������� �� ������i��, 3 - �i���� �� i����������, ������� ��������) ";
        cin >> sp;
        s[i].spec = (Spec)sp;
        cout << "��i��� � �i����: ";
        cin >> s[i].physics;
        cout << "��i��� � ����������: ";
        cin >> s[i].math;
        if (s[i].spec == 0) {
            cout << "��i��� � �������������: ";
            cin >> s[i].progr;
        }
        else if (s[i].spec == 1) {
            cout << "��i��� � ��������� �����i�: ";
            cin >> s[i].numb;
        }
        else {
            cout << "��i��� � �������i��: ";
            cin >> s[i].ped;
        }
    }
}
void print(Student* s, int amSt)
{
    cout << "=========================================================================================================================="
        << endl;
    cout << "| � |    ��i�����   | ���� |      ����i����i���     | �i���� | ���������� | ������������� | �������i ������ | �������i�� |"
        << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < amSt; i++) {

        cout << "| " << setw(2) << right << i + 1 << "";
        cout << "| " << setw(14) << left << s[i].lname
            << "| " << setw(5) << right << s[i].kurs
            << "| " << setw(23) << left << strSpec[s[i].spec]
            << "| " << setw(7) << s[i].physics
            << "| " << setw(11) << right << s[i].math;
        if (s[i].spec == 0) {
            cout << "| " << setw(14) << right << s[i].progr
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << " " << "| ";
        }
        else if (s[i].spec == 1) {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << s[i].numb
                << "| " << setw(11) << right << " " << "| ";
        }
        else {
            cout << "| " << setw(14) << right << " "
                << "| " << setw(16) << right << " "
                << "| " << setw(11) << right << s[i].ped << "| ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------------------------------------------------------"
        << endl;
}

double amount(Student s)
{
    double k = s.math + s.physics;
    if (s.spec == 0)
    {
        k += s.progr;
    }
    else if (s.spec == 1)
    {
        k += s.numb;
    }
    else
    {
        k += s.ped;
    }
    return k / 3;
}

string Prizv(Student* s, const int N)
{
    double min = amount(s[0]);
    int min_i = 0;
    for (int i = 0; i < N; i++)
    {
        if (amount(s[i]) < min)
        {
            min_i = i;
            min = amount(s[i]);
        }
    }
    return s[min_i].lname;
}

int Count(Student* s, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].math == 3)
        {
            k++;
        }
        if (s[i].physics == 3)
        {
            k++;
        }
        if (s[i].spec == 0 && s[i].progr == 3)
        {
            k ++;
        }
        else if (s[i].spec == 1  && s[i].numb == 3)
        {
            k ++;
        }
        else if( s[i].ped == 3)
        {
            k ++;
        }

    }
    return k;
}



int main() {
    setlocale(LC_ALL, "Ukrainian");
    int amSt;
    cout << "�i���i��� �������i�: ";
    cin >> amSt;
    Student* s = new Student[amSt];
    create(s, amSt);
    print(s, amSt);

    cout << "Ki���i��� ��i��� ���������� � ������� �������� ��� �������� " << Count(s, amSt) << endl;
    cout << "������� ��������, � ����� ��������� ������� ��� : " << Prizv(s, amSt) << endl;

    return 0;

}