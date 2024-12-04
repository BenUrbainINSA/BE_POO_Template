#ifndef MENUEXCEPTION_H
#define MENUEXCEPTION_H

#include <exception>
#include <string>

// Classe d'exception personnalisée pour la gestion des erreurs dans le menu
class MenuException : public std::exception {
private:
    std::string message; // Message décrivant l'erreur

public:
    // Constructeur avec un message d'erreur
    explicit MenuException(const std::string& msg) : message(msg) {}

    // Redéfinition de la méthode what() pour retourner le message d'erreur
    const char* what() const noexcept override {
        return message.c_str();
    }

    // Destructeur par défaut
    ~MenuException() noexcept = default;
};

#endif 
