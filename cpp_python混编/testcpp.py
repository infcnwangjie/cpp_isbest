import ctypes                 # 导入ctypes包
import time
so = ctypes.cdll.LoadLibrary  # 将包中的LoadLibrary方法赋给 so
func = so("./testcpp.so")     # 用 LoadLibrary 方法 打开当前文件夹下的 打包为 .so 格式的文件 并赋给func

start=time.time()
num=func.hello() 
end=time.time()
print(num,end-start) 

import ctypes
arr=(ctypes.c_uint8*3)(0,1,2)


result=func.addOne(arr,3)
for i in range(0,len(arr)):
    print(arr[i],end=' ')

print(result)


