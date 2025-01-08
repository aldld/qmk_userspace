
#define HCS(report)                                         \
    host_consumer_send(record->event.pressed ? report : 0); \
    return false
