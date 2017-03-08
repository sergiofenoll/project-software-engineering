/*
 * Spoor.h
 *
 *  Created on: 8 Mar 2017
 *      Author: sergio
 */

#ifndef SRC_SPOOR_H_
#define SRC_SPOOR_H_

class Spoor {
private:
    int lijnNr;
    Spoor* initCheck;
public:
	Spoor();
	virtual ~Spoor();

	/** \brief Kijk na of de constructor in de juiste staat geeindigd is.
     */
    bool properlyInitialised();

    /** \brief Geef het lijn nummer terug.
     *
     * REQUIRE(this->properlyInitialised(), "Spoor was niet geinitialiseerd bij de aanroep van getLijnNr.");
     */
    int getLijnNr() const;
};

#endif /* SRC_SPOOR_H_ */
