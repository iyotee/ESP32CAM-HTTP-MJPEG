# 🤝 Guide de Contribution

Merci de votre intérêt pour contribuer au projet ESP32CAM-HTTP-MJPEG ! Ce document vous guidera à travers le processus de contribution.

## 📋 Table des Matières

- [Comment Contribuer](#comment-contribuer)
- [Types de Contributions](#types-de-contributions)
- [Standards de Code](#standards-de-code)
- [Processus de Développement](#processus-de-développement)
- [Tests](#tests)
- [Documentation](#documentation)
- [Questions et Support](#questions-et-support)

## 🚀 Comment Contribuer

### Prérequis

- Connaissance de base en C++
- Familiarité avec ESP32 et Arduino
- Compréhension des protocoles HTTP/MJPEG
- Git installé sur votre machine

### Étapes de Contribution

1. **Fork le projet**
   ```bash
   git clone https://github.com/VOTRE_USERNAME/ESP32CAM-HTTP-MJPEG.git
   cd ESP32CAM-HTTP-MJPEG
   ```

2. **Créez une branche**
   ```bash
   git checkout -b feature/votre-fonctionnalite
   # ou pour un bug fix
   git checkout -b fix/nom-du-bug
   ```

3. **Développez votre fonctionnalité**
   - Suivez les [standards de code](#standards-de-code)
   - Ajoutez des tests si nécessaire
   - Mettez à jour la documentation

4. **Testez votre code**
   ```bash
   pio run -t upload
   pio device monitor
   ```

5. **Commitez vos changements**
   ```bash
   git add .
   git commit -m "feat: ajout de la fonctionnalité X"
   ```

6. **Poussez vers votre fork**
   ```bash
   git push origin feature/votre-fonctionnalite
   ```

7. **Créez une Pull Request**
   - Allez sur GitHub
   - Cliquez sur "New Pull Request"
   - Remplissez le template de PR

## 🎯 Types de Contributions

### 🐛 Corrections de Bugs

- **Critique** : Bugs qui cassent le fonctionnement de base
- **Important** : Bugs qui affectent l'expérience utilisateur
- **Mineur** : Bugs cosmétiques ou d'interface

**Format des commits** : `fix: description du bug`

### ✨ Nouvelles Fonctionnalités

- **Fonctionnalités majeures** : Nouvelles capacités importantes
- **Améliorations** : Optimisations de fonctionnalités existantes
- **Fonctionnalités mineures** : Petites améliorations

**Format des commits** : `feat: description de la fonctionnalité`

### 📚 Documentation

- Amélioration du README
- Ajout d'exemples d'utilisation
- Documentation technique
- Guides de dépannage

**Format des commits** : `docs: description de la documentation`

### 🔧 Configuration et Build

- Amélioration de `platformio.ini`
- Optimisation des dépendances
- Configuration de l'environnement

**Format des commits** : `config: description de la configuration`

## 📝 Standards de Code

### Style de Code C++

```cpp
// Bon exemple
void startCamera() {
    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_0;
    config.ledc_timer = LEDC_TIMER_0;
    // ... configuration
}

// Mauvais exemple
void startCamera(){
    camera_config_t config;
    config.ledc_channel=LEDC_CHANNEL_0;
    config.ledc_timer=LEDC_TIMER_0;
    // ... configuration
}
```

### Conventions de Nommage

- **Fonctions** : `camelCase` (ex: `startCamera()`)
- **Variables** : `snake_case` (ex: `camera_config`)
- **Constantes** : `UPPER_SNAKE_CASE` (ex: `RTSP_PORT`)
- **Classes** : `PascalCase` (ex: `MicroRTSP`)

### Commentaires

```cpp
// Commentaire simple sur une ligne

/*
 * Commentaire multi-lignes
 * pour expliquer des sections complexes
 */

/**
 * Documentation de fonction
 * @param param1 Description du paramètre
 * @return Description du retour
 */
```

### Structure des Fichiers

```
src/
├── main.cpp              # Point d'entrée principal
├── micro-rtsp.cpp       # Implémentation RTSP
├── micro-rtsp.h         # Interface RTSP
└── camera_pins.h        # Configuration broches
```

## 🔄 Processus de Développement

### Workflow Git

1. **Main** : Branche stable, toujours fonctionnelle
2. **Develop** : Branche de développement (si applicable)
3. **Feature branches** : Branches pour nouvelles fonctionnalités
4. **Hotfix branches** : Branches pour corrections urgentes

### Messages de Commit

Utilisez le format conventionnel :

```
type(scope): description courte

Description détaillée si nécessaire

Fixes #123
```

**Types** :
- `feat` : Nouvelle fonctionnalité
- `fix` : Correction de bug
- `docs` : Documentation
- `style` : Formatage
- `refactor` : Refactoring
- `test` : Tests
- `config` : Configuration

### Pull Request Template

```markdown
## Description
Brève description des changements

## Type de changement
- [ ] Bug fix
- [ ] Nouvelle fonctionnalité
- [ ] Documentation
- [ ] Configuration

## Tests
- [ ] Code testé localement
- [ ] Tests ajoutés/mis à jour

## Checklist
- [ ] Code suit les standards du projet
- [ ] Documentation mise à jour
- [ ] Tests passent
- [ ] Pas de régression introduite
```

## 🧪 Tests

### Tests Locaux

```bash
# Compilation
pio run

# Upload et test
pio run -t upload
pio device monitor
```

### Tests de Compatibilité

- [ ] ESP32-CAM AI-Thinker
- [ ] ESP32-CAM-MB
- [ ] ESP32-CAM-01M
- [ ] Différentes résolutions
- [ ] Différentes qualités JPEG

### Tests d'Intégration

- [ ] VLC Media Player
- [ ] FFmpeg
- [ ] Procastreamation
- [ ] Home Assistant
- [ ] Navigateurs web

## 📖 Documentation

### Mise à Jour du README

- Ajoutez des sections si nécessaire
- Mettez à jour les exemples
- Vérifiez les liens
- Ajoutez des captures d'écran si pertinent

### Documentation Technique

- Commentaires dans le code
- Documentation des APIs
- Guides de configuration
- Exemples d'utilisation

## ❓ Questions et Support

### Avant de Contribuer

1. **Vérifiez les Issues existantes**
2. **Lisez la documentation**
3. **Testez sur votre matériel**
4. **Posez des questions si nécessaire**

### Où Demander de l'Aide

- **Issues GitHub** : Pour bugs et fonctionnalités
- **Discussions GitHub** : Pour questions générales
- **Wiki** : Pour documentation collaborative

### Ressources Utiles

- [Documentation ESP32](https://docs.espressif.com/projects/esp-idf/)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [Arduino Reference](https://www.arduino.cc/reference/)

## 🎉 Reconnaissance

Toutes les contributions sont appréciées ! Les contributeurs seront mentionnés dans :

- Le fichier CONTRIBUTORS.md
- Les releases GitHub
- La documentation du projet

---

**Merci de contribuer à ESP32CAM-HTTP-MJPEG ! 🚀** 