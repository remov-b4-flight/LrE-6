EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title "LrE-6"
Date "2019-01-24"
Rev ""
Comp "Ruffles Inc,."
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L LrE-6-rescue:STM32F072C8Tx-MCU_ST_STM32F0 U1
U 1 1 5C490C50
P 8500 3950
F 0 "U1" H 8450 4250 50  0000 C CNN
F 1 "STM32F072C8Tx" H 8550 4400 50  0000 C CNN
F 2 "Package_QFP:LQFP-48_7x7mm_P0.5mm" H 7900 2550 50  0001 R CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00090510.pdf" H 8500 3950 50  0001 C CNN
	1    8500 3950
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0101
U 1 1 5C490E15
P 8300 5600
F 0 "#PWR0101" H 8300 5350 50  0001 C CNN
F 1 "GND" H 8305 5427 50  0000 C CNN
F 2 "" H 8300 5600 50  0001 C CNN
F 3 "" H 8300 5600 50  0001 C CNN
	1    8300 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 5450 8300 5550
Wire Wire Line
	8300 5550 8400 5550
Wire Wire Line
	8600 5550 8600 5450
Connection ~ 8300 5550
Wire Wire Line
	8300 5550 8300 5600
Wire Wire Line
	8400 5450 8400 5550
Connection ~ 8400 5550
Wire Wire Line
	8400 5550 8500 5550
Wire Wire Line
	8500 5450 8500 5550
Connection ~ 8500 5550
Wire Wire Line
	8500 5550 8600 5550
$Comp
L LrE-6-rescue:C-Device C13
U 1 1 5C490EFE
P 8000 1950
F 0 "C13" H 8115 1996 50  0000 L CNN
F 1 "0.1u" H 8115 1905 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8038 1800 50  0001 C CNN
F 3 "~" H 8000 1950 50  0001 C CNN
	1    8000 1950
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C16
U 1 1 5C490F9B
P 9000 1600
F 0 "C16" V 8950 1400 50  0000 C CNN
F 1 "0.1u" V 8950 1750 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9038 1450 50  0001 C CNN
F 3 "~" H 9000 1600 50  0001 C CNN
	1    9000 1600
	0    1    1    0   
$EndComp
$Comp
L LrE-6-rescue:C-Device C17
U 1 1 5C4911FC
P 9000 1900
F 0 "C17" V 8950 1700 50  0000 C CNN
F 1 "0.1u" V 8950 2050 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9038 1750 50  0001 C CNN
F 3 "~" H 9000 1900 50  0001 C CNN
	1    9000 1900
	0    1    1    0   
$EndComp
$Comp
L LrE-6-rescue:C-Device C18
U 1 1 5C49129B
P 9000 2200
F 0 "C18" V 8950 2000 50  0000 C CNN
F 1 "0.1u" V 8950 2350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9038 2050 50  0001 C CNN
F 3 "~" H 9000 2200 50  0001 C CNN
	1    9000 2200
	0    1    1    0   
$EndComp
$Comp
L LrE-6-rescue:C-Device C15
U 1 1 5C49133B
P 9000 1400
F 0 "C15" V 8950 1200 50  0000 C CNN
F 1 "4.7u" V 8950 1550 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9038 1250 50  0001 C CNN
F 3 "~" H 9000 1400 50  0001 C CNN
	1    9000 1400
	0    1    1    0   
$EndComp
$Comp
L LrE-6-rescue:C-Device C14
U 1 1 5C4913C6
P 9000 1200
F 0 "C14" V 8950 1000 50  0000 C CNN
F 1 "0.1u" V 8950 1350 50  0000 C CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9038 1050 50  0001 C CNN
F 3 "~" H 9000 1200 50  0001 C CNN
	1    9000 1200
	0    1    1    0   
$EndComp
$Comp
L LrE-6-rescue:+3V3-power #PWR0102
U 1 1 5C49143B
P 8300 950
F 0 "#PWR0102" H 8300 800 50  0001 C CNN
F 1 "+3V3" H 8315 1123 50  0000 C CNN
F 2 "" H 8300 950 50  0001 C CNN
F 3 "" H 8300 950 50  0001 C CNN
	1    8300 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 2450 8700 2400
Wire Wire Line
	8700 1050 8600 1050
Wire Wire Line
	8300 1050 8300 950 
Wire Wire Line
	8300 2450 8300 1700
Connection ~ 8300 1050
Wire Wire Line
	8400 2450 8400 1400
Connection ~ 8400 1050
Wire Wire Line
	8400 1050 8300 1050
Connection ~ 8500 1050
Wire Wire Line
	8500 1050 8400 1050
Connection ~ 8600 1050
Wire Wire Line
	8600 1050 8500 1050
$Comp
L LrE-6-rescue:GND-power #PWR0103
U 1 1 5C49307F
P 8000 2150
F 0 "#PWR0103" H 8000 1900 50  0001 C CNN
F 1 "GND" H 8005 1977 50  0000 C CNN
F 2 "" H 8000 2150 50  0001 C CNN
F 3 "" H 8000 2150 50  0001 C CNN
	1    8000 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1200 8400 1200
Connection ~ 8400 1200
Wire Wire Line
	8400 1200 8400 1050
Wire Wire Line
	8850 1400 8400 1400
Connection ~ 8400 1400
Wire Wire Line
	8400 1400 8400 1200
Wire Wire Line
	8850 1600 8500 1600
Connection ~ 8500 1600
Wire Wire Line
	8500 1600 8500 1050
Wire Wire Line
	8000 1800 8000 1700
Wire Wire Line
	8000 1700 8300 1700
Connection ~ 8300 1700
Wire Wire Line
	8300 1700 8300 1050
Wire Wire Line
	8000 2150 8000 2100
Wire Wire Line
	8850 1900 8600 1900
Wire Wire Line
	8850 2200 8700 2200
Connection ~ 8700 2200
Wire Wire Line
	8700 2200 8700 1050
$Comp
L LrE-6-rescue:C-Device C19
U 1 1 5C494805
P 9000 2400
F 0 "C19" V 8950 2200 50  0000 C CNN
F 1 "4.7u" V 8950 2550 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9038 2250 50  0001 C CNN
F 3 "~" H 9000 2400 50  0001 C CNN
	1    9000 2400
	0    1    1    0   
$EndComp
Wire Wire Line
	8700 2400 8850 2400
Connection ~ 8700 2400
Wire Wire Line
	8700 2400 8700 2200
$Comp
L LrE-6-rescue:GND-power #PWR0104
U 1 1 5C494D8B
P 9250 2600
F 0 "#PWR0104" H 9250 2350 50  0001 C CNN
F 1 "GND" H 9255 2427 50  0000 C CNN
F 2 "" H 9250 2600 50  0001 C CNN
F 3 "" H 9250 2600 50  0001 C CNN
	1    9250 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 2600 9250 2400
Wire Wire Line
	9250 1200 9150 1200
Wire Wire Line
	9150 1400 9250 1400
Connection ~ 9250 1400
Wire Wire Line
	9250 1400 9250 1200
Wire Wire Line
	9150 1600 9250 1600
Connection ~ 9250 1600
Wire Wire Line
	9250 1600 9250 1400
Wire Wire Line
	9150 1900 9250 1900
Wire Wire Line
	9150 2200 9250 2200
Connection ~ 9250 2200
Wire Wire Line
	9150 2400 9250 2400
Connection ~ 9250 2400
Wire Wire Line
	9250 2400 9250 2200
$Comp
L LrE-6-rescue:MountingHole-Mechanical H1
U 1 1 5C4990AB
P 12100 9750
F 0 "H1" H 12200 9796 50  0000 L CNN
F 1 "MountingHole" H 12200 9705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 12100 9750 50  0001 C CNN
F 3 "~" H 12100 9750 50  0001 C CNN
	1    12100 9750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:MountingHole-Mechanical H2
U 1 1 5C4990F9
P 12950 9750
F 0 "H2" H 13050 9796 50  0000 L CNN
F 1 "MountingHole" H 13050 9705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 12950 9750 50  0001 C CNN
F 3 "~" H 12950 9750 50  0001 C CNN
	1    12950 9750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:MountingHole-Mechanical H3
U 1 1 5C49919E
P 13750 9750
F 0 "H3" H 13850 9796 50  0000 L CNN
F 1 "MountingHole" H 13850 9705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 13750 9750 50  0001 C CNN
F 3 "~" H 13750 9750 50  0001 C CNN
	1    13750 9750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:MountingHole-Mechanical H4
U 1 1 5C499229
P 14600 9750
F 0 "H4" H 14700 9796 50  0000 L CNN
F 1 "MountingHole" H 14700 9705 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.2mm_M3" H 14600 9750 50  0001 C CNN
F 3 "~" H 14600 9750 50  0001 C CNN
	1    14600 9750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:USB_B_Micro-Connector J1
U 1 1 5C49B5B9
P 11650 1250
F 0 "J1" H 11705 1717 50  0000 C CNN
F 1 "USB_B_Micro" H 11705 1626 50  0000 C CNN
F 2 "LrE-6:USB_Micro-B_MCUBF-09_1" H 11800 1200 50  0001 C CNN
F 3 "~" H 11800 1200 50  0001 C CNN
	1    11650 1250
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:Conn_01x06-Connector_Generic J2
U 1 1 5C49BFE9
P 15000 3950
F 0 "J2" H 14900 4500 50  0000 L CNN
F 1 "SM06B-SRSS-TB" H 14900 4400 50  0000 L CNN
F 2 "Connector_JST:JST_SH_SM06B-SRSS-TB_1x06-1MP_P1.00mm_Horizontal" H 15000 3950 50  0001 C CNN
F 3 "~" H 15000 3950 50  0001 C CNN
	1    15000 3950
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:LDK130-08_SOT23_SOT353-Regulator_Linear U4
U 1 1 5C49CE6A
P 13600 1150
F 0 "U4" H 13600 1492 50  0000 C CNN
F 1 "SPX3819M5-L3-3TR" H 13600 1401 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 13600 1475 50  0001 C CNN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/29/10/f7/87/2f/66/47/f4/DM00076097.pdf/files/DM00076097.pdf/jcr:content/translations/en.DM00076097.pdf" H 13600 1150 50  0001 C CNN
	1    13600 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	11950 1050 13100 1050
Wire Wire Line
	9250 1600 9250 1900
$Comp
L LrE-6-rescue:GND-power #PWR0105
U 1 1 5C4A0726
P 14200 1650
F 0 "#PWR0105" H 14200 1400 50  0001 C CNN
F 1 "GND" H 14205 1477 50  0000 C CNN
F 2 "" H 14200 1650 50  0001 C CNN
F 3 "" H 14200 1650 50  0001 C CNN
	1    14200 1650
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0106
U 1 1 5C4A25A6
P 13600 1650
F 0 "#PWR0106" H 13600 1400 50  0001 C CNN
F 1 "GND" H 13605 1477 50  0000 C CNN
F 2 "" H 13600 1650 50  0001 C CNN
F 3 "" H 13600 1650 50  0001 C CNN
	1    13600 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	13600 1650 13600 1450
