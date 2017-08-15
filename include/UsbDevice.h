#ifndef USB_DEVICE_H
#define USB_DEVICE_H

class UsbDevice
{
public:
    static HANDLE getDeviceHandle(unsigned short vendor, unsigned short product, unsigned int MI = 0x0000);
	static void readDataFromDevice(HANDLE hFile, unsigned char* buf, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped);

private:
	static bool	IsMatchingDevice(wchar_t *pDeviceID, unsigned int uiVID, unsigned int uiPID, unsigned int uiMI);
};

// all of the conversions all based on big endian
// convert 4 bytes to float
float getFloat(unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3);
// convert 2 bytes to short
int getShort(unsigned char b0, unsigned char b1);
// convert 4 bytes to unsigned int
double getUnsignedInt(unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3);
// convert 4 bytes to int
double getInt(unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3);

#endif
