EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 2800 1950 1    50   Input ~ 0
BTN_NO
Text HLabel 1750 3400 0    50   Output ~ 0
MCU_LATCH_BTN
Text HLabel 4350 2950 2    50   Input ~ 0
MCU_LATCH_ENABLE
Wire Wire Line
	2800 1950 2800 2000
$Comp
L power:PWR_FLAG #FLG?
U 1 1 6109154A
P 2800 2000
F 0 "#FLG?" H 2800 2075 50  0001 C CNN
F 1 "PWR_FLAG" V 2800 2150 50  0000 L CNN
F 2 "" H 2800 2000 50  0001 C CNN
F 3 "~" H 2800 2000 50  0001 C CNN
	1    2800 2000
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60F1D2F1
P 2800 2300
F 0 "R?" H 2859 2346 50  0000 L CNN
F 1 "10K" H 2859 2255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 2800 2300 50  0001 C CNN
F 3 "~" H 2800 2300 50  0001 C CNN
	1    2800 2300
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener_Small D?
U 1 1 60F1C9B7
P 2550 2500
F 0 "D?" H 2550 2707 50  0000 C CNN
F 1 "3.3v Zener" H 2550 2616 50  0000 C CNN
F 2 "" V 2550 2500 50  0001 C CNN
F 3 "~" V 2550 2500 50  0001 C CNN
	1    2550 2500
	-1   0    0    1   
$EndComp
$Comp
L Transistor_FET:BSS138 Q?
U 1 1 612322E0
P 2050 3000
F 0 "Q?" H 2255 2954 50  0000 L CNN
F 1 "BSS138" H 2255 3045 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2250 2925 50  0001 L CIN
F 3 "https://www.onsemi.com/pub/Collateral/BSS138-D.PDF" H 2050 3000 50  0001 L CNN
	1    2050 3000
	-1   0    0    1   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 61240066
P 1950 3650
F 0 "#PWR?" H 1950 3500 50  0001 C CNN
F 1 "+3.3V" H 1965 3823 50  0000 C CNN
F 2 "" H 1950 3650 50  0001 C CNN
F 3 "" H 1950 3650 50  0001 C CNN
	1    1950 3650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 61242201
P 1950 2800
F 0 "#PWR?" H 1950 2550 50  0001 C CNN
F 1 "GND" V 1955 2672 50  0000 R CNN
F 2 "" H 1950 2800 50  0001 C CNN
F 3 "" H 1950 2800 50  0001 C CNN
	1    1950 2800
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R?
U 1 1 6124F10C
P 1950 3550
F 0 "R?" H 2009 3596 50  0000 L CNN
F 1 "10K" H 2009 3505 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 1950 3550 50  0001 C CNN
F 3 "~" H 1950 3550 50  0001 C CNN
	1    1950 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 3200 1950 3400
Connection ~ 1950 3400
Wire Wire Line
	1950 3400 1950 3450
Wire Wire Line
	2650 2500 2800 2500
Wire Wire Line
	1750 3400 1950 3400
Wire Wire Line
	2800 2400 2800 2500
Text Notes 2150 4900 0    50   ~ 0
Power enable is controlled by creating an OR logic gate using 2 n-channel mosfet(in our case a dual nchannel mosfet ic, SQ9945BEY).\nMCU_LATCH_ENABLE is put HIGH after the MCU has been initialized/booted.\nTo start the booting process the BTN_NO has to be put high(which is done with a physical trigger/button).\nBTN_NO has the same voltage as +BATT(it only has a switch in front).\nOnce MCU_LATCH_ENABLE is HIGH and power to the MCU is mainted we may want to detect button presses from the BTN_NO signal.\nThis is done with the BSS138 N-channel mosfet. The drain consists of a connection to the 3.3v supply of the MCU(through the AMS1117 on the devkit board).\nWhen the button/BTN_NO is put high the gate of the BSS138 is triggered which causes MCU_LATCH_BTN to become LOW.\nThis can be detected by code on the MCU.\n\nWe use the third n-channel mosfet/BSS138 to isolate +BATT/BTN_NO current/voltages from the MCU.
Text Notes 4050 2550 0    50   ~ 0
Dual N-Channel mosfet IC.
$Comp
L Device:R_Small R?
U 1 1 612E1840
P 3900 3100
F 0 "R?" H 3959 3146 50  0000 L CNN
F 1 "10K" H 3959 3055 50  0000 L CNN
F 2 "" H 3900 3100 50  0001 C CNN
F 3 "~" H 3900 3100 50  0001 C CNN
	1    3900 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 1600 4250 1600
$Comp
L Device:R_Small R?
U 1 1 612A253F
P 4050 1600
F 0 "R?" H 4109 1646 50  0000 L CNN
F 1 "1K" H 4109 1555 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 4050 1600 50  0001 C CNN
F 3 "~" H 4050 1600 50  0001 C CNN
	1    4050 1600
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 1600 3500 1500
Wire Wire Line
	3750 1600 3500 1600
