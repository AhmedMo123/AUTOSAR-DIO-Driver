#ifndef DET_H_
#define DET_H_

/***********************************************************************************************/
/*AUTOSAR (4.4.0) and Software (1.0.0) versions definitions*/
/***********************************************************************************************/
#define	DET_AR_RELEASE_MAJOR_VERSION	(4U)
#define	DET_AR_RELEASE_MINOR_VERSION	(4U)
#define	DET_AR_RELEASE_PATCH_VERSION	(0U)
#define	DET_SW_MAJOR_VERSION	(1U)
#define	DET_SW_MINOR_VERSION	(0U)
#define	DET_SW_PATCH_VERSION	(0U)
/***********************************************************************************************/
#include "Platform_Types.h"
/*AUTOSAR version checks*/
#if((PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)\
||	(PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)\
||	(PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION != DET_AR_RELEASE_PATCH_VERSION))
#error "The Std_Types.h AR version is not compatible with Det.h AR version"
#endif
/*Software version checks*/
#if((PLATFORM_TYPES_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION)\
||	(PLATFORM_TYPES_SW_MINOR_VERSION != DET_SW_MINOR_VERSION)\
||	(PLATFORM_TYPES_SW_PATCH_VERSION != DET_SW_PATCH_VERSION))
#error "The Std_Types.h SW version is not compatible with Dio.h SW version"
#endif
/****************************************************************************************/
/*Module APIs Prototypes*/
/****************************************************************************************/
void Det_ReportError( uint16 ModuleId,uint8 InstanceId,uint8 ApiId,uint8 ErrorId );

#endif /* DET_H_ */
