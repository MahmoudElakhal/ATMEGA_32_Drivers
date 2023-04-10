#include "../STD_TYPES.h"
#include "../TIMER/TIMER_Interface.h"
#include "../GIE/GIE_Interface.h"
#include "RTOS_Config.h"
#include "RTOS_Interface.h"
#include "RTOS_Private.h"

Task_t SystemTasks[TASK_NUM]={{NULL}};
void RTOS_voidStart(void)
{
	TIMER0_u8SetCallBack(&voidScheduler);
	GIE_voidEnable();
	TIMER0_voidINIT();
}

u8 RTOS_voidCreateTask(u8 Copy_u8Priority, u16 Copy_u16Periodicity , void (*Copy_pvTaskFunc)(void),u16 Copy_u16FirstDelay)
{
	u8 Local_u8ErrorStatus = OK;

	/*Check if the required priority is empty or used before for another task*/
	if(SystemTasks[Copy_u8Priority].TaskFunc == NULL)
	{
		SystemTasks[Copy_u8Priority].Periodicity = Copy_u16Periodicity;
		SystemTasks[Copy_u8Priority].TaskFunc 	 = Copy_pvTaskFunc;
		SystemTasks[Copy_u8Priority].State		 = TASK_RESUMED; /*initialize task state*/
		SystemTasks[Copy_u8Priority].FirstDelay  = Copy_u16FirstDelay;
	}
	else
	{
		/*Priority is reserved before don`t create the task*/
		Local_u8ErrorStatus = NOTOK;
	}
	return Local_u8ErrorStatus;
}
static void voidScheduler(void)
{
	u8 Local_u8TaskCounter;

	/*loop on all tasks to check their periodicity*/
	for(Local_u8TaskCounter = 0 ;Local_u8TaskCounter < TASK_NUM ; Local_u8TaskCounter++)
	{
		/*Check if the task suspended or not*/
		if(SystemTasks[Local_u8TaskCounter].State == TASK_RESUMED)
		{
			if (SystemTasks[Local_u8TaskCounter].FirstDelay==0)
			{
				/*Invoke The task function*/
				if(SystemTasks[Local_u8TaskCounter].TaskFunc !=NULL)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();

					/*Assign the first delay parameter to the periodicity*/
					SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].Periodicity-1;
				}
				else
				{
					/*Decrement the first delay*/
					SystemTasks[Local_u8TaskCounter].FirstDelay--;
				}
			}
		}
		else
		{
			/*Task is suspended do nothing*/
		}
	}

}

void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].State = TASK_RESUMED;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
	SystemTasks[Copy_u8Priority].TaskFunc = NULL;
}
