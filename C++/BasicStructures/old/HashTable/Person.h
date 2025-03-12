//
// Created by eduardo on 03.05.20.
//

#ifndef HASHTABLE_PERSON_H
#define HASHTABLE_PERSON_H

#include <string>

using namespace std;

class Person
{
public:
    explicit Person(const string& name);
    Person(const string& name, int age);
    ~Person();

    string getName() const;

    int getAge() const;
private:
    string name;
    int age;
};


#endif //HASHTABLE_PERSON_H
