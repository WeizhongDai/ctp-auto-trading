#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

char** ppInstrumentID;
int iInstrumentID;

int main(int argc, char** argv)
{
    // open instrument file.
    ifstream instr("instr.txt");
    if(!instr) {
        cerr << "error: unable to open input file: instr.txt" << endl;
        return -1;
    }

    // save to a vector
    string instrument;
    vector<string> instrv;
    while (instr >> instrument) {
        instrv.push_back(instrument);
    }
    instr.close();

    // construct the char**
    int count = instrv.size();
    ppInstrumentID = new char*[count];
    for (int i=0; i != count; ++i)
    {
        char* temp = strcpy(new char[instrv[i].length() + 1], instrv[i].c_str());
        ppInstrumentID[i] = temp;
    }

    // do something here
    cout << "fuck" << endl;


    // delete all memory newed;
    for (int i=0; i != count; ++i)
    {
        cout << ppInstrumentID[i] << endl;
        delete[] ppInstrumentID[i];
    }
    delete ppInstrumentID;

    int ii;
    cin >> ii;

    return 0;
}