#include<iostream>

int getInt() {
	return 5;
}

int main() {
	const int bufsize = 512;

	//bufsize = 1024;������ͼ�޸�const�����ֵ

	const int i = getInt();//����ʱ��ʼ��
	const int j = 42;//����ʱ��ʼ��
	//const int k; ���� kû�г�ʼ��

	const int *k = &j;
	//*k = 50; ��Ȼconst int *�ǲ����޸ĵ�
	//int *l = &j; ���󣬱�����constָ�������� 
	k = &i;

	int const *m = &j;//int const *m �ȼ���const int *m
	//int * const m = &j;������ôint * const m��ʲô��˼��? ����block

	{
		int a = 50;
		int b = 60;
		const int c = 100;
		const int d = 110;

		int * const n = &a;
		//n = &b;  ���� n���ɱ䣬Ҳ����nֻ�ܱ���a�ĵ�ַ�ˣ�ָ��a�ˣ�
		*n = 70; //ͨ�����Ա���һ�䣬a��ֵ���ǿɱ��~

		const int *const m = &a;
		std::cout << "a: " << a << "  *m: " << *m << std::endl;// ���a == m == 50
		a = 100;
		std::cout << "a: " << a << "  *m: " << *m << std::endl;// ���a == m == 100

		//m = &b;  ������֮ǰ��n = &bͬ��
		//*m = 150;����*m���ɱ�

		//�ܽᣬconst���θ�����֮��ı���
		//const int c��ͬ��int const c����Ϊ��������c
		//const int *k ��const���ε���*k����ʱ*k�ǲ��ɱ�ģ���k�ǿɱ�ģ��ײ�const��
		//int * const n ��const���ε���n����������֮ǰ��*  ����n��Ϊ��ֵַ���ɱ�(����const)
		//��const int *const m �����η������ϸ�ģ�����constȷ����m��*m�����ɱ�
		//Ȼ����ʵconstֻ�ܱ�֤����ͨ���������εı����޸ģ���֮ǰ��cout�����ʾ�����ֱ���޸�a��mҲ����Ÿı�
	}

	int x = 200;
	int &y = x;
	int z = 300;
	y = z;
	printf("x:%d y:%d z:%d\n",x, y, z);
	printf("*x:%p *y%p\n", &x, &y);//��ַ��ͬ������x��y��ʵ��һ������
	//���õ�ʵ���Ǳ�����y��x����һ������
	//���öԱ�ָ�룬������������ ����û�������ɶ���һ����������ò����ɱ�Ķ�������ã�����ָ���Ҫռ�ڴ棬һ��ָ����������Ҳ����ָ��ͬ�Ķ���

	return 0;
}
