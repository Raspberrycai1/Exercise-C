2020-11-10

[bilibili：从C到C++快速入门（2019版）](https://www.bilibili.com/video/BV16t411h7bD/?p=2)

## P2. C 标准库-注释-条件编译

### C标准库的C++移植

C++ 中包含了C标准库的移植版本，C标准库的头文件 **x.h** 基本上变成了 **cx**。如stdio.h 在 C++ 中对应的是 cstdio、math.h 变成了 cmath、string.h 变成了 cstring。

有例外，比如 malloc.h 仍然没变

### 注释

* 多行注释：/* 。。。 */
* 单行注释：//

### 条件编译

```c++
# if 0 
...
# endif
//////////////////
#if 1
....
# else
....
# endif
//////////////////
# ifdef xxx
    ...
# endif
//////////////
#ifndef xxx
    ....
#else
    ...
# endif
```

```c++
# if 1	//条件编译：条件为0(假)不要执行，1(真)是要执行
# define _CRT_SECURE_NO_WARNINGS	//忽略警告？
# include <cstdio>  //标准输入输出函数
# include <cmath>
# include <cstring> //字符串处理函数

int main()
{
    printf("hello\n");
    double x = 3.14;
    printf("%lf %lf\n",sqrt(x),sin(x));
    
    char s[10]="hello"; 
    /* c++ 不要求在开头定义变量
    字符串后面还有一个字符：'\0'，所有共占6个单元
    */
    
    puts(s);
    char s2[6];//空间不足，出错
    strcpy(s2,"world"); //字符串拷贝
    puts(s2);
    strcat(s2,"sdfsdf"); //字符串拼接
    puts(s2);
    printf("%d %d",strlen(s),strlen(s2)); 
    return 0;
}
# endif
```

```c++
#if 1   // 1 执行下面的代码，0 不执行包住的代码
# define _CRT_SECURE_NO_WARNNIGS
# include <cstdio>
# include <cstring>
# include <malloc.h>

int main()
{
# if 1
    //静态数组
    char s[10];
    strcpy(s,"hello");
    puts(s);
    
# else
    //动态数组
    char * s = (char *)malloc(sizeof(char)*12);
    strcpy(s, "hello world");
    puts(s);
# endif
    
}
# endif
```



## P3. C++标准输入输出-名字空间

* \<iostream\>  是C++ 标准输入输出流头文件

* cout 是一个标准**输出流变量（对象）**，代表控制台窗口

* **<<** 是一个运算符，假如 o 是一个输出流对象。x 是一个数据 o << x，把x 输出到 o 中（屏幕的窗口），返回的结果是 o

* cout 是标准名字空间 std 的一个名字。必须加上**名字空间限定 std::** 

  名字空间是为了防止名字冲突（不同班有同名的学生, 不同的库有相同名字的函数，每一个库有自己的名字空间）

  `计科1701::张伟  机械1803::张伟`

  在程序开头 `using std::out;` (引入单个名字), 后面就不用加 std::
  也可引入整个名字空间：`using namespace std;` 把std空间的所有名字引入进来

* std::endl  换行符，把换行符放入 cout ：`cout << endl ` 就是换行

* cin 是标准输入流对象，相当于键盘；

  \>> 是输入运算符

```c++
# if 1
# include <iostream>	// C++ 标准输入输出流头文件
using std::cout;
using std::endl;
int main()
{
    std::cout << "hello world!\n"<< std::endl;
    std::cout << 3+4;
    cout << "王子陈" << endl;
    double radius;
    std::cin >> radius;
    cout << 3.14* radius * radius << endl;
    
    cout << "   *" << endl;
    cout << " **  \n";
    cout << "   *" << endl;
    return 0;
}
# endif
```

计算器：

```c++
# include <iostream>
using namespace std;

void help()
{
    cout << "======简单计算器=====\n";
    cout << "请输入：左运算数 运算符 右运算符\n";
}
int main()
{
    while(1)
    {
        help();
        double a,b;
        char op;
        cin >> a >> op >> b;
        if (op == '+')
            cout << a+b <<endl;
        else if(op == '-')
            cout << a-b << endl;
        else if (op == '*')
            cout << a*b << endl;
        else if (op == '/')
            cout << a/b << endl;
        else
            cout << "Error" << endl;
    }
}
```

C++ 将外部设备都看成一个流，键盘，文件，网络都可以作为流输入输出

```c++
# include <fstream>
# include <iostram>
# include <string>
using namespace std;
int main()
{
    ofstream oF("test.txt");	//ofstream 类，oF输出文件流对象（“文件名”）
    oF << 3.14 << " " <<"hello World\n";
    oF.close(); //关闭
    
    ifstream iF("test.txt"); //输入文件流对象iF
    double d; //知道文件里有数字和字符
    string str;
    iF >> d >>str;
    cout << d << " " <<str <<endl;
    return 0;
}
```

## P4 引用变量、引用形参

* 引用变量是其他变量的别名。就如同一个人的外号

* 既然是引用，定义引用变量时就必须指明其引用的是哪个变量

  ``` c++
  int a = 3;
  int &r = a; //引用变量r，类型是int ，r是a的别名
  // r 和 a 是同一内存块的两个名字
  ```

* 引用变量是“从一而终”，一旦定义就不能再引用其他变量

  ```c++
  int &r = a;
  int &r = b; // 错
  ```

* 引用变量 和 被引用的变量类型必须匹配。

* 对引用变量的操作就是对它引用的变量的操作。

  ```c++
  int a = 3, &r = a;
  cout << a << '\t' << endl; // 3 3
  r = 5;
  cout << a << '\t' << end; // 5 5
  ```

  

### 函数的值形参

* C 函数的形参都是值参数：形参作为函数的局部变量有自己单独的内存块，当函数调用时，实参将值拷贝（赋值给）形参。**对形参的修改不会影响实参**。要想通过函数修改值，需要传入地址（指针类型的变量）
* 

```c++
void swap (int &x, int &y) //函数的引用形参：引用实参，x和y 没有内存块，分别是实参的别名，它们就是实参
{
    int t=x;
    x = y;
    y = t;
}

# include <iostream>
using namespace std;
int main()
{
    int a = 3, b = 4;
    cout << a << '\t' << b << endl;
    swap(a,b); //x 引用 a，x是a的别名
    cout << a << '\t' << b << endl;
}
```

## P5. 函数的默认形参、函数重载

### 函数的默认形参

* 函数的形参可以有默认值

  ` void print(char ch, int n = 1); `

  有默认值的形参可以不提供值

* 默认形参必须在非默认形参右边，即一律靠右

  ```c++
  add(x = 1,y, z = 3);//错
  add(y, x = 1, z = 3;) //ok
  ```

```c++
# include <iostream>
using namespace std;
void print(char ch, int n = 1)
{
    for(int i = 0; i<n; i++)
        cout << ch;
}
int main()
{
    print('*'); cout << endl; //*
    print('*',3); cout << endl; //***
    print('*',5); cout << endl; //*****
}
```

```c++
# include <iostream>
using namespace std;
int add(int x, int y=2, int z=3)
{
    return x+y+z;
}
int main()
{
    cout << add(5) << endl;
    cout << add(5,7) << endl;
    cout << add(5,7,9) << endl;
}
```

### 函数重载

* C++ 允许同一作用域里有同名的函数，只要它们的形参(类型，个数)不同。如：

  ```c++
  int add(int x, int y); 
  double add(double x, double y);
  ```

* 函数名和形参列表构造了**函数的签名**

* 函数重载不能根据返回类型区分函数。如：

  ```c++
  int add(int x, int y);
  double add(int x, int y);
  ```

```c++
# include <iostream>
using namespace std;

int add(int x, int y = 2)
{
    return x+y;
}
double add(double x, double y = 2.0)
{
    return x+y;
}
int main()
{
    cout << add(5,3) << endl;
    cout << add(5.3, 7.8) << endl;
    cout << add((double)5, 7.8) << endl; //不加强制转换，会有歧义性
}
```

## P6. 函数模板

```c++
int add(int x, int y)
{
    return x + y;
}
double add(double x, double y)
{
    return x + y;
}
```

每个地方都要单独修改。

通用算法：函数模板，也称为泛型算法。（在一个地方保证正确就可以了）

* 用 template 关键字增加一个模板头，将数据类型变成**类型模板参数**

  ```c++
  template <typename T>
  T add(T x, T y) // 数据类型是T
  {
      return x+y
  }
  ```

### 模板实例化

* 给模板参数传递实际的模板参数

  ```c++
  cout << add<int>(5, 3) << endl; //自动产生int版本的函数，把T换成 int
  cout << add<double>(5.3, 7.8) << endl;
  ```

```c++
# include <iostream>
# include <string>
using namespace std;

template <typename T>
T add(T x, T y)
{
    return x+y;
}
int main()
{
 	cout << add<int>(5, 3) << endl;
    cout << add<double>(5.3, 7.8) << endl;
    cout << add<int>(4, 6) << endl;//不会再产生一次
    cout << add<string>("hello","world") << endl;
}
```

编译器根据模板参数自动推断，应该产生哪种版本的实例

```c++
cout << add(5,3) << endl; //自动产生int版本函数
cout << add(5.3, 7.8) << endl; //产生double版本
cout << add(5, 7.8) << endl; //歧义性，需要显示指定参数类型或实例化类型
```

## P7. string 和 vector

### string

* 是一个用户定义类型，表示的是字符串

  `string s = "hello", s2("world");`

* 用成员访问运算符 .  访问string 类的成员

  ```c++
  cout << s.size() << endl; //调用成员函数
  string s3 = s.substr(1,3); //取下标1-3的字符 
  cout << s3 << endl;
  ```

* 用运算符对string 对象进行运算，如 + 、[]

```c++
# include <iostream>
# include <string>
using namespace std;
int main()
{
    string s = "hello", s2("world"), s_1{"morning"};
    //访问运算符
    cout << s.size() << endl; // 5
    
    string s3 = s.substr(1,3);
    cout << s3 << endl; //"ell"
    
    string s4 = s+ " " + s2;
    cout << s4 << endl; // "hello world"
    
    s4[0] = 'H';
    s4[6] = 'X';
    cout << s4 << endl; // "Hello Xorld"
    
    int pos = s4.find("orl"); //查找子串
    cout << pos << endl;
    
    s4.insert(3, "ABCDE");
    cout << s4 << endl;
    
    for (int i = 0; i< s4.size(); i++)
        cout << s4[i] << "-";
    cout << "\n";
}
```

### vector

#### 内在的数组(静态数组)

```c++
# include <iostream>
using std::cout;
int main()
{
    int arr[] = {1,2,3,4}; //大小固定，以后不能添加更多int值
    for (int i = 0; i < 4; i++)
        cout << arr[i] << '\t';
    cout << '\n';
}
```

* 向量vector，类似于数组，但可以动态增长。需要包含头文件 \<vector\>
* 是一个**类模板**，实例化产生一个类，如 vector\<int\> 产生一个数据元素是 int 的 **vector<int\> 类**（向量）
* 同样，可以通过 vector\<int\> 类的对象去访问其成员，如成员函数。
* 同样可以用运算符进行一些运算

```c++
# include <iostream>
# include <vector>
using namespace std;

int main()
{
    std::vector<int> v = {7,5,16,8}; //std::vector<int>是一个类，v是对象
    // push_back() 成员函数 在最后添加一个元素
    v.push_back(25);
    v.push_back(13);
    
    // 成员函数 size()、下标运算符[]
    for (int i = 0; i< v.size(); i++)
        cout << v[i] << '\t';
    cout << '\n';
    
    v.pop_back(); // 把最后一个元素弹出
    
    v.resize(2); // 把大小变为2
}
```

## P8. 指针和动态内存分配

### 指针

* 约定：指针就是地址，变量的指针就是变量的地址。可以用**取地址运算符&** 获得一个变量的地址。如：

  `&var` 

* **指针变量**就是存储指针（地址）的变量。如：

  `T* p; // p是存储 “T 类型变量的地址” 的变量` 

* 通过 **取内容运算符 *** 可以得到一个指针变量指向的变量

  ` *p 就是 p 指向的那个变量` 

```c++
# include <iostream>
using namespace std;
int main()
{
    int a = 3;
    int* p = &a;	// 取地址运算符& 获得a的地址
    cout << p << '\t' << &a << endl;//都是a的地址
    // 取内容运算符* 用于获得指针指向的变量（内存块)
    cout << *p << '\t' << a <<endl; //*p 就是 a = 3
    *p = 5;
    cout << *p << '\t' << a <<endl;
    
    int* q = p;	//q 和p的值相同，都是a的地址
    cout << *p << '\t' << *q << '\t'<< a <<endl;
    
    char* s = &a; // s是char* ，&a是int*类型，不匹配，出错
        
}
```

用指针访问数组元素：

```c++
# include <iostream>
using namespace std;
int main()
{
    int arr[] = {10,20,30,40};
    int* p = arr; //数组名就是数组第一个元素的地址，即arr等于& (arr[0]) , p[i] 就是 *(p+i)
    cout << *(p+2) << '\t' << p[2] << '\t' <<arr[2] << endl;
    
    for (int* q = p+4; p < q; p++) //q是最后一个元素的后面一个地址
        cout << *p <<'\t';
    cout << '\n';
}
```

上面是内存的堆栈区，每个程序有自己的堆栈区，下面是堆存储区(所有程序共享的空闲存储区，动态分配)

```c++
// 动态内存分配：new 用于申请内存块、delete 用于释放内存块
T* p = new T;
delete p;

T* q = new T[5]; // 数组
delete[] q;
```



```c++
// 动态分配
# include <iostream>
using namespace <iostream>;
int main()
{
    int* p = new int;//c里用malloc，c++ 用new（还会实例化对象），申请一个int型大小的内存块，分配成功，p的值非零，等于 new int 内存块的地址，p是堆栈区的内存块
    *p =3; // new int 内存块里存放的值是3
    cout << p << '\t' << *p << endl;
    delete p; //每次用完要释放，否则，后面的p重新指向了新的堆内存块，那原来的内存块就访问不到了，想释放也不行，可用内存越来越少（内存泄漏）
    p = new int;
    *p = 5;
    cout << p << '\t' << *p << endl;
    delete p;
}
```

```c++
// p 指向多个int 型的内存块
# include <iostream>
using namespace std;
int main()
{
    int n = 4;
    int *p = new int[n]; // 分配4个int型堆内存块
    for (int i = 0; i<n; i++)
        p[i] = 2*i + 1;
    // 遍历输出
    for (int* q = p+n; p<q; p++)
        cout << *p << '\t';
    cout << '\n';
    
    char* s = (char*)p; //强制类型转换，都指向了同一块内存，int占4字节，char占1字节, 在s看来共有16个单元
    char ch = 'A';
    int n2 = n*sizeof(int) /sizeof(char); //n2=16
    //遍历赋值
    for(int i = 0; i<n2; i++)
        s[i] = ch+i;
    // 遍历输出
    for(char* r = s+n2; s<r; s++) // r指向了最后一个元素的后面一个单元
        cout << *s;
    cout << '\n';
    
    delete[] p; //不加[], 只会释放4个字节
}
```

## P9 类和对象

### 面向对象编程

* 面向过程编程：变量（对象)是一些存储数据的内存块，而过程（函数）对这些数据进行处理，分而治之，分解成多个子问题。任何函数都能访问全局变量，可能导致数据不安全，程序不易维护
* 面向对象：程序是由不同种类的许多对象相互协作完成的。各对象有自己的 属性和行为。对象之间通过发生/接收消息来协作完成各种任务。由这些对象 构成的程序称之为“对象式系统”

