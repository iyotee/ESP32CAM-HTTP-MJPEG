/*
 * ESP32-CAM RTSP H264 Firmware Minimal
 * Compatible Procastreamation, FFmpeg, VLC, Home Assistant
 * Basé sur Micro-RTSP et esp32-camera
 *
 * Instructions :
 * - Configurez votre WiFi ci-dessous
 * - Flashez avec PlatformIO
 * - Ouvrez le port série (115200 bauds) pour voir l'IP et l'URL RTSP
 * - Flux RTSP : rtsp://<IP_ESP32>:8554/h264
 */

#include <WiFi.h>
#include "esp_camera.h"
#include "micro-rtsp.h"

// === CONFIG WIFI ===
const char *ssid = "VOTRE_SSID";
const char *password = "VOTRE_MOT_DE_PASSE";

// === CONFIG CAMERA ===
#define CAMERA_MODEL_AI_THINKER
#include "camera_pins.h"

// === CONFIG RTSP ===
#define RTSP_PORT 8554

// === OBJETS GLOBAUX ===
WiFiServer rtspServer(RTSP_PORT);
MicroRTSP rtsp;

void startCamera()
{
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sccb_sda = SIOD_GPIO_NUM;
  config.pin_sccb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA; // 640x480
  config.jpeg_quality = 12;          // 0-63 (0 = meilleur)
  config.fb_count = 2;

  // Initialisation caméra
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK)
  {
    Serial.printf("Erreur init caméra: 0x%x\n", err);
    while (1)
      delay(1000);
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(1000);
  Serial.println();
  Serial.println("ESP32-CAM RTSP H264 - Procastreamation Edition");

  // Connexion WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connexion WiFi");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Démarrage caméra
  startCamera();

  // Démarrage serveur HTTP MJPEG
  rtspServer.begin();
  Serial.printf("Flux MJPEG disponible: http://%s:%d/\n", WiFi.localIP().toString().c_str(), RTSP_PORT);
}

void loop()
{
  WiFiClient client = rtspServer.available();
  if (client)
  {
    Serial.println("Client RTSP connecté");
    rtsp.handleClient(client);
  }
  delay(10);
}
