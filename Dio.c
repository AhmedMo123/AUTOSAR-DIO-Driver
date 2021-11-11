#include "Dio.h"
#include "Dio_Regs.h"

#if (DIO_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
/*AUTOSAR version checks*/
#if((DIO_AR_RELEASE_MAJOR_VERSION != DET_AR_RELEASE_MAJOR_VERSION)\
		||	(DIO_AR_RELEASE_MINOR_VERSION != DET_AR_RELEASE_MINOR_VERSION)\
		||	(DIO_AR_RELEASE_PATCH_VERSION != DET_AR_RELEASE_PATCH_VERSION))
#error "The Det.h AR version is not compatible with Dio.h AR version"
#endif
/*Software version checks*/
#if((DIO_SW_MAJOR_VERSION != DET_SW_MAJOR_VERSION)\
		||	(DIO_SW_MINOR_VERSION != DET_SW_MINOR_VERSION)\
		||	(DIO_SW_PATCH_VERSION != DET_SW_PATCH_VERSION))
#error "The Det.h SW version is not compatible with Dio.h SW version"
#endif
#endif

/***********************************************************************************************/
/*Module Global Variables And Pointers*/
/****************************************************************************************/
STATIC uint8 Dio_Module_Status = DIO_NOT_INTIALIZED;
STATIC Dio_ConfigChannel *Dio_ChannelData = NULL_PTR;
/****************************************************************************************/
/*Module APIs Definition*/
/****************************************************************************************/
void Dio_Init(Dio_ConfigType* Dio_Config)
{
	/*Dio_Init Function is used to set the global pointer (Dio_ChannelData) to point to
	  the first member in the Dio_Configuration structure
	  (that is externed from the generated file)*/
#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(NULL_PTR == Dio_Config)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,DIO_INIT_SERVICE_ID,DIO_E_PARAM_CONFIG);
	}
