#include "OfflineStorage.h"

OfflineStorage::OfflineStorage(Stream &log) : PrintLog(log, "OfflineStorage") {}

void OfflineStorage::handle(void) {
  logInfo("WiFi unavailable, offline mode active");
}
