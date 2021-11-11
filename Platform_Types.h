#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_
/****************************************************************************************/
/*AUTOSAR (4.4.0) and Software (1.0.0) versions definitions*/
/****************************************************************************************/
#define	PLATFORM_TYPES_AR_RELEASE_MAJOR_VERSION	(4U)
#define	PLATFORM_TYPES_AR_RELEASE_MINOR_VERSION	(4U)
#define	PLATFORM_TYPES_AR_RELEASE_PATCH_VERSION	(0U)
#define	PLATFORM_TYPES_SW_MAJOR_VERSION	(1U)
#define	PLATFORM_TYPES_SW_MINOR_VERSION	(0U)
#define	PLATFORM_TYPES_SW_PATCH_VERSION	(0U)
/****************************************************************************************/
/*user definitions*/
/****************************************************************************************/
typedef unsigned char         boolean;

typedef unsigned char         uint8;          /*           0 .. 255             */
typedef signed char           sint8;          /*        -128 .. +127            */
typedef unsigned short        uint16;         /*           0 .. 65535           */
typedef signed short          sint16;         /*      -32768 .. +32767          */
typedef unsigned long         uint32;         /*           0 .. 4294967295      */
typedef signed long           sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long long    uint64;         /*       0..18446744073709551615  */
typedef signed long long      sint64;
typedef float                 float32;
typedef double                float64;

/****************************************************************************************/
/*In Compiler File definitions*/
/****************************************************************************************/
#define STATIC		static
#define NULL_PTR	((void*)0)
#define FALSE		(0u)
#define TRUE		(1u)
#endif /* PLATFORM_TYPES_H_ */
