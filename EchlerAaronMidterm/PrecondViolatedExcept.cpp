#include "PrecondViolatedExcept.h"


PrecondViolatedExcept::PrecondViolatedExcept(const std::string& message) : std::logic_error("Precondition Violated Exception: " + message) {


}
