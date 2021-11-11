#ifndef DIO_H_
#define DIO_H_
/****************************************************************************************/
/*AUTOSAR (4.4.0) and Software (1.0.0) versions definitions*/
/****************************************************************************************/
#define	DIO_AR_RELEASE_MAJOR_VERSION	(4U)
#define	DIO_AR_RELEASE_MINOR_VERSION	(4U)
#define	DIO_AR_RELEASE_PATCH_VERSION	(0U)
#define	DIO_SW_MAJOR_VERSION	(1U)
#define	DIO_SW_MINOR_VERSION	(0U)
#define	DIO_SW_PATCH_VERSION	(0U)
/****************************************************************************************/
/*Header Files inclusion*/
/****************************************************************************************/
#include "Std_Types.h"
/*AUTOSAR version checks*/
#if((STD_TYPES_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
||	(STD_TYPES_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
||	(STD_TYPES_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
#error "The Std_Types.h AR version is not compatible with Dio.h AR version"
#endif
/*Software version checks*/
#if((STD_TYPES_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
||	(STD_TYPES_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
||	(STD_TYPES_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
#error "The Std_Types.h SW version is not compatible with Dio.h SW version"
#endif
#include "Dio_Cfg.h"
/*AUTOSAR version checks*/
#if((DIO_CFG_AR_RELEASE_MAJOR_VERSION != DIO_AR_RELEASE_MAJOR_VERSION)\
||	(DIO_CFG_AR_RELEASE_MINOR_VERSION != DIO_AR_RELEASE_MINOR_VERSION)\
||	(DIO_CFG_AR_RELEASE_PATCH_VERSION != DIO_AR_RELEASE_PATCH_VERSION))
#error "The Dio_Cfg.h AR version is not compatible with Dio.h AR version"
#endif
/*Software version checks*/
#if((DIO_CFG_SW_MAJOR_VERSION != DIO_SW_MAJOR_VERSION)\
||	(DIO_CFG_SW_MINOR_VERSION != DIO_SW_MINOR_VERSION)\
||	(DIO_CFG_SW_PATCH_VERSION != DIO_SW_PATCH_VERSION))
#error "The Dio_Cfg.h SW version is not compatible with Dio.h SW version"
#endif
/*Non AUTOSAR File Inclusion*/
#include "Common_Macros.h"
/****************************************************************************************/
/*Module Definitions*/
/****************************************************************************************/
#define DIO_MODULE_ID    	(120U)		/* Dio Module Id */
#define DIO_INSTANCE_ID  	(0U)		/* Dio Instance Id */
#define DIO_INITIALIZED		(1U)
#define DIO_NOT_INTIALIZED	(0U)
/****************************************************************************************/
/*DET Error Codes Definitions*/
/****************************************************************************************/
/*Invalid Channel Requested Error Code*/
#define DIO_E_PARAM_INVALID_CHANNEL_ID	(uint8)0x0A
/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             	(uint8)0x10
/*Invalid port requested Error Code*/
#define DIO_E_PARAM_INVALID_PORT_ID 	(uint8)0x14
/*Invalid channel group requested Error Code*/
#define DIO_E_PARAM_INVALID_GROUP		(uint8)0x1F
/*API called with a NULL pointer Error Code*/
#define DIO_E_PARAM_POINTER 			(uint8)0x20
/*Non initialized DIO module Error code (Non-AUTOSAR 4.4.0 Error Code)*/
#define DIO_E_PARAM_UNINIT				(uint8)0xF0
/****************************************************************************************/
/*DIO APIs Service ID Definitions*/
/****************************************************************************************/
/*Service ID for DIO_ReadChannel API*/
#define DIO_READ_CHANNEL_SERVICE_ID			(uint8)0x00
/*Service ID for DIO_WriteChannel API*/
#define DIO_WRITE_CHANNEL_SERVICE_ID		(uint8)0x01
/*Service ID for DIO_ReadPort API*/
#define DIO_READ_PORT_SERVICE_ID			(uint8)0x02
/*Service ID for DIO_WritePort API*/
#define DIO_WRITE_PORT_SERVICE_ID			(uint8)0x03
/*Service ID for DIO_ReadChannelGroup API*/
#define DIO_READ_CHANNEL_GROUP_SERVICE_ID	(uint8)0x04
/*Service ID for DIO_WriteChannelGroup API*/
#define DIO_WRITE_CHANNEL_GROUP_SERVICE_ID	(uint8)0x05
/*Service ID for DIO_GetVersionInfo API*/
#define DIO_GET_VERSION_INFO_SERVICE_ID		(uint8)0x12
/* Service ID for DIO Init Channel */
#define DIO_INIT_SERVICE_ID	                (uint8)0x10
/*Service ID for DIO_FlipChannel API*/
#define DIO_FLIP_CHANNEL_SERVICE_ID			(uint8)0x11
/****************************************************************************************/
/*Module Data Types*/
/****************************************************************************************/
typedef uint8 Dio_ChannelType;			/*Channel Type Definition*/
typedef uint8 Dio_PortType;				/*Port Type Definition*/
typedef uint8 Dio_LevelType;			/*Level Type Definition*/
typedef uint8 Dio_PortLevelType;		/*Port Level Type Definition*/
typedef struct {
	Dio_ChannelType mask;				/*Channels that is wanted to be accessed*/
	Dio_ChannelType offset;				/*Channel Group Ending*/
	Dio_PortType port;					/*Channel Group Port*/
}Dio_ChannelGroupType;					/*Channel group Type definition*/
typedef struct{
	Dio_PortType Port_Num;				/*Channel Port Number*/
	Dio_ChannelType Channel_Num;		/*Channel Number*/
}Dio_ConfigChannel;						/*Specific Channel Configuration Type*/
typedef struct{
	Dio_ConfigChannel Dio_Channel [DIO_CONFIGURED_CHANNELS];
		/*Array of Dio_ConfigChannel Structure with [DIO_CONFIGURED_CHANNELS] Elements number*/
}Dio_ConfigType;
        /*DIO Configuration Structure that used in Dio_Lcfg.c (Generated file)*/
extern Dio_ConfigType Dio_Configuration;
		/*Dio_Configuration Extern that exists in Dio_Lcfg.c (Generated file)*/
/****************************************************************************************/
/*Module APIs Prototypes*/
/****************************************************************************************/
/*DIO Initialization API*/
void Dio_Init(Dio_ConfigType* Dio_Config);
/*DIO Read Channel API*/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);
/*DIO Write Channel API*/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
/*DIO Toggle Channel API*/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
/*DIO Read Port API*/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
/*DIO Write Port API*/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
/*DIO Read Channel Group API*/
Dio_PortLevelType Dio_ReadChannelGroup(Dio_ChannelGroupType *ChannelGroupIdPtr);
/*DIO Write Channel Group API*/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr,
						   Dio_PortLevelType Level);
/*DIO Get Software Version Information API*/
void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfo);

#endif /* DIO_H_ */
