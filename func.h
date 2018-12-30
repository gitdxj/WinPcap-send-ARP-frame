#ifndef FUNC
#define FUNC

#include <pcap.h>
#include <string>
#include <iostream>
#pragma comment (lib, "Ws2_32.lib")
#pragma pack(1)
typedef struct FrameHeader_t
{
	BYTE DesMAC[6];
	BYTE SrcMAC[6];
	WORD FramType;
} FrameHeader_t;

typedef struct ARPFrame_t
{
	FrameHeader_t FrameHeader;
	WORD HardwareType;
	WORD ProtocolType;
	BYTE HLen;
	BYTE PLen;
	WORD Operation;
	BYTE SendHa[6];
	BYTE SendIP[4]; //IP of sender
	BYTE RecvHa[6];
	BYTE RecvIP[4]; //IP of receiver
} ARPFrame_t;

#pragma pack()



#endif