### 面向对象设计

* 从具有共同特征的许多对象抽象出某种概念，如“人” 和 “车”，根据这个类，产生一个对象

* 某些概念之间可能存在某种关系：包含（组合）关系，继承（派生）关系
* 一个人到银行办业务：客户、银行员工，大堂精力，柜机，银行系统

* 过程式编程：用内在类型如int、double 表示数据，用面向这些机器类型的概念去解决复杂问题，不易于思考

### C++的面向对象特性：用户定义类型

* 程序员定义自己的“用户定义类型 " 如 类 类型，来表示各种应用问题中的各种概念

* C++ 标准库已经提供了很多实用的“用户定义类型”，是C++ 标准库的程序员实现的

  * cout 是一个 ostream 类 的对象，cin 是一个 istream类的对象，可以向它们发送消息

    cout << "hello world";

  * string 是一个表示字符串的类。向一个string 对象发送一个size() 消息，查询该对象包含的字符数目。

    ```c++
    string str = "hello world";
    cout << str.size();
    ```

  * 一个用户定义类型包括：

    1. 哪些属性（数据，成员变量）
    2. 哪些操作（成员函数）
    3. 不同属性或操作的访问权限，哪些是类外部可以访问的，哪些是仅内部才能访问的

  * 用户定义类型的关系，继承还是包含

  * 程序：哪些具体对象如何进行交互协作

