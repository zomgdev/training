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

	std::ofstream DataFile("./data_file.bin", std::ios_base::binary);

	DataFile.write((char*)&strct01.SizeOf, sizeof(strct01.SizeOf));
	DataFile.write((char*)&strct01.FileUID, sizeof(strct01.FileUID));
	DataFile.write((char*)&strct01.StorageUID, sizeof(strct01.StorageUID));
	DataFile.write((char*)&strct01.FileSize, sizeof(strct01.FileSize));
	DataFile.write((char*)&strct01.FileReplicas, sizeof(strct01.FileReplicas));
	
	DataFile.write((char*)strct01.FileName.data(), strct01.FileName.length()+1);
	//DataFile.write((char*)strct01.FileName.data(), len);


	return 0;
}
