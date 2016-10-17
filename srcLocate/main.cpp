#include <iostream>
#include "Geiger.h"
using namespace Eigen;
using namespace std;

int main()
{
	double LocOfSensors[15] = { 0,0,0,0,30,0,0,30,144,64,0,144,64,30,144 };							//��̽ͷ˳��洢�ĵ�ǰ�������õĴ�����λ��
    int NumOfSensors = 5;																			//ʹ�õĴ�������������ǰΪ5
	float LimitOfSpace[3] = { 64,30,144 };															//��ά��Ŀռ�����
    float SpeedOfSound=2000*1000;																	//����
    double TimeOfArrival[5]={6854e-7,6885e-7,7314e-7,7368e-7,7409e-7 };								//���εĵ���ʱ�䣬��λΪs
    
	geigerSolver Test(LocOfSensors, TimeOfArrival, LimitOfSpace, NumOfSensors, SpeedOfSound);
    double* Res=Test.doSolve();
    for(int i=0;i<3;i++){
        cout<<*(Res+i)<<endl;
    }

}