#include "micro-rtsp.h"
#include "esp_camera.h"

MicroRTSP::MicroRTSP() : _port(8554) {}

void MicroRTSP::begin(int port)
{
    _port = port;
}

void MicroRTSP::handleClient(WiFiClient &client)
{
    // Attendre une requête HTTP GET
    while (client.connected() && !client.available())
    {
        delay(1);
    }
    if (!client.connected())
        return;

    String req = client.readStringUntil('\r');
    if (req.indexOf("GET") < 0)
    {
        client.stop();
        return;
    }

    // Envoyer l'en-tête HTTP MJPEG
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: multipart/x-mixed-replace; boundary=frame");
    client.println();

    // Boucle d'envoi MJPEG
    while (client.connected())
    {
        camera_fb_t *fb = esp_camera_fb_get();
        if (!fb)
            continue;

        client.println("--frame");
        client.println("Content-Type: image/jpeg");
        client.print("Content-Length: ");
        client.println(fb->len);
        client.println();
        client.write(fb->buf, fb->len);
        client.println();

        esp_camera_fb_return(fb);
        delay(50); // ~20 FPS
    }
}
