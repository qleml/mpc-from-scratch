#include <MassSpringDamper.h>
#include <Simulator.h>
#include <Config.h>

#include <stdio.h>
#include <vector>


int main(int, char**){
    std::vector<double> state(3, 0);
    state[0] = 100.0;

    SimulatorConfig SimConfig;
    SimConfig.timeStep = 0.01;
    SimConfig.duration = 20.0;
    SimConfig.noiseMean = 0.0;
    SimConfig.noiseStdDev = 1.0;

    MassSpringDamper msd(10.0, 1000.0, 20, state);
    Simulator sim(msd, SimConfig);
    sim.run();
}
