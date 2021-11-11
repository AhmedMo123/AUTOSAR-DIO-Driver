/***********************************************************************************************/
/*AUTOSAR (4.4.0) and Software (1.0.0) versions definitions*/
/***********************************************************************************************/
#define	DIO_LCFG_AR_RELEASE_MAJOR_VERSION	(4U)
#define	DIO_LCFG_AR_RELEASE_MINOR_VERSION	(4U)
#define	DIO_LCFG_AR_RELEASE_PATCH_VERSION	(0U)
#define	DIO_LCFG_SW_MAJOR_VERSION	(1U)
#define	DIO_LCFG_SW_MINOR_VERSION	(0U)
#define	DIO_LCFG_SW_PATCH_VERSION	(0U)
/***********************************************************************************************/
/*Header Files inclusion*/
/***********************************************************************************************/
#include "Dio.h"
/*AUTOSAR version checks*/
#if((DIO_AR_RELEASE_MAJOR_VERSION != DIO_LCFG_AR_RELEASE_MAJOR_VERSION)\
||	(DIO_AR_RELEASE_MINOR_VERSION != DIO_LCFG_AR_RELEASE_MINOR_VERSION)\
||	(DIO_AR_RELEASE_PATCH_VERSION != DIO_LCFG_AR_RELEASE_PATCH_VERSION))
#error "The Dio.h AR version is not compatible with Dio_Lcfg.h AR version"
#endif
/*Software version checks*/
#if((DIO_SW_MAJOR_VERSION != DIO_LCFG_SW_MAJOR_VERSION)\
||	(DIO_SW_MINOR_VERSION != DIO_LCFG_SW_MINOR_VERSION)\
||	(DIO_SW_PATCH_VERSION != DIO_LCFG_SW_PATCH_VERSION))
#error "The Dio.h SW version is not compatible with Dio_Lcfg.h SW version"
#endif
/***********************************************************************************************/
/*Module APIs*/
/***********************************************************************************************/
const Dio_ConfigType Dio_configuration =
	{
	DioConfig_LED1_PORT_NUM,DioConfig_LED1_CHANNEL_NUM,
	DioConfig_LED2_PORT_NUM,DioConfig_LED2_CHANNEL_NUM,
	DioConfig_BUTTON1_PORT_NUM,DioConfig_BUTTON1_CHANNEL_NUM,
	DioConfig_BUTTON2_PORT_NUM,DioConfig_BUTTON2_CHANNEL_NUM
	};