$Comp
L LrE-6-rescue:C-Device C26
U 1 1 5C4A31C8
P 14800 1300
F 0 "C26" H 14915 1346 50  0000 L CNN
F 1 "1u" H 14915 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 14838 1150 50  0001 C CNN
F 3 "~" H 14800 1300 50  0001 C CNN
	1    14800 1300
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0108
U 1 1 5C4A32F6
P 14800 1650
F 0 "#PWR0108" H 14800 1400 50  0001 C CNN
F 1 "GND" H 14805 1477 50  0000 C CNN
F 2 "" H 14800 1650 50  0001 C CNN
F 3 "" H 14800 1650 50  0001 C CNN
	1    14800 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	14800 1150 14800 1050
Wire Wire Line
	14800 1650 14800 1450
Wire Wire Line
	13900 1050 14800 1050
Connection ~ 14800 1050
Wire Wire Line
	13300 1150 13100 1150
Wire Wire Line
	13100 1150 13100 1050
Connection ~ 13100 1050
Wire Wire Line
	13100 1050 13300 1050
Text Label 12550 1050 0    50   ~ 0
VBUS
$Comp
L LrE-6-rescue:C-Device C22
U 1 1 5C4A6079
P 13100 1450
F 0 "C22" H 13215 1496 50  0000 L CNN
F 1 "1u" H 13215 1405 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 13138 1300 50  0001 C CNN
F 3 "~" H 13100 1450 50  0001 C CNN
	1    13100 1450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0109
U 1 1 5C4A60F8
P 13100 1650
F 0 "#PWR0109" H 13100 1400 50  0001 C CNN
F 1 "GND" H 13105 1477 50  0000 C CNN
F 2 "" H 13100 1650 50  0001 C CNN
F 3 "" H 13100 1650 50  0001 C CNN
	1    13100 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	13100 1650 13100 1600
Wire Wire Line
	13100 1300 13100 1150
Connection ~ 13100 1150
$Comp
L LrE-6-rescue:GND-power #PWR0110
U 1 1 5C4A8121
P 11650 1800
F 0 "#PWR0110" H 11650 1550 50  0001 C CNN
F 1 "GND" H 11655 1627 50  0000 C CNN
F 2 "" H 11650 1800 50  0001 C CNN
F 3 "" H 11650 1800 50  0001 C CNN
	1    11650 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	11650 1800 11650 1700
Wire Wire Line
	11950 1250 12450 1250
Wire Wire Line
	11950 1350 12450 1350
Text Label 12100 1250 0    50   ~ 0
USB_DP
Text Label 12100 1350 0    50   ~ 0
USB_DM
Wire Wire Line
	14800 3950 14700 3950
Wire Wire Line
	14800 3850 14250 3850
Wire Wire Line
	14250 3850 14250 3250
$Comp
L LrE-6-rescue:C-Device C23
U 1 1 5C4BD331
P 13400 8200
F 0 "C23" H 13450 8300 50  0000 L CNN
F 1 "1u" H 13500 8100 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 13438 8050 50  0001 C CNN
F 3 "~" H 13400 8200 50  0001 C CNN
	1    13400 8200
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:C-Device C24
U 1 1 5C4D2D25
P 13400 8650
F 0 "C24" H 13450 8750 50  0000 L CNN
F 1 "1u" H 13450 8550 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 13438 8500 50  0001 C CNN
F 3 "~" H 13400 8650 50  0001 C CNN
	1    13400 8650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8500 1600 8500 2450
Connection ~ 8600 1900
Wire Wire Line
	8600 1900 8600 1050
Connection ~ 9250 1900
Wire Wire Line
	8600 1900 8600 2450
Wire Wire Line
	9250 1900 9250 2200
$Comp
L LrE-6-rescue:+3V3-power #PWR0119
U 1 1 5C4EAC46
P 13200 5450
F 0 "#PWR0119" H 13200 5300 50  0001 C CNN
F 1 "+3V3" H 13215 5623 50  0000 C CNN
F 2 "" H 13200 5450 50  0001 C CNN
F 3 "" H 13200 5450 50  0001 C CNN
	1    13200 5450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R19
U 1 1 5C4EACBD
P 13200 6550
F 0 "R19" V 13100 6350 50  0000 L CNN
F 1 "10K" V 13100 6550 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 13130 6550 50  0001 C CNN
F 3 "~" H 13200 6550 50  0001 C CNN
	1    13200 6550
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R20
U 1 1 5C4EAD6C
P 13450 6550
F 0 "R20" V 13350 6350 50  0000 L CNN
F 1 "10K" V 13350 6550 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 13380 6550 50  0001 C CNN
F 3 "~" H 13450 6550 50  0001 C CNN
	1    13450 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	13450 6400 13450 5500
Text Label 12500 7250 0    50   ~ 0
SDA
Text Label 12500 7400 0    50   ~ 0
SCL
$Comp
L LrE-6-rescue:R-Device R18
U 1 1 5C509B04
P 15200 8700
F 0 "R18" V 15300 8800 50  0000 C CNN
F 1 "62" V 15300 8600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 15130 8700 50  0001 C CNN
F 3 "~" H 15200 8700 50  0001 C CNN
	1    15200 8700
	1    0    0    -1  
$EndComp
Text Label 9200 3750 0    50   ~ 0
M0
Text Label 9200 3850 0    50   ~ 0
M1
Text Label 9200 3950 0    50   ~ 0
M2
Text Label 9200 4050 0    50   ~ 0
M3
Text Label 9200 4150 0    50   ~ 0
ENC1-A
Text Label 9200 4250 0    50   ~ 0
ENC1-B
Wire Wire Line
	9100 4150 9600 4150
Wire Wire Line
	9100 4250 9600 4250
Wire Wire Line
	9100 4050 9600 4050
Wire Wire Line
	9100 3950 9600 3950
Wire Wire Line
	9100 3850 9600 3850
Wire Wire Line
	9100 3750 9600 3750
Wire Wire Line
	7300 4050 7800 4050
Wire Wire Line
	7300 4150 7800 4150
Wire Wire Line
	7300 4250 7800 4250
Wire Wire Line
	7300 4350 7800 4350
Text Label 7300 4050 0    50   ~ 0
L0
Text Label 7300 4150 0    50   ~ 0
L1
Text Label 7300 4250 0    50   ~ 0
L2
Text Label 7300 4350 0    50   ~ 0
SCL
Wire Wire Line
	7800 2650 7300 2650
Text Label 7300 2650 0    50   ~ 0
NRST
Wire Wire Line
	7800 3050 7300 3050
Wire Wire Line
	7800 3150 7300 3150
Text Label 7300 3050 0    50   ~ 0
ENC5-A
Text Label 7300 3150 0    50   ~ 0
ENC5-B
Wire Wire Line
	7300 3450 7800 3450
Wire Wire Line
	7300 3550 7800 3550
Text Label 7300 3450 0    50   ~ 0
ENC4-A
Text Label 7300 3550 0    50   ~ 0
ENC4-B
Wire Wire Line
	9100 4850 9600 4850
Wire Wire Line
	9100 4950 9600 4950
Text Label 9200 4850 0    50   ~ 0
USB_DM
Text Label 9200 4950 0    50   ~ 0
USB_DP
Wire Wire Line
	9100 5050 9600 5050
Wire Wire Line
	9100 5150 9600 5150
Text Label 9200 5150 0    50   ~ 0
SWCLK
Text Label 9200 5050 0    50   ~ 0
SWDIO
Wire Wire Line
	7800 4450 7300 4450
Text Label 7300 4450 0    50   ~ 0
SDA
Wire Wire Line
	7800 3950 7300 3950
Text Label 7300 3950 0    50   ~ 0
L3
Wire Wire Line
	7800 4550 7300 4550
Wire Wire Line
	7800 4650 7300 4650
Wire Wire Line
	7800 4750 7300 4750
Wire Wire Line
	7800 4850 7300 4850
Text Label 7300 4750 0    50   ~ 0
ENC3-A
Text Label 7300 4850 0    50   ~ 0
ENC3-B
Text Label 7300 4550 0    50   ~ 0
ENC2-A
Text Label 7300 4650 0    50   ~ 0
ENC2-B
Wire Wire Line
	7800 4950 7300 4950
Wire Wire Line
	7800 5050 7300 5050
Text Label 7300 4950 0    50   ~ 0
ENC0-A
Text Label 7300 5050 0    50   ~ 0
ENC0-B
$Comp
L LrE-6-rescue:Rotary_Encoder_Switch-Device SW11
U 1 1 5C6AAF87
P 2300 1450
F 0 "SW11" H 2300 1817 50  0000 C CNN
F 1 "EC11_SMD" H 2300 1726 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 2150 1610 50  0001 C CNN
F 3 "~" H 2300 1710 50  0001 C CNN
	1    2300 1450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:Rotary_Encoder_Switch-Device SW12
