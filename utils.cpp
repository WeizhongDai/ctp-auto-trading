#include "utils.h"
#include <fstream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

InitSys::InitSys(const std::string inifile)
{
    ifstream instr(inifile.c_str());
    if(!instr)
        throw("unable to open file");

        // save to a vector
    string instrument;
    vector<string> instrv;
    while (instr >> instrument) {
        instrv.push_back(instrument);
    }
    instr.close();

    // construct the char**
    iInstrumentID = instrv.size();
    ppInstrumentID = new char*[iInstrumentID ];
    for (int i=0; i != iInstrumentID ; ++i)
    {
        char* temp = strcpy(new char[instrv[i].length() + 1], instrv[i].c_str());
        ppInstrumentID[i] = temp;
    }
}

char** InitSys::getInstrument(void)
{
    return ppInstrumentID;
}

int InitSys::getInstrCount(void)
{
    return iInstrumentID;
}

InitSys::~InitSys()
{
        // delete all memory newed;
    for (int i=0; i != iInstrumentID; ++i)
    {
        delete[] ppInstrumentID[i];
    }
    delete ppInstrumentID;
    ppInstrumentID = NULL;
}