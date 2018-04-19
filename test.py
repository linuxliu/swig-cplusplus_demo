from ajmdtool import AjmdTool
from multiprocessing import Process,Value
from threading import Thread
import time
import atexit

class A(Process):
    def __init__(self):
        Process.__init__(self)
        self.tool = None
    def run(self):
        self.tool = AjmdTool()
        print('run', self.tool)
        self.tool.do_good()



if __name__ == '__main__':
    a = A()
    a.daemon = True
    a.start()
    i = 0
    while True:
        if i > 3:
            if a.is_alive():
                print(a.pid)
                print('a is alive do stop')
                a.terminate()
            else:
                print('a is not alive')
        else:
            i += 1
        time.sleep(1)

    