#include "ajmdtool.h"
#include <unistd.h>
#include<signal.h>

void signalHandler(int sig)
{
    if (sig == SIGTERM) {
        cout << "SIGTERM catched" << endl;
        AjmdTool::m_stop = true;
    }
    else if (sig == SIGINT) {
         cout << "SIGINT catched" << endl;
         AjmdTool::m_stop = true;
    }
    else {
        cout << sig << " catched" << endl;
    }
}

bool AjmdTool::m_stop = false;
AjmdTool::AjmdTool()
{
    if (m_stop) {
        m_stop = !m_stop;
    }
}

AjmdTool::~AjmdTool()
{

}

int AjmdTool::do_good()
{
    signal(SIGTERM,signalHandler);
    cout << "this is a good man" << endl;
    while (true) {
        if (m_stop) {
            cout << "stop flag is set" << endl;
            break;
        }
        else {
            cout << "do_good is doing now ...." << endl;
        }
        sleep(1);

    }
    return 0;
}

void AjmdTool::stop()
{
    if (!m_stop) {
        m_stop = true;
    } 
}