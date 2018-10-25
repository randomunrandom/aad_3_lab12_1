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
    unsigned int time_hour;
    unsigned int time_min;
public:
    tel_record() : owner(""), time_hour(0), time_min(0), number(""){}
    tel_record(std::string o) : owner(std::move(o)), time_hour(0), time_min(0), number("") {}
    tel_record(std::string o, std::string n) : owner(std::move(o)), time_hour(0), time_min(0), number("") {}
    tel_record(std::string o, std::string n, unsigned int t_h, unsigned int t_m) : owner(std::move(o)), time_hour(t_h),
    time_min(t_m), number(n) {}

    const std::string &getOwner() const {return owner;}
    const std::string &getNumber() const {return number;}
    const unsigned int &getTime_hour() const {return time_hour;}
    const unsigned int &getTime_min() const {return time_min;}

    void setOwner(const std::string &owner) {tel_record::owner = owner;}
    void setNumber(const std::string &number) {tel_record::number = number;}
    void setTime_hour(const unsigned int &time_hour) {tel_record::time_hour = time_hour;}
    void setTime_min(const unsigned int &time_min) {tel_record::time_min = time_min;}

    void user_input();
    void print_information();
};


#endif //AAD_3_LAB012_1_TEL_RECORD_H
