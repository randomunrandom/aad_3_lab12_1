#include <utility>

//
// Created by danai on 10/25/18.
//

#ifndef AAD_3_LAB012_1_TEL_RECORD_H
#define AAD_3_LAB012_1_TEL_RECORD_H

#include <iostream>

class tel_record {
private:
    std::string owner;
    std::string number;
    std::string time;
public:
    tel_record() : owner(""), time(""), number(""){}
    tel_record(std::string o) : owner(std::move(o)), time(""), number("") {}
    tel_record(std::string o, std::string n) : owner(std::move(o)), time(std::move(n)), number("") {}
    tel_record(std::string o, std::string n, std::string t) : owner(std::move(o)), time(std::move(t)), number(n) {}

    const std::string &getOwner() const {return owner;}
    const std::string &getNumber() const {return number;}
    const std::string &getTime() const {return time;}

    void setOwner(const std::string &owner) {tel_record::owner = owner;}
    void setNumber(const std::string &number) {tel_record::number = number;}
    void setTime(const std::string &time) {tel_record::time = time;}

    void user_input();
    void print_information();
};


#endif //AAD_3_LAB012_1_TEL_RECORD_H
