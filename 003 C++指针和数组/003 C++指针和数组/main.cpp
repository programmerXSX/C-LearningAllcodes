#include <iostream>
using namespace std;

int main()
{
	//����ָ����������е�Ԫ��
	int arr[10] = { 1,3,5,7,9,11,7,8,9,10 };

	cout << "��һ��Ԫ��Ϊ ��" << arr[0] << endl;

	int* p = arr;//arr���������׵�ַ

	cout << "����ָ����ʵ�һ��Ԫ�� �� " << *p << endl;
	p++;
	cout << "����ָ����ʵڶ���Ԫ�� ��" << *p << endl;
	
	cout << "(��������ָ����ʵ�����Ԫ�� ��" << *p+1 << endl;

	cout << "����ָ����ʵ�����Ԫ�� ��" << *(p + 1) << endl;




	return 0;
}
