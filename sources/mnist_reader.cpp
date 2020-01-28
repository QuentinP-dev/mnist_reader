

//**********************************************************************//
// mnist_reader gives an easy way to read and managedthe mnist database	//
// Copyright (C) 2020 Quentin Putaud									//
//																		//
// This program is free software: you can redistribute it and/or modify	//
// it under the terms of the GNU General Public License as published by	//
// the Free Software Foundation, either version 3 of the License, or	//
// (at your option) any later version.									//
//																		//
// This program is distributed in the hope that it will be useful,		//
// but WITHOUT ANY WARRANTY; without even the implied warranty of		//
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the		//
// GNU General Public License for more details.							//
//																		//
// You should have received a copy of the GNU General Public License	//
// along with this program.  If not, see http://www.gnu.org/licenses	//
//**********************************************************************//


#include <fstream>
#include <iostream>

#include "mnist_reader.hpp"
#include "endianess.hpp"

/** ----- private ----- **/

void MnistReader::loadData(bool testset)
{
	Endianess cp_endianess=getComputerEndianess(); // endianess of the computer running the program

	std::string *path=&_pathToTrainingDataset; // used path, set by default to the training set
	std::vector<std::vector<unsigned char>> *data=nullptr; // pointer to the vector where the data will be loaded

	if(testset) // if test dataset
		path=&_pathToTestDataset;
	std::ifstream file((*path).c_str(),std::ios::binary); // binary file writen in big endian

    if (file.is_open())
    {
        unsigned int magic_number=0; //0 - 3 bytes of the file, must be 2051.
        unsigned int number_of_images=0; // 4 - 7
        unsigned int n_rows=0; // 8 - 11
        unsigned int n_cols=0; // 12 - 15
					  // 16 - end -> datas

        file.read((char*)&magic_number,sizeof(int));
		if(cp_endianess==Endianess::LittleEndian) //not the same endianess, must reverse the int bytes by bytes
			magic_number=changeEndianess(magic_number);
		if(magic_number==2051) //if not, wrong or corrupted file
		{
			file.read((char*)&number_of_images,sizeof(int));
			if(cp_endianess==Endianess::LittleEndian)
				number_of_images=changeEndianess(number_of_images);

			file.read((char*)&n_rows,sizeof(int));
			if(cp_endianess==Endianess::LittleEndian)
				n_rows=changeEndianess(n_rows);

			file.read((char*)&n_cols,sizeof(int));
			if(cp_endianess==Endianess::LittleEndian)
				n_cols=changeEndianess(n_cols);

			if(testset)
			{
                _dtest=std::vector<std::vector<unsigned char>>(number_of_images,std::vector<unsigned char>(n_rows*n_cols)); // allocation of the needed memory
				data=&_dtest;
			}
			else
			{
				_dtrain=std::vector<std::vector<unsigned char>>(number_of_images,std::vector<unsigned char>(n_rows*n_cols));
				data=&_dtrain;
			}
            for(size_t i=0 ; i<number_of_images ; ++i) // for each images
            {
                for(size_t j=0 ; j<n_rows*n_cols ; ++j) // for each pixel of the images (n_rows * n_cols)
                {
                    unsigned char temp;
                    file.read((char*)&temp,sizeof(unsigned char));
                    (*data)[i][j]=temp;
                }
            }
        }
		else // if magic_number != 2051
		{
			std::cerr << "Wrong or corrupted file : " << (*path) << "\n";
		}

    }
	else // file.is_open() retrun false
	{
		std::cerr << "Cannot open the file : " << (*path) << "\n";
	}
	file.close();
	_data=&_dtrain;
	if(testset)
        _data=&_dtest;
}

