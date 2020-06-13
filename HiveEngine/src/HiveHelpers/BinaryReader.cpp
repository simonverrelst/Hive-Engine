#include "HivePCH.h"
#include "BinaryReader.h"

Hive::BinaryReader::BinaryReader()
{
}

Hive::BinaryReader::~BinaryReader()
{
	if (readStream.is_open()) // if still open when we get destroyed then close stream
	{
		readStream.close();
	}
}

bool Hive::BinaryReader::OpenFile(const std::string& pathToWriteTo)
{
	filePath = pathToWriteTo;

	// if stream was already open close it
	if (readStream.is_open())
		readStream.close();

	readStream.open(filePath, std::ios::in | std::ios::binary);

	if (!readStream.is_open()) // Couldnt open the file
	{
		std::cout << "Could not open the file at path ( " << filePath << " ) \n";
		return false;
	}
	
	return true;
}

void Hive::BinaryReader::CloseFile()
{
	readStream.close();
}

bool Hive::BinaryReader::CheckIsReadable()
{
	if (readStream.eof()) {
		readStream.close();
		return false;
	}
	return true;
}

std::string Hive::BinaryReader::ReadString()
{
	if (CheckIsReadable()) 
	{
		std::string buffer{};
		size_t readSize{};

		// read string size
		readStream.read(reinterpret_cast<char*>(&readSize), sizeof(readSize));
		buffer.resize(readSize);

		// read string into buffer
		readStream.read(&buffer[0], readSize);
		return buffer;
	}
	else {
		std::cout << "EOF Reached returning \" \" \n";
		return "";
	}
	
}
