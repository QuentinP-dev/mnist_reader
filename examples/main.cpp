#include "mnist_reader.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	/** create the reader **/
    MnistReader mnr;

	/** set the path to the database files, here it s in the same folder **/
    mnr.setPathToTestDataset("t10k-images.idx3-ubyte");
    mnr.setPathToTestlabels("t10k-labels.idx1-ubyte");

	/** load the test dataset and the test labels **/
    mnr.loadTestDataset();
    mnr.loadTestLabels();

	/** select wich dataset the reader will use **/
    mnr.useTestDataset();

	/** init random **/
    srand(time(NULL));
	
	/** loop **/
	std::cout << "press e to exit\n";
	char a='a';
	while(a!='e')
	{
		/** choose a random image in the dataset **/
		size_t h=rand()%mnr.getNumberOfData();
	
		/** print the associted label of this image **/
		std::cout << "------------"
		<< static_cast<int>(mnr.getLabel(h))
		<< " -------------\n";

		/** print the image with "8" for "dark" pixels **/
		for(int j=0 ; j<28 ; j++)
		{
			for(int k=0 ; k<28 ; k++)
		    {
		   		std::cout << (mnr.getData(h,j*28+k)>150 ? "8" : " ");
		    }
		    std::cout << "\n";
	   	}
		/** e to exit **/
		std::cin >> a;
	}
   	return 0;
}