U 1 1 5C6AB096
P 2350 3100
F 0 "SW12" H 2350 3467 50  0000 C CNN
F 1 "EC11_SMD" H 2350 3376 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 2200 3260 50  0001 C CNN
F 3 "~" H 2350 3360 50  0001 C CNN
	1    2350 3100
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:Rotary_Encoder_Switch-Device SW13
U 1 1 5C6AB18A
P 2450 4850
F 0 "SW13" H 2450 5217 50  0000 C CNN
F 1 "EC11_SMD" H 2450 5126 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 2300 5010 50  0001 C CNN
F 3 "~" H 2450 5110 50  0001 C CNN
	1    2450 4850
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:Rotary_Encoder_Switch-Device SW14
U 1 1 5C6AB5C2
P 5000 1400
F 0 "SW14" H 5000 1767 50  0000 C CNN
F 1 "EC11_SMD" H 5000 1676 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 4850 1560 50  0001 C CNN
F 3 "~" H 5000 1660 50  0001 C CNN
	1    5000 1400
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:Rotary_Encoder_Switch-Device SW15
U 1 1 5C6AB6D3
P 5150 3100
F 0 "SW15" H 5150 3467 50  0000 C CNN
F 1 "EC11_SMD" H 5150 3376 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 5000 3260 50  0001 C CNN
F 3 "~" H 5150 3360 50  0001 C CNN
	1    5150 3100
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:Rotary_Encoder_Switch-Device SW16
U 1 1 5C6AB791
P 5250 4850
F 0 "SW16" H 5250 5217 50  0000 C CNN
F 1 "EC11_SMD" H 5250 5126 50  0000 C CNN
F 2 "Rotary_Encoder:RotaryEncoder_Alps_EC11E-Switch_Vertical_H20mm" H 5100 5010 50  0001 C CNN
F 3 "~" H 5250 5110 50  0001 C CNN
	1    5250 4850
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R6
U 1 1 5C6AB881
P 1400 1150
F 0 "R6" H 1470 1196 50  0000 L CNN
F 1 "10K" H 1470 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 1330 1150 50  0001 C CNN
F 3 "~" H 1400 1150 50  0001 C CNN
	1    1400 1150
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R5
U 1 1 5C6AB990
P 1100 1150
F 0 "R5" H 1170 1196 50  0000 L CNN
F 1 "10K" H 1170 1105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 1030 1150 50  0001 C CNN
F 3 "~" H 1100 1150 50  0001 C CNN
	1    1100 1150
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R8
U 1 1 5C6ABADC
P 1550 2800
F 0 "R8" H 1620 2846 50  0000 L CNN
F 1 "10K" H 1620 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 1480 2800 50  0001 C CNN
F 3 "~" H 1550 2800 50  0001 C CNN
	1    1550 2800
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R7
U 1 1 5C6ABBD0
P 1250 2800
F 0 "R7" H 1320 2846 50  0000 L CNN
F 1 "10K" H 1320 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 1180 2800 50  0001 C CNN
F 3 "~" H 1250 2800 50  0001 C CNN
	1    1250 2800
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R10
U 1 1 5C6ABCC1
P 1650 4500
F 0 "R10" H 1720 4546 50  0000 L CNN
F 1 "10K" H 1720 4455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 1580 4500 50  0001 C CNN
F 3 "~" H 1650 4500 50  0001 C CNN
	1    1650 4500
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R9
U 1 1 5C6ABE01
P 1300 4500
F 0 "R9" H 1370 4546 50  0000 L CNN
F 1 "10K" H 1370 4455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 1230 4500 50  0001 C CNN
F 3 "~" H 1300 4500 50  0001 C CNN
	1    1300 4500
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R12
U 1 1 5C6AC0FC
P 4200 1100
F 0 "R12" H 4270 1146 50  0000 L CNN
F 1 "10K" H 4270 1055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4130 1100 50  0001 C CNN
F 3 "~" H 4200 1100 50  0001 C CNN
	1    4200 1100
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R11
U 1 1 5C6AC218
P 3900 1100
F 0 "R11" H 3970 1146 50  0000 L CNN
F 1 "10K" H 3970 1055 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3830 1100 50  0001 C CNN
F 3 "~" H 3900 1100 50  0001 C CNN
	1    3900 1100
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R14
U 1 1 5C6AC31F
P 4300 2800
F 0 "R14" H 4370 2846 50  0000 L CNN
F 1 "10K" H 4370 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4230 2800 50  0001 C CNN
F 3 "~" H 4300 2800 50  0001 C CNN
	1    4300 2800
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R13
U 1 1 5C6AC425
P 4000 2800
F 0 "R13" H 4070 2846 50  0000 L CNN
F 1 "10K" H 4070 2755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3930 2800 50  0001 C CNN
F 3 "~" H 4000 2800 50  0001 C CNN
	1    4000 2800
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R16
U 1 1 5C6AC516
P 4350 4500
F 0 "R16" H 4420 4546 50  0000 L CNN
F 1 "10K" H 4420 4455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4280 4500 50  0001 C CNN
F 3 "~" H 4350 4500 50  0001 C CNN
	1    4350 4500
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R15
U 1 1 5C6AC614
P 4050 4500
F 0 "R15" H 4120 4546 50  0000 L CNN
F 1 "10K" H 4120 4455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3980 4500 50  0001 C CNN
F 3 "~" H 4050 4500 50  0001 C CNN
	1    4050 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 1350 1250 1350
Wire Wire Line
	2000 1550 1600 1550
Wire Wire Line
	2050 3000 1350 3000
Wire Wire Line
	2050 3200 1700 3200
Wire Wire Line
	2150 4750 1450 4750
Wire Wire Line
	2150 4950 1800 4950
Wire Wire Line
	1300 4650 1300 4750
Connection ~ 1300 4750
Wire Wire Line
	1300 4750 750  4750
Wire Wire Line
	1650 4650 1650 4950
Connection ~ 1650 4950
Wire Wire Line
	1650 4950 750  4950
Wire Wire Line
	1250 2950 1250 3000
Connection ~ 1250 3000
Wire Wire Line
	1250 3000 750  3000
Wire Wire Line
	1550 2950 1550 3200
Connection ~ 1550 3200
Wire Wire Line
	1550 3200 750  3200
Wire Wire Line
	1100 1300 1100 1350
Connection ~ 1100 1350
Wire Wire Line
	1100 1350 650  1350
Wire Wire Line
	1400 1300 1400 1550
Connection ~ 1400 1550
Wire Wire Line
	1400 1550 650  1550
$Comp
L LrE-6-rescue:+3V3-power #PWR0123
U 1 1 5C723BBE
P 1100 900
F 0 "#PWR0123" H 1100 750 50  0001 C CNN
F 1 "+3V3" H 1115 1073 50  0000 C CNN
F 2 "" H 1100 900 50  0001 C CNN
F 3 "" H 1100 900 50  0001 C CNN
	1    1100 900 
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:+3V3-power #PWR0124
U 1 1 5C723C85
P 1250 2550
F 0 "#PWR0124" H 1250 2400 50  0001 C CNN
F 1 "+3V3" H 1265 2723 50  0000 C CNN
F 2 "" H 1250 2550 50  0001 C CNN
F 3 "" H 1250 2550 50  0001 C CNN
	1    1250 2550
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:+3V3-power #PWR0125
U 1 1 5C723D83
P 1300 4250
F 0 "#PWR0125" H 1300 4100 50  0001 C CNN
F 1 "+3V3" H 1315 4423 50  0000 C CNN
F 2 "" H 1300 4250 50  0001 C CNN
F 3 "" H 1300 4250 50  0001 C CNN
	1    1300 4250
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:+3V3-power #PWR0126
U 1 1 5C724379
P 4050 4250
F 0 "#PWR0126" H 4050 4100 50  0001 C CNN
F 1 "+3V3" H 4065 4423 50  0000 C CNN
F 2 "" H 4050 4250 50  0001 C CNN
F 3 "" H 4050 4250 50  0001 C CNN
	1    4050 4250
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:+3V3-power #PWR0127
U 1 1 5C724780
P 4000 2550
F 0 "#PWR0127" H 4000 2400 50  0001 C CNN
F 1 "+3V3" H 4015 2723 50  0000 C CNN
F 2 "" H 4000 2550 50  0001 C CNN
F 3 "" H 4000 2550 50  0001 C CNN
	1    4000 2550
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:+3V3-power #PWR0128
U 1 1 5C724CCA
P 3900 850
F 0 "#PWR0128" H 3900 700 50  0001 C CNN
F 1 "+3V3" H 3915 1023 50  0000 C CNN
F 2 "" H 3900 850 50  0001 C CNN
F 3 "" H 3900 850 50  0001 C CNN
	1    3900 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3900 850  3900 900 
Wire Wire Line
	4200 950  4200 900 
Wire Wire Line
	4200 900  3900 900 
Connection ~ 3900 900 
Wire Wire Line
	3900 900  3900 950 
Wire Wire Line
	4000 2550 4000 2600
Wire Wire Line
	4300 2650 4300 2600
Wire Wire Line
	4300 2600 4000 2600
Connection ~ 4000 2600
Wire Wire Line
	4000 2600 4000 2650
Wire Wire Line
	4050 4250 4050 4300
Wire Wire Line
	4350 4350 4350 4300
Wire Wire Line
	4350 4300 4050 4300
Connection ~ 4050 4300
Wire Wire Line
	4050 4300 4050 4350
Wire Wire Line
	4950 4950 4550 4950
Wire Wire Line
	4050 4650 4050 4750
Connection ~ 4050 4750
Wire Wire Line
	4350 4650 4350 4950
Connection ~ 4350 4950
Wire Wire Line
	4850 3000 4100 3000
Wire Wire Line
	4850 3200 4450 3200
Wire Wire Line
	4000 2950 4000 3000
Connection ~ 4000 3000
Wire Wire Line
	4000 3000 3350 3000
Wire Wire Line
	4300 2950 4300 3200
Connection ~ 4300 3200
Wire Wire Line
	4300 3200 3350 3200
Wire Wire Line
	4700 1300 4000 1300
Wire Wire Line
	4700 1500 4350 1500
Wire Wire Line
	3900 1250 3900 1300
Connection ~ 3900 1300
Wire Wire Line
	3900 1300 3200 1300
Wire Wire Line
	4200 1250 4200 1500
Connection ~ 4200 1500
Wire Wire Line
	4200 1500 3200 1500
Wire Wire Line
	1250 2550 1250 2600
Wire Wire Line
	1250 2600 1550 2600
Wire Wire Line
	1550 2600 1550 2650
Connection ~ 1250 2600
Wire Wire Line
	1250 2600 1250 2650
Wire Wire Line
	1300 4250 1300 4300
Wire Wire Line
	1650 4350 1650 4300
Wire Wire Line
	1650 4300 1300 4300
Connection ~ 1300 4300
Wire Wire Line
	1300 4300 1300 4350
Wire Wire Line
	1100 900  1100 950 
Wire Wire Line
	1400 1000 1400 950 
Wire Wire Line
	1400 950  1100 950 
Connection ~ 1100 950 
Wire Wire Line
	1100 950  1100 1000
Wire Wire Line
	3400 4750 4050 4750
Wire Wire Line
	3400 4950 4350 4950
$Comp
L LrE-6-rescue:C-Device C1
U 1 1 5C8CF4FD
P 1250 1750
F 0 "C1" H 1365 1796 50  0000 L CNN
F 1 "0.01u" H 1300 1650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1288 1600 50  0001 C CNN
F 3 "~" H 1250 1750 50  0001 C CNN
	1    1250 1750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C2
U 1 1 5C8CF611
P 1600 1750
F 0 "C2" H 1715 1796 50  0000 L CNN
F 1 "0.01u" H 1650 1650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1638 1600 50  0001 C CNN
F 3 "~" H 1600 1750 50  0001 C CNN
	1    1600 1750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C3
U 1 1 5C8CF744
P 1350 3400
F 0 "C3" H 1465 3446 50  0000 L CNN
F 1 "0.01u" H 1400 3300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1388 3250 50  0001 C CNN
F 3 "~" H 1350 3400 50  0001 C CNN
	1    1350 3400
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C4
U 1 1 5C8CF86C
P 1700 3400
F 0 "C4" H 1815 3446 50  0000 L CNN
F 1 "0.01u" H 1750 3300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1738 3250 50  0001 C CNN
F 3 "~" H 1700 3400 50  0001 C CNN
	1    1700 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 1600 1250 1350
Connection ~ 1250 1350
Wire Wire Line
	1250 1350 1100 1350
Wire Wire Line
	1600 1600 1600 1550
Connection ~ 1600 1550
Wire Wire Line
	1600 1550 1400 1550
Wire Wire Line
	1350 3250 1350 3000
Connection ~ 1350 3000
Wire Wire Line
	1350 3000 1250 3000