### 类和对象

* 用 struct 或 class 关键字定义一个类。定义的类就是一个数据类型

  ```c++
  struct student //student 类
  {
      string name;
      double score;
  }
  ```

* 对象就是类的一个实例：

  ```c++
  student stu;
  ```

### 成员访问运算符

* 访问对象的成员

  ```c++
  stu.name = "LiPing";
  stu.score = 78.5;
  ```

* 和内在类型一样，可以定义类 类型的数组，存储一组对象

  ```c++
  student students[3];
  student[0].name = "LiPing";
  student[0].score = 60.5;
  ```

### 类 类型的指针变量

* T 是一个类 类型，则 T* 就是 T 指针类型。如 int* 是int 指针类型。

* T* 变量可以指向一个对象

  ```c++
  student stu;
  student* p = &stu;
  
  student students[3];
  p = students+2; //指向第3个 student 对象
  ```

### 间接访问运算符 ->、取内容运算符 *

```c++
student stu;
student* p = &stu;
(*p).name = "LiPing"; //*p 就是 p指向的变量stu
p->score = 78;	// p指向的类对象的成员 score

student students[3];
p = students + 2;	//指向第3个student 对象
p -> name = "WangWei";
```

### 指向可以动态分配的对象

```c++
student* p = new student;
p -> name = "Wang";
delete p;	// 不需要的内存块要及时释放

p = new student[3];	// p 指向3个 student 的内存块的起始地址
p[1].score = 67;
*(p+1).score = 67;
p -> score = 78;
```

