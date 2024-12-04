# BE_POO_Template


# Menu.cpp Documentation

Le fichier `Menu.cpp` contient la logique pour un menu interactif sur un écran LCD avec un potentiomètre et un bouton, permettant de naviguer entre différentes options et d'interagir avec des instruments musicaux. Ce code est utilisé dans un projet de gestion d'instruments où l'utilisateur peut ajouter des instruments, les sélectionner et jouer une mélodie. 

## Fonctionnalités Principales

- **Affichage du menu principal** : L'utilisateur peut choisir entre différentes options, comme jouer une mélodie ou ajouter un instrument.
- **Navigation avec un potentiomètre** : Utilisation d'un potentiomètre pour naviguer dans les options du menu.
- **Sélection avec un bouton** : Un bouton est utilisé pour sélectionner l'option mise en surbrillance sur l'écran LCD.
- **Gestion dynamique des instruments** : Les instruments peuvent être ajoutés et sélectionnés pour jouer une mélodie.
- **Antirebond pour le bouton** : La gestion de l'entrée du bouton pour éviter les erreurs de lecture dues à un appui rapide.

## Description des Fonctions

### 1. **Menu::init()**
   **Description** : 
   - Initialise les broches pour le potentiomètre et le bouton, ainsi que l'écran LCD.
   - Crée des objets d'instruments s'ils ne sont pas déjà présents.

   **Paramètres** :
   - Aucun.

   **Retour** :
   - Aucun.

### 2. **Menu::update()**
   **Description** :
   - Met à jour l'écran LCD en fonction de l'état actuel du menu.
   - Effectue des actions en fonction de la sélection dans le menu et de l'état du bouton.

   **Paramètres** :
   - Aucun.

   **Retour** :
   - Aucun.

### 3. **Menu::displayMainMenu()**
   **Description** :
   - Affiche le menu principal avec les options "Jouer Musique" et "Ajouter Instrument".
   - Gère la navigation entre les options via le potentiomètre et la sélection avec le bouton.

   **Paramètres** :
   - Aucun.

   **Retour** :
   - Aucun.

### 4. **Menu::displayMenuInstrument()**
   **Description** :
   - Affiche la liste des instruments disponibles pour la sélection.
   - Met à jour l'écran LCD en fonction de l'instrument sélectionné à l'aide du potentiomètre.

   **Paramètres** :
   - Aucun.

   **Retour** :
   - Aucun.

### 5. **Menu::handleSelection()**
   **Description** :
   - Gère la sélection d'un instrument.
   - Affiche un message confirmant l'instrument sélectionné.

   **Paramètres** :
   - Aucun.

   **Retour** :
   - Aucun.

### 6. **Menu::handlePlacement()**
   **Description** :
   - Gère le placement d'un instrument sur une position spécifique (de 1 à 16) en utilisant le potentiomètre.
   - Le bouton permet de confirmer la position et de placer l'instrument.

   **Paramètres** :
   - Aucun.

   **Retour** :
   - Aucun.

### 7. **Menu::displayPlacementMenu()**
   **Description** :
   - Affiche l'interface pour choisir une position où placer un instrument.

   **Paramètres** :
   - `position` (int) : La position où l'instrument doit être placé.

   **Retour** :
   - Aucun.

### 8. **Menu::placeInstrument()**
   **Description** :
   - Place un instrument dans la liste de lecture (`Lecture`) à une position spécifiée.
   - Émet un son pour confirmer l'ajout de l'instrument.

   **Paramètres** :
   - `position` (int) : L'indice où l'instrument doit être placé dans la liste de lecture.

   **Retour** :
   - Aucun.

### 9. **Menu::jouerMelodie()**
   **Description** :
   - Joue une mélodie en émettant les sons des instruments dans la liste de lecture.
   - Les instruments sont joués avec un tempo défini entre chaque note.

   **Paramètres** :
   - `tempo` (int) : Le tempo en millisecondes entre chaque note.

   **Retour** :
   - Aucun.

---

## Utilisation

### Initialisation

Dans la fonction `init()`, vous devez initialiser les broches du potentiomètre et du bouton, ainsi que l'écran LCD :

```cpp
Menu menu(potPin, buttonPin, lcd);
menu.init();
```

### Mise à jour

Appeler la fonction `update()` dans la boucle principale (`loop()`) pour mettre à jour l'écran et gérer les interactions :

```cpp
void loop() {
    menu.update();
}
```

### Ajouter des Instruments

Les instruments peuvent être ajoutés à la liste dans la fonction `init()`. Si vous souhaitez ajouter d'autres instruments, vous pouvez les pousser dans le vecteur `instruments` :

```cpp
instruments.push_back(new MonInstrument());
```

### Jouer une Mélodie

Si l'option "Jouer Musique" est sélectionnée, la fonction `jouerMelodie()` est appelée et joue la mélodie avec le tempo défini :

```cpp
jouerMelodie(500); // tempo de 500 ms entre chaque instrument
```

---

## Remarques

- Ce code utilise un potentiomètre pour naviguer dans les menus et un bouton pour sélectionner des options.
- Il est conçu pour fonctionner avec un écran LCD et un contrôleur ESP32.
- La gestion des instruments se fait dynamiquement à travers des objets de la classe `Instrument`.

---


