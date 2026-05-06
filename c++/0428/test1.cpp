#include <iostream>
#include <cstdio>
#include "control.h"
#if _TEST1
//作业1:c++多模块项目中如果需要全局变量，整体项目规划如何设计？

//作业2：解释以下语句
//const int a=1;
//int const a=1;
//const int *p;
//int const *p;
//int * const p;
//int const *const p;
//const int const *const p;


//作业一：首先，要将全局变量统一进行管理，尽量在尽可能少的文件中声明，且声明与定义分开存放。
//尽量使用extern在头文件中进行声明，然后在cpp文件中集中进行定义，并结合namespace对无法避免的重名变量进行封装，
//最后在需要使用全局变量的文件中引用全局变量头文件进行使用。
//最好是结合文件名或者规范命名格式对命名空间进行命名，因为这样可以保证其名称的唯一性。




using namespace std;

int main()
{
	int arf = 1;
	int beta = 2;
	/*	const int a = 1;
		cout << a << endl;
		int const a = 2;
		cout << a << endl;
		// ：“const int a” : 重定义
		// ：“a” : 重定义；多次初始化
		// 也就是说，对于c++而言，const int和int const是等价的
		// ，都是定义一个常量类型变量const var
	*/

	/*	const int* p;
		p = &arf;
		printf("p:%d|a:%d", *p, arf);
		p = &beta;
		printf("p:%d|a:%d", *p, arf);
		// p:2|a:1
		// *p = 3;
		// ：表达式必须是可修改的左值
		// 说明const int*中const修饰的是指针的指类，该指针是一个指向const int类型常量的普通指针。
		// 因此无法对这个指针指向的空间进行赋值，而可以对指针本身进行需修改
	*/

	/*	int* const p = &arf;
		// ：应输入表达式
		// 说明该指针是一个常量，需要赋初值。
		*p = 3;
		cout << arf << endl;
		// 输出：3
		// p = &beta;
		// ：表达式必须是可修改的左值
		// 说明int* const中const修饰的是指针变量本身，声明该变量是一个常量。
		// 因为是常量，所以自然不能对常量进行修改——即无法更改指针存储的地址。
		// 但因为该常指针指类是一个普通的int类，所以可以对指向的空间进行修改。

		// 那么，对于const int* const p;来说，就是声明一个指类为const int类型的一个常量指针。
		// 它本身是一个常量，不能被修改。它指向的空间类型为常量，不能被修改。*/



	int const gama = 12;
	const int* pa = &gama;
	// ："const int *" 类型的值不能用于初始化 "int *const" 类型的实体
	// 这说明，const修饰符实际上是将普通的变量的类型改为了const int类型。
	// 那么我们是否可以这样来想象：想象其实普通变量的声明其实和指针的声明一样，需要类似于（*）
	// 的标识符，只不过普通变量的变量名就是该空间的标识符，不能改变，因此在声明时是
	// 默认省略这个标识符的。而指针由于需要声明该变量为指针，所以需要一个标识符（*），因此我们就可以
	// 将const修饰符放到（*）后面来对指针本身进行修饰了。而对于普通变量，地址本身就是不可修改的，因此
	// 我们对普通变量的const修饰其实一直都是修饰其指类（变量类型）
	// 而在对常量取地址后，该地址就是一个指类为const int类型的指针
	// 而对于指针而言，重要的是其指类的统一。指针指类与其指向的空间的类型要保持一致，因此，
	// 【int* const】这个指类为int类型的指针就不能使用 指类（变量类型）为【const int】的变量地址进行初始化了。
	// 而const int*类型的指针也是因为其指类为const int类型，可以使用同样是const int类型的变量地址进行初始化。
	// 
	// 同理，你不能使用const int类型的变量地址对普通int*指针进行初始化，因为普通指针的指类是int类型。

	return 0;
}
#endif