#pragma once
#include "../uds_definitions.h"
#include "memory.hpp"

class SessionData : public Memory{
public:
    /**
  * @return Current Diagnostic Session - DiagnosticSession
  */
    static DiagnosticSession GetCurrentDiagnosticSession() { return SessionData::s_CurrentDiagnosticSession; }

    static void SetDiagnosticSession(DiagnosticSession session) {
        s_CurrentDiagnosticSession = session;
    }

    /**
     * @brief returns if the ecu security is locked or unlocked
     * @return true  - ecu is unlocked
     *         false - ecu is locked
     */
    static bool GetSecurityAccessStatus() { return SessionData::s_SecurityAccessStatus; }

    /**
     * @brief sets ecu security access to locked or unlocked
     * @param status - bool (true = unlocked,false = locked)
     */
    static void SetSecurityAccessStatus(bool status) { SessionData::s_SecurityAccessStatus = status; }

    /**
     * @brief returns if the ecu security seed is previously requested
     * @return true  - requested
     *         false - not requested
     */
    static bool IsSecurityAccessSeedRequested() { return SessionData::s_SecuritySeedRequested; }

    /**
     * @brief sets ecu security seed requested flag
     * @param status - bool (true = requested,false = not requested)
     */
    static void SetSecurityAccessSeedRequested(bool status) { SessionData::s_SecuritySeedRequested = status; }

    /**
     * @brief returns if the tester is present
     * @return true  - present
     *         false - not present
     */
    static bool IsTesterPresent() { return SessionData::s_TesterPresent; }

    /**
     * @brief sets tester present flag
     * @param status - bool (true = present,false = not present)
     */
    static void SetTesterPresent(bool status) { SessionData::s_TesterPresent = status; }

    static SessionData& GetHandler();

private:
    static inline DiagnosticSession s_CurrentDiagnosticSession{DiagnosticSession::Default};
    static inline bool s_SecurityAccessStatus{false};
    static inline bool s_SecuritySeedRequested{false};
    static inline bool s_TesterPresent{false};
};