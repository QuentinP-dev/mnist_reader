

//********************************************************************
// mnist_reader gives an easy way to read and managedthe mnist database	
// Copyright (C) 2020 Quentin Putaud
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see http://www.gnu.org/licenses
//********************************************************************


#ifndef MNIST_READER_HPP_INCLUDED
#define MNIST_READER_HPP_INCLUDED

#include <string>
#include <vector>

class MnistReader
{
private:

    	/**paths to the label and data files **/
	std::string _pathToTestDataset;
	std::string _pathToTrainingDataset;
	std::string _pathToTestLabels;
	std::string _pathToTrainingLabels;

    	/** the 2 dataset **/
	std::vector<std::vector<unsigned char>> _dtrain, _dtest;

	/** the 2 labelset **/
	std::vector<unsigned char> _ltrain,_ltest;

	/** current dataset **/
	std::vector<std::vector<unsigned char>> *_data=nullptr; // set to training set by default at initialisation

	/** current labelset **/
	std::vector<unsigned char> *_label=nullptr; // set to training set by default at initialisation

	/** private loading function used by public ones **/
	void loadData(bool testset);

	void loadLabel(bool testset);

public:

	/** ----- constructor ----- **/

	// default
	MnistReader(){};

	//with the path to the mnist files and an option to load all
	MnistReader(std::string pathToTrainingDataset,
                std::string pathToTrainingLabels,
                std::string pathToTestDataset,
                std::string pathToTestLabels, bool loadAll=false);

	/** ---- destructor ------ **/

	// default

	/** ------ member fonction ----- **/

	/** load all **/
	void load();

	/** load training dataset **/
	void loadTrainingDataset();

	/** load test dataset **/
	void loadTestDataset();

	/** load training labels **/
	void loadTrainingLabels();

	/** load test labels **/
	void loadTestLabels();

	/** ------ set ------ **/

	/** change the using dataset **/
	void useTrainingDataset();
	void useTestDataset();

	/** set the path to the mnist files **/
	void setPathToTestDataset(std::string path);
	void setPathToTrainingDataset(std::string path);
	void setPathToTestlabels(std::string path);
	void setPathToTrainingLabels(std::string path);

	/** ------ get ------ **/

	/** return the i image of the dataset with all pixel normalized **/
	std::vector<double> getImageNormalized(size_t i);

	/** return the j pixel normalized of the i image of the dataset **/
	double getDataNormalized(size_t i,size_t j);

	/** return the i image of the dataset **/
	std::vector<unsigned char> getImage(size_t i);

	/** return the j pixel of the i image of the dataset **/
	unsigned char getData(size_t i,size_t j);

	/** return the i label **/
	char getLabel(size_t i);

	/** return the size of a data **/
	size_t getDataSize();

	/** return the number of data in the dataset **/
	size_t getNumberOfData();
};

#endif // MNIST_READER_HPP_INCLUDED
