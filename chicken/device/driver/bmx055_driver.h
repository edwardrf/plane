#ifndef __BMX055_DRIVER_H__
#define __BMX055_DRIVER_H__

#include "io/io.h"

#ifndef NULL
#define NULL	0
#endif

#define ACC_ADDR			0x18
#define ACC_CHIPID_ADDR		0x00	//should read out 0xFA
#define ACC_SOFTRESET_ADDR	0x14
#define ACC_RANGE_ADDR		0x0F
#define ACC_X_LSB_ADDR		0x02
#define ACC_X_MSB_ADDR		0x03
#define ACC_Y_LSB_ADDR		0x04
#define ACC_Y_MSB_ADDR		0x05
#define ACC_Z_LSB_ADDR		0x06
#define ACC_Z_MSB_ADDR		0x07

#define GYRO_ADDR			0x68
#define GYRO_CHIPID_ADDR	0x00	//should read out 0x0F
#define GYRO_SOFTRESET_ADDR	0x14
#define GYRO_RANGE_ADDR		0x0F
#define GYRO_X_LSB_ADDR		0x02
#define GYRO_X_MSB_ADDR		0x03
#define GYRO_Y_LSB_ADDR		0x04
#define GYRO_Y_MSB_ADDR		0x05
#define GYRO_Z_LSB_ADDR		0x06
#define GYRO_Z_MSB_ADDR		0x07

#define MAG_ADDR			0x10
#define MAG_POWER_ADDR		0x4B

struct RawGyroValue
{
	int x;
	int y;
	int z;
	RawGyroValue() : x(0),y(0),z(0) {}
};

struct RawAccValue
{
	int x;
	int y;
	int z;
	RawAccValue() : x(0),y(0),z(0) {}
};

class Bmx055Driver
{
	public:
		Bmx055Driver(Io *io);
		bool readGyro(RawGyroValue &value);
		bool readAcc(RawAccValue &value);
	private:
		IicHandler *mIicHandler;
		void wakeupMag();
		void resetAcc();
		void resetGyro();
		bool readGyroAxis(uint8_t msbAddr, uint8_t lsbAddr, int &value);
		bool readAccAxis(uint8_t msbAddr, uint8_t lsbAddr, int &value);
};

#endif