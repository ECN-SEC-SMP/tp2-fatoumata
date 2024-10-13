
#include <iostream>

using namespace std;

#include "vehicule.hpp"

Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
  :vitesseMax_(vitesseMax), nbPlaces_(nbPlaces),occupants_(occupants){}

Voiture::Voiture(int vitesseMax, int nbPlaces, int occupants):Vehicule(vitesseMax, nbPlaces, occupants){}

Bateau::Bateau(int vitesseMax, int nbPlaces, int occupants):Vehicule(vitesseMax, nbPlaces, occupants){}

VoitureAmphibie:: VoitureAmphibie(int vMaxVoiture, int vMaxBateau, int nbPlaces, int occupants):Bateau(vMaxBateau, nbPlaces, occupants),Voiture(vMaxVoiture, nbPlaces, occupants){}



Vehicule::~Vehicule(){}

void Vehicule::demarrer(){}

void Vehicule::arreter(){}


int Vehicule::getVitesse() const{
  cout<<vitesse_<<endl;
  return vitesse_;
}

void Vehicule::depanner(){
  if (etat_ == MARCHE){
      throw invalid_argument("Le véhicule est déjà en marche");
  }
  if (etat_==PANNE_LEGERE){
      etat_=MARCHE;
  }
  if (etat_==PANNE_SEVERE){
      etat_=PANNE_LEGERE;
  }
}

void Vehicule::accelerer(int increment){
  if (etat_ != MARCHE){
      throw invalid_argument("Le véhicule doit etre en marche pour accélérer");
  }
  if (vitesse_ + increment > vitesseMax_){
    throw invalid_argument("Le véhicule ne peut pas accélérer plus que sa vitesse maximale");
  }
  vitesse_ += increment;
}

void Vehicule::freiner(int decrement){
  if (etat_ != MARCHE){
      throw invalid_argument("Le véhicule doit etre en marche pour freiner");
      }
  if (vitesse_ - decrement < 0){
    throw invalid_argument("Le véhicule ne peut pas freiner plus que sa vitesse actuelle est inférieure à 0");
  }
  vitesse_ -= decrement; 
}


void Vehicule::monter(int nbOcc){
  if (etat_ != ARRET){
      throw invalid_argument("Le véhicule doit etre en arret pour monter");
  }
  if (occupants_ + nbOcc > nbPlaces_){
    throw invalid_argument("Le véhicule ne peut pas monter plus qu'il n'ya plus de places disponibles");
  }
  occupants_ += nbOcc;
}

void Vehicule::descendre(int nbOcc){
  if (etat_ != ARRET){
      throw invalid_argument("Le véhicule doit s'arreter pour descendre");
  }
  if (occupants_ - nbOcc < 0){
    throw invalid_argument("Le véhicule ne peut pas descendre plus que il n'y a plus d'occupants");
  }
  occupants_ -= nbOcc;
    
}

void Vehicule::mettreEnPanne(double random){
  if (random < 0.5){
    etat_ = PANNE_LEGERE;  
  }
  else{
    etat_ = PANNE_SEVERE;
  }
}

string Vehicule::getEtat() const{
  if (etat_ == ARRET){
    cout<<"Véhicule arretée"<<endl;
    return "ARRET";
  }
  if (etat_ == MARCHE){
    cout<<"Véhicule en marche"<<endl;
    return "MARCHE";
  }
  if (etat_ == PANNE_LEGERE){
    cout<<"Véhicule en panne légère"<<endl;
    return "PANNE_LEGERE";
  }
  if (etat_==PANNE_SEVERE){
    cout<<"Véhicule en panne sévère"<<endl;
    return "PANNE_SEVERE";
  }
  return 0;
}

void Voiture::demarrer(){
  if (etat_ == MARCHE){
      throw invalid_argument("La voiture est déjà en marche");
  }
  etat_ = MARCHE;
  cout<<"demarrage d'une voiture"<<endl;
}


void Voiture::arreter(){
  if (etat_ == ARRET){
      throw invalid_argument("La voiture est déjà en arret");
  }
  etat_ = ARRET;
  cout<<"arret d'une voiture"<<endl;

}

void Bateau::demarrer(){
  if (etat_ == MARCHE){
      throw invalid_argument("Le bateau est déjà en marche");
  }
  etat_ = MARCHE;
  cout<<"démarrage d'un bateau"<<endl;
    }


void Bateau::arreter(){
  if (etat_ == ARRET){
      throw invalid_argument("Le bateau est déjà en arret");
  }
  etat_ = ARRET;
  cout<<"arret d'un bateau"<<endl;

}

void VoitureAmphibie::affichage(){
  std::cout << "Vitesse max en mode Voiture : " << Voiture::vitesseMax_ << std::endl;
  std::cout << "Vitesse max en mode Bateau : " << Bateau::vitesseMax_ << std::endl;

}
