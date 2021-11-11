#ifndef DIO_CFG_H_
#define DIO_CFG_H_
/***********************************************************************************************/
/*AUTOSAR (4.4.0) and Software (1.0.0) versions definitions*/
/***********************************************************************************************/
#define	DIO_CFG_AR_RELEASE_MAJOR_VERSION	(4U)
#define	DIO_CFG_AR_RELEASE_MINOR_VERSION	(4U)
#define	DIO_CFG_AR_RELEASE_PATCH_VERSION	(0U)
#define	DIO_CFG_SW_MAJOR_VERSION			(1U)
#define	DIO_CFG_SW_MINOR_VERSION			(0U)
#define	DIO_CFG_SW_PATCH_VERSION			(0U)
/***********************************************************************************************/
/* Pre-compile option for Development Error Detect */
/***********************************************************************************************/
#define DIO_DEV_ERROR_DETECT		(STD_ON)
/***********************************************************************************************/
/* Pre-compile option for Version Info API */
/***********************************************************************************************/
#define DIO_VERSION_INFO_API		(STD_ON)
/***********************************************************************************************/
/* Pre-compile option for presence of Dio_FlipChannel API */
/***********************************************************************************************/
#define DIO_FLIP_CHANNEL_API		(STD_ON)
/***********************************************************************************************/
/*Number of configured DIO channels*/
/***********************************************************************************************/
#define DIO_CONFIGURED_CHANNELS		(4U)
/***********************************************************************************************/
/*Number of used PORTS*/
/***********************************************************************************************/
#define DIO_CONFIGURED_PORTS		(4U)
/***********************************************************************************************/
/*Configured Channels ID Index*/
/***********************************************************************************************/
/*LED1 Structure index in Dio_configuration Structure in Lcfg.c File*/
#define DioConfig_LED1_CHANNEL_ID_INDEX		(uint8)0x00
/*LED2 Structure index in Dio_configuration Structure in Lcfg.c File*/
#define DioConfig_LED2_CHANNEL_ID_INDEX		(uint8)0x01
/*BUTTON1 Structure index in Dio_configuration Structure in Lcfg.c File*/
#define DioConfig_BUTTON1_CHANNEL_ID_INDEX	(uint8)0x02
/*BUTTON2 Structure index in Dio_configuration Structure in Lcfg.c File*/
#define DioConfig_BUTTON2_CHANNEL_ID_INDEX	(uint8)0x03
/***********************************************************************************************/
/*Configured Ports IDs'*/
/***********************************************************************************************/
#define DioConfig_LED1_PORT_NUM				(Dio_PortType)2		/*PORTC*/
#define DioConfig_LED2_PORT_NUM				(Dio_PortType)3		/*PORTD*/
#define DioConfig_BUTTON1_PORT_NUM			(Dio_PortType)0		/*PORTA*/
#define DioConfig_BUTTON2_PORT_NUM			(Dio_PortType)1		/*PORTB*/
/***********************************************************************************************/
/*Configured Channels IDs'*/
/***********************************************************************************************/
#define DioConfig_LED1_CHANNEL_NUM			(Dio_ChannelType)3	/*Pin 3 in PORTC*/
#define DioConfig_LED2_CHANNEL_NUM			(Dio_ChannelType)6	/*Pin 6 in PORTD*/
#define DioConfig_BUTTON1_CHANNEL_NUM		(Dio_ChannelType)2	/*Pin 2 in PORTA*/
#define DioConfig_BUTTON2_CHANNEL_NUM		(Dio_ChannelType)4	/*Pin 4 in PORTB*/

#endif /* DIO_CFG_H_ */
