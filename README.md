
---

## Table des matières

1. [Introduction](#introduction)
2. [Menu Class](#menu-class)
   - [Constructor: `Menu::Menu`](#menu-constructor)
   - [Destructor: `Menu::~Menu`](#menu-destructor)
   - [Method: `Menu::init`](#menu-init)
   - [Method: `Menu::update`](#menu-update)
   - [Method: `Menu::displayMainMenu`](#menu-displaymainmenu)
   - [Method: `Menu::displayMenuInstrument`](#menu-displaymenuinstrument)
   - [Method: `Menu::handleSelection`](#menu-handleselection)
   - [Method: `Menu::handlePlacement`](#menu-handleplacement)
   - [Method: `Menu::displayPlacementMenu`](#menu-displayplacementmenu)
   - [Method: `Menu::placeInstrument`](#menu-placeinstrument)
   - [Method: `Menu::jouerMelodie`](#menu-jouermelodie)
3. [Instrument Class](#instrument-class)
   - [Constructor: `Instrument::Instrument`](#instrument-constructor)
   - [Method: `Instrument::getNote`](#instrument-getnote)
   - [Method: `Instrument::getDuree`](#instrument-getduree)
   - [Method: `Instrument::getNom`](#instrument-getnom)
   - [Operator: `Instrument::operator=`](#instrument-operator)
   - [Destructor: `Instrument::~Instrument`](#instrument-destructor)
4. [Application Class](#application-class)
   - [Constructor: `Application::Application`](#application-constructor)
   - [Destructor: `Application::~Application`](#application-destructor)
   - [Method: `Application::init`](#application-init)
   - [Method: `Application::run`](#application-run)


---

## Introduction

Ce projet implémente un menu interactif pour la gestion d'instruments de musique dans un environnement Arduino avec un écran LCD RGB. Les utilisateurs peuvent naviguer à travers les menus, sélectionner des instruments, les placer dans un tableau, puis jouer une mélodie avec les instruments placés.

---

## Menu Class

La classe `Menu` gère les interactions utilisateur à travers un écran LCD et un potentiomètre (pour la navigation) ainsi qu'un bouton (pour la sélection). Elle permet de gérer l'affichage des menus, la sélection d'instruments et leur placement dans un tableau, ainsi que la lecture d'une mélodie en fonction des instruments sélectionnés.

### Constructor: `Menu::Menu`

Le constructeur initialise la classe `Menu` avec les broches du potentiomètre et du bouton, ainsi que l'écran LCD. Il configure également le tableau des instruments et initialise les instruments de base.

```cpp
Menu::Menu(int potPin, int button, rgb_lcd lcd)
```

- **potPin**: Broche du potentiomètre.
- **button**: Broche du bouton.
- **lcd**: Référence à un objet `rgb_lcd` pour l'écran LCD RGB.

### Destructor: `Menu::~Menu`

Le destructeur de la classe `Menu` ne fait qu'une libération de mémoire si nécessaire. Dans ce cas, il est défini mais ne contient pas de code spécifique.

```cpp
Menu::~Menu()
```

### Method: `Menu::init`

La méthode `init` configure les broches du potentiomètre et du bouton comme entrées, initialise l'écran LCD et affiche le menu principal.

```cpp
void Menu::init()
```

### Method: `Menu::update`

Cette méthode met à jour l'état du menu, en fonction des entrées du potentiomètre et du bouton. Elle gère les transitions d'état et les actions associées à chaque état.

```cpp
void Menu::update()
```

- **potValue**: Lit la valeur du potentiomètre et met à jour l'affichage du menu en fonction de cette valeur.
- **buttonValue**: Lit l'état du bouton pour déterminer les actions à réaliser (passer à un autre état, placer un instrument, etc.).

### Method: `Menu::displayMainMenu`

Affiche le menu principal qui permet de choisir entre jouer une mélodie ou ajouter un instrument.

```cpp
void Menu::displayMainMenu()
```

### Method: `Menu::displayMenuInstrument`

Affiche la liste des instruments disponibles pour sélection.

```cpp
void Menu::displayMenuInstrument()
```

### Method: `Menu::handleSelection`

Affiche l'instrument sélectionné et passe à l'état suivant du menu.

```cpp
void Menu::handleSelection()
```

### Method: `Menu::handlePlacement`

Permet de placer un instrument sélectionné à une position spécifique dans le tableau.

```cpp
void Menu::handlePlacement()
```

### Method: `Menu::displayPlacementMenu`

Affiche le menu de placement pour l'instrument à la position spécifiée. Cela inclut la vérification si une position est déjà occupée.

```cpp
void Menu::displayPlacementMenu(int position)
```

### Method: `Menu::placeInstrument`

Place l'instrument sélectionné à une position donnée dans le tableau `Lecture`.

```cpp
void Menu::placeInstrument(int position)
```

### Method: `Menu::jouerMelodie`

Joue une mélodie en utilisant les instruments placés dans le tableau `Lecture`.

```cpp
void Menu::jouerMelodie(int tempo)
```

---

## Instrument Class

La classe `Instrument` est une classe abstraite représentant un instrument musical. Elle définit les propriétés et méthodes communes pour tous les instruments, y compris la note, la durée et le nom. De plus, elle impose une méthode virtuelle pure `emettreSon` pour les classes dérivées, permettant à chaque instrument de jouer son propre son.

### Constructor: `Instrument::Instrument`

Le constructeur de la classe `Instrument` initialise les attributs de la classe : `note`, `duree` et `nom`.

```cpp
Instrument::Instrument(const int note, const int duree, const string nom)
```

- **note**: La fréquence de la note (en Hz) associée à l'instrument.
- **duree**: La durée pendant laquelle la note doit être jouée (en millisecondes).
- **nom**: Le nom de l'instrument.

### Method: `Instrument::getNote`

Retourne la fréquence de la note associée à l'instrument.

```cpp
int Instrument::getNote()
```

- **Retour**: La fréquence de la note (en Hz).

### Method: `Instrument::getDuree`

Retourne la durée pendant laquelle la note est jouée.

```cpp
int Instrument::getDuree()
```

- **Retour**: La durée en millisecondes.

### Method: `Instrument::getNom`

Retourne le nom de l'instrument.

```cpp
string Instrument::getNom()
```

- **Retour**: Le nom de l'instrument sous forme de chaîne de caractères.

### Operator: `Instrument::operator=`

Surcharge de l'opérateur d'affectation permettant de copier les attributs d'un instrument dans un autre.

```cpp
Instrument & Instrument::operator =(const Instrument & autre)
```

- **paramètre**: `autre` — L'instrument dont on veut copier les attributs.
- **Retour**: L'instrument actuel (*this), après avoir copié les attributs de `autre`.

### Destructor: `Instrument::~Instrument`

Destructeur virtuel de la classe `Instrument`. Ce destructeur permet une destruction correcte des objets dérivés via un pointeur de type `Instrument`.

```cpp
Instrument::~Instrument()
```

---

## Application Class

La classe `Application` est le point d'entrée de l'application. Elle orchestre l'exécution du programme en initialisant le menu et en gérant les interactions utilisateur.

### Constructor: `Application::Application`

Le constructeur de la classe `Application` initialise l'écran LCD, le potentiomètre et le bouton de sélection. Il crée aussi une instance de la classe `Menu`.

```cpp
Application::Application()
 : lcd(),                                   // Instancie l'écran LCD
      potentiometerPin(A0),                    // Initialisation des broches
      selectButtonPin(15), //pin D8
      menu(potentiometerPin, selectButtonPin, lcd) // Initialise le menu
```

- **lcd**: Une instance de l'écran LCD pour afficher les menus.
- **potentiometerPin**: Broche utilisée pour connecter le potentiomètre.
- **selectButtonPin**: Broche utilisée pour connecter le bouton de sélection.
- **menu**: Instance de la classe `Menu` permettant de gérer les interactions.

### Destructor: `Application::~Application`

Le destructeur ne nécessite aucune action supplémentaire dans ce cas, car la gestion de la mémoire est automatique.

```cpp
Application::~Application()
{
    // Rien à faire dans ce cas
}
```

### Method: `Application::init`

Cette méthode initialise la communication série (pour le débogage) et configure le menu.

```cpp
void Application::init(void)
{
  Serial.begin(9600);
  menu.init(); // Initialise le menu
}
```

- **Retour**: Rien, cette méthode est utilisée pour initialiser les paramètres nécessaires au démarrage de l'application.

### Method: `Application::run`

Cette méthode est exécutée en boucle pour mettre à jour l'affichage du menu et gérer les interactions.

```cpp
void Application::run(void)
{
  try {
    menu.update();
  } catch (const MenuException& e) {
    Serial.println("Exception capturée depuis Menu :");
    Serial.println(e.what());
  }
}
```

- **Retour**: Rien. Si une exception est lancée lors de la mise à jour du menu, elle est capturée et un message d'erreur est affiché via le port série.

---

