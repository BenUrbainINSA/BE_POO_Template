
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
3. [Menu Exception Class](#menu-exception-class)  
   - [Constructor: `MenuException::MenuException`](#menuexception-constructor)  
   - [Method: `MenuException::what`](#menuexception-what)  
   - [Destructor: `MenuException::~MenuException`](#menuexception-destructor)  
4. [Instrument Class](#instrument-class)  
   - [Constructor: `Instrument::Instrument`](#instrument-constructor)  
   - [Method: `Instrument::getNote`](#instrument-getnote)  
   - [Method: `Instrument::getDuree`](#instrument-getduree)  
   - [Method: `Instrument::getNom`](#instrument-getnom)  
   - [Operator: `Instrument::operator=`](#instrument-operator)  
   - [Destructor: `Instrument::~Instrument`](#instrument-destructor)  
5. [Application Class](#application-class)  
   - [Constructor: `Application::Application`](#application-constructor)  
   - [Destructor: `Application::~Application`](#application-destructor)  
   - [Method: `Application::init`](#application-init)  
   - [Method: `Application::run`](#application-run)  


---

## Introduction

Ce projet implémente un menu interactif pour la gestion d'instruments de musique avec un écran LCD RGB. Les utilisateurs peuvent naviguer à travers les menus, sélectionner des instruments, les placer dans un tableau, puis jouer une mélodie avec les instruments placés.

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

Le destructeur de la classe `Menu` est défini mais ne contient pas de code spécifique.

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
## Menu Exception Class

La classe `MenuException` est une classe d'exception personnalisée dérivée de la classe standard `std::exception`. Elle est conçue pour gérer les erreurs spécifiques liées au fonctionnement du menu de l'application.

### Attributs privés

- **message**: `std::string`  
  Contient le message décrivant l'erreur qui a causé l'exception.

---

### Constructeur : `MenuException`

Le constructeur permet de créer une exception avec un message d'erreur personnalisé.

```cpp
explicit MenuException(const std::string& msg);
```

- **msg** : `const std::string&`  
  Le message décrivant la nature de l'erreur.

**Exemple d'utilisation :**
```cpp
throw MenuException("Erreur: élément du menu invalide.");
```

---

### Méthode : `what`

La méthode `what()` est redéfinie pour retourner le message d'erreur associé à l'exception. Cette méthode est appelée lorsque l'exception est capturée, permettant d'obtenir une description de l'erreur.

```cpp
const char* what() const noexcept override;
```

- **Retour** : `const char*`  
  Une chaîne de caractères décrivant l'erreur.

**Exemple d'utilisation :**
```cpp
try {
    throw MenuException("Erreur: navigation hors limites.");
} catch (const MenuException& e) {
    Serial.println(e.what());
}
```

---

### Destructeur : `~MenuException`

Le destructeur par défaut, garanti comme `noexcept`, s'assure que la destruction de l'exception ne génère pas d'exception supplémentaire.

```cpp
~MenuException() noexcept = default;
```

---

### Fonctionnalités principales

- Permet de gérer les erreurs spécifiques au menu via des exceptions personnalisées.
- Compatible avec le système standard d'exceptions C++ (`try-catch`).
- Fournit des messages d'erreur clairs et détaillés.

---

Avec cette classe, vous pouvez capturer et identifier précisément les erreurs liées au menu, facilitant ainsi le débogage et la gestion des exceptions dans l'application.
---

## Instrument Class

La classe `Instrument` représente un instrument musical. C'est une classe abstraite qui sert de base pour tous les instruments. Elle impose une méthode virtuelle pure `emettreSon`, qui sera implémentée par les classes dérivées, et fournit des attributs et méthodes communs pour tous les instruments.

### Constructor: `Instrument::Instrument`

Le constructeur de la classe `Instrument` initialise les paramètres de la note, de la durée et du nom de l'instrument.

```cpp
Instrument::Instrument(const int note, const int duree, const string nom)
```

- **note**: La fréquence de la note associée à l'instrument (en Hz).
- **duree**: La durée pendant laquelle la note doit être jouée (en millisecondes).
- **nom**: Le nom de l'instrument.

### Operator: `Instrument::operator=`

L'opérateur d'affectation permet de copier les attributs d'un instrument dans un autre.
Il était initialement prévu qu'un utilisateur puisse copier un instrument et le modifier, cependant nous n'avons pas eu le temps de l'implémenter.

```cpp
Instrument & operator =(const Instrument & autre);
```

- **autre**: L'instrument à copier.
- **Retour**: La référence à l'instrument actuel (*this).

### Method: `Instrument::getNote`

Retourne la fréquence de la note de l'instrument.

```cpp
int getNote();
```

- **Retour**: Fréquence de la note en Hz.

### Method: `Instrument::getNom`

Retourne le nom de l'instrument.

```cpp
string getNom();
```

- **Retour**: Nom de l'instrument (en tant que chaîne de caractères).

### Method: `Instrument::getDuree`

Retourne la durée pendant laquelle la note est jouée.

```cpp
int getDuree();
```

- **Retour**: Durée en millisecondes.

### Destructor: `Instrument::~Instrument`

Destructeur virtuel de la classe `Instrument`. Il permet de garantir une destruction correcte des objets dérivés via un pointeur de type `Instrument`.

```cpp
virtual ~Instrument();
```

### Operator: `Instrument::operator+=`

L'opérateur `+=` permet d'émettre un son avec l'instrument pour une durée donnée. L'instrument utilise la fréquence de la note de l'objet courant et émet un son pendant la durée spécifiée en argument.
Nous avions également une fonction prévu à cet effet, mais nous avons choisis de modifier cet opérateur afin de rentrer dans le cahier des charges.

```cpp
inline void operator += (int duree);
```

- **duree**: Durée en millisecondes pendant laquelle l'instrument émet un son.
- **Retour**: Rien, l'opération fait émettre un son via la fonction `tone` sur la broche 14.

**Exemple d'utilisation**:
```cpp
Instrument piano(440, 1000, "Piano");
piano += 500;  // Émet un son de 500ms avec la note 440Hz (A4)
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
Elle possède une exception qui permet de detecter si jamais une durée d'émission de son est negative.

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