Connection ~ 3750 1600
$Comp
L power:PWR_FLAG #FLG?
U 1 1 610980DE
P 3500 1200
F 0 "#FLG?" H 3500 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 3500 1373 50  0000 C CNN
F 2 "" H 3500 1200 50  0001 C CNN
F 3 "~" H 3500 1200 50  0001 C CNN
	1    3500 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 1550 3750 1600
Wire Wire Line
	4250 1600 4250 1500
Wire Wire Line
	3750 1200 4050 1200
Connection ~ 3750 1200
Wire Wire Line
	3750 1350 3750 1200
$Comp
L Device:R_Small R?
U 1 1 60F53F6B
P 3750 1450
F 0 "R?" H 3809 1496 50  0000 L CNN
F 1 "100K" H 3809 1405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 3750 1450 50  0001 C CNN
F 3 "~" H 3750 1450 50  0001 C CNN
	1    3750 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1200 3750 1200
Connection ~ 3500 1200
Wire Wire Line
	3500 1300 3500 1200
$Comp
L Device:C_Small C?
U 1 1 60F52BB7
P 3500 1400
F 0 "C?" H 3409 1354 50  0000 R CNN
F 1 "10nF" H 3409 1445 50  0000 R CNN
F 2 "" H 3500 1400 50  0001 C CNN
F 3 "~" H 3500 1400 50  0001 C CNN
	1    3500 1400
	1    0    0    1   
$EndComp
$Comp
L Device:Q_PMOS_DGS Q?
U 1 1 60F1B941
P 4250 1300
F 0 "Q?" V 4592 1300 50  0000 C CNN
F 1 "SUD50P08-25L" V 4501 1300 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TO-252-3_TabPin2" H 4450 1400 50  0001 C CNN
F 3 "https://nl.mouser.com/datasheet/2/427/sud50p08-1766022.pdf" H 4250 1300 50  0001 C CNN
	1    4250 1300
	0    1    -1   0   
$EndComp
Wire Wire Line
	3700 2850 3700 3000
$Comp
L power:GND #PWR?
U 1 1 6108DDC7
P 3600 3300
F 0 "#PWR?" H 3600 3050 50  0001 C CNN
F 1 "GND" H 3605 3127 50  0000 C CNN
F 2 "" H 3600 3300 50  0001 C CNN
F 3 "" H 3600 3300 50  0001 C CNN
	1    3600 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 1850 3700 1850
Connection ~ 3700 1850
Wire Wire Line
	3800 1850 3900 1850
Connection ~ 3800 1850
$Comp
L SQ9945BEY-T1_GE3:SQ9945BEY-T1_GE3 T?
U 1 1 6125FA0F
P 3600 2850
F 0 "T?" V 4146 2422 50  0000 R CNN
F 1 "SQ9945BEY" V 4055 2422 50  0000 R CNN
F 2 "SOIC127P600X175-8N" H 4450 2950 50  0001 L CNN
F 3 "http://www.vishay.com/docs/71504/sq9945bey.pdf" H 4450 2850 50  0001 L CNN
F 4 "Vishay SQ9945BEY-T1_GE3 Dual N-channel MOSFET Transistor, 5.4 A, 60 V, 8-Pin SOIC" H 4450 2750 50  0001 L CNN "Description"
F 5 "1.75" H 4450 2650 50  0001 L CNN "Height"
F 6 "Vishay" H 4450 2550 50  0001 L CNN "Manufacturer_Name"
F 7 "SQ9945BEY-T1_GE3" H 4450 2450 50  0001 L CNN "Manufacturer_Part_Number"
F 8 "78-SQ9945BEY-T1_GE3" H 4450 2350 50  0001 L CNN "Mouser Part Number"
F 9 "https://www.mouser.co.uk/ProductDetail/Vishay-Siliconix/SQ9945BEY-T1_GE3?qs=jHkklCh7amjSMmNL6GXEpw%3D%3D" H 4450 2250 50  0001 L CNN "Mouser Price/Stock"
F 10 "" H 4450 2150 50  0001 L CNN "Arrow Part Number"
F 11 "" H 4450 2050 50  0001 L CNN "Arrow Price/Stock"
	1    3600 2850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3600 2850 3600 3250
Wire Wire Line
	3800 3250 3600 3250
Wire Wire Line
	3800 2850 3800 3250
Connection ~ 3600 3250
Wire Wire Line
	3600 3250 3600 3300
Wire Wire Line
	3700 1850 3800 1850
Wire Wire Line
	3750 1600 3900 1600
Wire Wire Line
	3900 1850 3900 1600
