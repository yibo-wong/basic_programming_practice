#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;
class Student {
	private:
		int age,num,grade[3];
		double ave;
		char name[20];
		char ch;
	public:
		void input()
		{
			cin.get(name,21,',');
			cin>>ch>>age>>ch>>num>>ch>>grade[0]>>ch>>grade[1]>>ch>>grade[2]>>ch>>grade[3];
			return;
		}
		void calculate()
		{
			ave=1.0*(grade[0]+grade[1]+grade[2]+grade[3])/4;
			return;
		}
		void output()
		{
			cout<<name<<","<<age<<","<<num<<","<<ave;
			return;
		}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
