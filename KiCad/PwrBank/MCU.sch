EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 8
Title "ESP32_Devkit_Addons"
Date "2021-07-17"
Rev ""
Comp "Logic Shift"
Comment1 "ESP32-WROOM32 DevkitC with additional required circuitry"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP32-DEVKITC-32D:ESP32-DEVKITC-32D U?
U 1 1 60F2EDCB
P 6050 2900
F 0 "U?" H 6050 4067 50  0000 C CNN
F 1 "ESP32-DEVKITC-32D" H 6050 3976 50  0000 C CNN
F 2 "ESP32-DEVKITC-32D:MODULE_ESP32-DEVKITC-32D" H 6050 2900 50  0001 L BNN
F 3 "" H 6050 2900 50  0001 L BNN
F 4 "4" H 6050 2900 50  0001 L BNN "PARTREV"
F 5 "Espressif Systems" H 6050 2900 50  0001 L BNN "MANUFACTURER"
	1    6050 2900
	1    0    0    -1  
$EndComp
Text HLabel 8600 3300 2    50   Output ~ 0
BMS_TX
Wire Wire Line
	8600 2200 8500 2200
Wire Wire Line
	8600 3000 8500 3000
Wire Wire Line
	8600 3100 8500 3100
Wire Wire Line
	8600 2300 8500 2300
$Sheet
S 7950 2900 550  500 
U 60F56C27
F0 "logic_shifter_mcu_TX" 50
F1 "logic_shifters_mcu.sch" 50
F2 "IO_LV" B R 8500 3200 50 
F3 "IO_HV" B R 8500 3300 50 
F4 "HV" I R 8500 3000 50 
F5 "LV" I R 8500 3100 50 
$EndSheet
Text HLabel 8600 2500 2    50   Input ~ 0
BMS_RX
Wire Wire Line
	8600 3300 8500 3300
Wire Wire Line
	8600 2500 8500 2500
Text Label 6950 3000 0    50   ~ 0
U2TXD
Wire Wire Line
	6850 3000 6950 3000
Wire Wire Line
	6850 3100 6950 3100
Text Label 6950 3100 0    50   ~ 0
U2RXD
Text Label 8850 3200 0    50   ~ 0
U2TXD
Wire Wire Line
	8850 2400 8500 2400
Text Label 8850 2400 0    50   ~ 0
U2RXD
Wire Wire Line
	8850 3200 8500 3200
Text Notes 8000 1950 0    50   ~ 0
IMPLIES THAT RX AND TX ARE TWISTED TO\nRX -> TX\nTX -> RX\nIN THE CONNECTOR CABLE\n\nRequired for serial communication.\nWe do not use VCC from BMS as HV since it outputs 10v\naccording to online resources.
Wire Notes Line
	7900 1250 10250 1250
Text Notes 7900 1200 0    50   ~ 10
3.3v - 5v bidirectional logic shifting for BMS communications
Wire Wire Line
	7150 2000 6850 2000
Text Notes 4800 1500 0    50   ~ 0
TXD0 and RXD0 are connected to the usb serial converter on the module.\nLeave unconnected.
Wire Wire Line
	5100 2700 5250 2700
Text HLabel 5100 2700 0    50   Output ~ 0
MCU_PWR_ENABLE
Text HLabel 5100 2600 0    50   Output ~ 0
MCU_PWR_BTN_DETECT
Text HLabel 6900 2500 2    50   BiDi ~ 0
SDA1
Wire Wire Line
	6900 2500 6850 2500
Text HLabel 6900 2200 2    50   Output ~ 0
SCL1
Wire Wire Line
	6900 2200 6850 2200
NoConn ~ 6850 3800
NoConn ~ 6850 3700
NoConn ~ 6850 3600
NoConn ~ 6850 3500
NoConn ~ 6850 3300
NoConn ~ 6850 2900
NoConn ~ 6850 2600
NoConn ~ 6850 2100
NoConn ~ 5250 2100
NoConn ~ 5250 2200
NoConn ~ 5250 2300
NoConn ~ 5250 2400
NoConn ~ 5250 2500
NoConn ~ 5250 2800
NoConn ~ 5250 2900
NoConn ~ 5250 3100
NoConn ~ 5250 3200
NoConn ~ 5250 3400
NoConn ~ 5250 3500
NoConn ~ 5250 3600
NoConn ~ 5250 3700
Wire Notes Line
	7900 1250 7900 3550
