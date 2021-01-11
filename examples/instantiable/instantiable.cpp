#include <iostream>
#include <ctime>

#include "mnist_reader/mnist_reader.hpp"

int main()
{
	/** create the reader **/
	qplib::MnistReader reader;

	/** set the path to the database files **/
	reader.setPathToTestDataset("datas/test_images");
	reader.setPathToTestLabels("datas/test_labels");

	/** load the test dataset and the test labels **/
	reader.loadTestDataset();
	reader.loadTestLabels();

	/** select wich dataset the reader will use **/
	reader.useTestDataset();

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
		id=rand()%reader.getNumberOfData();

		/** print the associted label of this image **/
		std::cout << "--------------------------------"
		<< reader.getLabel(id)
		<< "--------------------------------\n";

		/** print the image with '8' for dark pixels and '|' for medium dark pixels **/
		for(int i=0 ; i<28 ; ++i)
		{
			for(int j=0 ; j<28 ; ++j)
		    {
		    	temp=reader.getData(id,i*28+j);
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
