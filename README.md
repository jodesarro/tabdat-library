# TABdat library: A set of C++ functions for dealing with tabular numeric data files

<p align="right"><a href="README.pt-br.md">Leia em português (br)</a></p>

Tabular data files have a structure in which lines are separated by line breaks and columns are separated by tabular spacing. It is a very useful format for importing and exporting matrices, tables, numeric datasets, and so on. Such files are generally used for importing and exporting data in software such as Google Sheets, Microsoft Excel, Wolfram Mathematica (in [.dat Table format](https://reference.wolfram.com/language/ref/format/Table.html)), among others.

## Available functions

- Get the dimensions (number of rows and columns) of a tabular numeric data file
```
void tabdat_getsize( std::string tabdat_path, int &rows, int &columns )
```

- Import numeric data from a tabular data file and store the values in an one-dimensional array
```
void tabdat_import( std::string tabdat_path, double * data_array, int rows, int columns )
```

- Export numeric data of an one-dimensional array to a tabular numeric data file
```
void tabdat_export( std::string tabdat_path, double * data_array, int rows, int columns, int out_precision = 0, bool out_scientific = false )
```

## How to use

The library is in a header-only library style, i.e., there is nothing to build, you only have to include the <a href="tabdat-library.hpp">*tabdat-library.hpp*</a> file into your project.

## Usage examples

The following is an example of how one can export numeric data of an one-dimensional array to a tabular data file using C++.
```
#include <iostream>
#include "tabdat-library.hpp"

int main()
{

    // Declaring the number of rows and columns
    int rows = 10;
    int columns = 20;

    // Declaring and dynamic allocating a 1D array
    double * my_array = new double [ rows*columns ];

    // Storing any value to the elements of the array
    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            my_array[ i + rows*j ] = 2.1*double(i) + 7.5*double(j);
        }
    }

    // Exporting the array to a tabular data file
    tabdat_export( "my_tabdat_file.dat", my_array, rows, columns );

    // Free the memory allocated for the array
    delete[] my_array;

}
```

The next is an example of how one can import numeric data from a tabular data file and print the data on the screen using C++.
```
#include <iostream>
#include "tabdat-library.hpp"

int main()
{

    // Declaring the size of rows and columns
    int rows, columns;

    // Getting the number of rows and columns
    tabdat_getsize( "my_tabdat_file.dat", rows, columns );

    // Declaring and dynamic allocating a 1D array
    double * my_array = new double [ rows*columns ];

    // Importing a tabular data file and storing in the 1D array
    tabdat_import( "my_tabdat_file.dat", my_array, rows, columns );

    // Printing the data on the screen
    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            std::cout << my_array[ i + rows*j ] << "\t";
        }
    std::cout << std::endl;
    }

    // Free the memory allocated for the array
    delete[] my_array;

}
```

The excerpt below is an alternative way to export numeric data in a tabular data file using the software Wolfram Mathematica.
```
(* Creating any table and storing in the variable MyTable *)
MyTable = Table[ 2.1*i + 7.5*j, {i,0,9}, {j,0,19} ]

(* Exporting MyTable in a file my_tabdat_file.dat *) 
Export["my_tabdat_file.dat", MyTable]
```

And the final excerpt is an alternative way to import numeric data from a tabular data file using the software Wolfram Mathematica.
```
(* Importing data and storing in the variable MyTable *)
MyTable = Import["my_tabdat_file.dat"]
```

## Authorship

The codes and routines were developed and are updated by <a href="https://www.researchgate.net/profile/Jhonas-de-Sarro">Jhonas O. de Sarro</a> ([@jodesarro]( https://github.com/jodesarro )).

## Licensing

This project is protected under <a href="LICENSE">MIT License</a>. 