Wire Wire Line
	1700 3250 1700 3200
Connection ~ 1700 3200
Wire Wire Line
	1700 3200 1550 3200
$Comp
L LrE-6-rescue:C-Device C7
U 1 1 5C92A85A
P 4000 1750
F 0 "C7" H 4115 1796 50  0000 L CNN
F 1 "0.01u" H 4050 1650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4038 1600 50  0001 C CNN
F 3 "~" H 4000 1750 50  0001 C CNN
	1    4000 1750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C8
U 1 1 5C92A94C
P 4350 1750
F 0 "C8" H 4465 1796 50  0000 L CNN
F 1 "0.01u" H 4400 1650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4388 1600 50  0001 C CNN
F 3 "~" H 4350 1750 50  0001 C CNN
	1    4350 1750
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C9
U 1 1 5C92AA33
P 4100 3450
F 0 "C9" H 4215 3496 50  0000 L CNN
F 1 "0.01u" H 4150 3350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4138 3300 50  0001 C CNN
F 3 "~" H 4100 3450 50  0001 C CNN
	1    4100 3450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C10
U 1 1 5C92ABB3
P 4450 3450
F 0 "C10" H 4565 3496 50  0000 L CNN
F 1 "0.01u" H 4500 3350 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4488 3300 50  0001 C CNN
F 3 "~" H 4450 3450 50  0001 C CNN
	1    4450 3450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C11
U 1 1 5C92ACD6
P 4200 5150
F 0 "C11" H 4315 5196 50  0000 L CNN
F 1 "0.01u" H 4250 5050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4238 5000 50  0001 C CNN
F 3 "~" H 4200 5150 50  0001 C CNN
	1    4200 5150
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C12
U 1 1 5C92ADE4
P 4550 5150
F 0 "C12" H 4665 5196 50  0000 L CNN
F 1 "0.01u" H 4650 5050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 4588 5000 50  0001 C CNN
F 3 "~" H 4550 5150 50  0001 C CNN
	1    4550 5150
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C5
U 1 1 5C92AEF7
P 1450 5150
F 0 "C5" H 1565 5196 50  0000 L CNN
F 1 "0.01u" H 1550 5050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1488 5000 50  0001 C CNN
F 3 "~" H 1450 5150 50  0001 C CNN
	1    1450 5150
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C6
U 1 1 5C92B0B3
P 1800 5150
F 0 "C6" H 1915 5196 50  0000 L CNN
F 1 "0.01u" H 1850 5050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 1838 5000 50  0001 C CNN
F 3 "~" H 1800 5150 50  0001 C CNN
	1    1800 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 3300 4100 3000
Connection ~ 4100 3000
Wire Wire Line
	4100 3000 4000 3000
Wire Wire Line
	4450 3300 4450 3200
Connection ~ 4450 3200
Wire Wire Line
	4450 3200 4300 3200
Wire Wire Line
	4200 5000 4200 4750
Connection ~ 4200 4750
Wire Wire Line
	4200 4750 4050 4750
Wire Wire Line
	1450 5000 1450 4750
Connection ~ 1450 4750
Wire Wire Line
	1450 4750 1300 4750
Wire Wire Line
	1800 5000 1800 4950
Connection ~ 1800 4950
Wire Wire Line
	1800 4950 1650 4950
$Comp
L LrE-6-rescue:GND-power #PWR0129
U 1 1 5C9CBA79
P 4200 5450
F 0 "#PWR0129" H 4200 5200 50  0001 C CNN
F 1 "GND" H 4205 5277 50  0000 C CNN
F 2 "" H 4200 5450 50  0001 C CNN
F 3 "" H 4200 5450 50  0001 C CNN
	1    4200 5450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0130
U 1 1 5C9CBBAE
P 1450 5400
F 0 "#PWR0130" H 1450 5150 50  0001 C CNN
F 1 "GND" H 1455 5227 50  0000 C CNN
F 2 "" H 1450 5400 50  0001 C CNN
F 3 "" H 1450 5400 50  0001 C CNN
	1    1450 5400
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0131
U 1 1 5C9CBCA0
P 1350 3650
F 0 "#PWR0131" H 1350 3400 50  0001 C CNN
F 1 "GND" H 1355 3477 50  0000 C CNN
F 2 "" H 1350 3650 50  0001 C CNN
F 3 "" H 1350 3650 50  0001 C CNN
	1    1350 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 3650 1350 3600
Wire Wire Line
	1450 5300 1450 5350
Wire Wire Line
	1450 5350 1800 5350
Wire Wire Line
	1800 5350 1800 5300
Connection ~ 1450 5350
Wire Wire Line
	1450 5350 1450 5400
Wire Wire Line
	2150 4850 2100 4850
Wire Wire Line
	2100 4850 2100 5350
Wire Wire Line
	2100 5350 1800 5350
Connection ~ 1800 5350
Wire Wire Line
	2050 3100 2000 3100
Wire Wire Line
	2000 3100 2000 3600
Wire Wire Line
	2000 3600 1700 3600
Connection ~ 1350 3600
Wire Wire Line
	1350 3600 1350 3550
Wire Wire Line
	1700 3550 1700 3600
Connection ~ 1700 3600
Wire Wire Line
	1700 3600 1350 3600
Wire Wire Line
	4000 1600 4000 1300
Connection ~ 4000 1300
Wire Wire Line
	4000 1300 3900 1300
Wire Wire Line
	4350 1600 4350 1500
Connection ~ 4350 1500
Wire Wire Line
	4350 1500 4200 1500
Wire Wire Line
	4200 5450 4200 5400
$Comp
L LrE-6-rescue:GND-power #PWR0132
U 1 1 5CB17BB7
P 1250 2000
F 0 "#PWR0132" H 1250 1750 50  0001 C CNN
F 1 "GND" H 1255 1827 50  0000 C CNN
F 2 "" H 1250 2000 50  0001 C CNN
F 3 "" H 1250 2000 50  0001 C CNN
	1    1250 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 1900 1250 1950
Wire Wire Line
	1250 1950 1600 1950
Wire Wire Line
	1900 1950 1900 1450
Wire Wire Line
	1900 1450 2000 1450
Connection ~ 1250 1950
Wire Wire Line
	1250 1950 1250 2000
Wire Wire Line
	1600 1900 1600 1950
Connection ~ 1600 1950
Wire Wire Line
	1600 1950 1900 1950
$Comp
L LrE-6-rescue:GND-power #PWR0133
U 1 1 5CB92FE6
P 4000 2000
F 0 "#PWR0133" H 4000 1750 50  0001 C CNN
F 1 "GND" H 4005 1827 50  0000 C CNN
F 2 "" H 4000 2000 50  0001 C CNN
F 3 "" H 4000 2000 50  0001 C CNN
	1    4000 2000
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0134
U 1 1 5CB930D1
P 4100 3700
F 0 "#PWR0134" H 4100 3450 50  0001 C CNN
F 1 "GND" H 4105 3527 50  0000 C CNN
F 2 "" H 4100 3700 50  0001 C CNN
F 3 "" H 4100 3700 50  0001 C CNN
	1    4100 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 2000 4000 1950
Wire Wire Line
	4000 1950 4350 1950
Wire Wire Line
	4650 1950 4650 1400
Wire Wire Line
	4650 1400 4700 1400
Connection ~ 4000 1950
Wire Wire Line
	4000 1950 4000 1900
Wire Wire Line
	4350 1900 4350 1950
Connection ~ 4350 1950
Wire Wire Line
	4350 1950 4650 1950
Wire Wire Line
	4100 3600 4100 3650
Wire Wire Line
	4100 3650 4450 3650
Wire Wire Line
	4800 3650 4800 3100
Wire Wire Line
	4800 3100 4850 3100
Connection ~ 4100 3650
Wire Wire Line
	4100 3650 4100 3700
Wire Wire Line
	4450 3600 4450 3650
Connection ~ 4450 3650
Wire Wire Line
	4450 3650 4800 3650
Wire Wire Line
	4950 4850 4900 4850
Wire Wire Line
	4900 4850 4900 5400
Wire Wire Line
	4900 5400 4550 5400
Connection ~ 4200 5400
Wire Wire Line
	4200 5400 4200 5300
Wire Wire Line
	4550 5300 4550 5400
Connection ~ 4550 5400
Wire Wire Line
	4550 5400 4200 5400
Text Label 650  1350 0    50   ~ 0
ENC1-A
Text Label 650  1550 0    50   ~ 0
ENC1-B
Text Label 750  3000 0    50   ~ 0
ENC2-A
Text Label 750  3200 0    50   ~ 0
ENC2-B
Text Label 750  4750 0    50   ~ 0
ENC3-A
Text Label 750  4950 0    50   ~ 0
ENC3-B
Text Label 3200 1300 0    50   ~ 0
ENC4-A
Text Label 3200 1500 0    50   ~ 0
ENC4-B
Text Label 3350 3000 0    50   ~ 0
ENC5-A
Text Label 3350 3200 0    50   ~ 0
ENC5-B
Text Label 3400 4750 0    50   ~ 0
ENC0-A
Text Label 3400 4950 0    50   ~ 0
ENC0-B
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW1
U 1 1 5CCE212B
P 1500 7200
F 0 "SW1" H 1500 7478 50  0000 C CNN
F 1 "Tact_SW_8mm" H 1650 7400 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 1500 7200 50  0001 C CNN
F 3 "" H 1500 7200 50  0001 C CNN
	1    1500 7200
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW2
U 1 1 5CCE2246
P 1500 8250
F 0 "SW2" H 1500 8528 50  0000 C CNN
F 1 "Tact_SW_8mm" H 1650 8450 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 1500 8250 50  0001 C CNN
F 3 "" H 1500 8250 50  0001 C CNN
	1    1500 8250
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW3
U 1 1 5CCE2412
P 1500 9250
F 0 "SW3" H 1500 9528 50  0000 C CNN
F 1 "Tact_SW_8mm" H 1650 9450 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 1500 9250 50  0001 C CNN
F 3 "" H 1500 9250 50  0001 C CNN
	1    1500 9250
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW4
U 1 1 5CCE2530
P 1600 10500
F 0 "SW4" H 1600 10778 50  0000 C CNN
F 1 "Tact_SW_8mm" H 1700 10700 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 1600 10500 50  0001 C CNN
F 3 "" H 1600 10500 50  0001 C CNN
	1    1600 10500
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW5
U 1 1 5CCE2664
P 3850 7200
F 0 "SW5" H 3850 7478 50  0000 C CNN
F 1 "Tact_SW_8mm" H 3850 7387 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 3850 7200 50  0001 C CNN
F 3 "" H 3850 7200 50  0001 C CNN
	1    3850 7200
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW6
U 1 1 5CCE27CC
P 2650 7200
F 0 "SW6" H 2650 7478 50  0000 C CNN
F 1 "Tact_SW_8mm" H 2650 7387 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 2650 7200 50  0001 C CNN
F 3 "" H 2650 7200 50  0001 C CNN
	1    2650 7200
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW7
U 1 1 5CCE28E5
P 2650 8250
F 0 "SW7" H 2650 8528 50  0000 C CNN
F 1 "Tact_SW_8mm" H 2650 8437 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 2650 8250 50  0001 C CNN
F 3 "" H 2650 8250 50  0001 C CNN
	1    2650 8250
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW8
U 1 1 5CCE2A37
P 2750 9300
F 0 "SW8" H 2750 9578 50  0000 C CNN
F 1 "Tact_SW_8mm" H 2750 9487 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 2750 9300 50  0001 C CNN
F 3 "" H 2750 9300 50  0001 C CNN
	1    2750 9300
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW9
U 1 1 5CCE2B60
P 2750 10450
F 0 "SW9" H 2750 10728 50  0000 C CNN
F 1 "Tact_SW_8mm" H 2750 10637 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 2750 10450 50  0001 C CNN
F 3 "" H 2750 10450 50  0001 C CNN
	1    2750 10450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:SW_Push_45deg-Switch SW10
