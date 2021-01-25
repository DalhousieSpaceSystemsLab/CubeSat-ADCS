#include "main_test.h"
#include "Eigen/Dense"
#include "data.h"


struct gpsData g = { 2020, 2020, 7, 18, 51.6413, 231.7821, 257.8729, 30.0};



	//Eigen::MatrixXd y(18, 1);
	//Eigen::MatrixXd H(18, 3);
	//Eigen::MatrixXd rmfvA(3, 1);
	//Eigen::MatrixXd rmfvB(3, 1);


	static Eigen::Matrix<double, 3, 1> rmfvA = (Eigen::Matrix<double, 3, 1>() <<
		-0.798735150635402,
		-0.589342852417518,
		-0.121231849956297).finished();
	/*
	rmfvA << -0.798735150635402,
		-0.589342852417518,
		-0.121231849956297;
		*/
	static Eigen::Matrix<double, 3, 1> rmfvB = (Eigen::Matrix<double, 3, 1>() <<
		-0.798735150635402,
		-0.589342852417518,
		-0.121231849956297).finished();
	

	static Eigen::Matrix<double, 18, 3> H = (Eigen::Matrix<double, 18, 3>() <<

		0.353553390593274, 0.353553390593274, 0.866025403784439,
		-0.482962913144534, 0.12940952255126, 0.866025403784439,
		0.12940952255126, -0.482962913144534, 0.866025403784439,
		0.353553390593274, -0.353553390593274, -0.866025403784439,
		-0.482962913144534, -0.12940952255126, -0.866025403784439,
		0.12940952255126, 0.482962913144534, -0.866025403784439,
		0.353553390593274, -0.866025403784439, 0.353553390593274,
		-0.482962913144534, -0.866025403784439, 0.129409522551261,
		0.12940952255126, -0.866025403784439, -0.482962913144534,
		0.866025403784439, 0.353553390593274, 0.353553390593274,
		0.866025403784439, -0.482962913144534, 0.12940952255126,
		0.866025403784439, 0.12940952255126, -0.482962913144534,
		-0.353553390593274, 0.866025403784439, 0.353553390593274,
		0.482962913144534, 0.866025403784438, 0.12940952255126,
		-0.12940952255126, 0.866025403784439, -0.482962913144534,
		-0.866025403784439, -0.353553390593274, 0.353553390593274,
		-0.866025403784439, 0.482962913144534, 0.12940952255126,
		-0.866025403784439, -0.12940952255126, -0.482962913144534).finished();

	static Eigen::Matrix<double, 18, 1> y = (Eigen::Matrix<double, 18, 1>() <<
		0.123,
		0.123,
		0.123,
		0.455163574314287,
		0.152901077299585,
		0.811298752064704,
		0.123,
		0.123,
		0.123,
		0.462908935785717,
		0.160646438771015,
		0.819044113536134,
		0.108533326057569,
		0.672196655331935,
		0.723487548910507,
		0.123,
		0.123,
		0.123).finished();


	double ws1 = 59.6951780433913;
	double ws2 = -29.6490103428103;
	double ws3 = 89.5490774125823;
	double wx = -0.0206888331068794;
	double wy = -8.95713431965391e-05;
	double wz = 0.0127879145560983;
	double gx = 2.00000000000000e-05;
	double gy = 0;
	double gz = 0;
	double ga1 = 0.000150000000000000;
	double ga2 = -7.50000000000000e-05;
	double ga3 = 0.000225000000000000;

	static Eigen::Matrix<double, 12, 1> rar = (Eigen::Matrix<double, 12, 1>() <<
	ws1, ws2, ws3, wx, wy, wz, gx, gy, gz, ga1, ga2, ga3).finished();

	rawSunSensorData rssd = { y, H };

	sensorData s = { rssd, rmfvA, rmfvB, rar };
