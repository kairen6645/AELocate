#pragma once


#include <Eigen>
#include <vector>

using namespace Eigen;
using namespace std;

class geigerSolver{
private:
	Matrix<double, Dynamic, 3> sensorLoc;	//����������
	VectorXd arrivalTime;					//����ʱ��
	Vector3d spaceLimit;					//�Լ��Ŀռ�ߴ�
	int sensorNumber;
	float sonicSpeed;

public:
	geigerSolver(double *LocOfSensor,double *TimeOfArrival,float *LimitOfSpace,int NumOfSensors,float SpeedOfSound);	//���캯��
	double* doSolve();						//��⺯��
	double pdist(RowVector3d, RowVector3d);	//����������
	double LocRes[3] = { 0,0,0 };			//��λ���
	bool isAccurate = true;					//�Ƿ�׼ȷ�ı�־λ��Ĭ��Ϊ��
	void resRevised();						//�������ƫ��ʱ����������
	bool isInBox();							//�ж��Ƿ�������
	double targetFunc(RowVector3d);			//���ۺ���
};