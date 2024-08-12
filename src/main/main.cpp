#include <MassSpringDamper.h>
#include <Simulator.h>

#include <stdio.h>
#include <vector>


int main(int, char**){
    std::vector<double> state(3, 0);
    state[0] = 10.0;

    MassSpringDamper msd(1.0, 2.0, 3.0, state);
    Simulator sim(msd, 0.01, 20.0);
    sim.run();
}
