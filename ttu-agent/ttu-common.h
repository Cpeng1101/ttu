/*********************************************
*
*
*
*********************************************/

#ifndef __TTU_PROTOCOL_H__
#define __TTU_PROTOCOL_H__

#ifndef		uint8
#define		uint8	unsigned char
#endif

#ifndef		uint16
#define		uint16	unsigned short
#endif

#ifndef		uint32
#define 	uint32	unsigned int
#endif
/*
typedef struct TTU_header 
{
	uint8	FunCode;
	uint16	OpCode;
	uint8	DirCode;
	uint8	MsgCode;
	uint8	reserved[3];
}ttu_hdr;
*/

typedef struct TTU_header 
{
	uint16	OpCode;
	uint8	MsgCode;
	uint8	reserved[5];
}ttu_hdr;

typedef struct APP_header
{
	uint8	Off_name;
	uint8	Off_para;
	uint8	Off_image;
}app_hdr;

//OPCODE
#define	SHOW_ONE
#define UPLOAD
#define DELETE
#define SHOW_ALL

#define	CREATE_APP		0x01
#define	STOP_APP		0x02
#define	DELETE_APP		0x03
#define	UPGRADE_APP	0x04
#define	SHOW_ALL_APPS	0x20
#define	SHOW_ONE_APP	0x21	
#define	SHOW_ONE_TTU	0x40
#define UPGRADE_TTU	0x41


#define	SHOW_MORE
#define MONITOR_APP_RULE	0x51
#define GET_APP_STATE		0x52
#define GET_APP_RES_INFO	0x53

#define REQUEST		0x0
#define ACK			0x1
#define NACK		0x2

#define	MONITOR_OS
#define	MONITOR_APP
#define MONITOR_INFO_SHOW
#define	WARNING_DELETE
#define APP_INFO_GET

#define MAX_ORDER_NUM	8
#define	TTU_HDR_LEN	(sizeof(ttu_hdr))
#endif
