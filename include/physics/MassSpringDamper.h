#ifndef MASSSPRINGDAMPER_H
#define MASSSPRINGDAMPER_H

#include "PhysicsObject.h"

#include <vector>
#include <mutex>

class MassSpringDamper : public PhysicsObject
{
public:
    MassSpringDamper(
        double mass, 
        double springConstant, 
        double dampingCoefficient,
        std::vector<double> state = std::vector<double>(3, 0.0)
    );
    ~MassSpringDamper();

    void update(double force, double dt);

    void setMass(double mass);
    void setSpringConstant(double springConstant);
    void setDampingCoefficient(double dampingCoefficient);

    double getMass() const;
    double getSpringConstant() const;
    double getDampingCoefficient() const;

private:
    double mass;
    double springConstant;
    double dampingCoefficient;

    mutable std::mutex mtx;
};

#endif // MASSSPRINGDAMPER_H