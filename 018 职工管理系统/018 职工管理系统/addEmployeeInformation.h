#include <iostream>
#include <fstream>
#include "employeeCategory.h"
using namespace std;
//����ְ����Ϣ�ĺ���
void addEmployeeInformation();
bool inputStaff();
Staff& inputInformation( Staff& staff);
Manager& inputInformation(Manager& manager);
Boss& inputInformation(Boss& boss);