U 1 1 5CCE2C90
P 3850 8250
F 0 "SW10" H 3850 8528 50  0000 C CNN
F 1 "Tact_SW_8mm" H 3850 8437 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm_H9.5mm" H 3850 8250 50  0001 C CNN
F 3 "" H 3850 8250 50  0001 C CNN
	1    3850 8250
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D4
U 1 1 5C4E1850
P 1700 10750
F 0 "D4" V 1746 10670 50  0000 R CNN
F 1 "1N4148W" V 1655 10670 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 1700 10575 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1700 10750 50  0001 C CNN
	1    1700 10750
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D9
U 1 1 5C4E2E74
P 2850 10700
F 0 "D9" V 2896 10620 50  0000 R CNN
F 1 "1N4148W" V 2805 10620 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 2850 10525 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2850 10700 50  0001 C CNN
	1    2850 10700
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:R-Device R4
U 1 1 5C4E6032
P 1050 10900
F 0 "R4" V 843 10900 50  0000 C CNN
F 1 "1K" V 934 10900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 980 10900 50  0001 C CNN
F 3 "~" H 1050 10900 50  0001 C CNN
	1    1050 10900
	0    1    1    0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D3
U 1 1 5C4E8A83
P 1600 9500
F 0 "D3" V 1646 9420 50  0000 R CNN
F 1 "1N4148W" V 1555 9420 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 1600 9325 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1600 9500 50  0001 C CNN
	1    1600 9500
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D8
U 1 1 5C4E949A
P 2850 9550
F 0 "D8" V 2896 9470 50  0000 R CNN
F 1 "1N4148W" V 2805 9470 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 2850 9375 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2850 9550 50  0001 C CNN
	1    2850 9550
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:R-Device R3
U 1 1 5C4EAB19
P 1000 9700
F 0 "R3" V 793 9700 50  0000 C CNN
F 1 "1K" V 884 9700 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 930 9700 50  0001 C CNN
F 3 "~" H 1000 9700 50  0001 C CNN
	1    1000 9700
	0    1    1    0   
$EndComp
$Comp
L LrE-6-rescue:R-Device R2
U 1 1 5C4EBA08
P 1000 8650
F 0 "R2" V 1207 8650 50  0000 C CNN
F 1 "1K" V 1116 8650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 930 8650 50  0001 C CNN
F 3 "~" H 1000 8650 50  0001 C CNN
	1    1000 8650
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D2
U 1 1 5C4EC382
P 1600 8500
F 0 "D2" V 1646 8420 50  0000 R CNN
F 1 "1N4148W" V 1555 8420 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 1600 8325 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1600 8500 50  0001 C CNN
	1    1600 8500
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D7
U 1 1 5C4ED026
P 2750 8500
F 0 "D7" V 2796 8420 50  0000 R CNN
F 1 "1N4148W" V 2705 8420 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 2750 8325 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2750 8500 50  0001 C CNN
	1    2750 8500
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D10
U 1 1 5C4ED821
P 3950 8500
F 0 "D10" V 3996 8420 50  0000 R CNN
F 1 "1N4148W" V 3905 8420 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 3950 8325 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 3950 8500 50  0001 C CNN
	1    3950 8500
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0135
U 1 1 5C4EFC63
P 900 11000
F 0 "#PWR0135" H 900 10750 50  0001 C CNN
F 1 "GND" H 905 10827 50  0000 C CNN
F 2 "" H 900 11000 50  0001 C CNN
F 3 "" H 900 11000 50  0001 C CNN
	1    900  11000
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0136
U 1 1 5C4F0FEB
P 850 9800
F 0 "#PWR0136" H 850 9550 50  0001 C CNN
F 1 "GND" H 855 9627 50  0000 C CNN
F 2 "" H 850 9800 50  0001 C CNN
F 3 "" H 850 9800 50  0001 C CNN
	1    850  9800
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0137
U 1 1 5C4F2322
P 850 8750
F 0 "#PWR0137" H 850 8500 50  0001 C CNN
F 1 "GND" H 855 8577 50  0000 C CNN
F 2 "" H 850 8750 50  0001 C CNN
F 3 "" H 850 8750 50  0001 C CNN
	1    850  8750
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  8750 850  8650
Wire Wire Line
	850  9800 850  9700
Wire Wire Line
	900  11000 900  10900
Wire Wire Line
	2850 10900 2850 10850
Connection ~ 1700 10900
Wire Wire Line
	1700 10900 2850 10900
Wire Wire Line
	1150 9700 1600 9700
Wire Wire Line
	1600 9650 1600 9700
Connection ~ 1600 9700
Wire Wire Line
	1600 9700 2850 9700
Wire Wire Line
	1150 8650 1600 8650
Connection ~ 1600 8650
Wire Wire Line
	1600 8650 2750 8650
Connection ~ 2750 8650
Wire Wire Line
	2750 8650 3950 8650
$Comp
L LrE-6-rescue:1N4148W-Diode D1
U 1 1 5C6AD044
P 1600 7450
F 0 "D1" V 1646 7370 50  0000 R CNN
F 1 "1N4148W" V 1555 7370 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 1600 7275 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 1600 7450 50  0001 C CNN
	1    1600 7450
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D6
U 1 1 5C6AE01B
P 2750 7450
F 0 "D6" V 2796 7370 50  0000 R CNN
F 1 "1N4148W" V 2705 7370 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 2750 7275 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2750 7450 50  0001 C CNN
	1    2750 7450
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D5
U 1 1 5C6AEB31
P 3950 7450
F 0 "D5" V 3996 7370 50  0000 R CNN
F 1 "1N4148W" V 3905 7370 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 3950 7275 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 3950 7450 50  0001 C CNN
	1    3950 7450
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:R-Device R1
U 1 1 5C6B3D26
P 1050 7600
F 0 "R1" V 843 7600 50  0000 C CNN
F 1 "1K" V 934 7600 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 980 7600 50  0001 C CNN
F 3 "~" H 1050 7600 50  0001 C CNN
	1    1050 7600
	0    1    1    0   
$EndComp
Connection ~ 2750 7600
Wire Wire Line
	2750 7600 3950 7600
$Comp
L LrE-6-rescue:GND-power #PWR0138
U 1 1 5C7E5536
P 900 7750
F 0 "#PWR0138" H 900 7500 50  0001 C CNN
F 1 "GND" H 905 7577 50  0000 C CNN
F 2 "" H 900 7750 50  0001 C CNN
F 3 "" H 900 7750 50  0001 C CNN
	1    900  7750
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  7750 900  7600
Wire Wire Line
	1400 9150 1300 9150
Wire Wire Line
	1300 9150 1300 8150
Wire Wire Line
	1500 10400 1300 10400
Wire Wire Line
	1300 10400 1300 9150
Connection ~ 1300 9150
Wire Wire Line
	1400 8150 1300 8150
Connection ~ 1300 8150
Wire Wire Line
	1300 8150 1300 7100
Wire Wire Line
	1400 7100 1300 7100
Connection ~ 1600 7600
Wire Wire Line
	1600 7600 2750 7600
Wire Wire Line
	1200 7600 1600 7600
Text Label 1300 6900 1    50   ~ 0
L0
Wire Wire Line
	2300 10350 2300 9200
Wire Wire Line
	2550 8150 2300 8150
Connection ~ 2300 8150
Wire Wire Line
	2300 8150 2300 7100
Wire Wire Line
	2650 9200 2300 9200
Connection ~ 2300 9200
Wire Wire Line
	2300 9200 2300 8150
Wire Wire Line
	2300 10350 2650 10350
Wire Wire Line
	2550 7100 2300 7100
Text Label 2300 6900 1    50   ~ 0
L1
Wire Wire Line
	3400 8150 3750 8150
Wire Wire Line
	3750 7100 3400 7100
Wire Wire Line
	3400 7100 3400 8150
Text Label 3400 6900 1    50   ~ 0
L2
$Comp
L LrE-6-rescue:1N4148W-Diode D12
U 1 1 5CAC9D35
P 2650 3350
F 0 "D12" V 2696 3270 50  0000 R CNN
F 1 "1N4148W" V 2605 3270 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 2650 3175 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2650 3350 50  0001 C CNN
	1    2650 3350
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D11
U 1 1 5CACAD5F
P 2600 1700
F 0 "D11" V 2646 1620 50  0000 R CNN
F 1 "1N4148W" V 2555 1620 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 2600 1525 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2600 1700 50  0001 C CNN
	1    2600 1700
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D13
U 1 1 5CACBDAF
P 2750 5100
F 0 "D13" V 2796 5020 50  0000 R CNN
F 1 "1N4148W" V 2705 5020 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 2750 4925 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 2750 5100 50  0001 C CNN
	1    2750 5100
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D14
U 1 1 5CACD41C
P 5300 1650
F 0 "D14" V 5346 1570 50  0000 R CNN
F 1 "1N4148W" V 5255 1570 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 5300 1475 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 5300 1650 50  0001 C CNN
	1    5300 1650
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D15
U 1 1 5CACE3B1
P 5450 3350
F 0 "D15" V 5496 3270 50  0000 R CNN
F 1 "1N4148W" V 5405 3270 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 5450 3175 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 5450 3350 50  0001 C CNN
	1    5450 3350
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:1N4148W-Diode D16
U 1 1 5CACF29F
P 5550 5100
F 0 "D16" V 5596 5020 50  0000 R CNN
F 1 "1N4148W" V 5505 5020 50  0000 R CNN
F 2 "LrE-6:D_SOD-123" H 5550 4925 50  0001 C CNN
F 3 "https://www.vishay.com/docs/85748/1n4148w.pdf" H 5550 5100 50  0001 C CNN
	1    5550 5100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2850 10900 4050 10900
Connection ~ 2850 10900
Wire Wire Line
	2850 9700 4000 9700
Connection ~ 2850 9700
Wire Wire Line
	3950 7600 4550 7600
