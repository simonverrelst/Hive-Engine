#pragma once
#include <iostream>
#include <fstream>
#include <type_traits>

namespace Hive
{
	class BinaryWriter
	{


	public:
		BinaryWriter();
		~BinaryWriter();

		bool OpenFile(const std::string& pathToWriteTo);
		void CloseFile();


		//Writes any POD type to file
		template<typename T>
		void Write(T& value);

		//Writes a string to file
		void WriteString(const std::string& string) noexcept;

	private:

		std::ofstream writeStream;
		std::string filePath;
	};

	template<typename T>
	inline void BinaryWriter::Write(T& value)
	{
		if (!std::is_pod<T>()) {
			std::cout << "is not a POD. Didn't write to file! \n";
			return;
		}

		writeStream.write(reinterpret_cast<char*>(&value), sizeof(value));
	}
}


