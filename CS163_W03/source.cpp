#include "Examinee.h"
#include <fstream>

using namespace std;

float readString(string info, int &index)
{
    string temp = "";
    while (index < info.length() && info[index] != ',')
    {
        temp += info[index];
        ++index;
    }
    ++index;
    if (temp.length() != 0)
        return stof(temp);
    else
        return 0;
}

Examinee ReadExaminee(string line_info)
{
    Examinee contestant;
    string temp;
    int index = 0;
    while (line_info[index] != ',')
    {
        temp += line_info[index];
        ++index;
    }
    contestant.id = temp;
    ++index;

    contestant.math = readString(line_info, index);
    contestant.literature = readString(line_info, index);
    contestant.physic = readString(line_info, index);
    contestant.chemistry = readString(line_info, index);
    contestant.biology = readString(line_info, index);
    contestant.history = readString(line_info, index);
    contestant.geography = readString(line_info, index);
    contestant.civic_education = readString(line_info, index);
    contestant.natural_science = contestant.physic + contestant.chemistry + contestant.biology;
    contestant.social_science = contestant.history + contestant.geography + contestant.civic_education;
    index += 2;
    contestant.foreign_language = readString(line_info, index);
    return contestant;
}

vector<Examinee> ReadExamineeList(string file_name)
{
    vector<Examinee> temp;
    string tempread;
    ifstream fi;
    fi.open(file_name);
    if (fi.is_open())
    {
        getline(fi, tempread);
        while (!fi.eof())
        {
            getline(fi, tempread);
            temp.push_back(ReadExaminee(tempread));
        }
    }
    else cout << "can't open the file" << endl;
    fi.close();
    return temp;
}

void WriteSumOfScore(vector<Examinee> examinee_list, string out_file_name)
{
    ofstream fo;
    fo.open(out_file_name);
    if (fo.is_open())
    {
        int size = examinee_list.size();
        for (int i = 0; i < size; ++i)
        {
            fo << examinee_list[i].id << " ";
            fo << examinee_list[i].math + examinee_list[i].literature + examinee_list[i].foreign_language \
                + examinee_list[i].natural_science + examinee_list[i].social_science << endl;
        }
    }
    else cout << "can't open the file" << endl;
    fo.close();
    return;
}
