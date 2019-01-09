#ifndef MPU6050_H
#define MPU6050_H

#include <stdbool.h>
#include <stdint.h>

typedef enum {
	SMPLRT_DIV	=0X19,
	CONFIG,
	GYRO_CONFIG,
	ACCEL_CONFIG,
	ACCEL_XOUT_H=0X3B,
	ACCEL_XOUT_L,
	ACCEL_YOUT_H,
	ACCEL_YOUT_L,
	ACCEL_ZOUT_H,
	ACCEL_ZOUT_L,
	
	TEMP_OUT_H=0x41,
	TEMP_OUT_L,
	
	GYRO_XOUT_H  =0X43,
	GYRO_XOUT_L,
	GYRO_YOUT_H,
	GYRO_YOUT_L,
	GYRO_ZOUT_H,
	GYRO_ZOUT_L,
	
	PWR_MEMT_1=0x6B,
	
	
}mpu_reg_address;


//低通滤波
#define DLPF_5HZ			(6)
#define DLPF_10HZ			(5)
#define DLPF_21HZ			(4)
#define DLPF_44HZ			(3)
#define DLPF_94HZ			(2)
#define DLPF_184HZ		(1)
#define DLPF_260HZ		(0)
#define DLPF_RESERVE	(7)

//低通滤波参数设置为0，7时，陀螺仪输出频率为8KHZ
//1-6时陀螺仪输出频率为1KHZ
//在陀螺仪输出频率为	1KHZ时使用以下宏定义采样频率
#define SAMPLE_50HZ		(19)
#define SAMPLE_125HZ	(7)

//不需要开启加速度计自检时使用
#define ACCEL_FS_2g		(0)
#define ACCEL_FS_4g		(8)
#define ACCEL_FS_8g		(0x10)
#define ACCEL_FS_16g	(0x18)

//不需要开启陀螺仪自检时使用
#define GYRO_FS_250		(0)
#define GYRO_FS_500		(8)
#define GYRO_FS_1000		(10)
#define GYRO_FS_2000	(18)


#define CLOCK_SEL_INTER8M		(0)
#define CLOCK_SEL_PllGyroX	(1)


#define WAKEUP	(0x00)

bool mpu6050_init(void);
/**
  @brief Function for writing a MPU6050 register contents over TWI.
  @param[in]  register_address Register address to start writing to
  @param[in] value Value to write to register
  @retval true Register write succeeded
  @retval false Register write failed
*/
bool mpu6050_register_write(uint8_t register_address, const uint8_t value);

/**
  @brief Function for reading MPU6050 register contents over TWI.
  Reads one or more consecutive registers.
  @param[in]  register_address Register address to start reading from
  @param[in]  number_of_bytes Number of bytes to read
  @param[out] destination Pointer to a data buffer where read data will be stored
  @retval true Register read succeeded
  @retval false Register read failed
*/
bool mpu6050_register_read(uint8_t register_address, uint8_t *destination, uint8_t number_of_bytes);

/**
  @brief Function for reading and verifying MPU6050 product ID.
  @retval true Product ID is what was expected
  @retval false Product ID was not what was expected
*/
bool mpu6050_verify_product_id(void);


bool get_mpu6050data(void);

#endif /* MPU6050_H */
