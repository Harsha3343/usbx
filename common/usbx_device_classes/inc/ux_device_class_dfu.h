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
/**   DFU Class                                                           */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

/**************************************************************************/ 
/*                                                                        */ 
/*  COMPONENT DEFINITION                                   RELEASE        */ 
/*                                                                        */ 
/*    ux_device_class_dfu.h                               PORTABLE C      */ 
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    Chaoqiong Xiao, Microsoft Corporation                               */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */ 
/*    This file defines the equivalences for the USBX Device Class DFU    */ 
/*    ACM component.                                                      */ 
/*                                                                        */ 
/*  RELEASE HISTORY                                                       */ 
/*                                                                        */ 
/*    DATE              NAME                      DESCRIPTION             */ 
/*                                                                        */ 
/*  05-19-2020     Chaoqiong Xiao           Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/

#ifndef UX_DEVICE_CLASS_DFU_H
#define UX_DEVICE_CLASS_DFU_H

/* Define DFU class descriptor capabilities.  */                    
#define UX_SLAVE_CLASS_DFU_CAPABILITY_WILL_DETACH                   0x08
#define UX_SLAVE_CLASS_DFU_CAPABILITY_MANIFESTATION_TOLERANT        0x04
#define UX_SLAVE_CLASS_DFU_CAPABILITY_CAN_UPLOAD                    0x02
#define UX_SLAVE_CLASS_DFU_CAPABILITY_CAN_DOWNLOAD                  0x01

/* Define DFU Class USB Class constants.  */
#define UX_SLAVE_CLASS_DFU_CLASS                                    0xFE
#define UX_SLAVE_CLASS_DFU_SUBCLASS                                 0x01
#define UX_SLAVE_CLASS_DFU_PROTOCOL_RUNTIME                         0x01
#define UX_SLAVE_CLASS_DFU_PROTOCOL_DFU_MODE                        0x02

/* Define DFU MODES signals.  */
#define UX_DEVICE_CLASS_DFU_MODE_RUNTIME                            1
#define UX_DEVICE_CLASS_DFU_MODE_DFU                                2




/* Device DFU Requests */
#define UX_SLAVE_CLASS_DFU_COMMAND_DETACH                           0
#define UX_SLAVE_CLASS_DFU_COMMAND_DOWNLOAD                         1
#define UX_SLAVE_CLASS_DFU_COMMAND_UPLOAD                           2
#define UX_SLAVE_CLASS_DFU_COMMAND_GET_STATUS                       3
#define UX_SLAVE_CLASS_DFU_COMMAND_CLEAR_STATUS                     4
#define UX_SLAVE_CLASS_DFU_COMMAND_GET_STATE                        5
#define UX_SLAVE_CLASS_DFU_COMMAND_ABORT                            6

/* Device DFU Status values */
#define UX_SLAVE_CLASS_DFU_STATUS_OK                                0x00
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_TARGET                      0x01
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_FILE                        0x02
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_WRITE                       0x03
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_ERASE                       0x04
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_CHECK_ERASED                0x05
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_PROG                        0x06
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_VERIFY                      0x07
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_ADDRESS                     0x08
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_NOTDONE                     0x09
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_FIRMWARE                    0x0A
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_VENDOR                      0x0B
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_USBR                        0x0C
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_POR                         0x0D
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_UNKNOWN                     0x0E
#define UX_SLAVE_CLASS_DFU_STATUS_ERROR_STALLEDPKT                  0x0F

#define UX_SLAVE_CLASS_DFU_STATUS_STATE_APP_IDLE                    0
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_APP_DETACH                  1
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_IDLE                    2
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_DNLOAD_SYNC             3
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_DNBUSY                  4
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_DNLOAD_IDLE             5
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_MANIFEST_SYNC           6
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_MANIFEST                7
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_MANIFEST_WAIT_RESET     8
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_UPLOAD_IDLE             9
#define UX_SLAVE_CLASS_DFU_STATUS_STATE_DFU_ERROR                   10

/* Define DFU class GET_STATUS command response.  */
#define UX_SLAVE_CLASS_DFU_GET_STATUS_STATUS                        0
#define UX_SLAVE_CLASS_DFU_GET_STATUS_POLL_TIMEOUT                  1
#define UX_SLAVE_CLASS_DFU_GET_STATUS_STATE                         4
#define UX_SLAVE_CLASS_DFU_GET_STATUS_STRING                        5
#define UX_SLAVE_CLASS_DFU_GET_STATUS_LENGTH                        6

/* Define DFU class GET_STATE command response.  */
#define UX_SLAVE_CLASS_DFU_GET_STATE_STATE                          0
#define UX_SLAVE_CLASS_DFU_GET_STATE_LENGTH                         1

