//UART.h
#define REC_LENGTH 1
#define MAX_REC_LENGTH 1024

#define PRT_ERROR_HEAD_MSG printf( "ERROR order. Please check the head bit.\r\n");
#define PRT_ERROR_BIT_MSG printf( "ERROR order. Please check the state bit.\r\n");

#define PRT_SUCCESS printf( "success\r\n");

extern unsigned char Uart1ReceiveBuf[MAX_REC_LENGTH]; //UART1 �洢��������
extern unsigned char Uart1ReceiveFlag; //UART1 ������ɱ�־
extern unsigned int Uart1ReceiveCnt; //UART1 �������ݼ�����
extern unsigned char Uart1Temp[REC_LENGTH]; //UART1 �������ݻ���
