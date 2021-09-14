#include <iostream>
#include "employeeCategory.h"
#include <string>
using namespace std;

//删除离职员工的函数
void deleteExemployee();
bool findDeleteEmployee(char number[64]);
bool ifFind_Delete(string if_find, int goalNumber, Staff staff[100], Manager manager[10], Boss boss[5]);
void deleteEmployee(int goalNumber, Staff staff[100]);
void deleteEmployee(int goalNumber, Manager manager[10]);
void deleteEmployee(int goalNumber, Boss boss[5]);
