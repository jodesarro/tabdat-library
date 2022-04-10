#pragma once

#include <fstream>
#include <string>

void tabdat_getsize( std::string tabdat_path, int &rows, int &columns )
{

    std::ifstream tabdat_file( tabdat_path );
    std::string tempstring;

    rows = 0;
    while ( std::getline(tabdat_file, tempstring) )
    {
        ++rows;
    }

    std::string tempstring;
    std::getline( tabdat_file, tempstring );
    tabdat_file.close();

    ( rows > 0 ) ? columns = 1 : columns = 0;
    for(char& c : tempstring)
    {
        if ( c == '\t' )
        {
            ++columns;
        }
    }

}

void tabdat_import( std::string tabdat_path, double * data_array, int rows, int columns )
{

    std::ifstream tabdat_file( tabdat_path );

    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            tabdat_file >> data_array[i+rows*j];
        }
    }

    tabdat_file.close();

}

void tabdat_export( std::string tabdat_path, double * data_array, int rows, int columns, int out_precision = 0, bool out_scientific = false )
{

    std::ofstream tabdat_file( tabdat_path );

    if ( out_precision != 0 )
    {
        tabdat_file.precision(out_precision);
    }

    if ( out_scientific )
    {
        tabdat_file << std::scientific;
    }

    tabdat_file << data_array[0+rows*0];
    for ( int j = 1; j < columns; j++ )
    {
        tabdat_file << "\t" << data_array[0+rows*j];
    }
    for ( int i = 1; i < rows; i++ )
    {
        tabdat_file << "\n";

        tabdat_file << data_array[i+rows*0];
        for ( int j = 1; j < columns; j++ )
        {
            tabdat_file << "\t" << data_array[i+rows*j];
        }

    }

    tabdat_file.close();

}
