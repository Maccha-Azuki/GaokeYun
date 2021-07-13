# �жϵĽ��ܺͰ�����ʹ��

1. �жϵĸ���
    - ʲô���ж�?
    - ΪʲôҪ���ж�?/�ж�������ܴ��ڵ�����?
2. �жϵ�ʹ��
    - �����жϵ�ʹ�ó���
3. �жϳ�������(�԰���Ϊ��)
    - �������水������LED��Ӧ�����š�ԭ��ͼ����
    - ��ͼ�����ʵ���������?
    - ����Դ�����


## �жϵĸ���
1. ����ʵ������
- �ٶ�һ���龰���������ڼ�д��ҵ�������Ѹ��㷢QQ�������ڰ���������Ϸװ������û����������Ϊ���������*ѧϰ��װ����Ҫ*��
- ��ոռ���ѧϰ������֮�����ŵ���������һ�ɺ�ζ����Ͻ�ȥ�ѻ���ˡ���Ϊ*����ʧ���ѧϰ��Ҫ*��
2. ʲô���жϣ�
- ��ͣԭ�ȵĳ�������飬ִ������һЩ��������飬ִ����ɺ󷵻�ԭ���ĳ���
3. ΪʲôҪ���жϣ�
- ��Ϊ**��һЩ������������ԭ��������������Ҫ��Ҫ**��������Щͻ����������**�޷�������������**�ġ�
## �жϵ�ʹ��
- �����ģ��򵥵�Ӧ��A
    - ��SW0/1����LED
        - [x] ��/��
        - [x] ������ɫ

## �������

### ��Ӧ����

![20200502_204355_30](images/20200502_204355_30.png)

![20200502_225910_69](images/20200502_225910_69.png)

### Դ��
```c
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include <inc/hw_gpio.h>
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include <driverlib/rom_map.h>
#include <driverlib/rom.h>
#include <inc/hw_ints.h>
#include <driverlib/interrupt.h>
#include "driverlib/sysctl.h"

int flag;
void INT_GPIOF_Handler(void);
void vGPIO_Config_1(void);

int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    //system control clock set  400kHZ/(4*2)
    vGPIO_Config_1();

    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2, 0XFF);   //the initial state of LED
    while(1)
        ;     //waiting for the interrupts
}


void vGPIO_Config_1(void)
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); //Enable a peripheral

		// -Workshop 14.2 API Fuctions
    IntEnable(INT_GPIOF); //The specified interrupt is enabled in the interrupt controller
    IntPrioritySet(INT_GPIOF,0); //Smaller numbers correspond to higher interrupt priorities; priority 0 is the highest interrupt priority.
    IntRegister(INT_GPIOF,INT_GPIOF_Handler); //Registers a function to be called when an interrupt occurs

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 ); //Configures pins for use as GPIO outputs
    GPIODirModeSet(GPIO_PORTF_BASE,GPIO_PIN_4|GPIO_PIN_0,GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4,GPIO_STRENGTH_2MA,GPIO_PIN_TYPE_STD_WPU);

    GPIOIntEnable(GPIO_PORTF_BASE,GPIO_INT_PIN_4);
    GPIOIntTypeSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_FALLING_EDGE );
    IntMasterEnable(); //Enables the processor interrupt.
}

void INT_GPIOF_Handler(void)
{
     GPIOIntClear(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
     flag++;   //switch the states of the LED
     if(flag==4)
		flag=1;
     switch(flag)
     {
        case 1: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2 |GPIO_PIN_3,GPIO_PIN_2 |GPIO_PIN_3); break;
        case 2: GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2 |GPIO_PIN_3,GPIO_PIN_1|GPIO_PIN_3); break;
        case 3:GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1|GPIO_PIN_2 |GPIO_PIN_3,0XFF); break;
     }
}


```
### Դ�����ע��

![20200504_233010_91](images/20200504_233010_91.png)

![20200504_233048_58](images/20200504_233048_58.png)
- `GPIOPadConfigSet()`���� ��Ĳ���
    - ������ǿ����ʱ,����Ҫ�ƶ�һ��8ŷ��������,��ȻҪ������������,��ʱ��Ҫǿ��./
    - ��©��������ȡ�ܽŵ�ѹ,����IICͨѶһ��Ҫ��©
    - ������:�������ùܽ�ƽʱΪ�ߵ�
    - ������:�������ùܽ�ƽʱΪ�͵�
