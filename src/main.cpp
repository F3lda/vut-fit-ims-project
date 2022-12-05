#include <simlib.h>
#include "delivery.h"
#include "depo.h"
#include "truck_work.h"
#include "van_load.h"
#include "common.h"



using namespace std;

int main() {         
  cout << "# HYPSOZ --- model of delivery service" << endl;
  //SetOutput("hypsoz.dat");
  for (int i = 1; i <= CONS_ATTEMPTS_COUNT; i++) {
      cout << "Trying simulation number " << i << endl;
      cout << "=======================================================================\n";
      cout << "Simulating delivery shift from 8 to 16" << endl;
      Init(0);

      VanLoad *vanLoad = new VanLoad();
      TruckWork *truckWork = new TruckWork(vanLoad);
      Depo *depo = new Depo(truckWork);
      Delivery *del = new Delivery(depo);
      del->Activate();
      
      Run();
      cout << "=======================================================================\n";
      cout << "Ending simulation number " << i << endl;
      SIMLIB_statistics.Output();
  }
  return 0;
}
