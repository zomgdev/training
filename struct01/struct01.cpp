// training.cpp : Defines the entry point for the application.
//

#include "struct01.h"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	struct01 strct01;

	
	strct01.FileUID      = 1;
	strct01.StorageUID   = 1;
	strct01.FileSize     = 4398046511104;
	strct01.FileReplicas = 3;
	strct01.FileName     = "data.1";
	strct01.SizeOf = \
		sizeof(strct01.SizeOf) + \
		sizeof(strct01.FileUID) + \
		sizeof(strct01.StorageUID) + \
		sizeof(strct01.FileSize) + \
		sizeof(strct01.FileReplicas) + \
		strct01.FileName.length () + 1;
		
	cout << "sizeof strct01.SizeOf       " << sizeof(strct01.SizeOf) << endl;
	cout << "sizeof strct01.FileUID      " << sizeof(strct01.FileUID) << endl;
	cout << "sizeof strct01.StorageUID   " << sizeof(strct01.StorageUID) << endl;
	cout << "sizeof strct01.FileSize     " << sizeof(strct01.FileSize) << endl;
	cout << "sizeof strct01.FileReplicas " << sizeof(strct01.FileReplicas) << endl;
	cout << "sizeof strct01.FileName     " << strct01.FileName.length() + 1 << endl;

	cout << "sizeof strct01: " << strct01.SizeOf << endl;
	cout << "sizeof string: " << strct01.FileName.size() << endl << endl;

	cout << "strct01.SizeOf       " << strct01.SizeOf << endl;
	cout << "strct01.FileUID      " << strct01.FileUID << endl;
	cout << "strct01.StorageUID   " << strct01.StorageUID << endl;
	cout << "strct01.FileSize     " << strct01.FileSize << endl;
	cout << "strct01.FileReplicas " << unsigned(strct01.FileReplicas) << endl;
	cout << "strct01.FileName     " << strct01.FileName.c_str() << endl;

	//cout << "UINT64_MAX" << UINT64_MAX << endl;
	//cout << 4 * 1024 * 1024 * 1024 << endl;

	std::fstream DataFile("./data_file.bin", DataFile.binary | DataFile.in | DataFile.out | DataFile.trunc);
	if (!DataFile.is_open()) {
		cout << "Ooops, ./data_file.bin isnt open." << endl;

	}
	else {
	DataFile.write(reinterpret_cast<char*>(&strct01.SizeOf), sizeof(strct01.SizeOf));
	DataFile.write(reinterpret_cast<char*>(& strct01.FileUID), sizeof(strct01.FileUID));
	DataFile.write(reinterpret_cast<char*>(& strct01.StorageUID), sizeof(strct01.StorageUID));
	DataFile.write(reinterpret_cast<char*>(& strct01.FileSize), sizeof(strct01.FileSize));
	DataFile.write(reinterpret_cast<char*>(& strct01.FileReplicas), sizeof(strct01.FileReplicas));
	
	DataFile.write(reinterpret_cast<char*>(strct01.FileName.data()), strct01.FileName.length()+1);

	//DataFile.write((char*)strct01.FileName.data(), len);


	DataFile.seekp(0);
	struct01 tSt;

	DataFile.read(reinterpret_cast<char*>(&tSt.SizeOf), 2);

	cout << "Get struct size bytes: " << unsigned(tSt.SizeOf) << endl;

	DataFile.seekp(0);
	DataFile.read(reinterpret_cast<char*>(&tSt.SizeOf), 2);
	DataFile.read(reinterpret_cast<char*>(&tSt.FileUID), 8);
	DataFile.read(reinterpret_cast<char*>(&tSt.StorageUID), 4);
	DataFile.read(reinterpret_cast<char*>(&tSt.FileSize), 8);
	DataFile.read(reinterpret_cast<char*>(&tSt.FileReplicas), 1);
	
	char *buf = new char[tSt.SizeOf-23];

	DataFile.read(reinterpret_cast<char*>(buf), 7);
	tSt.FileName = buf;
	//DataFile >> tSt.FileName;

	// check results
	cout << "SizeOf       " << tSt.SizeOf << endl;
	cout << "FileUID      " << tSt.FileUID << endl;
	cout << "StorageUID   " << tSt.StorageUID << endl;
	cout << "FileSize     " << tSt.FileSize << endl;
	cout << "FileReplicas " << unsigned(tSt.FileReplicas) << endl;
	cout << "FileName     " << tSt.FileName << endl;


	}


	return 0;
}
