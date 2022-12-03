#include <simlib.h>
#include "delivery.h"

const int TRIALS = 5;

using namespace std;

int main() {         
  //SetOutput("ims.dat");
  cout << "# HYPSOZ --- model of delivery service" << endl;
  //SetOutput("hypsoz.dat");
  for (int i = 1; i <= 1; i++) {
      cout << "Trying simulation number " << i << endl;
      cout << "=======================================================================\n";
      cout << "Simulating delivery shift from 8 to 16" << endl;
      Init(0, 24*60);
      Delivery *del = new Delivery(13, 109, 0);
      del->Activate();
      Run();
      cout << "=======================================================================\n";
      cout << "Ending simulation number " << i << endl;
      SIMLIB_statistics.Output();
  }
  return 0;
}
