问题1：找不到libs/add.h

原因：调用的是c语言构建的动态链接库，需要用extern处理一下：
extern "C"
{
#endif
#include "libs/add.h"
#ifdef __cplusplus
}
#endif


问题2 运行Demo.exe时候找不到libadd.dll
 直接将动态链接库放到Demo.exe同级目录下面即可