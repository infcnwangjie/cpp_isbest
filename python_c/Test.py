from ctypes import cdll, c_uint, c_void_p, c_int, c_float, c_char_p,POINTER,byref,Structure,cast
#调用库
MWORKDLL = cdll.LoadLibrary("libDemo.dll")

#测试strTest方法
MWORKDLL.strTest.argtype = c_char_p
MWORKDLL.strTest.restype = c_char_p
c=MWORKDLL.strTest("dfdsd".encode())
print("c:{}".format(c))

#测试szTest方法

print ("传递一维数组")
INPUT = c_int * 10
data = INPUT()
 
for i in range(10):
        data[i] = i
MWORKDLL.szTest.argtype = (c_int*10,c_int)
MWORKDLL.szTest.restype = c_int
result=MWORKDLL.szTest(data,len(data))
print('data[9] ',data[9],'   返回值result: data[9]+5  ',result)

#测试floatTest

MWORKDLL.floatTest.argtype = POINTER(c_float)
MWORKDLL.floatTest.restype = c_float
result=MWORKDLL.floatTest(byref((c_float)(10.7)))
print(result)


#测试Structure用法，封装whoheavy C方法
class Student(Structure):
    _fields_=[('id',c_int),('name',c_char_p),('age',c_int),('weight',c_float)]

a_student=Student()
a_student.id=1
a_student.name=b'wj'
a_student.age=31
a_student.weight=143.2
b_student=Student()
b_student.id=2
b_student.name=b'ycs'
b_student.age=32
b_student.weight=123.2

MWORKDLL.whoheavy.argtype = POINTER(Student),POINTER(Student)
MWORKDLL.whoheavy.restype = POINTER(Student)
result=MWORKDLL.whoheavy(byref(a_student),byref(b_student))
#由于whoheavy返回的是Student结构体的指针，因此需要从contents中取出指针，然后再取name,正确的解释如下所示：
#在获取结构体值的时候，指针类型结构体里面的值是在contents里面。如果python接受到一个指针类型的结构体，
#那么他们的值全部都在contents里面
print(result.contents.name)


import numpy as np
MWORKDLL.test_numpy.argtype=np.ctypeslib.ndpointer(dtype=np.float64,ndim=1,flags="C_CONTIGUOUS")
a=np.ones(1024,dtype="float64")
a_ctypes_ptr = cast(a.ctypes.data, POINTER(c_float))
result=MWORKDLL.test_numpy(a_ctypes_ptr)
print(result)

