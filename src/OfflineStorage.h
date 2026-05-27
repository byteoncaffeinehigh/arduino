#ifndef _OFFLINE_STORAGE_H_
#define _OFFLINE_STORAGE_H_

#include <Arduino.h>
#include "Main/PrintLog.h"

class OfflineStorage : public PrintLog {
public:
  OfflineStorage(Stream &log);

  void handle(void);
};

#endif /** _OFFLINE_STORAGE_H_ */
