#pragma once

#include <Eigen>
#include <vector>

using namespace Eigen;
using namespace std;

class planeSolver {
private:
	MatrixX2d sensorLoc;					//ƽ�洫��������
	VectorXd arrivalTime;					//����ʱ��
	Vector2d spaceLimit;					//ƽ��ߴ�
	int sensorNumber;
	float sonicSpeed;

public:
	planeSolver(double *LocOfSensor, double *TimeOfArrival, float *LimitOfSpace, int NumOfSensors, 
					float SpeedOfSound, double Height);	//���캯��
	double* doSolve();						//��⺯��
	double pdist(const RowVector2d& r1, const RowVector2d& r2);	//����������
	double LocRes[2] = { 0,0 };			    //��λ���
	bool isAccurate = true;					//�Ƿ�׼ȷ�ı�־λ��Ĭ��Ϊ��
	bool isInBox();							//�ж��Ƿ���ƽ����
	void resRevised();						//�������ƫ��ʱ����������
};