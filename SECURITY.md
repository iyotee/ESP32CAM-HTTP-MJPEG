# 🔒 Politique de Sécurité

## 🚨 Signaler une Vulnérabilité

Nous prenons la sécurité très au sérieux. Si vous découvrez une vulnérabilité de sécurité, merci de nous la signaler de manière responsable.

### Comment Signaler

**NE PAS** créer une issue publique pour les vulnérabilités de sécurité.

Au lieu de cela, envoyez un email à : [security@iyotee.dev](mailto:security@iyotee.dev)

### Informations à Inclure

- Description détaillée de la vulnérabilité
- Étapes pour reproduire le problème
- Impact potentiel
- Suggestions de correction (si applicable)

### Réponse

- **24h** : Accusé de réception
- **7 jours** : Évaluation initiale
- **30 jours** : Plan de correction
- **90 jours** : Correction publique

## 🛡️ Mesures de Sécurité Actuelles

### Authentification
- Aucune authentification par défaut (flux public)
- Configuration WiFi sécurisée
- Pas de stockage de mots de passe en clair

### Réseau
- Flux HTTP uniquement (pas HTTPS par défaut)
- Port configurable (défaut: 8554)
- Pas d'exposition de services sensibles

### Firmware
- Pas de backdoor ou de téléchargement distant
- Code source ouvert et auditable
- Basé sur des librairies open source éprouvées

## 🔧 Recommandations de Sécurité

### Pour les Utilisateurs

1. **Réseau WiFi**
   - Utilisez un réseau WiFi sécurisé (WPA2/WPA3)
   - Changez les identifiants WiFi par défaut
   - Isolez le réseau ESP32 si possible

2. **Accès Réseau**
   - Limitez l'accès au port 8554 si nécessaire
   - Utilisez un firewall pour restreindre l'accès
   - Surveillez les connexions réseau

3. **Mise à Jour**
   - Maintenez le firmware à jour
   - Surveillez les releases pour les corrections de sécurité
   - Testez les nouvelles versions avant déploiement

### Pour les Développeurs

1. **Code Review**
   - Toutes les contributions passent par une review
   - Vérification des bonnes pratiques de sécurité
   - Tests de sécurité avant merge

2. **Dépendances**
   - Surveillance des vulnérabilités dans les dépendances
   - Mise à jour régulière des librairies
   - Utilisation de versions stables uniquement

## 📋 Historique des Vulnérabilités

### Vulnérabilités Corrigées

Aucune vulnérabilité de sécurité majeure n'a été découverte à ce jour.

### Vulnérabilités Connues

Aucune vulnérabilité connue actuellement.

## 🔗 Ressources

- [Guide de Sécurité ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/security/index.html)
- [Bonnes Pratiques IoT](https://owasp.org/www-project-internet-of-things/)
- [CVE Database](https://cve.mitre.org/)

---

**Merci de contribuer à la sécurité de ce projet ! 🔒** 