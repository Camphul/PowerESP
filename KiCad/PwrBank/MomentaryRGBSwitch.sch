EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 8 8
Title "RGB Momentary switch"
Date "2021-07-22"
Rev "1"
Comp "Logic Shift"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1300 2000 2    50   Output ~ 0
LED_G
Text HLabel 1300 1900 2    50   Output ~ 0
LED_B
Text HLabel 1200 1100 2    50   Output ~ 0
BUTTON_NO
$Comp
L Connector:Conn_01x03_Female J?
U 1 1 60ECD1C9
P 950 1200
F 0 "J?" H 842 875 50  0000 C CNN
F 1 "BTN_CONNECTOR" H 842 966 50  0000 C CNN
F 2 "Connector_JST:JST_XH_B3B-XH-A_1x03_P2.50mm_Vertical" H 950 1200 50  0001 C CNN
F 3 "https://www.jst-mfg.com/product/pdf/eng/eXH.pdf" H 950 1200 50  0001 C CNN
	1    950  1200
	-1   0    0    1   
$EndComp
Text Notes 950  2550 0    50   ~ 0
LED's are switched on ground. Single 3.3v provided and led's should be connected to gnd\n\n
Text HLabel 1300 2100 2    50   Output ~ 0
LED_R
$Comp
L power:+BATT #PWR?
U 1 1 61051377
P 1150 1200
F 0 "#PWR?" H 1150 1050 50  0001 C CNN
F 1 "+BATT" V 1165 1328 50  0000 L CNN
F 2 "" H 1150 1200 50  0001 C CNN
F 3 "" H 1150 1200 50  0001 C CNN
	1    1150 1200
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR?
U 1 1 61051BE7
P 1300 2200
F 0 "#PWR?" H 1300 2050 50  0001 C CNN
F 1 "+3.3V" V 1315 2328 50  0000 L CNN
F 2 "" H 1300 2200 50  0001 C CNN
F 3 "" H 1300 2200 50  0001 C CNN
	1    1300 2200
	0    1    1    0   
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 610A3A67
P 1300 2200
F 0 "#FLG?" H 1300 2275 50  0001 C CNN
F 1 "PWR_FLAG" H 1300 2373 50  0000 C CNN
F 2 "" H 1300 2200 50  0001 C CNN
F 3 "~" H 1300 2200 50  0001 C CNN
	1    1300 2200
	-1   0    0    1   
$EndComp
Wire Wire Line
	1200 2000 1300 2000
Wire Wire Line
	1200 2100 1300 2100
Wire Wire Line
	1200 2200 1300 2200
Text HLabel 1200 1300 2    50   Output ~ 0
CAPACITIVE_SENSE
Wire Wire Line
	1300 1900 1200 1900
Wire Wire Line
	1150 1300 1200 1300
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 60EC404A
P 1000 2100
F 0 "J?" H 850 1700 50  0000 C CNN
F 1 "RGB_LED_CONNECTOR" H 850 1800 50  0000 C CNN
F 2 "Connector_JST:JST_XH_B4B-XH-A_1x04_P2.50mm_Vertical" H 1000 2100 50  0001 C CNN
F 3 "https://www.jst-mfg.com/product/pdf/eng/eXH.pdf" H 1000 2100 50  0001 C CNN
	1    1000 2100
	-1   0    0    1   
$EndComp
Connection ~ 1300 2200
Wire Wire Line
	1200 1100 1150 1100
Text Notes 950  1600 0    50   ~ 0
Assumes +BATT is connect to the button and puts BUTTON_NO high when clicked.\nCAPACITIVE SENSE should be connected to the outer body of the switch.\nThe MCU will sense capacitiveness allowing for custom logic to run.
$EndSCHEMATC
