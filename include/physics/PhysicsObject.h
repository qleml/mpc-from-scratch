#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include <vector>
#include <mutex>

class PhysicsObject
{
public:
    PhysicsObject();
    virtual ~PhysicsObject();
    virtual void update(double force, double dt);
    void setState(const std::vector<double>& state);
    std::vector<double> getState() const;

protected:
    std::vector<double> _state;

private:
    mutable std::mutex _mutex; // Mutex to protect access to _state
};

#endif // PHYSICSOBJECT_H