Connection ~ 3900 1850
Connection ~ 3900 1600
Wire Wire Line
	3900 1600 3950 1600
$Comp
L Device:R_Small R?
U 1 1 6131BD5F
P 2800 2750
F 0 "R?" H 2859 2796 50  0000 L CNN
F 1 "1K" H 2859 2705 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 2800 2750 50  0001 C CNN
F 3 "~" H 2800 2750 50  0001 C CNN
	1    2800 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 2850 3900 2950
$Comp
L Device:R_Small R?
U 1 1 61321165
P 4050 2950
F 0 "R?" H 4109 2996 50  0000 L CNN
F 1 "1K" H 4109 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 4050 2950 50  0001 C CNN
F 3 "~" H 4050 2950 50  0001 C CNN
	1    4050 2950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3950 2950 3900 2950
Wire Wire Line
	2800 2650 2800 2500
Connection ~ 2800 2500
Wire Wire Line
	2800 2850 2800 3000
Wire Wire Line
	2800 3000 3700 3000
Connection ~ 2800 3000
$Comp
L power:+BATT #PWR?
U 1 1 61002D6C
P 2500 1200
F 0 "#PWR?" H 2500 1050 50  0001 C CNN
F 1 "+BATT" V 2515 1327 50  0000 L CNN
F 2 "" H 2500 1200 50  0001 C CNN
F 3 "" H 2500 1200 50  0001 C CNN
	1    2500 1200
	0    -1   -1   0   
$EndComp
$Comp
L +batt_switched:+BATT_SWITCHED #PWR?
U 1 1 6102417F
P 5500 1200
F 0 "#PWR?" H 5500 1050 50  0001 C CNN
F 1 "+BATT_SWITCHED" V 5500 1350 50  0000 L CNN
F 2 "" H 5500 1200 50  0001 C CNN
F 3 "" H 5500 1200 50  0001 C CNN
	1    5500 1200
	0    1    1    0   
$EndComp
Text Notes 5000 1050 0    50   ~ 0
+BATT is connected to the battery(min 10V, max 17V, nomal 14V)\n+BATT_SWITCHED is equal to +BATT once switched on.
$Comp
L Device:C_Small C?
U 1 1 6145342C
P 3100 1400
F 0 "C?" H 3009 1354 50  0000 R CNN
F 1 "100nF" H 3009 1445 50  0000 R CNN
F 2 "" H 3100 1400 50  0001 C CNN
F 3 "~" H 3100 1400 50  0001 C CNN
	1    3100 1400
	1    0    0    1   
$EndComp
Wire Wire Line
	2500 1200 3100 1200
Wire Wire Line
	3100 1300 3100 1200
Connection ~ 3100 1200
Wire Wire Line
	3100 1200 3500 1200
Wire Wire Line
	3100 1500 3100 1600
Wire Wire Line
	3100 1600 3500 1600
Connection ~ 3500 1600
$Comp
L Device:C_Small C?
U 1 1 61457964
P 2550 2350
F 0 "C?" V 2350 2400 50  0000 R CNN
F 1 "10nF" V 2450 2400 50  0000 R CNN
F 2 "" H 2550 2350 50  0001 C CNN
F 3 "~" H 2550 2350 50  0001 C CNN
	1    2550 2350
	0    -1   1    0   
$EndComp
Wire Wire Line
	2450 2350 2450 2500
Wire Wire Line
	2650 2350 2650 2500
Connection ~ 2650 2500
Connection ~ 2800 2000
Wire Wire Line
	2800 2000 2800 2200
$Comp
L power:GND #PWR?
U 1 1 6146EA25
P 2450 2500
F 0 "#PWR?" H 2450 2250 50  0001 C CNN
F 1 "GND" V 2455 2372 50  0000 R CNN
F 2 "" H 2450 2500 50  0001 C CNN
F 3 "" H 2450 2500 50  0001 C CNN
	1    2450 2500
	0    1    1    0   
$EndComp
Connection ~ 2450 2500
Wire Wire Line
	2250 3000 2800 3000
$Comp
L power:GND #PWR?
U 1 1 614709E0
P 3900 3300
F 0 "#PWR?" H 3900 3050 50  0001 C CNN
F 1 "GND" H 3905 3127 50  0000 C CNN
F 2 "" H 3900 3300 50  0001 C CNN
F 3 "" H 3900 3300 50  0001 C CNN
	1    3900 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 3000 3900 2950
Connection ~ 3900 2950
Wire Wire Line
	3900 3300 3900 3200
Wire Wire Line
	4150 2950 4350 2950
Wire Wire Line
	4450 1200 5500 1200
Text GLabel 4300 1600 2    50   Output ~ 0
PMOS_GATE
Wire Wire Line
	4300 1600 4250 1600
Connection ~ 4250 1600
$EndSCHEMATC
