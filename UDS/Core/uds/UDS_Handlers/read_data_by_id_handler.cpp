#include "read_data_by_id_handler.hpp"
#include "../uds_definitions.h"
#include "memory_map.hpp"
#include <string>

ReadDataByIdentifierHandler::ReadDataByIdentifierHandler() {
  m_REQ_SID = UDS_READ_DATA_BY_ID_REQUEST_SID;
  m_RES_SID = UDS_READ_DATA_BY_ID_RESPONSE_SID;
}

void ReadDataByIdentifierHandler::MainHandle(Message message) {
  InitResponseBuffer();

  if (message.length() != 3) {
    SendNegativeResponse(NRC::IncorrectMessageLengthOrInvalidFormat);
  } else {
    uint16_t did =
        (((uint16_t)message[1]) << 8) | ((uint16_t)message[2] & 0xFF);
    int status = HandleDID(did, message);
    if (status == 0) {
      SendPositiveResponse();
    } else {
      SendNegativeResponse(status);
    }
  }
}
int ReadDataByIdentifierHandler::HandleDID(uint16_t did, Message &message) {
  switch (did) {
  case RDID_Logical_Software_Block_Counter_Of_Programming_Attempts: {
    for (size_t i = 0; i < 14; i++)
      AddByteToRespBuffer(0x00);
    break;
  }
  case RDID_Logical_Software_Block_Lock_Value: {
    for (size_t i = 0; i < 14; i++)
      AddByteToRespBuffer(0x00);
    break;
  }
  case RDID_BootloaderTPBlocksize: {
    AddByteToRespBuffer(0x0F);
    break;
  }
  case RDID_ActiveDiagnosticSession: {
    AddByteToRespBuffer((uint8_t)SessionData::GetCurrentDiagnosticSession());
    break;
  }
  case RDID_SparePartNumber: {
    for (size_t i = 0; i < 11; i++) {
      AddByteToRespBuffer('_');
    }
    break;
  }
  case RDID_logical_block_downgrade_protection_versions: {
    uint8_t arr[] = {0x01, 0x30, 0x30, 0x30, 0x35, 0x30, 0x30, 0x30, 0x36,
                     0x30, 0x30, 0x30, 0x35, 0x30, 0x30, 0x30, 0x36, 0x30,
                     0x30, 0x30, 0x35, 0x30, 0x30, 0x30, 0x35};
    AddByteArrayToRespBuffer(arr, sizeof(arr) / sizeof(uint8_t));
    break;
  }
  case RDID_ECUHardwareNumber: {
    for (size_t i = 0; i < 11; i++) {
      AddByteToRespBuffer('_');
    }
    break;
  }
  case RDID_SoftwareVersionNumber: {
    uint8_t version[4] = {'\0', '\0', '\0', '\0'};
    uint8_t status = SessionData::ReadBufferFromEEPROM(
        MEM_RDID_SoftwareVersionNumber_Location, version,
        MEM_RDID_SoftwareVersionNumber_Size);
    if (status == 0) {
      AddByteArrayToRespBuffer(version, MEM_RDID_SoftwareVersionNumber_Size);
    } else {
      return NRC::GeneralProgrammingFailure;
    }
    break;
  }
  case RDID_EngineType: {
    uint8_t type[13] = {'\0', '\0', '\0', '\0', '\0', '\0', '\0',
                        '\0', '\0', '\0', '\0', '\0', '\0'};
    uint8_t status = SessionData::ReadBufferFromEEPROM(
        MEM_RDID_EngineType_Location, type, MEM_RDID_EngineType_Size);
    if (status == 0) {
      AddByteArrayToRespBuffer(type, MEM_RDID_EngineType_Size);
    } else {
      return 1;
    }
    break;
  }
  case RDID_ASAM_ODX_File_Identifier: {
    for (size_t i = 0; i < 25; i++)
      AddByteToRespBuffer('_');
    break;
  }
  case RDID_ECUHardwareVersionNumber: {
    AddByteToRespBuffer('-');
    AddByteToRespBuffer('-');
    AddByteToRespBuffer('-');
  }
  case RDID_FDSProjectData: {
    uint8_t arr[] = {0x00, 0x00, 0x00, 0x0A, 0x75, 0x00, 0x00};
    AddByteArrayToRespBuffer(arr, sizeof(arr) / sizeof(uint8_t));
    break;
  }
  case 0xFFFF: {
    uint16_t address =
        ((uint16_t)message[3] << 8) | ((uint16_t)message[4] & 0xFF);
    switch (address) {
    case RDID_SoftwareVersionNumber: {
      uint8_t version[MEM_RDID_SoftwareVersionNumber_Size] = {'X', '_', '0',
                                                              '0'};
      if (currentSession.WriteBufferToEEPROM(
              MEM_RDID_SoftwareVersionNumber_Location, version,
              MEM_RDID_SoftwareVersionNumber_Size) != 0) {
        return 1;
      }
      break;
    }
    case RDID_EngineType: {
      uint8_t version[MEM_RDID_EngineType_Size] = {
          'g', 'a', 's', 'o', 'l', 'i', 'n', 'e', '-', '-', '-', '-', '-'};
      if (currentSession.WriteBufferToEEPROM(MEM_RDID_EngineType_Location,
                                             version,
                                             MEM_RDID_EngineType_Size) != 0) {
        return 1;
      }
      break;
    }
    default:
      return 0;
    }

    break;
  }
  default:
    return NRC::RequestOutOfRange;
  }
  return 0;
}

void ReadDataByIdentifierHandler::PostHandle() {}
