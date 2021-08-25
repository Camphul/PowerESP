EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L PCA9632DP1:PCA9632DP1 U?
U 1 1 60FA7C2A
P 4400 3250
F 0 "U?" H 4375 3415 50  0000 C CNN
F 1 "PCA9632DP1" H 4375 3324 50  0000 C CNN
F 2 "Package_SO:TSSOP-8_3x3mm_P0.65mm" H 4400 3350 50  0001 C CNN
F 3 "https://nl.mouser.com/datasheet/2/302/PCA9632-1127666.pdf" H 4400 3250 50  0001 C CNN
	1    4400 3250
	1    0    0    -1  
$EndComp
Text HLabel 3900 3300 0    50   Output ~ 0
LEDRING_R
Text HLabel 3900 3400 0    50   Output ~ 0
LEDRING_G
Text HLabel 3900 3500 0    50   Output ~ 0
LEDRING_B
$Comp
L power:GND #PWR?
U 1 1 60FA879A
P 5050 3600
F 0 "#PWR?" H 5050 3350 50  0001 C CNN
F 1 "GND" V 5055 3472 50  0000 R CNN
F 2 "" H 5050 3600 50  0001 C CNN
F 3 "" H 5050 3600 50  0001 C CNN
	1    5050 3600
	0    -1   -1   0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 60FA900F
P 5450 3100
F 0 "#PWR?" H 5450 2950 50  0001 C CNN
F 1 "+3.3V" V 5465 3228 50  0000 L CNN
F 2 "" H 5450 3100 50  0001 C CNN
F 3 "" H 5450 3100 50  0001 C CNN
	1    5450 3100
	0    1    1    0   
$EndComp
Text HLabel 5500 3400 2    50   BiDi ~ 0
SDA
Wire Wire Line
	3900 3500 4100 3500
Wire Wire Line
	3900 3400 4100 3400
Wire Wire Line
	3900 3300 4100 3300
Text HLabel 5500 3500 2    50   Input ~ 0
SCL
Wire Wire Line
	4650 3600 5050 3600
$Comp
L Device:R_Small R?
U 1 1 60FAADB1
P 5350 3250
F 0 "R?" H 5409 3296 50  0000 L CNN
F 1 "10k" H 5409 3205 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 5350 3250 50  0001 C CNN
F 3 "~" H 5350 3250 50  0001 C CNN
	1    5350 3250
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small R?
U 1 1 60FAD892
P 5050 3250
F 0 "R?" H 5109 3296 50  0000 L CNN
F 1 "10k" H 5109 3205 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.20x1.40mm_HandSolder" H 5050 3250 50  0001 C CNN
F 3 "~" H 5050 3250 50  0001 C CNN
	1    5050 3250
	-1   0    0    1   
$EndComp
Wire Wire Line
	4800 3300 4650 3300
NoConn ~ 4100 3600
Wire Wire Line
	4800 3100 4800 3300
Wire Wire Line
	4650 3400 5050 3400
Wire Wire Line
	4650 3500 5350 3500
Wire Wire Line
	5050 3150 5050 3100
Wire Wire Line
	5050 3100 4800 3100
Wire Wire Line
	5050 3100 5350 3100
Wire Wire Line
	5350 3100 5350 3150
Connection ~ 5050 3100
Wire Wire Line
	5050 3350 5050 3400
Wire Wire Line
	5350 3350 5350 3500
Wire Wire Line
	5450 3100 5350 3100
Connection ~ 5350 3100
Text Notes 4100 4050 0    50   ~ 0
8=VCC, 7=SDA, 6=SCL, 5=GND\n\nPull i2c bus pins to high with 10k for high bandwidth(400kbit/s)
Wire Wire Line
	5050 3400 5500 3400
Connection ~ 5050 3400
Wire Wire Line
	5500 3500 5350 3500
Connection ~ 5350 3500
$EndSCHEMATC
