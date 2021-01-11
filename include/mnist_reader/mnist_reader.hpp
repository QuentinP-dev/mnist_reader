

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
*\version 1.1
*\date 18/12/2020
*/

#ifndef MNIST_READER_HPP_INCLUDED
#define MNIST_READER_HPP_INCLUDED

/*!
*\def MNIST_READER_STATIC_CLASS
*\Define MNIST_READER_SATIC_CLASS at compilation time to use the MnistReader class as a static class.
*/
#ifdef MNIST_READER_STATIC_CLASS
	#define STATIC static
	#define CONST
	#define VIRTUAL
#else
	#define STATIC
	#define CONST const

	/*!
	*\def MNIST_READER_SUPER_CLASS
	*\Define MNIST_READER_SUPER_CLASS at compilation time to use the MnistReader class as a super class.
	*/
	#ifdef MNIST_READER_SUPER_CLASS
		#define VIRTUAL virtual
	#else
		#define VIRTUAL
	#endif
#endif

#include <vector>

/*!
*\namespace qplib Namespace of my personal lib
*/
namespace qplib
{

/*!
*\class MnistReader mnist_reader.hpp "mnist_reader.hpp"
*\brief A C++ class to read, store and use the mnist database.
*/
class MnistReader
{
protected:

    /**paths to the label and data files **/
	STATIC std::string _pathToTestDataset;
	STATIC std::string _pathToTrainingDataset;
	STATIC std::string _pathToTestLabels;
	STATIC std::string _pathToTrainingLabels;

    /** the 2 dataset **/
	STATIC std::vector<std::vector<uint8_t>> _dtrain, _dtest;

	/** the 2 labelset **/
	STATIC std::vector<uint8_t> _ltrain,_ltest;

	/** current dataset **/
	STATIC std::vector<std::vector<uint8_t>>* _data;

	/** current labelset **/
	STATIC std::vector<uint8_t>* _label;

	/** private loading function used by public ones **/
	STATIC void loadData(bool testset);

	STATIC void loadLabel(bool testset);

	#ifdef MNIST_READER_STATIC_CLASS
	/*!
	*\brief Virtual pure destructor : instantiation disabled
	*/
	virtual ~MnistReader()=0;
	#endif

public:

	#ifndef MNIST_READER_STATIC_CLASS

	/*!
	*\brief Default constructor.
	*/
	MnistReader(void){};

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

	#endif

	#ifdef MNIST_READER_SUPER_CLASS
	/*!
	*\brief Virtual destructor
	*/
	virtual ~MnistReader(){};
	#endif

	/*!
	*\brief Load all the database files.
	*\return void
	*/
	VIRTUAL STATIC void load(void);

	/*!
	*\brief Load the training dataset file.
	*\return void
	*/
	VIRTUAL STATIC void loadTrainingDataset(void);

	/*!
	*\brief Load the test dataset file.
	*\return void
	*/
	VIRTUAL STATIC void loadTestDataset(void);

	/*!
	*\brief Load the training labels file.
	*\return void
	*/
	VIRTUAL STATIC void loadTrainingLabels(void);

	/*!
	*\brief Load the test labels file.
	*\return void
	*/
	VIRTUAL STATIC  void loadTestLabels(void);

	/*!
	*\brief Set the using dataset to the training dataset.
	*\return void
	*/
	VIRTUAL STATIC void useTrainingDataset(void);

	/*!
	*\brief Set the using dataset to the test dataset.
	*\return void
	*/
	VIRTUAL STATIC void useTestDataset(void);

	/*!
	*\brief Set the path to the test dataset file.
	*\param[in] path std::string : path to the test dataset file.
	*\return void
	*/
	VIRTUAL STATIC void setPathToTestDataset(std::string path);

	/*!
	*\brief Set the path to the training dataset file.
	*\param[in] path std::string : path to the training dataset file.
	*\return void
	*/
	VIRTUAL STATIC void setPathToTrainingDataset(std::string path);

	/*!
	*\brief Set the path to the test labels file.
	*\param[in] path std::string : path to the test labels file.
	*\return void
	*/
	VIRTUAL STATIC void setPathToTestLabels(std::string path);

	/*!
	*\brief Set the path to the training labels file.
	*\param[in] path std::string : path to the training labels file.
	*\return void
	*/
	VIRTUAL STATIC void setPathToTrainingLabels(std::string path);

	/*!
	*\brief Return the id_image image of the used dataset with all its values normalized between 0 and 1.
	*\param[in] id_image size_t : the index of the image.
	*\return std::vector<double> : the normalized image at the index id_image.
	*/
	VIRTUAL STATIC std::vector<double> getImageNormalized(size_t id_image) CONST;

	/*!
	*\brief Return the i pixel of the id_image image of the used dataset.
	*The pixel is normalized between 0 and 1.
	*\param[in] id_image size_t : the index of the image.
	*\param[in] i size_t : the index of the pixel.
	*\return double : the normalized pixel at the index i of the image at the index id_image.
	*/
	VIRTUAL STATIC double getDataNormalized(size_t id_image,size_t i) CONST;

	/*!
	*\brief Return the [i,j] pixel of the id_image image of the used dataset.
	*The pixel is normalized between 0 and 1.
	*\param[in] id_image size_t : the index of the image.
	*\param[in] i uint8_t : the index of the colum's pixel.
	*\param[in] j uint8_t : the index of the line's pixel.
	*\return double : the normalized pixel at the index [i,j] of the image at the index id_image.
	*/
	VIRTUAL STATIC double getDataNormalized(size_t id_image,uint8_t i,uint8_t j) CONST;

	/*!
	*\brief Return the id_image image of the used dataset.
	*\param[in] id_image size_t : the index of the image.
	*\return std::vector<uint8_t> : the image at the index id_image.
	*/
	VIRTUAL STATIC std::vector<uint8_t> getImage(size_t id_image) CONST;

	/*!
	*\brief Return the i pixel of the id_image image of the used dataset.
	*\param[in] id_image size_t : the index of the image.
	*\param[in] i size_t : the index of the pixel.
	*\return uint8_t : the pixel at the index i of the image at the index id_image.
	*/
	VIRTUAL STATIC uint8_t getData(size_t id_image,size_t i) CONST;

	/*!
	*\brief Return the [i,j] pixel of the id_image image of the used dataset.
	*\param[in] id_image size_t : the index of the image.
	*\param[in] i uint8_t : the index of the colum's pixel.
	*\param[in] j uint8_t : the index of the line's pixel.
	*\return uint8_t : the pixel at the index [i,j] of the image at the index id_image.
	*/
	VIRTUAL STATIC uint8_t getData(size_t id_image,uint8_t i,uint8_t j) CONST;

	/*!
	*\brief Return the i label of the used dataset.
	*\param[in] i size_t : the index of the label.
	*\return uint8_t : the label at the index i.
	*/
	VIRTUAL STATIC uint8_t getLabel(size_t i) CONST;

	/*!
	*\brief Return the size of images in the dataset.
	*\return size_t : size of images.
	*/
	VIRTUAL STATIC size_t getDataSize(void) CONST;

	/*!
	*\brief Return number of image in the used dataset.
	*\return size_t : number of image.
	*/
	VIRTUAL STATIC size_t getNumberOfData(void) CONST;
};

} // end namespace


#endif // MNIST_READER_HPP_INCLUDED
