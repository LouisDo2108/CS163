#include "Examinee.h"

using namespace std;

int main()
{
    string in_file_name, out_file_name;
    vector<Examinee> examineeList;
    cout << "Please input the input file path: ";
    getline(cin, in_file_name);
    cout << "Please input the output file path: ";
    getline(cin, out_file_name);
    examineeList = ReadExamineeList(in_file_name);
    WriteSumOfScore(examineeList, out_file_name);
    return 0;
}