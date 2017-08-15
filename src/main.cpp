#include <WinSock2.h>  
#include <set>
#include <stdio.h>
#include <tchar.h>
#include <wtypes.h>
#include <hidsdi.h>
#include <string>
#include <iostream>

#include "UsbDevice.h"

#pragma comment(lib, "ws2_32.lib")  

#define vendorID 0x483
#define productID 0x5750
#define msgLen 33

using namespace std;

int main(int argc, char **argv) {
	// message length = 32
	unsigned char buf[32];
	HANDLE deviceHandle = UsbDevice::getDeviceHandle(vendorID, productID);
	if (!deviceHandle) {
		std::cout << "Device is not detected! Please try again!!!" << std::endl;
		return 1;
	}

	// len = message length + 1
	DWORD len = msgLen;

	// for FILE_FLAG_OVERLAPPED mode
	OVERLAPPED osReader = { 0 }; 
	osReader.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (osReader.hEvent == NULL)
	{
		std::cout << "creating overlapped event; abort." << std::endl;
		return 1;
	}
	
	while (true) {		
		// read message from device
		//UsbDevice::readDataFromDevice(deviceHandle, buf, len, &len, &osReader); // use this if using FILE_FLAG_OVERLAPPED mode
		UsbDevice::readDataFromDevice(deviceHandle, buf, len, &len, NULL);
		
		string msg("");
		for (int i = 0; i < len; ++i) {
			msg += to_string(buf[i]) + ",";
		}
	std:cout << "Received message: " << msg.substr(0, msg.length() - 1) << std::endl;
	}
	

	return 0;
}
