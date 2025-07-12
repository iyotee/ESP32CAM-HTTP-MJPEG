# 📷 ESP32-CAM HTTP MJPEG Streamer

[![PlatformIO](https://img.shields.io/badge/PlatformIO-Project-blue.svg)](https://platformio.org/)
[![ESP32](https://img.shields.io/badge/ESP32-Compatible-green.svg)](https://www.espressif.com/en/products/socs/esp32)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

Un firmware minimal et optimisé pour ESP32-CAM qui diffuse un flux vidéo HTTP MJPEG compatible avec tous les outils vidéo modernes (VLC, FFmpeg, Procastreamation, Home Assistant, etc.).

## 🎯 Objectifs

- ✅ **Simplicité** : Firmware minimal et facile à flasher
- ✅ **Compatibilité** : Flux HTTP MJPEG standard compatible avec tous les outils
- ✅ **Performance** : Optimisé pour une diffusion fluide en temps réel
- ✅ **Intégration** : Compatible avec Procastreamation et autres systèmes de surveillance
- ✅ **Open Source** : Basé sur des librairies open source éprouvées

## 🛠️ Matériel Compatible

### Caméras Supportées
- **ESP32-CAM AI-Thinker** (recommandé)
- **ESP32-CAM-MB** 
- **ESP32-CAM-01M**
- **Toutes les variantes ESP32-CAM** avec le même brochage

### Connectivité
- **WiFi** : 2.4GHz (802.11 b/g/n)
- **Port** : HTTP sur port 8554 (configurable)
- **Protocole** : HTTP MJPEG standard

## 📦 Contenu du Projet

```
ESP32CAM-HTTP-MJPEG/
├── src/
│   ├── main.cpp              # Code principal du firmware
│   ├── micro-rtsp.cpp        # Implémentation du serveur HTTP MJPEG
│   ├── micro-rtsp.h          # Interface du serveur HTTP MJPEG
│   └── camera_pins.h         # Configuration des broches caméra
├── platformio.ini            # Configuration PlatformIO
├── .gitignore               # Fichiers à ignorer par Git
└── README.md               # Ce fichier
```

## 🚀 Installation Rapide

### Prérequis
- **PlatformIO** : Extension VSCode ou installation via `pip install platformio`
- **ESP32-CAM** : Caméra compatible
- **Câble USB** : Pour la programmation et l'alimentation

### Étapes d'Installation

1. **Cloner le projet**
   ```bash
   git clone https://github.com/iyotee/ESP32CAM-HTTP-MJPEG.git
   cd ESP32CAM-HTTP-MJPEG
   ```

2. **Configurer le WiFi**
   Éditez `src/main.cpp` et modifiez les paramètres WiFi :
   ```cpp
   const char *ssid = "VOTRE_SSID_WIFI";
   const char *password = "VOTRE_MOT_DE_PASSE_WIFI";
   ```

3. **Flasher le firmware**
   ```bash
   pio run -t upload
   ```

4. **Vérifier la connexion**
   Ouvrez le moniteur série (115200 bauds) pour voir l'adresse IP :
   ```bash
   pio device monitor
   ```

## 📺 Utilisation

### Accès au Flux Vidéo

Une fois flasher, votre ESP32-CAM sera accessible via :

- **URL MJPEG** : `http://<IP_ESP32>:8554/`
- **Format** : HTTP MJPEG standard
- **Résolution** : 640x480 (configurable)
- **FPS** : ~20 FPS (configurable)

### Exemples d'Utilisation

#### Avec VLC
```
vlc http://192.168.1.100:8554/
```

#### Avec FFmpeg
```bash
ffmpeg -i "http://192.168.1.100:8554/" -c copy output.mp4
```

#### Avec Procastreamation
Ajoutez une caméra avec l'URL : `http://192.168.1.100:8554/`

#### Avec Home Assistant
```yaml
camera:
  - platform: mjpeg
    name: ESP32-CAM
    mjpeg_url: http://192.168.1.100:8554/
```

## ⚙️ Configuration

### Paramètres Modifiables

Dans `src/main.cpp`, vous pouvez ajuster :

```cpp
// Configuration WiFi
const char *ssid = "VOTRE_SSID";
const char *password = "VOTRE_MOT_DE_PASSE";

// Configuration caméra
config.frame_size = FRAMESIZE_VGA;  // Résolution
config.jpeg_quality = 12;           // Qualité (0-63)
config.xclk_freq_hz = 20000000;    // Fréquence d'horloge

// Configuration serveur
#define RTSP_PORT 8554              // Port HTTP
```

### Résolutions Disponibles

- `FRAMESIZE_QQVGA` : 160x120
- `FRAMESIZE_QVGA` : 320x240
- `FRAMESIZE_VGA` : 640x480 (défaut)
- `FRAMESIZE_SVGA` : 800x600
- `FRAMESIZE_XGA` : 1024x768

### Qualité JPEG

- **0-10** : Qualité excellente (gros fichiers)
- **10-20** : Qualité très bonne (recommandé)
- **20-30** : Qualité bonne
- **30-63** : Qualité faible (petits fichiers)

## 🔧 Dépannage

### Problèmes Courants

#### L'ESP32 ne se connecte pas au WiFi
- Vérifiez les identifiants WiFi dans `main.cpp`
- Assurez-vous que le réseau WiFi est en 2.4GHz
- Vérifiez la distance et la puissance du signal

#### Le flux vidéo ne s'affiche pas
- Vérifiez l'adresse IP dans le moniteur série
- Testez l'URL dans un navigateur : `http://<IP>:8554/`
- Vérifiez que le port 8554 n'est pas bloqué par un firewall

#### Image de mauvaise qualité
- Ajustez `jpeg_quality` dans `main.cpp` (0 = meilleure qualité)
- Vérifiez l'éclairage de la scène
- Ajustez la résolution selon vos besoins

#### Déconnexions fréquentes
- Vérifiez la stabilité de l'alimentation (USB recommandé)
- Réduisez la qualité JPEG pour diminuer la charge
- Vérifiez la stabilité de la connexion WiFi

### Logs de Débogage

Le firmware affiche des informations utiles sur le port série :
- Adresse IP obtenue
- Statut de la connexion WiFi
- Connexions clients
- Erreurs éventuelles

## 📚 API Technique

### Endpoints HTTP

| Endpoint | Description | Format |
|----------|-------------|---------|
| `/` | Flux MJPEG principal | `multipart/x-mixed-replace` |
| `/status` | Statut du serveur | `application/json` |

### Headers HTTP

Le serveur envoie les headers suivants :
```
HTTP/1.1 200 OK
Content-Type: multipart/x-mixed-replace; boundary=frame
Cache-Control: no-cache
Connection: close
```

### Format MJPEG

Chaque frame est envoyée avec :
```
--frame
Content-Type: image/jpeg
Content-Length: <taille>
<données_jpeg>
```

## 🤝 Contribution

Nous accueillons toutes les contributions ! Voici comment participer :

### Comment Contribuer

1. **Fork** le projet
2. **Créez** une branche pour votre fonctionnalité (`git checkout -b feature/AmazingFeature`)
3. **Commitez** vos changements (`git commit -m 'Add some AmazingFeature'`)
4. **Push** vers la branche (`git push origin feature/AmazingFeature`)
5. **Ouvrez** une Pull Request

### Types de Contributions

- 🐛 **Correction de bugs**
- ✨ **Nouvelles fonctionnalités**
- 📚 **Amélioration de la documentation**
- 🎨 **Amélioration de l'interface**
- ⚡ **Optimisations de performance**
- 🔧 **Amélioration de la configuration**

### Standards de Code

- Suivez les conventions de nommage C++
- Ajoutez des commentaires pour les parties complexes
- Testez vos modifications avant de soumettre
- Mettez à jour la documentation si nécessaire

## 📄 Licence

Ce projet est sous licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

## 🙏 Remerciements

Ce projet est basé sur :
- **[Micro-RTSP](https://github.com/geeksville/Micro-RTSP)** par Geeksville
- **[esp32-camera](https://github.com/espressif/esp32-camera)** par Espressif
- **[PlatformIO](https://platformio.org/)** pour l'environnement de développement

## 📞 Support

### Ressources Utiles

- 📖 **Documentation ESP32-CAM** : [Espressif](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/peripherals/camera.html)
- 🔧 **PlatformIO** : [Documentation officielle](https://docs.platformio.org/)
- 💬 **Communauté** : [Forum ESP32](https://esp32.com/)

### Signaler un Bug

Si vous rencontrez un problème :
1. Vérifiez les [Issues existantes](https://github.com/iyotee/ESP32CAM-HTTP-MJPEG/issues)
2. Créez une nouvelle Issue avec :
   - Description détaillée du problème
   - Étapes pour reproduire
   - Logs du port série
   - Configuration matérielle

### Demander une Fonctionnalité

Pour suggérer une nouvelle fonctionnalité :
1. Créez une Issue avec le label `enhancement`
2. Décrivez clairement le besoin
3. Expliquez l'impact sur les utilisateurs

---

**⭐ Si ce projet vous est utile, n'oubliez pas de le star sur GitHub !**

---

*Développé avec ❤️ pour la communauté ESP32 et la surveillance vidéo open source.* 