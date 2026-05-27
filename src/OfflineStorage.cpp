#include "OfflineStorage.h"

OfflineStorage::OfflineStorage(Stream &log)
    : PrintLog(log, "OfflineStorage"), _rtc(Wire) {}

bool OfflineStorage::begin(TwoWire &wire) {
  if (_isBegin) {
    logInfo("Already initialized");
    return true;
  }

  _rtc.Begin();

  if (!_rtc.GetIsRunning()) {
    logError("RTC is not running or not found");
    return false;
  }

  _isBegin = true;
  logInfo("RTC initialized");
  return true;
}

void OfflineStorage::handle(void) {
  if (!_isBegin) {
    logError("Not initialized");
    return;
  }

  logInfo("WiFi unavailable, offline mode active");
}
