//
// Created by eduardo on 03.05.20.
//

#include "Person.h"

Person::Person(const string &name): name(name), age(0)
{

}


Person::Person(const string &name, int age): name(name), age(age)
{

}

string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

Person::~Person() = default;
