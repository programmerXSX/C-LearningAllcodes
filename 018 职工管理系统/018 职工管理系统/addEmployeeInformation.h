#include <iostream>
#include <fstream>
#include "employeeCategory.h"
using namespace std;
//增加职工信息的函数
void addEmployeeInformation();
bool inputStaff();
Staff& inputInformation( Staff& staff);
Manager& inputInformation(Manager& manager);
Boss& inputInformation(Boss& boss);