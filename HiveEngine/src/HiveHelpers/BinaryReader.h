#pragma once
#include <iostream>
#include <fstream>
#include <type_traits>

namespace Hive 
{
	class BinaryReader
	{
	public:
		BinaryReader();
		~BinaryReader();

		bool OpenFile(const std::string& pathToWriteTo);
		void CloseFile();



		//Writes any POD type to file
		template<typename T>
		void Read(T& value);

		template<typename T>
		T Read();

		//Writes a string to file
		std::string ReadString();

	private:
		std::ifstream readStream;
		std::string filePath;

		bool CheckIsReadable();

	};

	template<typename T>
	inline void BinaryReader::Read(T& value)
	{
		if (CheckIsReadable())
		{
			readStream.read((char*)&value, sizeof(value));
		}
	}

	template<typename T>
	inline T BinaryReader::Read()
	{
		CheckIsReadable();

		T value;
		readStream.read((char*)&value, sizeof(value));
		return value;

	}
}


