#ifndef AJMD_TOOL_H
#define AJMD_TOOL_H
#include <iostream>
using namespace std;

class AjmdTool {
public:
    AjmdTool();
    ~AjmdTool();
    int do_good();
    void stop();
   static bool m_stop;
};

#endif