

//********************************************************************
// mnist_reader.hpp defines a class to read, store a use the mnist
// database in C++
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


/*!
*\file mnist_reader.hpp
*\author Quentin Putaud
*\version 1.0
*\date 20/04/2020
*/

#ifndef MNIST_READER_HPP_INCLUDED
#define MNIST_READER_HPP_INCLUDED

#include <vector>

/*!
*\class MnistReader mnist_reader.hpp "mnist_reader.hpp"
*\brief A C++ class to read, store and use the mnist database.
*/
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

	/*!
	*\brief Default constructor.
	*/
	MnistReader(){};

	/*!
	*\brief Constructor with all paths to the mnist database files.
	*\param[in] pathToTrainingDataset std::string : path to the training dataset file.
	*\param[in] pathToTrainingLabels std::string : path to the training labels file.
	*\param[in] pathToTestDataset std::string : path to the test dataset file.
	*\param[in] pathToTestLabels std::string : path to the test labels file.
	*\param[in] loadAll bool : if set to true, directly load all the database files. Set to false by default.
	*/
	MnistReader(std::string pathToTrainingDataset,
                std::string pathToTrainingLabels,
                std::string pathToTestDataset,
                std::string pathToTestLabels, bool loadAll=false);

	/*!
	*\brief Load all the database files.
	*\return void
	*/
	void load();

	/*!
	*\brief Load the training dataset file.
	*\return void
	*/
	void loadTrainingDataset();

	/*!
	*\brief Load the test dataset file.
	*\return void
	*/
	void loadTestDataset();

	/*!
	*\brief Load the training labels file.
	*\return void
	*/
	void loadTrainingLabels();

	/*!
	*\brief Load the test labels file.
	*\return void
	*/
	void loadTestLabels();

	/*!
	*\brief Set the using dataset to the training dataset.
	*\return void
	*/
	void useTrainingDataset();
	
	/*!
	*\brief Set the using dataset to the test dataset.
	*\return void
	*/
	void useTestDataset();

	/*!
	*\brief Set the path to the test dataset file.
	*\param[in] path std::string : path to the test dataset file.
	*\return void
	*/
	void setPathToTestDataset(std::string path);
	
	/*!
	*\brief Set the path to the training dataset file.
	*\param[in] path std::string : path to the training dataset file.
	*\return void
	*/
	void setPathToTrainingDataset(std::string path);
	
	/*!
	*\brief Set the path to the test labels file.
	*\param[in] path std::string : path to the test labels file.
	*\return void
	*/
	void setPathToTestlabels(std::string path);
	
	/*!
	*\brief Set the path to the training labels file.
	*\param[in] path std::string : path to the training labels file.
	*\return void
	*/
	void setPathToTrainingLabels(std::string path);

	/*!
	*\brief Return the i image of the used dataset with all its values normalized between 0 and 1.
	*\param[in] i size_t : the index of the image.
	*\return std::vector<double> : the normalized image at the index i.
	*/
	std::vector<double> getImageNormalized(size_t i);

	/*!
	*\brief Return the j pixel of the i image of the used dataset.
	*The pixel is normalized between 0 and 1.
	*\param[in] i size_t : the index of the image.
	*\param[in] j size_t : the index of the pixel.
	*\return double : the normalized pixel at the index j of the image at the index i.
	*/
	double getDataNormalized(size_t i,size_t j);

	/*!
	*\brief Return the i image of the used dataset.
	*\param[in] i size_t : the index of the image.
	*\return std::vector<unsigned char> : the image at the index i.
	*/
	std::vector<unsigned char> getImage(size_t i);

	/*!
	*\brief Return the j pixel of the i image of the used dataset.
	*\param[in] i size_t : the index of the image.
	*\param[in] j size_t : the index of the pixel.
	*\return unsigned char : the pixel at the index j of the image at the index i.
	*/
	unsigned char getData(size_t i,size_t j);

	/*!
	*\brief Return the i label of the used dataset.
	*\param[in] i size_t : the index of the label.
	*\return char : the label at the index i.
	*/
	char getLabel(size_t i);

	/*!
	*\brief Return the size of images in the dataset.
	*\return size_t : size of images.
	*/
	size_t getDataSize();

	/*!
	*\brief Return number of image in the used dataset.
	*\return size_t : number of image.
	*/
	size_t getNumberOfData();
};


#endif // MNIST_READER_HPP_INCLUDED
