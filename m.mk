C_SOURCES += Drivers/SYSTEM/sys/sys.c \
Drivers/SYSTEM/delay/delay.c \
Drivers/SYSTEM/usart/usart.c 

__EX = 10

ifeq ($(__EX), 1)
C_SOURCES += Src/ex1.c \
Drivers/BSP/LED/led.c
endif

ifeq ($(__EX), 2)
C_SOURCES += Src/ex2.c \
Drivers/BSP/LED/led.c \
Drivers/BSP/BEEP/beep.c
endif

ifeq ($(__EX), 3)
C_SOURCES += Src/ex3.c \
Drivers/BSP/LED/led.c \
Drivers/BSP/BEEP/beep.c \
Drivers/BSP/KEY/key.c
endif

ifeq ($(__EX), 4)
C_SOURCES += Src/ex4.c \
Drivers/BSP/LED/led.c \
Drivers/BSP/BEEP/beep.c \
Drivers/BSP/KEY/key.c \
Drivers/BSP/EXTI/exti.c
endif

ifeq ($(__EX), 5)
C_SOURCES += Src/ex5.c \
Drivers/BSP/LED/led.c 
endif

ifeq ($(__EX), 6)
C_SOURCES += Src/ex6.c \
Drivers/BSP/WDG/wdg.c 
endif

ifeq ($(__EX), 7)
C_SOURCES += Src/ex7.c \
Drivers/BSP/WDG/wdg.c \
Drivers/BSP/LED/led.c
endif


ifeq ($(__EX), 8)
C_SOURCES += Src/ex8.c \
Drivers/BSP/TIMER/btim.c \
Drivers/BSP/LED/led.c
endif

ifeq ($(__EX), 9)
C_SOURCES += Src/ex9.c \
Drivers/BSP/TIMER/gtim.c \
Drivers/BSP/LED/led.c
endif

ifeq ($(__EX), 10)
C_SOURCES += Src/ex10.c \
Drivers/BSP/TIMER/gtim.c 
endif
