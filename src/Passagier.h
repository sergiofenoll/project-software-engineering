//
// Created by jonathan on 19.04.17.
//

#ifndef PSE_PASSAGIER_H
#define PSE_PASSAGIER_H

#include <string>
#include "DesignByContract.h"

/**
 * \brief Passagier klasse die een groep passagiers zal voorstellen.
 */
class Passagier {
    std::string naam;
    std::string beginStation;
    std::string eindStation;
    int hoeveelheid;
    bool vertrokken;
    Passagier* initCheck;
    int tram;
public:

    /**
     * \brief Lege constructor.
     * \post ENSURE(properlyInitialised(),
     *              "Passagier is niet in de juiste staat geeindigd na de aanroep van de constructor.");
     */
    Passagier();

    /**
     * \brief Default constructor van Passagier.
     * \param n De naam van de groep passagiers.
     * \param begin Het beginstation van de groep.
     * \param eind Het eindstation van de groep.
     * \param h De hoeveelheid personen in de groep.
     * \post ENSURE(properlyInitialised(),
     *              "Passagier is niet in de juiste staat geeindigd na de aanroep van de constructor.");
     */
    Passagier(std::string n, std::string begin, std::string eind, int h);

    /**
     * \brief Kijk na of de constructor in de juiste staat geeindigd is.
     * \return Boolean die aangeeft of het object juist geinitialiseerd is.
     */
    bool properlyInitialised() const;

    /**
     * \brief Geef de naam van de groep passagiers.
     * \return Naam van de groep.
     * \pre REQUIRE(properlyInitialised(), "Passagier was niet geinitialiseerd bij de aanroep van getNaam.");
     */
    std::string getNaam() const;

    /**
     * \brief Geef het beginstation van de groep passagiers.
     * \return Beginstation van de groep.
     * \pre REQUIRE(properlyInitialised(),
     *              "Passagier was niet geinitialiseerd bij de aanroep van getBeginStation.");
    */
    std::string getBeginStation() const;

    /**
     * \brief Geef het eindstation van de groep passagiers.
     * \return Eindstation van de groep.
     * \pre REQUIRE(properlyInitialised(),
     *              "Passagier was niet geinitialiseerd bij de aanroep van getEindStation.");
    */
    std::string getEindStation() const;

    /**
     * \brief Geef het aantal personen in de groep passagiers.
     * \return Aantal personen in de groep.
     * \pre REQUIRE(properlyInitialised(),
     *              "Passagiers was niet geinitialiseerd bij de aanroep van getHoeveelheid.");
    */
    int getHoeveelheid() const;

    /**
     * \brief Verander de huide het huidige tram van het de passagier.
     * \param tram Nieuwe tram.
     * \pre REQUIRE(properlyInitialised(),
     *              "Passagiers was niet geinitialiseerd bij de aanroep van setHuidigePassagier.");
     * \post ENSURE(huidigeTram() == tram, "Tram was niet correct aangepast na aanroep van setHuidigeTram.");
     */
    void setHuidigeTram(int tram);

    /**
     * \brief Geeft aan op welke tram de passagier reist.
     * \return De huidige tram waarop de passagier zich begeeft.
     * \pre REQUIRE(properlyInitialised, "Passagier was niet geinitialiseerd bij de aanroep van huidigeTram.");
     */
    int huidigeTram() const;

    /**
     * \brief Geeft aan of de passagier vertrokken is.
     * \return Een boolean die aangeeft of de passagier vertrokken is.
     * \pre REQUIRE(properlyInitialised(), "Passagier was niet geinitialiseerd bij de aanroep van isVertrokken.");
     */
    bool isVertrokken() const;

    /**
     * \brief Update de status van de passagiers. (wachtend -> vertrokken)
     * \pre REQUIRE(properlyInitialised(),
     *              "Passagier was niet geinitialiseerd bij de aanroep van updateVertrokken.");
     */
    void updateVertrokken();

    /**
     * \brief Geeft aan of de passagier is aangekomen.
     * \pre REQUIRE(properlyInitialised(), "Passagier was niet geinitialiseerd bij de aanroep van isAangekomen.");
     */
     bool isAangekomen();

};


#endif //PSE_PASSAGIER_H
