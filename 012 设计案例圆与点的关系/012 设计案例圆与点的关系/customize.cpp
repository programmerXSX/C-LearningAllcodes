#include "customize.h"
#include <iostream>

void set_coordinate(Circle& C, Point& P)		//设置坐标
{
	cout << "请输入圆的坐标" << endl;
	cin >> C.c_X >> C.c_Y;
	cout << "请输入圆的半径" << endl;
	cin >> C.R;
	cout << "请输入点的坐标" << endl;
	cin >> P.p_X >> P.p_Y;

}

void relation_C_P(Circle C, Point P)			//圆与点关系
{
	double distance = pow(pow(C.c_X - P.p_X, 2) + pow(C.c_Y - P.p_Y, 2), 0.5);
	cout << "点到圆心距离为：" << distance << endl;
	cout << "点与圆的关系为：";
	if (distance - C.R > 0)cout << "点在圆内" << endl;
	else if (distance - C.R < 0)cout << "点在园外" << endl;
	else cout << "点在圆上" << endl;
}