Connection ~ 3950 7600
Wire Wire Line
	3950 8650 4550 8650
Connection ~ 3950 8650
Text Label 4050 10900 0    50   ~ 0
M3
Text Label 4000 9700 0    50   ~ 0
M2
Text Label 4550 8650 0    50   ~ 0
M1
Text Label 4550 7600 0    50   ~ 0
M0
Wire Wire Line
	2600 1850 2600 2050
Wire Wire Line
	2600 2050 2850 2050
Wire Wire Line
	2650 3500 2650 3700
Wire Wire Line
	2650 3700 2900 3700
Wire Wire Line
	2650 3000 2900 3000
Wire Wire Line
	2600 1350 2900 1350
Wire Wire Line
	2750 4750 3000 4750
Text Label 2900 1350 0    50   ~ 0
L3
Text Label 2900 3000 0    50   ~ 0
L3
Text Label 2850 2050 0    50   ~ 0
M0
Text Label 2900 3700 0    50   ~ 0
M1
Text Label 3000 4750 0    50   ~ 0
L3
Wire Wire Line
	2750 5250 2750 5400
Wire Wire Line
	2750 5400 3100 5400
Text Label 3100 5400 0    50   ~ 0
M2
Wire Wire Line
	5300 1300 5800 1300
Wire Wire Line
	5450 3000 5950 3000
Wire Wire Line
	5550 4750 6100 4750
Wire Wire Line
	5550 5250 5550 5450
Wire Wire Line
	5550 5450 6150 5450
Wire Wire Line
	5450 3500 5450 3600
Wire Wire Line
	5450 3600 6000 3600
Wire Wire Line
	5300 1800 5300 2000
Wire Wire Line
	5300 2000 5850 2000
Text Label 5850 2000 0    50   ~ 0
M2
Text Label 6000 3600 0    50   ~ 0
M3
Text Label 6150 5450 0    50   ~ 0
M3
Text Label 5800 1300 0    50   ~ 0
L2
Text Label 5950 3000 0    50   ~ 0
L2
Text Label 6100 4750 0    50   ~ 0
L3
$Comp
L LrE-6-rescue:+3V3-power #PWR0139
U 1 1 5C5248C7
P 14850 2400
F 0 "#PWR0139" H 14850 2250 50  0001 C CNN
F 1 "+3V3" H 14865 2573 50  0000 C CNN
F 2 "" H 14850 2400 50  0001 C CNN
F 3 "" H 14850 2400 50  0001 C CNN
	1    14850 2400
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R24
U 1 1 5C5249AB
P 14550 2450
F 0 "R24" V 14343 2450 50  0000 C CNN
F 1 "1K" V 14434 2450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 14480 2450 50  0001 C CNN
F 3 "~" H 14550 2450 50  0001 C CNN
	1    14550 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	14700 2450 14850 2450
Wire Wire Line
	14850 2450 14850 2400
$Comp
L LrE-6-rescue:LED-Device D18
U 1 1 5C54E897
P 14150 2450
F 0 "D18" H 14141 2666 50  0000 C CNN
F 1 "LED0603_BL" H 14141 2575 50  0000 C CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 14150 2450 50  0001 C CNN
F 3 "~" H 14150 2450 50  0001 C CNN
	1    14150 2450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0140
U 1 1 5C54EA62
P 13850 2550
F 0 "#PWR0140" H 13850 2300 50  0001 C CNN
F 1 "GND" H 13855 2377 50  0000 C CNN
F 2 "" H 13850 2550 50  0001 C CNN
F 3 "" H 13850 2550 50  0001 C CNN
	1    13850 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	13850 2550 13850 2450
Wire Wire Line
	13850 2450 14000 2450
Wire Wire Line
	14300 2450 14400 2450
$Comp
L LrE-6-rescue:GND-power #PWR0141
U 1 1 5C4E242E
P 7000 2950
F 0 "#PWR0141" H 7000 2700 50  0001 C CNN
F 1 "GND" H 7005 2777 50  0000 C CNN
F 2 "" H 7000 2950 50  0001 C CNN
F 3 "" H 7000 2950 50  0001 C CNN
	1    7000 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 2950 7000 2850
Wire Wire Line
	7000 2850 7800 2850
Wire Wire Line
	1300 7100 1300 6750
Connection ~ 1300 7100
Wire Wire Line
	2300 7100 2300 6750
Connection ~ 2300 7100
Wire Wire Line
	3400 7100 3400 6700
Connection ~ 3400 7100
Wire Wire Line
	4200 4750 4950 4750
Wire Wire Line
	4550 5000 4550 4950
Connection ~ 4550 4950
Wire Wire Line
	4550 4950 4350 4950
NoConn ~ 14800 4250
NoConn ~ 11950 1450
Wire Wire Line
	11550 1650 11550 1700
Wire Wire Line
	11550 1700 11650 1700
Connection ~ 11650 1700
Wire Wire Line
	11650 1700 11650 1650
Text Notes 14900 10450 0    197  ~ 0
F2.8-1
Wire Wire Line
	1200 10900 1700 10900
$Comp
L LrE-6-rescue:TestPoint-Connector TP1
U 1 1 5C9CF623
P 13200 2400
F 0 "TP1" H 13258 2518 50  0000 L CNN
F 1 "TestPoint" H 13258 2427 50  0000 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 13400 2400 50  0001 C CNN
F 3 "~" H 13400 2400 50  0001 C CNN
	1    13200 2400
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0144
U 1 1 5C9D2E04
P 13200 2550
F 0 "#PWR0144" H 13200 2300 50  0001 C CNN
F 1 "GND" H 13205 2377 50  0000 C CNN
F 2 "" H 13200 2550 50  0001 C CNN
F 3 "" H 13200 2550 50  0001 C CNN
	1    13200 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	13200 2550 13200 2400
$Comp
L LrE-6-rescue:GND-power #PWR0111
U 1 1 5C4AB9A8
P 15050 4500
F 0 "#PWR0111" H 15050 4250 50  0001 C CNN
F 1 "GND" H 15055 4327 50  0000 C CNN
F 2 "" H 15050 4500 50  0001 C CNN
F 3 "" H 15050 4500 50  0001 C CNN
	1    15050 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	14800 1050 14800 1000
$Comp
L LrE-6-rescue:+3V3-power #PWR0107
U 1 1 5C4A315E
P 14800 1000
F 0 "#PWR0107" H 14800 850 50  0001 C CNN
F 1 "+3V3" H 14815 1173 50  0000 C CNN
F 2 "" H 14800 1000 50  0001 C CNN
F 3 "" H 14800 1000 50  0001 C CNN
	1    14800 1000
	1    0    0    -1  
$EndComp
Text Label 13700 3750 0    50   ~ 0
NRST
Wire Wire Line
	14800 4150 14150 4150
Wire Wire Line
	14800 4050 14150 4050
Text Label 14250 4050 0    50   ~ 0
SWDIO
Text Label 14250 4150 0    50   ~ 0
SWCLK
$Comp
L LrE-6-rescue:+3V3-power #PWR0112
U 1 1 5C4ACA20
P 13400 3150
F 0 "#PWR0112" H 13400 3000 50  0001 C CNN
F 1 "+3V3" H 13415 3323 50  0000 C CNN
F 2 "" H 13400 3150 50  0001 C CNN
F 3 "" H 13400 3150 50  0001 C CNN
	1    13400 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	13400 3150 13400 3250
Wire Wire Line
	13400 3250 13400 3300
Connection ~ 13400 3250
Wire Wire Line
	14250 3250 13400 3250
Wire Wire Line
	13400 3750 13400 3600
Connection ~ 13400 3750
Wire Wire Line
	14800 3750 13400 3750
Wire Wire Line
	13400 3850 13400 3750
Wire Wire Line
	13400 4150 13400 4200
$Comp
L LrE-6-rescue:GND-power #PWR0113
U 1 1 5C4ACBA6
P 13400 4200
F 0 "#PWR0113" H 13400 3950 50  0001 C CNN
F 1 "GND" H 13405 4027 50  0000 C CNN
F 2 "" H 13400 4200 50  0001 C CNN
F 3 "" H 13400 4200 50  0001 C CNN
	1    13400 4200
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R17
U 1 1 5C4ACB2C
P 13400 3450
F 0 "R17" H 13470 3496 50  0000 L CNN
F 1 "10K" H 13470 3405 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 13330 3450 50  0001 C CNN
F 3 "~" H 13400 3450 50  0001 C CNN
	1    13400 3450
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C21
U 1 1 5C4ACA82
P 13400 4000
F 0 "C21" H 13515 4046 50  0000 L CNN
F 1 "1u" H 13515 3955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 13438 3850 50  0001 C CNN
F 3 "~" H 13400 4000 50  0001 C CNN
	1    13400 4000
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0145
U 1 1 5E26EB21
P 2250 1850
F 0 "#PWR0145" H 2250 1600 50  0001 C CNN
F 1 "GND" H 2255 1677 50  0000 C CNN
F 2 "" H 2250 1850 50  0001 C CNN
F 3 "" H 2250 1850 50  0001 C CNN
	1    2250 1850
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0146
U 1 1 5E26F099
P 4950 1800
F 0 "#PWR0146" H 4950 1550 50  0001 C CNN
F 1 "GND" H 4955 1627 50  0000 C CNN
F 2 "" H 4950 1800 50  0001 C CNN
F 3 "" H 4950 1800 50  0001 C CNN
	1    4950 1800
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0147
U 1 1 5E35B268
P 5100 3500
F 0 "#PWR0147" H 5100 3250 50  0001 C CNN
F 1 "GND" H 5105 3327 50  0000 C CNN
F 2 "" H 5100 3500 50  0001 C CNN
F 3 "" H 5100 3500 50  0001 C CNN
	1    5100 3500
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0148
U 1 1 5E3D5025
P 2300 3500
F 0 "#PWR0148" H 2300 3250 50  0001 C CNN
F 1 "GND" H 2305 3327 50  0000 C CNN
F 2 "" H 2300 3500 50  0001 C CNN
F 3 "" H 2300 3500 50  0001 C CNN
	1    2300 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	15050 4400 15050 4450
Wire Wire Line
	15050 4450 14950 4450
Wire Wire Line
	14700 3950 14700 4450
Wire Wire Line
	14950 4400 14950 4450
Connection ~ 14950 4450
Wire Wire Line
	14950 4450 14700 4450
Wire Wire Line
	15050 4450 15050 4500
Connection ~ 15050 4450
Wire Wire Line
	2250 1750 2250 1800
Wire Wire Line
	2250 1800 2400 1800
Wire Wire Line
	2400 1800 2400 1750
Connection ~ 2250 1800
Wire Wire Line
	2250 1800 2250 1850
Wire Wire Line
	2300 3400 2300 3450
Wire Wire Line
	2450 3400 2450 3450
Wire Wire Line
	2300 3450 2450 3450
Connection ~ 2300 3450
Wire Wire Line
	2300 3450 2300 3500
