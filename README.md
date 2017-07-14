# C11learn
Just to learn C++0x

//lambda +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*
capture 指定了在可见域范围内 lambda 表达式的代码内可见得外部变量的列表，具体解释如下：
    [a,&b] a变量以值的方式呗捕获，b以引用的方式被捕获。
	[this] 以值的方式捕获 this 指针。
	[&] 以引用的方式捕获所有的外部自动变量。
	[=] 以值的方式捕获所有的外部自动变量。
	[] 不捕获外部的任何变量。

parameter(可选)lambda表达式使用的参数列表。只有在不使用任何参数，并且没有自定mutable、一个exception_specification 和一个return_type的情况下可以忽略该列表，返回类型在某些情况下也是可以忽略的，详见对return_type的说明：eg: [] {return 10;}
    参数列表和普通函数的参数列表类似，区别如下：
    参数不能有默认值。
    不允许变长参数列表。
    不允许未命名的参数。

mutable：（可选）如果所在作用域的变量是通过值捕捉到，那么lambda表达式主体中可以使用这些变量的副本。这些副本默认标记为const，因此lambda表达式的主体不能修改这些副本的值。如果lambda表达式标记为mutable，那么这些副本则不是const，因此主体可以修改这些本地副本。

exception_specification：（可选）用于指定lambda可以抛出的异常。

return_type：（可选）返回值的类型。如果忽略了return_type，那么编译器会根据以下原则判断返回类型：
如果lambda表达式主体的形式为{return expression;}那么表达式return_type的类型为expression的类型。
其他情况下的return_type为void。

 */
 
[capture_block](parameters) mutable exception_specification->return_type{ body }

//example 1, call it directly, "second Lambda" corresponds to const string &str
string result = [](const string & str){ return "Hello from " + str; }("second Lambda"); 

//example 2, 
auto fn = [](const string& str) {return "hello from " + str; };
cout << fn("call 1") << endl;  
cout << fn("call 2") << endl;

git clone git://sourceware.org/git/glibc.git
cd glibc
git checkout --track -b local_glibc-2.25 origin/release/2.25/master