### 类的成员函数

```c++
struct student
{
    string name;
    double score;
    void print()
    {
        cout << name << "  " << score << '\n';
    }
};

int main()
{
    student stu;
    stu.print();
}
```

### 类体外定义成员函数

```c++
struct student
{
    string name;
    double score;
    void print();	//函数的声明
};

void student::print()	// 函数的实现，要加类作用域
{
    cout << name << "  " << score << '\n';
}
```

## P10. 学生成绩分析程序

* 输入一组学生成绩（姓名和分数），输出：平均成绩、最高分和最低分。也要能输出所有学生信息

```c++
# include <iostream>
# include <string>
# include <vector>
using namespace std;

struct student
{
    string name;
    double score;
    void print();
};
void student::print()
{
    cout << name << "  " << score << endl;
}
int main()
{
#if 0
    student stu;
    stu.name = "Li Ping";
    stu.score = 78.5;
    stu.print();
# endif
    vector<student> students; // 大小初始为0
    while (1)
    {
        student stu; // 临时对象
        cout << "请输入姓名 分数：\n";
        cin >> stu.name >> stu.score;
        if(stu.score < 0) break;
        students.push_back(stu);
    }
    for(int i = 0; i<students.size(); i++)
        students[i].print();
    
    double min = 100, max = 0, sum = 0,average = 0;
    for(int i = 0; i<students.size(); i++)
    {
        if(students[i].score < min)
            min = students[i].score;
        if(students[i].score > max)
            max = students[i].score;
        sum + = students[i].score;
    }
    average = sum/students.size();
    cout << "平均分、最高分、最低分：" << average<<" " <<max<<min <<endl;
}
```

