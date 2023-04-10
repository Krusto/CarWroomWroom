#include "File.h"
#include <fstream>

File::File(const char *path,FileFormat format){
    this->m_Path = path;
    this->m_FileFormat = format;
}
void File::Init(const char* path, FileFormat format){
    m_Path = path;
    m_FileFormat = format;
}
std::vector<uint8_t> File::ReadBinaryData() {
    if(!m_Opened){
        std::fstream file(m_Path,std::ios::in | std::ios::binary);
        if(file.good()) {
            m_Opened = true;
        }else{
            return {};
        }
        file.seekg(0, std::ios::end);
        size_t length = file.tellg();
        file.seekg(0, std::ios::beg);
        std::vector<uint8_t> buffer(length);
        file.read((char*)buffer.data(), length);
        file.close();
        m_Opened = false;

        return buffer;
    }
    return {};
}
std::string File::ReadTextData() {
    if(!m_Opened){
        std::fstream file(m_Path,std::ios::in);
        if(file.good()) {
            m_Opened = true;
        }else{
            return std::string();
        }
        file.seekg(0, std::ios::end);
        size_t length = file.tellg();
        file.seekg(0, std::ios::beg);
        std::string buffer;
        buffer.resize(length);
        file.read(&buffer[0], length);
        file.close();
        m_Opened = false;
        return buffer;
    }
    return std::string();
}