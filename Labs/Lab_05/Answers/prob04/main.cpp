//
//  main.cpp
//  Phonebook Display
//
//  Created by Mark Icasas on 4/9/20.
//  Copyright © 2020 Mark Icasas. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    //INITIALIZE VARIABLES
    std::string f;
    
    //PROMPT USER TO INPUT FILE NAME
    std::cout << "Please provide the file name for your donation file: ";
    std::cin >> f;
    std::ifstream my_file;
    
    //OPEN FILE
    my_file.open(f);
    
    //IF FILE IS OPEN EXECUTE THE FOLLOWING
    if (my_file.is_open())
    {
        //INITIALIZE VARIABLES
        double line;
        double total_Don = 0;
        int don_Price;
        
        my_file >> don_Price;
        my_file.seekg(1, my_file.beg); //START AT 1 TO SKIP # OF DONATORS
        
        //LOOP TO DISPLAY DONATION & SUM
        for (int i = 1; i <= don_Price; i++)
        {
            //DISPLAY DONATIONs
            std::cout << "Donation " << i << ": $";
            my_file >> line;
            //DISPLAY PRICE IN 2 DECIMAL POINTS
            std::cout.precision(2);
            std::cout.setf(std::ios::fixed);
            std::cout << line << '\n';
            
            //CALCULATE TOTAL DONATION
            total_Don = total_Don + line;
        }
        //CLOSE FILE
        my_file.close();
        
        //DISPLAY TOTAL DONATION
        std::cout << "\n" << "Total donation: $" << total_Don << "\n";
    }
    //IF FILE IS INVALID
    else
    {
        std::cout << "Invalid donation file!" << "\n";
    }
    return 0;   //END PROGRAM
}
