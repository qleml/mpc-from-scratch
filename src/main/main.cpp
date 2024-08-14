#include <MassSpringDamper.h>
#include <Simulator.h>
#include <Config.h>

#include "Renderer.h"

#include <stdio.h>
#include <vector>

int main(int, char**){
    std::vector<double> state(3, 0);
    state[0] = 0;

    SimulatorConfig SimConfig;
    SimConfig.timeStep = 0.001;
    SimConfig.duration = 60.0;
    SimConfig.noiseMean = 0.0;
    SimConfig.noiseStdDev = 0.0;
    SimConfig.gui = true;

    MassSpringDamper msd(10.0, 1000.0, 20, state);
    Simulator sim(msd, SimConfig);
    sim.run();
}
