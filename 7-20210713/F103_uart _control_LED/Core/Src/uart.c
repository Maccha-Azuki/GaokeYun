//UART.c
#include "uart.h"

unsigned char Uart1ReceiveBuf[MAX_REC_LENGTH] = {0}; //UART1 �洢��������
unsigned char Uart1ReceiveFlag = 0; //UART1 ������ɱ�־
unsigned int Uart1ReceiveCnt = 0; //UART1 �������ݼ�����
unsigned char Uart1Temp[REC_LENGTH] = {0}; //UART1 �������ݻ���
