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

* 向量，类似于数组，但可以动态增长。需要包含头文件 \<vector\>
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

* 指针变量就是存储指针（地址）的变量。如：

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
    
    char* s = &a; // s是char* ，不匹配，出错
        
}
```

用指针访问数组元素：

```c++
# include <iostream>
using namespace std;
int main()
{
    int arr[] = {10,20,30,40};
    int *p = arr; //数组名就是数组第一个元素的地址，即arr等于& (arr[0]) , p[i] 就是 *(p+i)
    cout << *(p+2) << '\t' << p[2] << '\t' <<arr[2] << endl;
    
    for (int *q = p+4; p < q; p++)
        cout << *p <<'\t';
    cout << '\n';
}
```