## P11. this 指针、访问控制、构造函数

### this指针

* 成员函数实际上隐含一个this指针

```c++
# include <iostream>
# include <string>
using namespace std;

struct student
{
    string name;
    double score;
    void print()
    {
        cout << name << "  " <<score << endl;
        /*cout << this->name << " " << this->score <<endl; 是可以的 */
    }
};
/* 编译器内部把成员函数转换成普通函数:
void print(student* this)
{
	cout << name << " " << score << endll;
}
*/
int main()
{
    student stu;
    stu.name = "Li Ping";
    stu.score = 78.5;
    stu.print(); //其实是 print(#stu)
}
```

### class

mian函数和class类没有关系，外部函数的对象不能访问class类的私有成员，可以访问公有成员。

struct 和 class 的区别：

* struct 里的成员默认是public （公开的）
* class里的成员默认是private（私有的）

加上 public: 关键字，成员就可以外部访问。但是其他外部函数同样就都可以修改对象的数据了。所以一般public：加在数据定义后面，成员函数可以public，可以外部访问，但是不能直接访问 name 和 score。

如果想要访问 name 或 score，调用成员函数 get_name() , get_score()

有 get 就有 set，修改成员变量，调用成员函数 set_name() , set_score()，自己修改自己的数据能保证是安全的

