// read information from files to initialize ststem.
#include <string>

class InitSys
{
public:
    InitSys(const std::string inifile);
    char** getInstrument(void);
    int getInstrCount(void);
    ~InitSys();

private:
    char** ppInstrumentID;
    int iInstrumentID;
};