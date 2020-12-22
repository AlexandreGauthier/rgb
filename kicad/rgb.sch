EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5500 1350 5500 1400
$Comp
L power:GND #PWR0101
U 1 1 5FE3CA70
P 5500 1400
F 0 "#PWR0101" H 5500 1150 50  0001 C CNN
F 1 "GND" H 5505 1227 50  0000 C CNN
F 2 "" H 5500 1400 50  0001 C CNN
F 3 "" H 5500 1400 50  0001 C CNN
	1    5500 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 950  5500 900 
Wire Wire Line
	5500 900  6000 900 
Text Label 6000 900  2    50   ~ 0
DRAIN_1
Wire Wire Line
	5500 2350 5500 2400
$Comp
L power:GND #PWR0102
U 1 1 5FE3FFDC
P 5500 2400
F 0 "#PWR0102" H 5500 2150 50  0001 C CNN
F 1 "GND" H 5505 2227 50  0000 C CNN
F 2 "" H 5500 2400 50  0001 C CNN
F 3 "" H 5500 2400 50  0001 C CNN
	1    5500 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 1950 5500 1900
Wire Wire Line
	5500 1900 6000 1900
Text Label 6000 1900 2    50   ~ 0
DRAIN_2
Wire Wire Line
	4900 2150 5200 2150
Text Label 4900 2150 0    50   ~ 0
PWM_2
$Comp
L Device:Q_NMOS_GSD Q2
U 1 1 5FE3FFD3
P 5400 2150
F 0 "Q2" H 5605 2196 50  0000 L CNN
F 1 "PMV15ENEA" H 5605 2105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 5600 2250 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PMV15ENEA.pdf" H 5400 2150 50  0001 C CNN
	1    5400 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1150 5200 1150
Text Label 4900 1150 0    50   ~ 0
PWM_1
$Comp
L Device:Q_NMOS_GSD Q1
U 1 1 5FE256DE
P 5400 1150
F 0 "Q1" H 5605 1196 50  0000 L CNN
F 1 "PMV15ENEA" H 5605 1105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23_Handsoldering" H 5600 1250 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/PMV15ENEA.pdf" H 5400 1150 50  0001 C CNN
	1    5400 1150
	1    0    0    -1  
$EndComp
$Comp
L ATTINY404-SSNR:ATTINY404-SSNR U1
U 1 1 5FE13C65
P 1490 1450
F 0 "U1" H 2690 1937 60  0000 C CNN
F 1 "ATTINY404-SSNR" H 2690 1831 60  0000 C CNN
F 2 "rgb_footprints:ATTINY404-SSNR" H 2690 1790 60  0001 C CNN
F 3 "https://ww1.microchip.com/downloads/en/DeviceDoc/ATtiny204-404-DataSheet-DS50002687B.pdf" H 2690 1831 60  0001 C CNN
	1    1490 1450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
