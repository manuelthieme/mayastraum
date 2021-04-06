#pragma once

#include <sstream>

#include <yaml-cpp/yaml.h>

class Serialisable {
public:
    virtual void to_yaml (YAML::Emitter *output) const;
    virtual std::string to_string() const;
};

YAML::Emitter &operator<<(YAML::Emitter &output, const Serialisable &serialisable);
std::ostream &operator<<(std::ostream  &output, const Serialisable &serialisable);
