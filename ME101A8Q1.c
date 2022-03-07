const int NUMDIR = 7;
const int MOTORPOWER = 25;

void rotateAngle(int angle, int motorPower);
void configureAllSensors();
void drive(string direction, int duration);


task main()
{
	configureAllSensors();

  string directions[NUMDIR]={"ST","CW","ST","CW","ST", "CCW", "ST"};
  int durations[NUMDIR]={1200, 90, 900, 90, 900, 45, 1100};

  for (int numMovement = 0; numMovement < NUMDIR; numMovement++)
  {
  	drive(directions[numMovement], durations[numMovement]);
  }
  displayString(5, "JB");
  wait1Msec(10000);
}

void rotateAngle(int angle, int motorPower)
{
	resetGyro(S4);

	if (angle > 0)
	{
		motor[motorA] = -motorPower;
		motor[motorD] = motorPower;
	}
	else
	{
		motor[motorA] = motorPower;
		motor[motorD] = -motorPower;
	}
	angle = abs(angle);

	while (abs(getGyroDegrees(S4)) < angle)
	{}

	motor[motorA] = motor[motorD] = 0;
}

void configureAllSensors()
{
	SensorType[S1] = sensorEV3_Touch;
	SensorType[S2] = sensorEV3_Ultrasonic;
	SensorType[S3] = sensorEV3_Color;
	wait1Msec(50);
	SensorMode[S3] = modeEV3Color_Color;
	wait1Msec(50);
	SensorType[S4] = sensorEV3_Gyro;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_Calibration;
	wait1Msec(50);
	SensorMode[S4] = modeEV3Gyro_RateAndAngle;
	wait1Msec(50);
}

void drive(string direction, int duration)
{
	nMotorEncoder[motorA] = 0;
	if (direction == "ST")
	{
		motor[motorA] = motor[motorD] = MOTORPOWER;
		while (abs(nMotorEncoder[motorA]) < duration)
		{}
		motor[motorA] = motor[motorD] = 0;
	}
	else if (direction == "CW")
	{
		rotateAngle(duration, MOTORPOWER);
	}
	else
	{
		rotateAngle(-duration, MOTORPOWER);
	}
}
