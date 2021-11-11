#ifndef STD_TYPES_H_
#define STD_TYPES_H_
/****************************************************************************************/
/*AUTOSAR (4.4.0) and Software (1.0.0) versions definitions*/
/****************************************************************************************/
#define	STD_TYPES_AR_RELEASE_MAJOR_VERSION	(4U)
#define	STD_TYPES_AR_RELEASE_MINOR_VERSION	(4U)
#define	STD_TYPES_AR_RELEASE_PATCH_VERSION	(0U)
#define	STD_TYPES_SW_MAJOR_VERSION	(1U)
#define	STD_TYPES_SW_MINOR_VERSION	(0U)
#define	STD_TYPES_SW_PATCH_VERSION	(0U)
/****************************************************************************************/
/*Files Inclusion*/
/****************************************************************************************/
#include "Platform_Types.h"
/*AUTOSAR version checks*/
#if((PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION != STD_TYPES_AR_RELEASE_MAJOR_VERSION)\
		||	(PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION != STD_TYPES_AR_RELEASE_MINOR_VERSION)\
		||	(PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION != STD_TYPES_AR_RELEASE_PATCH_VERSION))
#error "The Platform_Types.h AR version is not compatible with Dio.h AR version"
#endif
/*Software version checks*/
#if((PLATFORM_TYPES_SW_MAJOR_VERSION != STD_TYPES_SW_MAJOR_VERSION)\
		||	(PLATFORM_TYPES_SW_MINOR_VERSION != STD_TYPES_SW_MINOR_VERSION)\
		||	(PLATFORM_TYPES_SW_PATCH_VERSION != STD_TYPES_SW_PATCH_VERSION))
#error "The Platform_Types.h SW version is not compatible with Dio.h SW version"
#endif
/****************************************************************************************/
/*Module Definitions*/
/****************************************************************************************/
#define STD_LOW			0x00U		/* Standard Low*/
#define STD_HIGH		0x01U		/* Standard High*/

#define STD_ON          0x01U       /* Standard ON */
#define STD_OFF         0x00U       /* Standard OFF */

typedef struct{
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;
}Std_VersionInfoType;

#endif /* STD_TYPES_H_ */
