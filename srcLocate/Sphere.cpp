#include "Sphere.h"
#include <math.h>

/**
 * 构造函数
 * @param  LocOfSensor   传感器球面坐标一维数组,以天顶角、方位角的顺序排列
 * @param  TimeOfArrival 到达时间数组
 * @param  Radius        球面半径
 * @param  NumOfSensors  传感器数量
 * @param  SpeedOfSound  声速
 */
sphereSolver::sphereSolver(double *LocOfSensor,double *TimeOfArrival,
								float *Radius,int NumOfSensors,float SpeedOfSound){
	sensorNumber=NumOfSensors;
	sonicSpeed = SpeedOfSound;
	radius = Radius;
	arrivalTime = VectorXd::Zero(sensorNumber);
	sensorLoc = MatrixX2d::Zero(sensorNumber, 2);
	sensorLocXYZ = MatrixX3d::Zero(sensorNumber, 3);

	sensorNumber = Map(TimeOfArrival);
	sensorLoc = Map(LocOfSensor);
	
	// for(int i=0;i<NumOfSensors;i++){
	// 	arrivalTime(i) = *(TimeOfArrival + i);
	// 	sensorLoc(i,0) = *(LocOfSensor + 2 * i + 0);
	// 	sensorLoc(i,1) = *(LocOfSensor + 2 * i + 1); 
	// }
/**
 * 将球面坐标转化为三维直角坐标
 */
	for(int i=0;i<NumOfSensors;i++){
		sensorLocXYZ(i,0) = radius * sin(sensorLoc(i,0)) * cos(sensorLoc(i,1));
		sensorLocXYZ(i,1) = radius * sin(sensorLoc(i,0)) * sin(sensorLoc(i,1));
		sensorLocXYZ(i,1) = radius * cos(sensorLoc(i,0));
	}
}
/**
 * 球面定位求解函数
 * @return 定位结果的三维直角坐标
 */
double sphereSolver::doSolve(){

}