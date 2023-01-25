#include <iostream>
#include <cmath>
#include  <bits/stdc++.h>

using namespace std;
void repeat(int times = 10, char value = '*');
void swap_ref(int& a, int& b);
void swap_val(int a, int b);
void datingRange(int age, int& max, int&min);
void quadratic(int a, int b, int c, double& root1, double& root2);
void nameDiamond(string name);

int main() {
    // int a = 17;
    // int b = 35;

    // swap_val(a, b);
    // cout << a << " " << b << endl;

    // swap_ref(a, b);
    // cout << a << " " << b << endl;


    // int age = 0;
    // cout << "Enter your age: ";
    // cin >> age;
    // int min = 0, max = 0;
    // datingRange(age, max, min);

    // cout << "This is your dating range: [ " << min << ", " << max << " ]" << endl;


    // double root1 = 0, root2 = 0;
    // int a = 0, b = 0, c = 0;
    // cout << "Enter a, b, c of quadratic equation: ";
    // cin >> a >> b >> c;
    // quadratic(a, b, c, root1, root2);
    // cout << root1 << " " << root2 << endl;



    // string s = "Mukhammadrizo";
    // cout << s.substr(2, 4) << " "<< &s << endl;
    // cout << s.find('u') << endl;
    // cout << s.find('w') << endl;
    // if(s.find("Knu") != string::npos) {
    //     cout << string::npos << endl;
    // }

    string y_name = "";
    cout << "Enter your name: ";
    cin >> y_name;
    nameDiamond(y_name);
}

void nameDiamond(string name) {
    for (size_t i = 1; i <= name.size(); i++)
    {
        cout << name.substr(0, i) << endl;
    }

    for (size_t i = 1; i < name.size(); i++)
    {
        repeat(i, ' ');
        cout << name.substr(i) << endl;
    }
    
}


void quadratic(int a, int b, int c, double& root1, double& root2) {
    double sqroot = sqrt(a*a + b*b - 4*a*c);
    if (sqroot > 0) {
        root1 = (-b - sqroot)/2*a;
        root2 = (-b + sqroot)/2*a;
    } else if (sqroot == 0) {
        root1 = root2 = -b/(2*a);
    } else {
        cout << "no solution" << endl;
        root1 = root2 = 0;
    }
}

void datingRange(int age, int& max, int&min) {
    min = age / 2 + 7;
    max = (age - 7) * 2;
}

void repeat(int times, char value) {
    for (int i = 0; i < times; i++)
    {
        cout << value;
    }
    
}

void swap_val(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void swap_ref(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}