将add做成动态链接库，给test.c调用

gcc -g -Wall -shared -fpic add.c -o libadd.dll

参数解释-g 为了gdb用， -shared 用来制作动态链接库 ，-fpic用来做位置无关的库
gcc -g Wall test.c -o test  -L./ -ladd