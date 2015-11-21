#include <stdio.h>
#include <string>
#include <iostream>
#include <conio.h>
#include "bot_control.h"

using namespace std;


serial comm; //serial is a class type defined in these files, used for referring to the communication device
void main() {
	char data; //To store the character to send
	string manuel = "hola";
	comm.startDevice("COM5", 57600);
	/* “COM 2” refers to the com port in which the USB to SERIAL port is attached. It is shown by right clicking on my computer, then going to properties and then device manager
	9600 is the baud-rate in bits per second */
	
	for (char &x:manuel)
		comm.send_data(x); //The data is sent through the port
	std:getline(cin, manuel);
	for(char &x:manuel)
		comm.send_data(x);

	while (1){
		data = comm.get_data();
	}

	comm.stopDevice(); //The device is closed down
	_getch();
}