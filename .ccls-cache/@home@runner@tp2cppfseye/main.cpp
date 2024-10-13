#include <iostream>

using namespace std;

#include "vehicule.hpp"

int main() {
  //try {
    Voiture v1(100, 4, 0);
    v1.arreter();
    v1.monter(3);
    v1.demarrer();
    v1.getEtat();
    v1.accelerer(10);
    v1.getVitesse();
    v1.arreter();
    v1.getEtat();
    v1.descendre(2);
    v1.demarrer();
    v1.getEtat();
    v1.freiner(5);
    v1.getEtat();  
    v1.mettreEnPanne(0.3);
    v1.getEtat();
    v1.depanner();
    v1.getEtat();
  // }
  // catch (const std::invalid_argument& e) {
  //   std::cerr << "Erreur : " << e.what() << std::endl;
  // } catch (...) {
  //   std::cerr << "Erreur inconnue." << std::endl;
  // }
  
  VoitureAmphibie V2(100, 120, 4, 0);
  V2.affichage();
}