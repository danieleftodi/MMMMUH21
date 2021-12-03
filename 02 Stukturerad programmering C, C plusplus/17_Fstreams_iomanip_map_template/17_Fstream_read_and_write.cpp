#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool bWriteRecordToFileBegin = false;

// Step 1: Write to a .txt file
bool writeRecordToFile (string file_name, string field_one, string field_two, string field_three)
{
	ofstream file;
	
    if (bWriteRecordToFileBegin)
    {
         file.open(file_name, ios_base::app);    // append to file
    }
    else
    {
        file.open(file_name, ios_base::trunc); 		 // over-write file
        bWriteRecordToFileBegin = true;
    }
	file << field_one << ";" << field_two << ";" << field_three << endl;
	file.close();

	return 0;
}

// Step 2: Read from a .txt file
vector<string> readRecordFromFile (string file_name, string search_term)
{
	vector<string> record;
	ifstream file;
	file.open(file_name);

	bool found_record = false;

	string field_one;
	string field_two;
	string field_three;

    for ( int i = 0; getline(file, field_one, ';') && !found_record; i++)
	{
		getline(file, field_two, ';');
		getline(file, field_three, '\n');

        printf("VEC[%d]: %s\n", i, field_one.c_str());
        printf("VEC[%d]: %s\n", i, field_two.c_str());
        printf("VEC[%d]: %s\n\n", i, field_three.c_str());

		if(field_one == search_term)
		{
			found_record = true;
            printf("Found Record: VEC[%d]\n\n", i);
			record.push_back(field_one);
			record.push_back(field_two);
			record.push_back(field_three);
            break;
		}
	}
    
    if (!found_record)
    {
        record.push_back("Null");
        record.push_back("Null");
        record.push_back("Null");
    }

	file.close();
	return record;
}

int main ()
{
	// Step 1: Write to a .txt file
    bool writeToFile;
    
    writeToFile = writeRecordToFile("17_Fstream_read_and_write.txt", "2395", "Daniel", "1981");
    printf("writeToFile: %d\n", writeToFile);
    
    writeToFile = writeRecordToFile("17_Fstream_read_and_write.txt", "1234", "Ludwig", "1997");
    printf("writeToFile: %d\n\n", writeToFile);
    

	// Step 2: Read from a .txt file
	vector<string> Result = readRecordFromFile("17_Fstream_read_and_write.txt", "1234");

	// Step 3: Print result ...
	cout << "Result: " << endl << Result[0] << endl << Result[1] << endl << Result [2] << endl << endl;

	return 0;
}
