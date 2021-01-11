#include <iostream>
#include <ctime>

#include "mnist_reader/mnist_reader.hpp"

int main()
{
	/** Won't compile cause MnistReader is a static class **/
	// qplib::MnistReader reader;

	/** set the path to the database files **/
	qplib::MnistReader::setPathToTestDataset("datas/test_images");
	qplib::MnistReader::setPathToTestLabels("datas/test_labels");

	/** load the test dataset and the test labels **/
	qplib::MnistReader::loadTestDataset();
	qplib::MnistReader::loadTestLabels();

	/** select wich dataset the reader will use **/
	qplib::MnistReader::useTestDataset();

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
		id=rand()%qplib::MnistReader::getNumberOfData();

		/** print the associted label of this image **/
		std::cout << "--------------------------------"
		<< qplib::MnistReader::getLabel(id)
		<< "--------------------------------\n";

		/** print the image with '8' for dark pixels and '|' for medium dark pixels **/
		for(int i=0 ; i<28 ; ++i)
		{
			for(int j=0 ; j<28 ; ++j)
		    {
		    	temp=qplib::MnistReader::getData(id,i*28+j);
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
   	return 0;
}
