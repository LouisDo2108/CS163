#ifndef _Examinee_H_
#define _Examinee_H_

#include <iostream>
#include <string>
#include <vector>

struct Examinee
{
    std::string id;
    float math, literature, physic, chemistry, biology, history, geography, civic_education,
        natural_science, social_science, foreign_language;
};

float readString(std::string info, int &index);
Examinee ReadExaminee(std::string line_info);
std::vector<Examinee> ReadExamineeList(std::string file_name);
void WriteSumOfScore(std::vector<Examinee> examinee_list, std::string out_file_name);
#endif