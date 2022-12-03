#include <simlib.h>
#include <iostream>

/*
* Třída reprezentující směnu dodávek od 8 do 16
*/
class Delivery : public Process
{
private:
    /*
    * Sklad dodávek
    */
    Store *vans;

    /*
    * Počet zásilek v dodávce
    */
    unsigned long *packages;

    /*
    * Statistika určující čas cesty na box
    */
    Stat *vanBoxRideTime;

    /*
    * Statistika určující čas cesty na klasickou výdejnu
    */
    Stat *vanNonBoxRideTime;

    /*
    * Statistika určující čas výkládání zásilky na výdejně/boxu
    */
    Stat *vanLoadToPointTime;


    
public:
    /*
    * Kontruktor
    */
    Delivery(unsigned long vans, double averagePackages, double packagesDeviation);

    /*
    * Desktruktor
    */
    ~Delivery();

    /*
    * behavior metoda
    */
    void Behavior() override;

    /*
    * Metoda výpočtu rovnoměrného rozdělení
    */

};
