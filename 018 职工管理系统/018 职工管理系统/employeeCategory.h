#include <iostream>
#pragma once
//所有职工类
class Allstaff
{
public:
	const char* number = "NUMBER";//职工编号
	const char* name = "NAME";//职工姓名
};
//普通职工类
class Staff :public Allstaff
{
public:
	Staff& operator=(Staff staff);
	const char* station = "普通职工";//职工岗位
	const char* responsibility= "完成";//职工职责	完成经理交给的任务
};
//经理
class Manager :public Allstaff
{
public:
	
	const char* station = "经理";//职工岗位
	const char* responsibility = "完成下发";//职工职责		完成老板交给的任务，并下发任务给员工
};
//老板
class Boss :public Allstaff
{
public:
	const char* station = "老板";//职工岗位
	const char* responsibility = "管理";//职工职责		管理公司所有事务
};