Wire Wire Line
	5100 3400 5100 3450
Wire Wire Line
	5250 3400 5250 3450
Wire Wire Line
	5250 3450 5100 3450
Connection ~ 5100 3450
Wire Wire Line
	5100 3450 5100 3500
Wire Wire Line
	4950 1800 4950 1750
Wire Wire Line
	4950 1750 5100 1750
Wire Wire Line
	5100 1750 5100 1700
Connection ~ 4950 1750
Wire Wire Line
	4950 1750 4950 1700
$Comp
L LrE-6-rescue:GND-power #PWR0149
U 1 1 5E927946
P 5200 5250
F 0 "#PWR0149" H 5200 5000 50  0001 C CNN
F 1 "GND" H 5205 5077 50  0000 C CNN
F 2 "" H 5200 5250 50  0001 C CNN
F 3 "" H 5200 5250 50  0001 C CNN
	1    5200 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 5150 5200 5200
Wire Wire Line
	5200 5200 5350 5200
Wire Wire Line
	5350 5200 5350 5150
Connection ~ 5200 5200
Wire Wire Line
	5200 5200 5200 5250
$Comp
L LrE-6-rescue:GND-power #PWR0150
U 1 1 5E9A409D
P 2400 5250
F 0 "#PWR0150" H 2400 5000 50  0001 C CNN
F 1 "GND" H 2405 5077 50  0000 C CNN
F 2 "" H 2400 5250 50  0001 C CNN
F 3 "" H 2400 5250 50  0001 C CNN
	1    2400 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 5150 2400 5200
Wire Wire Line
	2550 5150 2550 5200
Wire Wire Line
	2550 5200 2400 5200
Connection ~ 2400 5200
Wire Wire Line
	2400 5200 2400 5250
$Comp
L LrE-6:WS2812B-2020 D31
U 1 1 5CFA2C68
P 5700 7650
F 0 "D31" H 5400 7900 50  0000 L CNN
F 1 "WS2812B-2020" H 5200 7400 50  0000 L CNN
F 2 "LrE-6:LED_WS2812B-2020" H 5750 7350 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/product-files/2686/SK6812MINI_REV.01-1-2.pdf" H 5800 7275 50  0001 L TNN
	1    5700 7650
	1    0    0    -1  
$EndComp
$Comp
L LrE-6:WS2812B-2020 D32
U 1 1 5CFAA8BB
P 6800 7650
F 0 "D32" H 6500 7900 50  0000 L CNN
F 1 "WS2812B-2020" H 6300 7400 50  0000 L CNN
F 2 "LrE-6:LED_WS2812B-2020" H 6850 7350 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/product-files/2686/SK6812MINI_REV.01-1-2.pdf" H 6900 7275 50  0001 L TNN
	1    6800 7650
	1    0    0    -1  
$EndComp
$Comp
L LrE-6:WS2812B-2020 D33
U 1 1 5CFAB701
P 7950 7650
F 0 "D33" H 7650 7900 50  0000 L CNN
F 1 "WS2812B-2020" H 7450 7400 50  0000 L CNN
F 2 "LrE-6:LED_WS2812B-2020" H 8000 7350 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/product-files/2686/SK6812MINI_REV.01-1-2.pdf" H 8050 7275 50  0001 L TNN
	1    7950 7650
	1    0    0    -1  
$EndComp
$Comp
L LrE-6:WS2812B-2020 D34
U 1 1 5CFAC587
P 9100 7650
F 0 "D34" H 8750 7900 50  0000 L CNN
F 1 "WS2812B-2020" H 8600 7400 50  0000 L CNN
F 2 "LrE-6:LED_WS2812B-2020" H 9150 7350 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/product-files/2686/SK6812MINI_REV.01-1-2.pdf" H 9200 7275 50  0001 L TNN
	1    9100 7650
	1    0    0    -1  
$EndComp
$Comp
L LrE-6:WS2812B-2020 D35
U 1 1 5CFAD843
P 10250 7650
F 0 "D35" H 9950 7900 50  0000 L CNN
F 1 "WS2812B-2020" H 9750 7400 50  0000 L CNN
F 2 "LrE-6:LED_WS2812B-2020" H 10300 7350 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/product-files/2686/SK6812MINI_REV.01-1-2.pdf" H 10350 7275 50  0001 L TNN
	1    10250 7650
	1    0    0    -1  
$EndComp
$Comp
L LrE-6:WS2812B-2020 D36
U 1 1 5CFAE065
P 11400 7650
F 0 "D36" H 11050 7900 50  0000 L CNN
F 1 "WS2812B-2020" H 10900 7400 50  0000 L CNN
F 2 "LrE-6:LED_WS2812B-2020" H 11450 7350 50  0001 L TNN
F 3 "https://cdn-shop.adafruit.com/product-files/2686/SK6812MINI_REV.01-1-2.pdf" H 11500 7275 50  0001 L TNN
	1    11400 7650
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0122
U 1 1 5CFAF29C
P 5700 8050
F 0 "#PWR0122" H 5700 7800 50  0001 C CNN
F 1 "GND" H 5705 7877 50  0000 C CNN
F 2 "" H 5700 8050 50  0001 C CNN
F 3 "" H 5700 8050 50  0001 C CNN
	1    5700 8050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 8050 5700 8000
Wire Wire Line
	5700 8000 6100 8000
Wire Wire Line
	11400 8000 11400 7950
Connection ~ 5700 8000
Wire Wire Line
	5700 8000 5700 7950
Wire Wire Line
	10250 7950 10250 8000
Connection ~ 10250 8000
Wire Wire Line
	10250 8000 10650 8000
Wire Wire Line
	9100 7950 9100 8000
Connection ~ 9100 8000
Wire Wire Line
	9100 8000 9450 8000
Wire Wire Line
	7950 7950 7950 8000
Connection ~ 7950 8000
Wire Wire Line
	6800 7950 6800 8000
Connection ~ 6800 8000
Wire Wire Line
	6800 8000 7150 8000
Wire Wire Line
	11400 7350 11400 7200
Wire Wire Line
	11400 7200 10650 7200
Wire Wire Line
	10250 7350 10250 7200
Connection ~ 10250 7200
Wire Wire Line
	10250 7200 9450 7200
Wire Wire Line
	9100 7350 9100 7200
Connection ~ 9100 7200
Wire Wire Line
	9100 7200 8300 7200
Wire Wire Line
	7950 7350 7950 7200
Connection ~ 7950 7200
Wire Wire Line
	7950 7200 7150 7200
Wire Wire Line
	6800 7350 6800 7200
Connection ~ 6800 7200
Wire Wire Line
	6800 7200 6100 7200
Wire Wire Line
	5700 7350 5700 7200
Connection ~ 5700 7200
Wire Wire Line
	5700 7200 5300 7200
Text Label 4900 7200 0    50   ~ 0
VBUS
Wire Wire Line
	6000 7650 6500 7650
Wire Wire Line
	7100 7650 7650 7650
Wire Wire Line
	8250 7650 8800 7650
Wire Wire Line
	9400 7650 9950 7650
Wire Wire Line
	10550 7650 11100 7650
NoConn ~ 11700 7650
NoConn ~ 10400 7750
$Comp
L LrE-6-rescue:C-Device C31
U 1 1 5D7055E7
P 6100 7350
F 0 "C31" H 6215 7396 50  0000 L CNN
F 1 "0.1u" H 6215 7305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6138 7200 50  0001 C CNN
F 3 "~" H 6100 7350 50  0001 C CNN
	1    6100 7350
	1    0    0    -1  
$EndComp
Connection ~ 6100 7200
Wire Wire Line
	6100 7200 5700 7200
$Comp
L LrE-6-rescue:C-Device C32
U 1 1 5D706229
P 7150 7350
F 0 "C32" H 7265 7396 50  0000 L CNN
F 1 "0.1u" H 7265 7305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 7188 7200 50  0001 C CNN
F 3 "~" H 7150 7350 50  0001 C CNN
	1    7150 7350
	1    0    0    -1  
$EndComp
Connection ~ 7150 7200
Wire Wire Line
	7150 7200 6800 7200
$Comp
L LrE-6-rescue:C-Device C33
U 1 1 5D706B4B
P 8300 7350
F 0 "C33" H 8415 7396 50  0000 L CNN
F 1 "0.1u" H 8415 7305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 8338 7200 50  0001 C CNN
F 3 "~" H 8300 7350 50  0001 C CNN
	1    8300 7350
	1    0    0    -1  
$EndComp
Connection ~ 8300 7200
Wire Wire Line
	8300 7200 7950 7200
Connection ~ 9450 7200
Wire Wire Line
	9450 7200 9100 7200
$Comp
L LrE-6-rescue:C-Device C35
U 1 1 5D7076C0
P 10650 7350
F 0 "C35" H 10765 7396 50  0000 L CNN
F 1 "0.1u" H 10765 7305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 10688 7200 50  0001 C CNN
F 3 "~" H 10650 7350 50  0001 C CNN
	1    10650 7350
	1    0    0    -1  
$EndComp
Connection ~ 10650 7200
Wire Wire Line
	10650 7200 10250 7200
$Comp
L LrE-6-rescue:C-Device C36
U 1 1 5D708E26
P 11850 7350
F 0 "C36" H 11965 7396 50  0000 L CNN
F 1 "0.1u" H 11965 7305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 11888 7200 50  0001 C CNN
F 3 "~" H 11850 7350 50  0001 C CNN
	1    11850 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	11400 7200 11850 7200
Connection ~ 11400 7200
Wire Wire Line
	11400 8000 11850 8000
Wire Wire Line
	11850 8000 11850 7500
Connection ~ 11400 8000
Wire Wire Line
	6100 7500 6100 8000
Connection ~ 6100 8000
Wire Wire Line
	6100 8000 6800 8000
Wire Wire Line
	7150 7500 7150 8000
Connection ~ 7150 8000
Wire Wire Line
	7150 8000 7950 8000
Wire Wire Line
	8300 7500 8300 8000
Wire Wire Line
	7950 8000 8300 8000
Connection ~ 8300 8000
Wire Wire Line
	8300 8000 9100 8000
Wire Wire Line
	9450 7500 9450 8000
Connection ~ 9450 8000
Wire Wire Line
	9450 8000 10250 8000
$Comp
L LrE-6-rescue:C-Device C34
U 1 1 5D707270
P 9450 7350
F 0 "C34" H 9565 7396 50  0000 L CNN
F 1 "0.1u" H 9565 7305 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 9488 7200 50  0001 C CNN
F 3 "~" H 9450 7350 50  0001 C CNN
	1    9450 7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 7500 10650 8000
Connection ~ 10650 8000
Wire Wire Line
	10650 8000 11400 8000
