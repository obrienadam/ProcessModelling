#ifndef UNIT_H
#define UNIT_H

#include <string>

class Unit
{
public:
    Unit(const std::string& name, double convertToMetric);

    double getMetric() const { return CONVERT_TO_METRIC_*value; }
    const std::string& name() const { return name_; }

    double value;

private:
    const std::string name_;
    const double CONVERT_TO_METRIC_;
};

#endif // UNIT_H
