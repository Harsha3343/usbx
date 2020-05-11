/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */ 
/** USBX Component                                                        */ 
/**                                                                       */
/**   OHCI Controller Driver                                              */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/


/* Include necessary system files.  */

#define UX_SOURCE_CODE

#include "ux_api.h"
#include "ux_hcd_ohci.h"
#include "ux_host_stack.h"


/**************************************************************************/ 
/*                                                                        */ 
/*  FUNCTION                                               RELEASE        */ 
/*                                                                        */ 
/*    _ux_hcd_ohci_transfer_request_process               PORTABLE C      */ 
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*     This function process the transfer request that was completed      */ 
/*     either with success or because of a partial transmission or        */ 
/*     because of an error. The transfer request descriptor tells us what */ 
/*     to do with it, either put a semaphore to the caller or invoke a    */ 
/*     completion routine. If a completion routine is specified, the      */ 
/*     routine is called and no semaphore is put.                         */ 
/*                                                                        */ 
/*  INPUT                                                                 */ 
/*                                                                        */ 
/*    transfer_request                      Pointer to transfer request   */ 
/*                                                                        */ 
/*  OUTPUT                                                                */ 
/*                                                                        */ 
/*    None                                                                */ 
/*                                                                        */ 
/*  CALLS                                                                 */ 
/*                                                                        */ 
/*    (ux_transfer_request_completion_function) Completion function       */ 
/*    _ux_utility_semaphore_put                 Signal transfer complete  */ 
/*                                                                        */ 
/*  CALLED BY                                                             */ 
/*                                                                        */ 
/*    OHCI Controller Driver                                              */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */ 
/*                                                                        */ 
/*  05-19-2020     Chaoqiong Xiao           Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/
VOID  _ux_hcd_ohci_transfer_request_process(UX_TRANSFER *transfer_request)
{

    /* Check if there is a function for the transfer completion.  */ 
    if (transfer_request -> ux_transfer_request_completion_function != UX_NULL)
    
        /* Yes, so we call it!  */
        transfer_request -> ux_transfer_request_completion_function(transfer_request);
    else

        /* There is a semaphore so send the signal to the class.   */
        _ux_utility_semaphore_put(&transfer_request -> ux_transfer_request_semaphore);

    /* Return to caller.  */
    return;
}