```c++
clss student
{
//public
private:
    string name;
    double score;
public: // 接口
    void print()
    {
        cout << name << "  " <<score << endl;
    }
    string get_name() { return name;}
    double get_score() { return score;}
    
    void set_name(string n) {name = n;}
    void set_score(double s) {score = s}
};
int main()
{
    student stu;
    //stu.name = "Li Ping";
    //stu.score = 78.5;
    stu.set_name("Li Ping");
    stu.set_score(78.5);
    stu.print(); //其实是 print(#stu)
    cout<<stu.get_name()<<" "<<stu.get_score()<< endl;
}
```

### 构造函数

在创建一个对象时会自动调用（生成）称为“构造函数”的成员函数

构造函数：函数名和类名相同且无返回类型的成员函数。如果自己没有定义构造函数，自动创建空的默认构造函数：

```c++
student(){} // 无返回类型，没有参数，函数体是空的
```



```c++
class student 
{
private:
    string name;
    double score;
public:
    student(){}// 默认构造函数
    student(string n, double s) //自己构造函数，调用时需要给参数
    {
        name = n;
        score = s;
    }
    void print()
    {
        cout << this->name << " " << this->score << endl;
    }
};
int main()
{
    student stu("Liping",80.5);// 根据参数确定调用哪个构造函数
    stu.print();
    
    student students[3]; //无法给数组传参数(因为有多个对象)，只能调用默认构造函数，如果一个类没有默认构造函数，就不能定义这个类的数组
}
```

## P12. 运算符重载

```c++

```

## P13. String类、拷贝构造函数、析构函数

```c++
# include <iostream>
using namespace <iostream>;

class String // 防止冲突用大写的 S 开头
{
    char* data;	//存放字符
    int n;		//字符个数
public:
    Str()		//默认构造函数：参数是空指针
    {
        if(s == 0)
        {
            data = 0; n= 0; return;
        }
        const char* p = s;	//char* 指针
        while(*p != '\0') p++;
        n = p-s;	//有效字符个数
        data = new char[n+1];	//多分配一个，用来放'\0'
    }
    String(const char* s)	//构造函数:根据参数字符串动态分配内存
    {
        
    }
};
int main()
{
    String str, str2("hello world");//调用默认构造函数(无参数)，和调用带参数的构造函数
}
```

## P14. 类模板

