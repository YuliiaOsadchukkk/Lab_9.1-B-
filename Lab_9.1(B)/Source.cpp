
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;
enum Specialty { КН, МЕ, ТН, ІФ, ФІ };
string strSpecialty[] = { "КН","МЕ","ТН","ІФ","ФІ" };

struct Student
{
    string prizv;
    Specialty specialty;
    short unsigned kurs;
    short unsigned Fiz;
    short unsigned Mat;
    
    union
    {
        short unsigned Programming;
        short unsigned Methods;
        short unsigned Pedagogika;
    };
};

void Create(Student* s, const int N)
{
    int kurs, specialty;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент№ " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << "  прізвище: "; getline(cin, s[i].prizv);
        cout << "  курс: "; cin >> s[i].kurs;
        cout << "  спеціальність (0 - Комп'ютерні науки, 1 - Математика та економіка, 2 - Трудове навчання, 3 - Інформатика, 4 - Фізика та інформатика): "; cin >> specialty;
        s[i].specialty = (Specialty)specialty;
        cout << "  оцінка з фізики: "; cin >> s[i].Fiz;
        cout << "  оцінка з математики: "; cin >> s[i].Mat;
        
        switch (specialty)
        {
        case 0:
            cout << "  оцінка з програмування: "; cin >> s[i].Programming;
            break;
        case 3:
            cout << "  оцінка з чисельних методів: "; cin >> s[i].Methods;
            break;
        case 1:
            cout << "  оцінка з педагогіки: "; cin >> s[i].Pedagogika;
            break;
        case 2:
            cout << "  оцінка з педагогіки: "; cin >> s[i].Pedagogika;
            break;
        case 4:
            cout << "  оцінка з педагогіки: "; cin >> s[i].Pedagogika;
            break;
        }
    }
}

void Print(Student* s, const int N)
{
    cout << "================================================================================================================="
        << endl;
    cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |"
        << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
   
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(13) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << "  "
            << "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
            << "| " << setw(4) << right << s[i].Fiz << "   "
            << "| " << setw(6) << right << s[i].Mat << "     ";
        switch (s[i].specialty)
        {

        case 0:
            cout << "| " << setw(7) << right << s[i].Programming << "       |" << setw(18) << "|" << setw(13) << "|" << endl;
            break;
        case 3:
            cout << "| " << setw(15) << "|" << setw(10) << right << s[i].Methods << "       |" << setw(13) << "|" << endl;
            break;
        case 1:
            cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].Pedagogika << "     |" << endl;
            break;
        case 2:
            cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].Pedagogika << "     |" << endl;
            break;
        case 4:
            cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].Pedagogika << "     |" << endl;
            break;

        }
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

    }
    cout << "=================================================================================================================" << endl;
}



void Mat_5(Student* s, const int N, int& k1)
{
    k1 = 0;
    for (int i = 0; i < N; i++)
        if (s[i].Mat == 5)
            k1++;
}

void Fiz_5(Student* s, const int N, int& k2)
{
    k2 = 0;
    for (int i = 0; i < N; i++)
        if (s[i].Fiz == 5)
            k2++;
}


void Programming_Methods_Pedgogik_5(Student* s, const int N, int& k3, int& k4, int& k5)
{
    k3 = 0;
    for (int i = 0; i < N; i++)
    {
        switch (s[i].specialty)
        {
        case 0:
            if (s[i].Programming == 5)
                k3++;
            break;
        case 3:
            if (s[i].Methods == 5)
                k4++;
            break;
        case 1:
            if (s[i].Pedagogika == 5)
                k5++;
            break;
        case 2:
            if (s[i].Pedagogika == 5)
                k5++;
            break;
        case 4:
            if (s[i].Pedagogika == 5)
                k5++;
            break;
        }
    }   
}


void Fiz_Mat_five(Student* s, const int N, int& k)
{
    k = 0;
    for (int i = 0; i < N; i++)
        if (s[i].Mat == 5 && s[i].Fiz == 5)
            k++;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;
    Student* s = new Student[N];
    Create(s, N);
    Print(s, N);
    int k1 = 0;
    int k2 = 0;
    int k3 = 0;
    int k4 = 0;
    int k5 = 0;
    int k = 0;

    Mat_5(s, N, k1);
    cout << "| Кількість п'ятірок з математики: " << fixed << setprecision(2) << k1 << setw(77) << "|" << endl;

    Fiz_5(s, N, k2);
    cout << "| Кількість п'ятірок з фізики: " << fixed << setprecision(2) << k2 << setw(81) << "|" << endl;

    Programming_Methods_Pedgogik_5(s, N, k3, k4, k5);
    cout << "| Кількість п'ятірок з програмування: " << fixed << setprecision(2) << k3 << setw(74) << "|" << endl;
    cout << "| Кількість п'ятірок з чисельних методів: " << fixed << setprecision(2) << k4 << setw(70) << "|" << endl;
    cout << "| Кількість п'ятірок з педагогіки " << fixed << setprecision(2) << k5 << setw(78) << "|" << endl;

    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
             
    
    
    Fiz_Mat_five(s, N, k);
    cout << "| К/к студентів, які отримали з фізики і з математики оцінки 5 : " << fixed << setprecision(2)<< k << setw(47) << "|" << endl;

    cout << "=================================================================================================================" << endl;
    
    delete[] s;
}