#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <Arduino.h>
#include <iostream>
#include <string>
using namespace std;

/**
 * @class Instrument
 * @brief Classe abstraite représentant un instrument musical.
 * 
 * Cette classe sert de base pour tous les instruments musicaux. Elle impose une méthode virtuelle pure 
 * `emettreSon` pour émettre un son, tout en fournissant des attributs et des méthodes communs à tous les instruments.
 */

/**
 * @fn Instrument::Instrument(const int note, const int duree, const string nom)
 * @brief Constructeur de la classe Instrument.
 * 
 * @param note La fréquence de la note associée à l'instrument.
 * @param duree La durée pendant laquelle la note doit être jouée.
 * @param nom Le nom de l'instrument.
 * 
 * @example Instrument piano(440, 1000, "Piano");
 */

class Instrument{
  protected :
    int note;
    int duree;
    string nom;
  
  public :
    Instrument(const int note, const int duree, const string nom);

    virtual void emettreSon() const = 0;


/**
 * @fn Instrument& Instrument::operator=(const Instrument & autre)
 * @brief Surcharge de l'opérateur d'affectation pour copier les attributs d'un instrument.
 * 
 * @param autre Référence vers l'instrument à copier.
 * @return Référence vers l'instrument actuel (*this).
 * 
 * @example instrument1 = instrument2;
 */

    Instrument & operator =(const Instrument & autre){
      this->note = autre.note;
      this->duree = autre.duree;
      this->nom = autre.nom;

      return *this;
    }

/**
 * @fn int Instrument::getNote()
 * @brief Retourne la fréquence de la note de l'instrument.
 * 
 * @return Fréquence de la note (en Hz).
 * 
 * @example int note = instrument.getNote();
 */
    int getNote();

/**
 * @fn string Instrument::getNom()
 * @brief Retourne le nom de l'instrument.
 * 
 * @return Nom de l'instrument (en tant que chaîne de caractères).
 * 
 * @example string nom = instrument.getNom();
 */
    string getNom() ;


/**
 * @fn int Instrument::getDuree()
 * @brief Retourne la durée pendant laquelle la note est jouée.
 * 
 * @return Durée en millisecondes.
 * 
 * @example int duree = instrument.getDuree();
 */
    int getDuree();

/**
 * @fn Instrument::~Instrument()
 * @brief Destructeur virtuel de la classe Instrument.
 * 
 * Permet de garantir une destruction correcte des objets dérivés via un pointeur de type Instrument.
 */
    virtual ~Instrument();

/**
 * @fn operator +=()
 * @brief Permet de emetre un son d'une durée donnée  en fait instrument+=durée.
 * 
 * 
 */
  inline void operator += (int duree){
      tone(14,this->note,duree);
  }

};



#endif