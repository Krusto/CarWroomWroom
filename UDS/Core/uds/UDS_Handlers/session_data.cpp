#include "session_data.hpp"

static SessionData currentSessionData;

SessionData &SessionData::GetHandler() {
    return currentSessionData;
}
