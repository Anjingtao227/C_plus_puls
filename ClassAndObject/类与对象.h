#pragma once

//定义一个矩形类，类名是Rect
class Rect
{
	//属性有两个：长度和宽度
	//属性也有命名规范：m_数据类型缩写+属性名（建议使用大驼峰）
private:
	int m_nLength;
	int m_nWidth;
	//方法
	//方法命名规范：一个或多个单词来组成，第一个单词全小写，其他单词首字母大写
public:
	//自己声明一个构造函数，用来构造对象，实现初始化。当我们自己写了构造函数之后，编译器就不会生成默认的那个无参构造函数
	Rect();//这是无参构造函数
	Rect(int nLength, int nWidth);//这是有参构造函数，有两个参数
	Rect(int nLength);
	void setLength(int nLength);//设置矩形的长度
	void setWidth(int nWidth);//设置矩形的宽度
	int getArea();//计算矩形的面积
	int getPerimeter();//计算矩形的周长
};