/*
  The MIT License

  Copyright (c) 2020 David Hoy david@thehoys.com

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

/*
  Inherited NMEA2000 object for PIC32MX internal CAN
  based setup. See also NMEA2000 library.
*/

#ifndef _NMEA2000_PIC32MX_H_
#define _NMEA2000_PIC32MX_H_

#include <NMEA2000.h> 
#include <N2kMsg.h>


class tNMEA2000_pic32mx : public tNMEA2000
{
protected:
    uint16_t DefTimeOut; 
    uint8_t NumTxMailBoxes;
    
    bool CANSendFrame(unsigned long id, unsigned char len, const unsigned char *buf, bool wait_sent);
    bool CANOpen();
    bool CANGetFrame(unsigned long &id, unsigned char &len, unsigned char *buf);
    void InitCANFrameBuffers();
  
public:
    tNMEA2000_pic32mx(uint16_t _DefTimeOut=4, uint8_t CANBusIndex=0);
};

#endif