void MnistReader::loadLabel(bool testset)
{
	Endianess cp_endianess=getComputerEndianess(); // endianess of the computer running the program

	std::string *path=&_pathToTrainingLabels; // used path, set by default to the training set
	std::vector<unsigned char> *label; // pointer to the vector where the data will be loaded
	if(testset) // if test labels
		path=&_pathToTestLabels;
	std::ifstream file((*path).c_str(),std::ios::binary); // binary file writen in big endian

	if(file.is_open())
	{
    	unsigned int magic_number=0; //0 - 3 bytes of the file, must be 2049.
        unsigned int number_of_labels=0; // 4 - 7
					  			// 8 - end -> datas

        file.read((char*)&magic_number,sizeof(int));
		if(cp_endianess==Endianess::LittleEndian) //not the same endianess, must reverse the int bytes by bytes
			magic_number=changeEndianess(magic_number);
		if(magic_number==2049) //if not, wrong or corrupted file
		{
			file.read((char*)&number_of_labels,sizeof(int));
			if(cp_endianess==Endianess::LittleEndian)
				number_of_labels=changeEndianess(number_of_labels);

			if(testset)
			{
				_ltest=std::vector<unsigned char>(number_of_labels); // allocation of the needed memory
				label=&_ltest;
			}
			else
			{
				_ltrain=std::vector<unsigned char>(number_of_labels);
				label=&_ltrain;
			}
            for(size_t i=0 ; i<number_of_labels ; ++i) // for each label
            {
                unsigned char temp;
                file.read((char*)&temp,sizeof(unsigned char));
                (*label)[i]=temp;
            }
        }
		else // if magic_number != 2049
		{
			std::cerr << "Wrong or corrupted file : " << (*path) << "\n";
		}

    }
	else // file.is_open() retrun false
	{
		std::cerr << "Cannot open the file : " << (*path) << "\n";
	}
	file.close();
	_label=&_ltrain;
	if(testset)
        _label=&_ltest;
}

/** ----- public ----- **/

MnistReader::MnistReader(std::string pathToTrainingDataset, std::string pathToTrainingLabels, std::string pathToTestDataset, std::string pathToTestLabels, bool loadAll)
{
    _pathToTrainingDataset=pathToTrainingDataset;
    _pathToTestDataset=pathToTestDataset;
    _pathToTrainingLabels=pathToTrainingLabels;
    _pathToTestLabels=pathToTestLabels;
	if(loadAll)
	{
		load(); // load all
	}
}

void MnistReader::load()
{
	loadData(false); // training dataset
	loadData(true); // test dataset
	loadLabel(false); // training label
	loadData(true); // test label
}

void MnistReader::loadTrainingDataset()
{
	loadData(false);
}

void MnistReader::loadTestDataset()
{
	loadData(true);
}

void MnistReader::loadTrainingLabels()
{
	loadLabel(false);
}

void MnistReader::loadTestLabels()
{
	MnistReader::loadLabel(true);
}

void MnistReader::useTrainingDataset()
{
	_data=&_dtrain;
	_label=&_ltrain;
}

void MnistReader::useTestDataset()
{
	_data=&_dtest;
	_label=&_ltest;
}

void MnistReader::setPathToTestDataset(std::string path)
{
	_pathToTestDataset=path;
}

void MnistReader::setPathToTrainingDataset(std::string path)
{
	_pathToTrainingDataset=path;
}

void MnistReader::setPathToTestlabels(std::string path)
{
	_pathToTestLabels=path;
}

void MnistReader::setPathToTrainingLabels(std::string path)
{
	_pathToTrainingLabels=path;
}

std::vector<double> MnistReader::getImageNormalized(size_t i)
{
	std::vector<double> img=std::vector<double>((*_data)[i].size()); // create a new vector with doubles
	for(size_t j=0 ; j<img.size() ; ++j) // normalize dividing by 255 each pixel of the i image and store it in the new vector
		img[j]=static_cast<double>((*_data)[i][j])/255;
	return img;
}

double MnistReader::getDataNormalized(size_t i,size_t j)
{
	return static_cast<double>((*_data)[i][j])/255; // normalized the j pixel of the i image dividing it by 255 and cast it in double
}

std::vector<unsigned char> MnistReader::getImage(size_t i)
{
	return (*_data)[i];
}

unsigned char MnistReader::getData(size_t i,size_t j)
{
	return (*_data)[i][j];
}

char MnistReader::getLabel(size_t i)
{
	return (*_label)[i];
}

size_t MnistReader::getDataSize()
{
	return (*_data)[0].size();
}

size_t MnistReader::getNumberOfData()
{
	return (*_data).size();
}
