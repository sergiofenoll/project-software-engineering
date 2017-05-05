/*
 * Tram.cpp
 *
 *  Created on: 8 Mar 2017
 *      Author: Sergio Fenoll
 */

#include "Tram.h"

// Global consts
double Tram::ticketPrijs = 2.0;


Tram::Tram() {
    initCheck = this;
    ENSURE(this->properlyInitialised(), "Tram is niet in de juiste staat geëindigd na aanroep van de constuctor.");
}

Tram::Tram(int zit, int snel, int sp, int nr, std::string typeNaam, std::string beginS, StatisticsTram* statistics) {
    stats = statistics;
    bezettePlaatsen = 0;
    zitplaatsen = zit;
    voertuignummer = nr;
    snelheid = snel;
    spoor = sp;
    if (typeNaam == "Albatros") type = Albatros;
    else if (typeNaam == "PCC") type = PCC;
    beginStation = beginS;
    huidigStation = beginS;
    initCheck = this;
    ENSURE(this->properlyInitialised(), "Tram is niet in de juiste staat geëindigd na aanroep van de constuctor.");
}

bool Tram::properlyInitialised() const {
    return initCheck == this;
}

int Tram::getZitplaatsen() const {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van getZitplaatsen.");
    return zitplaatsen;
}

int Tram::getBezettePlaatsen() const {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van getBezetteZitplaatsen.");
    return bezettePlaatsen;
}

std::vector<Passagier*> Tram::getPassagiers() const {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van getPassagiers.");
    return passagiers;
}

int Tram::getSnelheid() const {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van getSnelheid.");
    return snelheid;
}

int Tram::getSpoor() const {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van getSpoor.");
    return spoor;
}

std::string Tram::getBeginStation() const {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van getBeginStation.");
    return beginStation;
}

std::string Tram::getHuidigStation() const {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van getHuidigStation.");
    return huidigStation;
}

std::string Tram::getType() const {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van getType.");
    switch (type) {
        case Albatros :
            return "Albatrso";
        case PCC :
            return "PCC";
    }
}

int Tram::getVoertuignummer() const {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van getVoertuignummer.");
    return voertuignummer;
}

double Tram::getOmzet() const {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van getOmzet.");
    return stats->getOmzet();
}

double Tram::getTicketPrijs() const {
    ENSURE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van getTicketPrijs.");
    return ticketPrijs;
}

bool Tram::bevatPassagier(Passagier *pas) const {
    return (find(passagiers.begin(), passagiers.end(), pas) != passagiers.end());
}

void Tram::setHuidigStation(std::string station) {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van getHuidigStation.");
    huidigStation = station;
    ENSURE((getHuidigStation() == station), "huidigStation is niet aangepast door setHuidigStation.");
}

void Tram::setBezettePlaatsen(int aantalBezettePlaatsen) {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanrooep van setBezettePlaatsen.");
    bezettePlaatsen = aantalBezettePlaatsen;
    ENSURE((this->getBezettePlaatsen() == aantalBezettePlaatsen), "bezettePlaatsen is niet aangepast door setBezettePlaatsen.");
}

void Tram::setOmzet(double o) {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van setOmzet.");
    stats->setOmzet(o);
}

void Tram::addPassagier(Passagier* pas){
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van addPassagiers.");
    REQUIRE(pas->properlyInitialised(), "Passagier was niet geinitialiseerd bij de aanroep van addPassagier.");
    passagiers.push_back(pas);
    ENSURE(bevatPassagier(pas), "Passagiers niet aangepast bij aanroep van addPassagiers.");
}

void Tram::removePassagier(Passagier *pas) {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van removePassagiers.");
    REQUIRE(pas->properlyInitialised(), "Passagier was niet geinitialiseerd bij de aanroep van removePassagier.");
    REQUIRE(bevatPassagier(pas), "Passagier zat niet in tram bij de aanroep van removePassagier");
    passagiers.erase(std::remove(passagiers.begin(), passagiers.end(), pas));
    ENSURE(!bevatPassagier(pas), "Passagiers niet aangepast bij aanroep van addPassagiers.");
}

bool Tram::isAlbatros() const {
    REQUIRE(this-properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van isAlbatros.");
    return type == Albatros;
}

bool Tram::isPCC() const {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van isPCC.");
    return type == PCC;
}

void Tram::setVoertuignummer(int n) {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van setVoertuignummer.");
    voertuignummer = n;
    ENSURE((getVoertuignummer() == n), "Voertuignummer niet aangepast bij aanroep van setVoertuignummer.");
}

void Tram::verplaatsTram(std::string station, Exporter* exp, std::ostream& os) {
    REQUIRE(this->properlyInitialised(),
            "Tram was niet geinitialiseerd bij de aanroep van verplaatsTram.");

    std::string output = "Tram " + std::to_string(spoor) + " reed van station " +
                         huidigStation + " naar station " + station + ".\n";
    this->setHuidigStation(station);

    ENSURE((getHuidigStation() == station),
           "huidigStation is niet correct aangepast.");
}

bool Tram::afstappen(Passagier* pas){
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van afstappen.");
    REQUIRE(pas->properlyInitialised(), "Passagier was niet geinitialiseerd bij de aanroep van afstappen.");
    removePassagier(pas);
    pas->updateVertrokken();
    setBezettePlaatsen(getBezettePlaatsen() - pas->getHoeveelheid());
    return true;
}

bool Tram::opstappen(Passagier* pas) {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van afstappen.");
    REQUIRE(pas->properlyInitialised(), "Passagier was niet geinitialiseerd bij de aanroep van afstappen.");
    if(getBezettePlaatsen() + pas->getHoeveelheid() > getZitplaatsen()){
        return false;
    }
    else{
        // Passagier stapt op
        addPassagier(pas);
        pas->updateVertrokken();
        setBezettePlaatsen(getBezettePlaatsen() + pas->getHoeveelheid());
        setOmzet(getOmzet() + (pas->getHoeveelheid() * ticketPrijs));
        return true;
    }
}

StatisticsTram* Tram::getStatistics() {
    REQUIRE(this->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van getStatistics.");
    return stats;
}

Tram::~Tram() {
    delete stats;
}