Wire Notes Line
	10250 1250 10250 3550
Wire Notes Line
	7900 3550 10250 3550
Wire Notes Line
	3450 4000 7750 4000
Wire Notes Line
	7750 4000 7750 1250
Wire Notes Line
	7750 1250 3450 1250
Wire Notes Line
	3450 1250 3450 4000
Text Notes 3450 1200 0    50   ~ 10
ESP32-WROOM32 DevKitC with additional circuitry\n
Wire Wire Line
	5250 2000 5150 2000
Wire Wire Line
	5150 3800 5250 3800
$Comp
L power:GND #PWR?
U 1 1 61034275
P 7150 2000
F 0 "#PWR?" H 7150 1750 50  0001 C CNN
F 1 "GND" V 7155 1872 50  0000 R CNN
F 2 "" H 7150 2000 50  0001 C CNN
F 3 "" H 7150 2000 50  0001 C CNN
	1    7150 2000
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 61037CC9
P 5150 2000
F 0 "#PWR?" H 5150 1850 50  0001 C CNN
F 1 "+3.3V" V 5165 2128 50  0000 L CNN
F 2 "" H 5150 2000 50  0001 C CNN
F 3 "" H 5150 2000 50  0001 C CNN
	1    5150 2000
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 61038914
P 5150 3800
F 0 "#PWR?" H 5150 3650 50  0001 C CNN
F 1 "+5V" V 5165 3928 50  0000 L CNN
F 2 "" H 5150 3800 50  0001 C CNN
F 3 "" H 5150 3800 50  0001 C CNN
	1    5150 3800
	0    -1   -1   0   
$EndComp
$Sheet
S 7950 2100 550  500 
U 60F3980E
F0 "logic_shifters_mcu_RX" 50
F1 "logic_shifters_mcu.sch" 50
F2 "IO_LV" B R 8500 2400 50 
F3 "IO_HV" B R 8500 2500 50 
F4 "HV" I R 8500 2200 50 
F5 "LV" I R 8500 2300 50 
$EndSheet
$Comp
L power:+5V #PWR?
U 1 1 61039E33
P 8600 2200
F 0 "#PWR?" H 8600 2050 50  0001 C CNN
F 1 "+5V" V 8615 2328 50  0000 L CNN
F 2 "" H 8600 2200 50  0001 C CNN
F 3 "" H 8600 2200 50  0001 C CNN
	1    8600 2200
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 6103A5D9
P 8600 2300
F 0 "#PWR?" H 8600 2150 50  0001 C CNN
F 1 "+3.3V" V 8615 2428 50  0000 L CNN
F 2 "" H 8600 2300 50  0001 C CNN
F 3 "" H 8600 2300 50  0001 C CNN
	1    8600 2300
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 6103DF7E
P 8600 3000
F 0 "#PWR?" H 8600 2850 50  0001 C CNN
F 1 "+5V" V 8615 3128 50  0000 L CNN
F 2 "" H 8600 3000 50  0001 C CNN
F 3 "" H 8600 3000 50  0001 C CNN
	1    8600 3000
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 6103E675
P 8600 3100
F 0 "#PWR?" H 8600 2950 50  0001 C CNN
F 1 "+3.3V" V 8615 3228 50  0000 L CNN
F 2 "" H 8600 3100 50  0001 C CNN
F 3 "" H 8600 3100 50  0001 C CNN
	1    8600 3100
	0    1    1    0   
$EndComp
Text HLabel 6900 2300 2    50   Output ~ 0
U1TXD
Text HLabel 6900 2400 2    50   Input ~ 0
U1RXD
Wire Wire Line
	6850 2300 6900 2300
Wire Wire Line
	6850 2400 6900 2400
Text HLabel 6900 3200 2    50   Output ~ 0
TOUCH_SENSE
Wire Wire Line
	6900 3200 6850 3200
Wire Wire Line
	5100 2600 5250 2600
NoConn ~ 6850 3400
NoConn ~ 5250 3000
NoConn ~ 5250 3300
Text Notes 3450 4200 0    50   ~ 0
MCU_PWR_BTN_DETECT=sense clicks on the button which controls a mosfet\nMCU_PWR_ENABLE=output pin to maintain power once button has been clicked
NoConn ~ 6850 2700
NoConn ~ 6850 2800
$EndSCHEMATC
