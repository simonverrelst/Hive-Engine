#include "HivePCH.h"
#include "BinaryWriter.h"

Hive::BinaryWriter::BinaryWriter()
{

}

Hive::BinaryWriter::~BinaryWriter()
{
	if (writeStream.is_open()) // if still open when we get destroyed then close stream
	{
		writeStream.close();
	}
}

bool Hive::BinaryWriter::OpenFile(const std::string& pathToWriteTo)
{
	filePath = pathToWriteTo;

	// if stream was already open close it
	if (writeStream.is_open())
		writeStream.close();

	writeStream.open(filePath, std::ios::out | std::ios::binary);

	if (!writeStream.is_open()) // Couldnt open the file
	{
		std::cout << "Could not open the file at path ( " << filePath << " ) \n";
		return false;
	} 
		
	return true;
}

void Hive::BinaryWriter::CloseFile()
{
	writeStream.close();
}

void Hive::BinaryWriter::WriteString(const std::string& string) noexcept
{
	unsigned int size = static_cast<unsigned int>(string.size());
	writeStream.write(reinterpret_cast<char*>(&size), sizeof(size));
	writeStream.write(string.c_str(), size);
}