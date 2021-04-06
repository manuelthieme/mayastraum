#include <util/serialisable.h>

void Serialisable::to_yaml(YAML::Emitter *output) const {
    *output << YAML::Key << "SerialisableError" << YAML::Value << "to_yaml not overloaded";
}

std::string Serialisable::to_string() const {
    return "SerialisableError: to_sstream not overloaded";
}

YAML::Emitter &operator<<(YAML::Emitter &output, const Serialisable &serialisable) {
    serialisable.to_yaml(&output);
    return output;
}

std::ostream& operator<<(std::ostream &output, const Serialisable &serialisable) {
    output << serialisable.to_string();
    return output;
}
