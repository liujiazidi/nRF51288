/* Copyright (c) 2012 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */
#ifndef TWI_MASTER_CONFIG
#define TWI_MASTER_CONFIG

#define TWI_MASTER_CONFIG_CLOCK_PIN_NUMBER (24U)
#define TWI_MASTER_CONFIG_DATA_PIN_NUMBER (25U)

#define GSENSOR_INT_PIN_NUMBER             (10)  

#define I2C_ADR(address)                   (unsigned char)(address << 1) 
	
#define GSENSOR_I2C_DEVICE_ADDRESS         I2C_ADR(0x4c)


#endif
