/*
 * Metronet.h
 *
 *  Created on: 8 Mar 2017
 *      Author: Sergio Fenoll
 */

#ifndef SRC_METRONET_H_
#define SRC_METRONET_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "tinyxml.h"
#include "tinystr.h"
#include "Station.h"
#include "Tram.h"
#include "Exporter.h"

#include "DesignByContract.h"

enum SuccessEnum {
    Success,
    PartialImport,
    BadImport
};

class Metronet {
private:
    Exporter* exp;
    std::map<std::string, Station*> stations;
    std::map<int, Tram*> trams;
    std::vector<int> sporen;
    Metronet* initCheck;
public:
    Metronet();
    Metronet(Exporter* exp);
    virtual ~Metronet();

    Metronet& operator=(const Metronet& rhs);

    /** \brief Kijk na of de constructor in de juiste staat geeindigd is.
     *  \return Boolean die aangeeft of het object juist geinitialiseerd is.
     */
    bool properlyInitialised();

    /** \brief Verwerkt het XML-bestand.
     *
     * \param filename De naam van het XML-bestand.
     * \param os De stream waarnaar de output geschreven wordt (nodig voor de exporter).
     *
     *  \pre REQUIRE(this->properlyInitialised, "Het metronet was niet geinitialiseerd bij het aanroepen van setupStations.");\n
     */
    SuccessEnum setup(std::string filename, std::ostream& os);

    /** \brief Geeft alle stations in het metronet terug.
     *  \return Map met stations in het metronet.
     *
     *  REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij de aanroep van getStations.");\n
     */
     std::map<std::string, Station*> getStations();

    /** \brief Geeft alle trams in het metronet terug.
     *  \return Map met trams in het metronet.
     *
     *  REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij de aanroep van getTrams.");\n
     */
    std::map<int, Tram*>& getTrams();

    /** \brief Voegt station toe aan metronet.
     *  \param station Het station dat toegevoegd zal worden.
     *
     * REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij de aanroep van addStation.");\n
     * REQUIRE(station->properlyInitialised(), "Station was niet geinitialiseerd bij de aanroep van addStation.");\n
     * ENSURE((stations.find(station->getNaam()) != stations.end()), "Station was niet toegevoegd bij de aanroep van addStation.");\n
     */
    void addStation(Station* station);

    /** \brief Voegt tram toe aan metronet.
     *  \param tram De tram die toegevoegd zal worden.
     *
     * REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij de aanroep van addTram.");\n
     * REQUIRE(tram->properlyInitialised(), "Tram was niet geinitialiseerd bij de aanroep van addTram.");\n
     * ENSURE(trams.find(tram->getSpoor()) != trams.end()), "Tram was niet toegevoegd bij de aanroep van addTram.");\n
     */
    void addTram(Tram* tram);

    /** \brief Voegt spoor toe aan metronet.
     *  \param spoor Het spoor dat toegevoegd zal worden.
     *
     * REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij de aanroep van addSpoor.");\n
     * ENSURE(sporen[sporen.size() - 1] == spoor), "Spoor was niet toegevoegd bij de aanroep van addSpoor.");\n
     */
    void addSpoor(int spoor);

    /** \brief Kijkt na of het metronet consistent is.
     *  \param exp De exporter die de output zal behandelen.
     *  \param os De stream waar de output naar gestuurd zal worden.
     *  \return Boolean die aangeeft of het Metronet consistent is.
     *
     * REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij de aanroep van checkConsistent.");\n
     */
    bool checkConsistent(std::ostream& os);

    /** \brief Print het hele metronet.
     *
     * \param exp De exporter die gebruikt moet worden
     * \param os De stream waarnaar de output moet gestuurd worden
     *
     * REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij aanroep van printMetronet.");\n
     */
    void printMetronet(std::ostream& os);

    /** \brief Behandelt het opstappen en afstappen van passagiers.
     *  \param station Het station waar mensen opstappen en afstappen.
     *
     * REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij aanroep van opstappenAfstappen.");\n
     * REQUIRE((stations.find(station) != stations.end()), "Station bestaat niet in het metronet.");\n
     * REQUIRE(stations[station]->properlyInitialised(), "Station was niet geinitialiseerd bij aanroep van opstappenAfstappen.");\n
     */
    bool opstappenAfstappen(std::string station, std::ostream& os);


    /** \brief Emuleert het rondrijden van trams
     *
     *
     */

    void rondrijden(std::ostream& os);

    /** \brief Reset heel het systeem.
    *
    *
    * REQUIRE(this->properlyInitialised(), "Metronet was niet geinitialiseerd bij aanroep van reset.");\n
    */
     void reset();
};

#endif /* SRC_METRONET_H_ */
