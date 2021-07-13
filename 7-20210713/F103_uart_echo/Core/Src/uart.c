//UART.c
unsigned char Uart1ReceiveBuf[MAX_REC_LENGTH] = {0}; //UART1 存储接收数据
unsigned char Uart1ReceiveFlag = 0; //UART1 接收完成标志
unsigned int Uart1ReceiveCnt = 0; //UART1 接受数据计数器
unsigned char Uart1Temp[REC_LENGTH] = {0}; //UART1 接收数据缓存