Text Label 4900 7650 0    50   ~ 0
LED_DOUT
Text Label 6150 7650 0    50   ~ 0
LED1OUT
Text Label 7300 7650 0    50   ~ 0
LED2OUT
Text Label 8400 7650 0    50   ~ 0
LED3OUT
Text Label 9550 7650 0    50   ~ 0
LED4OUT
Text Label 10750 7650 0    50   ~ 0
LED5OUT
Text Label 10850 4100 0    50   ~ 0
LED_DOUT
NoConn ~ 7800 3350
NoConn ~ 7800 3750
NoConn ~ 7800 5150
Wire Wire Line
	14200 1450 14200 1650
Wire Wire Line
	13900 1150 14200 1150
$Comp
L LrE-6-rescue:C-Device C25
U 1 1 5C4910AD
P 14200 1300
F 0 "C25" H 14400 1400 50  0000 C CNN
F 1 "0.01u" H 14400 1300 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 14238 1150 50  0001 C CNN
F 3 "~" H 14200 1300 50  0001 C CNN
	1    14200 1300
	1    0    0    -1  
$EndComp
NoConn ~ 9100 4450
$Comp
L LrE-6-rescue:2N7002-Transistor_FET Q1
U 1 1 5D0213C1
P 10200 4350
F 0 "Q1" H 10406 4396 50  0000 L CNN
F 1 "2N7002" H 10406 4305 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 10400 4275 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7002.pdf" H 10200 4350 50  0001 L CNN
	1    10200 4350
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0121
U 1 1 5D0228D6
P 10300 4550
F 0 "#PWR0121" H 10300 4300 50  0001 C CNN
F 1 "GND" H 10305 4377 50  0000 C CNN
F 2 "" H 10300 4550 50  0001 C CNN
F 3 "" H 10300 4550 50  0001 C CNN
	1    10300 4550
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:R-Device R21
U 1 1 5D024220
P 10300 3800
F 0 "R21" H 10370 3846 50  0000 L CNN
F 1 "10K" H 10370 3755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 10230 3800 50  0001 C CNN
F 3 "~" H 10300 3800 50  0001 C CNN
	1    10300 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10300 4150 10300 4100
Wire Wire Line
	10000 3550 10300 3550
Wire Wire Line
	10300 3550 10300 3650
Wire Wire Line
	10300 4100 10850 4100
Connection ~ 10300 4100
Wire Wire Line
	10300 4100 10300 3950
Text Label 9200 4350 0    50   ~ 0
LED_DON
Text Label 10000 3550 0    50   ~ 0
VBUS
NoConn ~ 7800 3850
NoConn ~ 7800 5250
$Comp
L LrE-6-rescue:C-Device C30
U 1 1 5D54B231
P 5300 7350
F 0 "C30" H 5050 7400 50  0000 L CNN
F 1 "0.1u" H 5050 7300 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5338 7200 50  0001 C CNN
F 3 "~" H 5300 7350 50  0001 C CNN
	1    5300 7350
	1    0    0    -1  
$EndComp
Connection ~ 5300 7200
Wire Wire Line
	5700 8000 5300 8000
Wire Wire Line
	5300 8000 5300 7500
Wire Wire Line
	4900 7650 5400 7650
Wire Wire Line
	4900 7200 5300 7200
Wire Wire Line
	9100 4350 10000 4350
NoConn ~ 9100 4650
NoConn ~ 9100 4750
NoConn ~ 9100 4550
Wire Wire Line
	13200 6700 13200 7400
Connection ~ 13200 7400
Wire Wire Line
	13450 6700 13450 7250
Wire Wire Line
	13200 7400 13900 7400
Wire Wire Line
	13550 8200 13900 8200
Wire Wire Line
	13550 8650 13900 8650
Wire Wire Line
	13250 8200 13000 8200
Wire Wire Line
	13250 8650 13000 8650
Wire Wire Line
	13900 7700 12500 7700
Wire Wire Line
	13900 8800 13000 8800
Wire Wire Line
	13000 8650 13000 8800
Wire Wire Line
	13900 8350 13000 8350
Wire Wire Line
	13000 8200 13000 8350
Wire Wire Line
	13450 7250 13900 7250
Connection ~ 13450 7250
$Comp
L LrE-6-rescue:C-Device C28
U 1 1 5E946B99
P 15800 8950
F 0 "C28" H 15600 8800 50  0000 L CNN
F 1 "4.7u" H 15550 9050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 15838 8800 50  0001 C CNN
F 3 "~" H 15800 8950 50  0001 C CNN
	1    15800 8950
	-1   0    0    1   
$EndComp
$Comp
L LrE-6-rescue:C-Device C29
U 1 1 5E947AA4
P 15500 8950
F 0 "C29" H 15300 8800 50  0000 L CNN
F 1 "4.7u" H 15300 9050 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 15538 8800 50  0001 C CNN
F 3 "~" H 15500 8950 50  0001 C CNN
	1    15500 8950
	-1   0    0    1   
$EndComp
Text Label 12500 7700 0    50   ~ 0
NRST
$Comp
L LrE-6-rescue:C-Device C20
U 1 1 5EE6A509
P 14900 6550
F 0 "C20" H 14650 6450 50  0000 L CNN
F 1 "1u" H 14700 6650 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 14938 6400 50  0001 C CNN
F 3 "~" H 14900 6550 50  0001 C CNN
	1    14900 6550
	0    -1   -1   0   
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0114
U 1 1 5C4B6C52
P 14500 9100
F 0 "#PWR0114" H 14500 8850 50  0001 C CNN
F 1 "GND" H 14505 8927 50  0000 C CNN
F 2 "" H 14500 9100 50  0001 C CNN
F 3 "" H 14500 9100 50  0001 C CNN
	1    14500 9100
	1    0    0    -1  
$EndComp
Wire Wire Line
	14500 9000 14500 9100
$Comp
L LrE-6-rescue:GND-power #PWR0115
U 1 1 5E367F16
P 13750 6550
F 0 "#PWR0115" H 13750 6300 50  0001 C CNN
F 1 "GND" H 13755 6377 50  0000 C CNN
F 2 "" H 13750 6550 50  0001 C CNN
F 3 "" H 13750 6550 50  0001 C CNN
	1    13750 6550
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0116
U 1 1 5E3C3094
P 15200 9100
F 0 "#PWR0116" H 15200 8850 50  0001 C CNN
F 1 "GND" H 15205 8927 50  0000 C CNN
F 2 "" H 15200 9100 50  0001 C CNN
F 3 "" H 15200 9100 50  0001 C CNN
	1    15200 9100
	1    0    0    -1  
$EndComp
Wire Wire Line
	15100 8350 15200 8350
Wire Wire Line
	15200 9100 15200 8850
Wire Wire Line
	15800 7250 15800 8800
Wire Wire Line
	15500 7800 15500 8800
$Comp
L LrE-6-rescue:GND-power #PWR0117
U 1 1 5E4AEB5A
P 15250 6600
F 0 "#PWR0117" H 15250 6350 50  0001 C CNN
F 1 "GND" H 15255 6427 50  0000 C CNN
F 2 "" H 15250 6600 50  0001 C CNN
F 3 "" H 15250 6600 50  0001 C CNN
	1    15250 6600
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0118
U 1 1 5E4AEDFA
P 15800 9100
F 0 "#PWR0118" H 15800 8850 50  0001 C CNN
F 1 "GND" H 15805 8927 50  0000 C CNN
F 2 "" H 15800 9100 50  0001 C CNN
F 3 "" H 15800 9100 50  0001 C CNN
	1    15800 9100
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:GND-power #PWR0120
U 1 1 5E4AF14D
P 15500 9100
F 0 "#PWR0120" H 15500 8850 50  0001 C CNN
F 1 "GND" H 15505 8927 50  0000 C CNN
F 2 "" H 15500 9100 50  0001 C CNN
F 3 "" H 15500 9100 50  0001 C CNN
	1    15500 9100
	1    0    0    -1  
$EndComp
$Comp
L LrE-6-rescue:C-Device C27
U 1 1 5C4B998D
P 14050 6400
F 0 "C27" H 13800 6350 50  0000 L CNN
F 1 "1u" H 13850 6500 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 14088 6250 50  0001 C CNN
F 3 "~" H 14050 6400 50  0001 C CNN
	1    14050 6400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	15200 8550 15200 8350
Wire Wire Line
	15100 7800 15500 7800
Wire Wire Line
	15100 7250 15800 7250
Wire Wire Line
	14650 5500 14650 6550
Wire Wire Line
	15050 6550 15250 6550
Wire Wire Line
	15250 6550 15250 6600
Wire Wire Line
	13900 6400 13750 6400
Wire Wire Line
	13750 6400 13750 6550
Wire Wire Line
	14200 6400 14400 6400
Wire Wire Line
	14400 6400 14400 6800
Connection ~ 14650 6550
Wire Wire Line
	14650 6550 14650 6800
Wire Wire Line
	14650 6550 14750 6550
NoConn ~ 9100 5250
$Comp
L LrE-6:OLED-0.91 U3
U 1 1 5E1BA71E
P 14500 7900
F 0 "U3" H 14500 7950 50  0000 C CNN
F 1 "SSD1306_OLED_0.91" H 14500 7850 50  0000 C CNN
F 2 "LrE-6:OLED-9.1" H 14500 7900 50  0001 C CNN
F 3 "" H 14500 7900 50  0001 C CNN
	1    14500 7900
	1    0    0    -1  
$EndComp
NoConn ~ 15100 8150
Wire Wire Line
	12500 7250 13450 7250
Wire Wire Line
	12500 7400 13200 7400
Wire Wire Line
	13200 6400 13200 5500
$Comp
L Device:R R23
U 1 1 5EEE6BD3
P 14400 5850
F 0 "R23" H 14150 5950 50  0000 L CNN
F 1 "100" H 14150 5850 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 14330 5850 50  0001 C CNN
F 3 "~" H 14400 5850 50  0001 C CNN
	1    14400 5850
	1    0    0    -1  
$EndComp
$Comp
L Device:R R22
U 1 1 5EEE73A1
P 14050 6150
F 0 "R22" V 13843 6150 50  0000 C CNN
F 1 "1K" V 13934 6150 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 13980 6150 50  0001 C CNN
F 3 "~" H 14050 6150 50  0001 C CNN
	1    14050 6150
	0    1    1    0   
$EndComp
Wire Wire Line
	14400 6000 14400 6150
Connection ~ 14400 6400
Wire Wire Line
	14200 6150 14400 6150
Connection ~ 14400 6150
Wire Wire Line
	14400 6150 14400 6400
Wire Wire Line
	13900 6150 13750 6150
Wire Wire Line
	13750 6150 13750 6400
Connection ~ 13750 6400
Wire Wire Line
	13200 5500 13450 5500
Connection ~ 13200 5500
Wire Wire Line
	13200 5500 13200 5450
Connection ~ 13450 5500
Wire Wire Line
	13450 5500 14400 5500
Wire Wire Line
	14400 5700 14400 5500
Connection ~ 14400 5500
Wire Wire Line
	14400 5500 14650 5500
$EndSCHEMATC
