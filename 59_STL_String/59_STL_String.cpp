// 59_STL_String.cpp: 目标的源文件。
//string是C++风格的字符串，而string本质上是一个类
// 
//string和char*的区别
//char*是一个指针
//string是一个类，类内部封装了char*，管理这个字符串的是一个char*类型的容器

//特点
//string类内部封装了很多成员方法		例如：查找find，拷贝copy，删除delete，插入insert
//string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

#include "59_STL_String.h"

//string的构造函数
//构造函数原型
//1、string();						//创建一个空的字符串 例如string str;
//	 string(const char* s);			//使用字符串s进行初始化
//2、string(const string& str);		//使用一个string对象初始化另一个string对象
//3、string(int n,char c);			//使用n个字符c初始化
void test01()
{
	//默认无参构造
	string s1;

	//使用字符串str进行初始化
	const char* str = "We come, we see, we conquer!";
	string s2(str);
	cout << "s2 = " << s2 << endl;

	//使用一个string对象初始化另一个string对象
	string s3(s2);
	cout << "s3 = " << s3 << endl;

	//使用n个字符c初始化
	string s4(5, '6');
	cout << "s4 = " << s4 << endl;
	
}

//string赋值操作
//string& operator=(const char* s);		//char*类型字符串 赋值给当前的字符串
//string& operator=(const string& s);	//把字符串s赋给当前的字符串
//string& operator=(char c);			//字符赋值给当前的字符串
//string& assign(const char* s);		//把字符串s赋给当前的字符串
//string& assign(const char* s, int n); //把字符串s的前n个字符赋给当前的字符串
//string& assign(const string& s);		//把字符串s赋给当前字符串
//string& assign(int n, char c);		//用n个字符c赋给当前字符串
void test02()
{
	//string& operator=(const char* s); //char*类型字符串 赋值给当前的字符串
	string str1;
	str1 = "hello world";
	cout << str1 << endl;
	//string& operator=(const string& s); //把字符串s赋给当前的字符串
	string str2;
	str2 = str1;
	cout << str2 << endl;
	//string& operator=(char c); //字符赋值给当前的字符串
	string str3;
	str3 = 'b';
	cout << str3 << endl;
	//string& assign(const char* s); //把字符串s赋给当前的字符串
	string str4;
	str4.assign("hello Cplusplus");
	cout << str4 << endl;
	//string& assign(const char* s, int n); //把字符串s的前n个字符赋给当前的字符串
	const char* s = "we come,we see,we conquer!";
	string str5;
	str5.assign(s, 10);
	cout << str5 << endl;
	//string& assign(const string& s); //把字符串s赋给当前字符串
	string str6;
	str6.assign(s);
	cout << str6 << endl;
	//string& assign(int n, char c); //用n个字符c赋给当前字符串
	string str7;
	str7.assign(6, '6');
	cout << str7 << endl;
}

//string拼接
//string& operator+=(const char* str);					//重载+=操作符
//string& operator+=(const char c);						//重载+=操作符
//string& operator+=(const string& str);				//重载+=操作符
//string& append(const char* s);						//把字符串s连接到当前字符串结尾
//string& append(const char* s, int n);					//把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string& s);						//同operator+=(const string& str)
//string& append(const string& s, int pos, int n);		//字符串s中从pos开始的n个字符连接到字符串结尾
void test03()
{
	//string& operator+=(const char* str);					//重载+=操作符
	string str1 = "我";
	str1 += "爱玩游戏";
	cout << "str1 = " << str1 << endl;
	//string& operator+=(const char c);						//重载+=操作符
	str1 += ':';
	cout << "str1 = " << str1 << endl;
	//string& operator+=(const string& str);				//重载+=操作符
	string str2 = "LOL DNF";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	//string& append(const char* s);						//把字符串s连接到当前字符串结尾
	str3.append(" love ");
	//string& append(const char* s, int n);					//把字符串s的前n个字符连接到当前字符串结尾
	str3.append("game abcde", 4);
	//str3.append(str2);
	//string& append(const string& s, int pos, int n);		//字符串s中从pos开始的n个字符连接到字符串结尾
	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	cout << "str3 = " << str3 << endl;
}

//string查找替换
//int find(const string& str, int pos = 0) const;		//查找str第一次出现位置,从pos开始查找
//int find(const char* s, int pos = 0) const;			//查找s第一次出现位置,从pos开始查找
//int find(const char* s, int pos, int n) const;		//从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const;			//查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const;	//查找str最后一次位置,从pos开始查找
//int rfind(const char* s, int pos = npos) const;		//查找s最后一次出现位置,从pos开始查找
//int rfind(const char* s, int pos, int n) const;		//从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const;			//查找字符c最后一次出现位置
//string& replace(int pos, int n, const string& str);	//替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s);		//替换从pos开始的n个字符为字符串s
void test04()
{
	//查找
	//从左往右
	string str1 = "abcdefgde";
	int pos = str1.find("de");
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}
	//从右往左
	pos = str1.rfind("de");
	cout << "pos = " << pos << endl;
	
	//替换
	string str2 = "abcdefgde";
	str2.replace(1,3, "1111");
	cout << "str2 = " << str2 << endl;
}
//string字符串比较
//int compare(const string& s) const;	//与字符串s比较
//int compare(const char* s) const;		//与字符串s比较
void test05()
{
	//比较ASCII码，逐位比较
	string s1 = "hello";
	string s2 = "aello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		cout << "s1 等于 s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 大于 s2" << endl;
	}
	else
	{
		cout << "s1 小于 s2" << endl;
	}
}

//string字符存取
//char& operator[](int n); //通过[]方式取字符
//char& at(int n); //通过at方法获取字符
void test06()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
}

//string的插入和删除
//string& insert(int pos, const char* s); //插入字符串
//string& insert(int pos, const string& str); //插入字符串
//string& insert(int pos, int n, char c); //在指定位置插入n个字符c
//string& erase(int pos, int n = npos); //删除从Pos开始的n个字符
void test07()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;
	str.erase(1, 3); //从1号位置开始3个字符
	cout << str << endl;
}

//string的子串：从字符串中获取想要的子串
//string substr(int pos = 0, int n = npos) const;	//返回由pos开始的n个字符组成的字符串
void test08()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;
	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}
int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();

	return 0;
}
