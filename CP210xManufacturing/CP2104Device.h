/*
 * CP2104Device.h
 *
 *  Created on: Oct 29, 2012
 *      Author: strowlan
 */

#ifndef CP2104DEVICE_H_
#define CP2104DEVICE_H_

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include "libusb.h"
#include "CP210xManufacturing.h"
#include "CP210xDevice.h"

/////////////////////////////////////////////////////////////////////////////
// CCP210xDevice Class
/////////////////////////////////////////////////////////////////////////////

class CCP2104Device : public CCP210xDevice {
    // Public Methods
public:

    CCP2104Device(libusb_device_handle* h);

    virtual CP210x_STATUS GetDeviceManufacturerString(LPVOID lpManufacturer, LPBYTE lpbLength, BOOL bConvertToASCII = true);
    virtual CP210x_STATUS GetDeviceInterfaceString(BYTE bInterfaceNumber, LPVOID lpInterface, LPBYTE lpbLength, BOOL bConvertToASCII);
    virtual CP210x_STATUS GetFlushBufferConfig(LPWORD lpwFlushBufferConfig);
    virtual CP210x_STATUS GetDeviceMode(LPBYTE lpbDeviceModeECI, LPBYTE lpbDeviceModeSCI);
    virtual CP210x_STATUS GetBaudRateConfig(BAUD_CONFIG* baudConfigData);
    virtual CP210x_STATUS GetPortConfig(PORT_CONFIG* PortConfig);
    virtual CP210x_STATUS GetDualPortConfig(DUAL_PORT_CONFIG* DualPortConfig);
    virtual CP210x_STATUS GetQuadPortConfig(QUAD_PORT_CONFIG* QuadPortConfig);
    virtual CP210x_STATUS GetLockValue(LPBYTE lpbLockValue);


    virtual CP210x_STATUS SetManufacturerString(LPVOID lpvManufacturer, BYTE bLength, BOOL bConvertToUnicode = true);
    virtual CP210x_STATUS SetInterfaceString(BYTE bInterfaceNumber, LPVOID lpvInterface, BYTE bLength, BOOL bConvertToUnicode);
    virtual CP210x_STATUS SetFlushBufferConfig(WORD wFlushBufferConfig);
    virtual CP210x_STATUS SetDeviceMode(BYTE bDeviceModeECI, BYTE bDeviceModeSCI);
    virtual CP210x_STATUS SetBaudRateConfig(BAUD_CONFIG* baudConfigData);
    virtual CP210x_STATUS SetPortConfig(PORT_CONFIG* PortConfig);
    virtual CP210x_STATUS SetDualPortConfig(DUAL_PORT_CONFIG* DualPortConfig);
    virtual CP210x_STATUS SetQuadPortConfig(QUAD_PORT_CONFIG* QuadPortConfig);
    virtual CP210x_STATUS SetLockValue();

};



#endif /* CP2104DEVICE_H_ */