#endif
	/*After DEM Checking*/
	Dio_Module_Status = DIO_INITIALIZED;		 	/*Set the module status to be initialized*/
	/*Set the global pointer to point to the first channel in the Dio_Configuration Structure
	  Dio_Configuration->Channel[0]*/
	Dio_ChannelData = Dio_Config->Dio_Channel;
}
/**********************************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
	Dio_PortLevelType *Ptr2PinReg = NULL_PTR;
	Dio_LevelType channel_value = STD_LOW;
	boolean error = FALSE;

#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(DIO_NOT_INTIALIZED == Dio_Module_Status)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SERVICE_ID,DIO_E_PARAM_UNINIT);
		error = TRUE;
	}
	if(ChannelId > DIO_CONFIGURED_CHANNELS)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_SERVICE_ID,DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
#endif

	/*After DEM Checking*/
	if(FALSE == error)
	{
		/*switch on Port_Num of Dio_channelData pointer on member#[channelId]
	  and point to the PIN register address to this port using Ptr2PinReg local pointer */
		switch(Dio_ChannelData[ChannelId].Port_Num)
		{
		case 0: 	/*0 is PORTA Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINA_REG;
			break;
		case 1: 	/*1 is PORTB Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINB_REG;
			break;
		case 2: 	/*2 is PORTC Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINC_REG;
			break;
		case 3: 	/*3 is PORTD Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PIND_REG;
			break;
		}
		/*Read The Required Channel*/
		if(BIT_IS_SET(*Ptr2PinReg,Dio_ChannelData[ChannelId].Channel_Num))
		{
			channel_value = STD_HIGH;
		}
		else
		{
			channel_value = STD_LOW;
		}
	}
	/*Return The Channel Value*/
	return channel_value;
}
/**********************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	Dio_PortLevelType *Ptr2PortReg = NULL_PTR;
	boolean error = FALSE;

#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(DIO_NOT_INTIALIZED == Dio_Module_Status)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SERVICE_ID,DIO_E_PARAM_UNINIT);
		error = TRUE;
	}
	if(ChannelId > DIO_CONFIGURED_CHANNELS)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SERVICE_ID,DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
#endif

	/*After DEM Checking*/
	if(FALSE == error)
	{
		/*switch on Port_Num of Dio_channelData pointer on member#[channelId]
	and point to the PORT register address to this port using Ptr2PortReg local pointer */
		switch(Dio_ChannelData[ChannelId].Port_Num)
		{
		case 0:		/*0 is PORTA Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTA_REG;
			break;
		case 1:		/*1 is PORTB Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTB_REG;
			break;
		case 2:		/*2 is PORTC Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTC_REG;
			break;
		case 3:		/*3 is PORTD Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTD_REG;
			break;
		}
		if (STD_HIGH == Level)
		{
			SET_BIT(*Ptr2PortReg,Dio_ChannelData[ChannelId].Channel_Num);
		}
		else if (STD_LOW == Level)
		{
			CLEAR_BIT(*Ptr2PortReg,Dio_ChannelData[ChannelId].Channel_Num);
		}
	}
}
/**********************************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	Dio_PortLevelType *Ptr2PinReg = NULL_PTR;
	Dio_PortLevelType *Ptr2PortReg = NULL_PTR;
	Dio_LevelType channel_value = STD_LOW;
	boolean error = FALSE;

#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(DIO_NOT_INTIALIZED == Dio_Module_Status)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_FLIP_CHANNEL_SERVICE_ID,DIO_E_PARAM_UNINIT);
		error = TRUE;
	}
	if(ChannelId > DIO_CONFIGURED_CHANNELS)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_FLIP_CHANNEL_SERVICE_ID,DIO_E_PARAM_INVALID_CHANNEL_ID);
		error = TRUE;
	}
#endif

	/*After DEM Checking*/
	if(FALSE == error)
	{
		/*switch on Port_Num of Dio_channelData pointer on member#[channelId]
	and point to the PIN register address to this port using Ptr2PinReg local pointer
	and point to the PORT register address to this port using Ptr2PortReg local pointer */
		switch(Dio_ChannelData[ChannelId].Port_Num)
		{
		case 0:		/*0 is PORTA Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINA_REG;
			Ptr2PortReg = &PORTA_REG;
			break;
		case 1:		/*1 is PORTB Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINB_REG;
			Ptr2PortReg = &PORTB_REG;
			break;
		case 2:		/*2 is PORTC Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINC_REG;
			Ptr2PortReg = &PORTC_REG;
			break;
		case 3: 	/*3 is PORTD Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PIND_REG;
			Ptr2PortReg = &PORTD_REG;
			break;
		}
		if(BIT_IS_SET(*Ptr2PinReg,Dio_ChannelData[ChannelId].Channel_Num))
		{
			CLEAR_BIT(*Ptr2PinReg,Dio_ChannelData[ChannelId].Channel_Num);
			channel_value = STD_LOW;
		}
		else if(BIT_IS_CLEAR(*Ptr2PinReg,Dio_ChannelData[ChannelId].Channel_Num))
		{
			SET_BIT(*Ptr2PinReg,Dio_ChannelData[ChannelId].Channel_Num);
			channel_value = STD_HIGH;
		}
	}
	return channel_value;
}
/**********************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	Dio_PortLevelType port_value = STD_LOW;
	boolean error = FALSE;

#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(DIO_NOT_INTIALIZED == Dio_Module_Status)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_READ_PORT_SERVICE_ID,DIO_E_PARAM_UNINIT);
		error = TRUE;
	}
	if(PortId > DIO_CONFIGURED_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_READ_PORT_SERVICE_ID,DIO_E_PARAM_INVALID_PORT_ID);
		error = TRUE;
	}
#endif

	/*After DEM Checking*/
	if(FALSE == error)
	{
		/*Switch on PortId and save the PIN Register data in a port_value local variable*/
		switch(PortId)
		{
		case 0:		/*0 is PORTA Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			port_value = PINA_REG;
			break;
		case 1:		/*1 is PORTB Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			port_value = PINB_REG;
			break;
		case 2:		/*2 is PORTC Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			port_value = PINC_REG;
			break;
		case 3:		/*3 is PORTD Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			port_value = PIND_REG;
			break;
		}
	}
	return port_value;
}

/**********************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
	boolean error = FALSE;

#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(DIO_NOT_INTIALIZED == Dio_Module_Status)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SERVICE_ID,DIO_E_PARAM_UNINIT);
		error = TRUE;
	}
	if(PortId > DIO_CONFIGURED_PORTS)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_SERVICE_ID,DIO_E_PARAM_INVALID_PORT_ID);
		error = TRUE;
	}
#endif

	/*After DEM Checking*/
	if(FALSE == error)
	{
		/*Switch on PortId and Write Level Value to the PORT Register*/
		switch(PortId)
		{
		case 0:		/*0 is PORTA Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			PORTA_REG = Level;
			break;
		case 1:		/*1 is PORTB Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			PORTB_REG = Level;
			break;
		case 2:		/*2 is PORTC Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			PORTC_REG = Level;
			break;
		case 3:		/*3 is PORTD Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			PORTD_REG = Level;
			break;
		}
	}
}
/**********************************************************************************************/
Dio_PortLevelType Dio_ReadChannelGroup(Dio_ChannelGroupType *ChannelGroupIdPtr)
{
	Dio_PortType *Ptr2PinReg = NULL_PTR;
	Dio_PortLevelType channel_group_value = STD_LOW;
	boolean error = FALSE;

#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(DIO_NOT_INTIALIZED == Dio_Module_Status)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_GROUP_SERVICE_ID,DIO_E_PARAM_UNINIT);
		error = TRUE;
	}
	if(NULL_PTR == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_READ_CHANNEL_GROUP_SERVICE_ID,DIO_E_PARAM_POINTER);
		error = TRUE;
	}
#endif
	/*After DEM Checking*/
	if(FALSE == error)
	{
		/*Switch on port in ChannelGroupIdPtr and point to the PIN register address to this port
	  using Ptr2PinReg local pointer*/
		switch(ChannelGroupIdPtr->port)
		{
		case 0: 	/*0 is PORTA Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINA_REG;
			break;
		case 1: 	/*1 is PORTB Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINB_REG;
			break;
		case 2: 	/*2 is PORTC Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PINC_REG;
			break;
		case 3: 	/*3 is PORTD Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PinReg = &PIND_REG;
			break;
		}
		channel_group_value = (((*Ptr2PinReg) & (ChannelGroupIdPtr->mask))
				>>(ChannelGroupIdPtr->offset));
	}
	return channel_group_value;
}
/**********************************************************************************************/
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr,
		Dio_PortLevelType Level)
{
	Dio_PortType *Ptr2PortReg = NULL_PTR;
	boolean error = FALSE;

#if(DIO_DEV_ERROR_DETECT == STD_ON)
	if(DIO_NOT_INTIALIZED == Dio_Module_Status)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_GROUP_SERVICE_ID,DIO_E_PARAM_UNINIT);
		error = TRUE;
	}
	if(NULL_PTR == ChannelGroupIdPtr)
	{
		Det_ReportError(DIO_MODULE_ID,DIO_INSTANCE_ID,
				DIO_WRITE_CHANNEL_GROUP_SERVICE_ID,DIO_E_PARAM_POINTER);
		error = TRUE;
	}
#endif
	/*After DEM Checking*/
	if(FALSE == error)
	{
		/*Switch on port in ChannelGroupIdPtr and point to the PORT register address to this port
	  using Ptr2PortReg local pointer*/
		switch(ChannelGroupIdPtr->port)
		{
		case 0: 	/*0 is PORTA Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTA_REG;
			break;
		case 1: 	/*1 is PORTB Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTB_REG;
			break;
		case 2: 	/*2 is PORTC Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTC_REG;
			break;
		case 3: 	/*3 is PORTD Number according to Configured Ports IDs' in Dio_Cfg.h File*/
			Ptr2PortReg = &PORTD_REG;
			break;
		}
		*Ptr2PortReg = ((*Ptr2PortReg) & (!(ChannelGroupIdPtr->mask)))
								| (Level<<(ChannelGroupIdPtr->offset));
	}
}
/**********************************************************************************************/
void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfo)
{
#if (DIO_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == VersionInfo)
	{
		/* Report to DET  */
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID,
				DIO_GET_VERSION_INFO_SERVICE_ID, DIO_E_PARAM_POINTER);
	}
	else
#endif
	VersionInfo->sw_major_version = DIO_SW_MAJOR_VERSION;
	VersionInfo->sw_minor_version = DIO_SW_MINOR_VERSION;
	VersionInfo->sw_patch_version = DIO_SW_PATCH_VERSION;
}
