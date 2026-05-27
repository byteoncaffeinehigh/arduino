#include "OfflineStorage.h"

OfflineStorage::OfflineStorage(Stream &log)
    : PrintLog(log, "OfflineStorage"), _rtc(Wire) {}

bool OfflineStorage::begin(TwoWire &wire) {
  if (_isBegin) {
    return true;
  }

  if (!_rtc.GetIsRunning()) {
    _rtc.SetIsRunning(true);
  }

  if (_rtc.LastError() != 0) {
    logError("RTC not found on I2C bus");
    return false;
  }

  _isBegin = true;
  logInfo("RTC initialized");
  return true;
}

void OfflineStorage::handle(const String &payload) {
  if (!_isBegin) {
    logError("Not initialized");
    return;
  }

  RtcDateTime now = _rtc.GetDateTime();
  uint32_t timestamp = now.TotalSeconds();

  logInfo("ts=" + String(timestamp) + " " + payload);
}
