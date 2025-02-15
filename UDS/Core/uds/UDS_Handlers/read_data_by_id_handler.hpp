#pragma once

#include "service_handler.h"

#include <string_view>

#define RDID_Logical_Software_Block_Counter_Of_Programming_Attempts 0x0407
#define RDID_Logical_Software_Block_Lock_Value 0x040F
#define RDID_BootloaderTPBlocksize 0x0410
#define RDID_ActiveDiagnosticSession 0xF186
#define RDID_SparePartNumber 0xF187
#define RDID_logical_block_downgrade_protection_versions 0x0189
#define RDID_SoftwareVersionNumber 0xF189
#define RDID_ECUHardwareNumber 0xF191
#define RDID_EngineType 0xF197
#define RDID_ASAM_ODX_File_Identifier 0xF19E
#define RDID_ECUHardwareVersionNumber 0xF1A3
#define RDID_FDSProjectData 0xF1D5

class ReadDataByIdentifierHandler : public ServiceHandler {
public:
  ReadDataByIdentifierHandler();

  virtual void Init() override {}

  virtual void Destroy() override{};

  virtual void MainHandle(Message message) override;

  virtual void PostHandle() override;

  static std::string_view GetName() { return "ReadDataByIdentifier handler"; };

private:
  int HandleDID(uint16_t did, Message &message);
};