#include <iostream>
#include <ctime>

#include "mnist_reader/mnist_reader.hpp"

class MyReader : public qplib::MnistReader
{
public:
	/** if MNIST_READER_SUPER_CLASS is not define, this function wont be called **/
	uint8_t getData(size_t id_image,uint8_t i,uint8_t j) const
	{
		if(i==0)
			return 255;
		if(j==0)
			return 255;
		if(i==27)
			return 255;
		if(j==27)
			return 255;
		return qplib::MnistReader::getData(id_image,i,j);
	}
};

int main()
{
	/** create a ptr of the super class **/
	qplib::MnistReader* reader;

	reader=new MyReader;

	/** set the path to the database files **/
	reader->setPathToTestDataset("datas/test_images");
	reader->setPathToTestLabels("datas/test_labels");

	/** load the test dataset and the test labels **/
	reader->loadTestDataset();
	reader->loadTestLabels();

	/** select wich dataset the reader will use **/
	reader->useTestDataset();

	/** init random **/
	srand(time(NULL));

	/** loop **/
	std::cout << "press e to exit\n";
	char a='a';

	/** id of the image **/
	size_t id;

	/** value on that image **/
	uint8_t temp;

	while(a!='e')
	{
		/** randomly select one image **/
		id=rand()%reader->getNumberOfData();

		/** print the associted label of this image **/
		std::cout << "--------------------------------"
		<< reader->getLabel(id)
		<< "--------------------------------\n";

		/** print the image with '8' for dark pixels and '|' for medium dark pixels **/
		for(int i=0 ; i<28 ; ++i)
		{
			for(int j=0 ; j<28 ; ++j)
		    {
		    	temp=reader->getData(id,j,i);
		    	if(temp>220)
		    		std::cout << '8';
		    	else if(temp>150)
		    		std::cout << '|';
		    	else
		    		std::cout << ' ';
		    }
		    std::cout << "\n";
	   	}
		/** e to exit **/
		std::cin >> a;
	}

	delete reader;
   	return 0;
}
