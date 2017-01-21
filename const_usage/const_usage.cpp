#include<iostream>

int getInt() {
	return 5;
}

int main() {
	const int bufsize = 512;

	//bufsize = 1024;错误，试图修改const对象的值

	const int i = getInt();//运行时初始化
	const int j = 42;//编译时初始化
	//const int k; 错误， k没有初始化

	const int *k = &j;
	//*k = 50; 当然const int *是不可修改的
	//int *l = &j; 错误，必须由const指针来引用 
	k = &i;

	int const *m = &j;//int const *m 等价于const int *m
	//int * const m = &j;错误，那么int * const m是什么意思呢? 如下block

	{
		int a = 50;
		int b = 60;
		const int c = 100;
		const int d = 110;

		int * const n = &a;
		//n = &b;  错误， n不可变，也就是n只能保存a的地址了（指向a了）
		*n = 70; //通过，对比上一句，a的值还是可变的~

		const int *const m = &a;
		std::cout << "a: " << a << "  *m: " << *m << std::endl;// 结果a == m == 50
		a = 100;
		std::cout << "a: " << a << "  *m: " << *m << std::endl;// 结果a == m == 100

		//m = &b;  错误，如之前的n = &b同理
		//*m = 150;错误，*m不可变

		//总结，const修饰跟在他之后的变量
		//const int c等同与int const c，因为都是修饰c
		//const int *k 的const修饰的是*k，这时*k是不可变的，而k是可变的（底层const）
		//int * const n 的const修饰的是n，而无视了之前的*  这样n作为地址值不可变(顶层const)
		//而const int *const m 的修饰法是最严格的，两个const确保了m和*m都不可变
		//然而其实const只能保证不会通过被他修饰的变量修改，如之前的cout语句显示，如果直接修改a，m也会跟着改变
	}

	int x = 200;
	int &y = x;
	int z = 300;
	y = z;
	printf("x:%d y:%d z:%d\n",x, y, z);
	printf("*x:%p *y%p\n", &x, &y);//地址相同，所以x和y其实是一个东西
	//引用的实质是别名，y是x的另一个名字
	//引用对比指针，最大的区别再于 引用没有新生成对象，一个对象的引用不会变成别的对象的引用；而新指针会要占内存，一个指针在运行中也可以指向不同的对象

	return 0;
}
