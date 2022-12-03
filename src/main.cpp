#include <simlib.h>
#include "delivery.h"

const int TRIALS = 5;

using namespace std;

int main() {         
  //SetOutput("ims.dat");
  cout << "# HYPSOZ --- model of delivery service" << endl;
  for (int i = 1; i <= 5; i++) {
      cout << "Trying simulation number " << i << endl;
      cout << "==========================\n";
      cout << "Simulating delivery shift from 8 to 16" << endl;
      Delivery *del = new Delivery(13, 109, 0);
      del->Activate();
      SIMLIB_statistics.Output();

      cout << "Ending simulation number " << i << endl;
  }
  return 0;
}
