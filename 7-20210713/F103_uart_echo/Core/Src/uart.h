//UART.h
#define REC_LENGTH 1
#define MAX_REC_LENGTH 1024

extern unsigned char Uart1ReceiveBuf[MAX_REC_LENGTH]; //UART1 �洢��������
extern unsigned char Uart1ReceiveFlag; //UART1 ������ɱ�־
extern unsigned int Uart1ReceiveCnt; //UART1 �������ݼ�����
extern unsigned char Uart1Temp[REC_LENGTH]; //UART1 �������ݻ���
