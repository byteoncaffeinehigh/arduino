#ifndef _OFFLINE_STORAGE_H_
#define _OFFLINE_STORAGE_H_

#include <Arduino.h>
#include <Wire.h>
#include <RtcDS3231.h>
#include "Main/PrintLog.h"

class OfflineStorage : public PrintLog {
private:
  RtcDS3231<TwoWire> _rtc;
  bool _isBegin = false;

public:
  OfflineStorage(Stream &log);

  bool begin(TwoWire &wire);
  void handle(void);
};

#endif /** _OFFLINE_STORAGE_H_ */
