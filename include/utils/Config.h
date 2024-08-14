// Config.h
#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

struct MassSpringDamperConfig {
    double mass;
    double springConstant;
    double dampingCoefficient;
    std::vector<double> initialState;
    double timeStep;
    double duration;
};

struct SimulatorConfig {
    double timeStep = 0.01;
    double duration = 100.0;
    double noiseMean = 0.0;
    double noiseStdDev = 1.0;
    bool gui = true;
};

#endif // CONFIG_H