/* Define DFU application notification signals.  */
#define UX_SLAVE_CLASS_DFU_NOTIFICATION_BEGIN_DOWNLOAD              1
#define UX_SLAVE_CLASS_DFU_NOTIFICATION_END_DOWNLOAD                2
#define UX_SLAVE_CLASS_DFU_NOTIFICATION_ABORT_DOWNLOAD              3        

/* Define DFU application notification signals.  */
#define UX_SLAVE_CLASS_DFU_MEDIA_STATUS_OK                          0
#define UX_SLAVE_CLASS_DFU_MEDIA_STATUS_BUSY                        1
#define UX_SLAVE_CLASS_DFU_MEDIA_STATUS_ERROR                       2 

/* Define DFU thread event signals.  */
#define UX_DEVICE_CLASS_DFU_THREAD_EVENT_DISCONNECT                 1
#define UX_DEVICE_CLASS_DFU_THREAD_EVENT_WAIT_RESET                 2

/* Define Slave DFU Class Calling Parameter structure */

typedef struct UX_SLAVE_CLASS_DFU_PARAMETER_STRUCT
{

    ULONG                   ux_slave_class_dfu_parameter_will_detach;
    ULONG                   ux_slave_class_dfu_parameter_capabilities;
    VOID                    (*ux_slave_class_dfu_parameter_instance_activate)(VOID *);
    VOID                    (*ux_slave_class_dfu_parameter_instance_deactivate)(VOID *);
    UINT                    (*ux_slave_class_dfu_parameter_read)(VOID *dfu, ULONG block_number, UCHAR * data_pointer, ULONG length, ULONG *media_status);
    UINT                    (*ux_slave_class_dfu_parameter_write)(VOID *dfu, ULONG block_number, UCHAR * data_pointer, ULONG length, ULONG *media_status);
    UINT                    (*ux_slave_class_dfu_parameter_get_status)(VOID *dfu, ULONG *media_status);
    UINT                    (*ux_slave_class_dfu_parameter_notify)(VOID *dfu, ULONG notification);
    UCHAR                   *ux_slave_class_dfu_parameter_framework;
    ULONG                   ux_slave_class_dfu_parameter_framework_length;

} UX_SLAVE_CLASS_DFU_PARAMETER;

/* Define DFU Class structure.  */

typedef struct UX_SLAVE_CLASS_DFU_STRUCT
{
    UX_SLAVE_INTERFACE      *ux_slave_class_dfu_interface;
    ULONG                   ux_slave_class_dfu_status;
    ULONG                   ux_slave_class_dfu_state;
    VOID                    (*ux_slave_class_dfu_instance_activate)(VOID *);
    VOID                    (*ux_slave_class_dfu_instance_deactivate)(VOID *);
    UINT                    (*ux_slave_class_dfu_read)(VOID *dfu, ULONG block_number, UCHAR * data_pointer, ULONG length, ULONG *media_status);
    UINT                    (*ux_slave_class_dfu_write)(VOID *dfu, ULONG block_number, UCHAR * data_pointer, ULONG length, ULONG *media_status);
    UINT                    (*ux_slave_class_dfu_get_status)(VOID *dfu, ULONG *media_status);
    UINT                    (*ux_slave_class_dfu_notify)(VOID *dfu, ULONG notification);
    ULONG                   ux_slave_class_dfu_download_block_count;
    ULONG                   ux_slave_class_dfu_upload_block_count;
    TX_THREAD               ux_slave_class_dfu_thread;
    UCHAR                   *ux_slave_class_dfu_thread_stack;
    TX_EVENT_FLAGS_GROUP    ux_slave_class_dfu_event_flags_group;
    
} UX_SLAVE_CLASS_DFU;

/* Define Device DFU Class prototypes.  */

UINT  _ux_device_class_dfu_activate(UX_SLAVE_CLASS_COMMAND *command);
UINT  _ux_device_class_dfu_control_request(UX_SLAVE_CLASS_COMMAND *command);
UINT  _ux_device_class_dfu_deactivate(UX_SLAVE_CLASS_COMMAND *command);
UINT  _ux_device_class_dfu_entry(UX_SLAVE_CLASS_COMMAND *command);
UINT  _ux_device_class_dfu_initialize(UX_SLAVE_CLASS_COMMAND *command);
VOID  _ux_device_class_dfu_thread(ULONG dfu_class);

/* Define Device DFU Class API prototypes.  */

#define ux_device_class_dfu_entry        _ux_device_class_dfu_entry   

#endif /* UX_DEVICE_CLASS_DFU_H */
