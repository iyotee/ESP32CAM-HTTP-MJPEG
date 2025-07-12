#ifndef MICRO_RTSP_H
#define MICRO_RTSP_H

#include <WiFiClient.h>

class MicroRTSP
{
public:
    MicroRTSP();
    void begin(int port = 8554);
    void handleClient(WiFiClient &client);

private:
    int _port;
    void sendRTSPHeaders(WiFiClient &client);
    void sendMJPEGFrame(WiFiClient &client, const uint8_t *buf, size_t len);
};

#endif // MICRO_RTSP_H
