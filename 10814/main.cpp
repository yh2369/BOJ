#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Person {
    int age;
    string name;
    int pid;
} Person;

bool cmp (Person& a, Person& b)
{
    if(a.age < b.age)
    {
        return true;
    }
    else if(a.age == b.age)
    {
        return a.pid < b.pid;
    }
    else
    {
        return false;
    }
}

int main()
{
    int N;
    cin >> N;
    
    vector<Person> people(N, Person());
    for(int i =0; i<N; i++)
    {
        int age;
        string name;
        cin >> age >> name;
        people[i].age = age;
        people[i].name = name;
        people[i].pid = i;
    }

    sort(people.begin(), people.end(), cmp);

    for(int i = 0; i< N; i++)
    {
        cout << people[i].age << " " << people[i].name <<"\n";
    }
    return 0;
}