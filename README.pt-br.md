# Biblioteca para arquivos de dados tabulares

<p align="right"><a href="README.md">Read in English</a></p>

Um conjunto de funções em C++ para lidar com arquivos de dados numéricos tabulares.

Arquivos de dados tabulares possuem uma estrutua na qual as linhas são separadas por quebras de linha e as colunas são separadas por espaçamento tabular.

É muito útil na importação e exportação de matrizes, tabelas, conjuntos de dados numéricos e etc.

Geralmente esses arquivos são utilizados na importação e exportação de dados em softwares como o Google Sheets, Microsoft Excel, Wolfram Mathematica (no [formato Table .dat](https://reference.wolfram.com/language/ref/format/Table.html)), dentre outros.

## Funções disponíveis

- Obter as dimensões (número de linhas e colunas) de um arquivo de dados numéricos tabulares
```
void tabdat_getsize( std::string tabdat_path, int &rows, int &columns )
```

- Importar dados numéricos de um arquivo de dados tabulares e armazenar os valores em um array de uma dimensão
```
void tabdat_import( std::string tabdat_path, double * data_array, int rows, int columns )
```

- Exportar dados numéricos de um array de uma dimensão para um arquivo de dados tabulares
```
void tabdat_export( std::string tabdat_path, double * data_array, int rows, int columns, int out_precision = 0, bool out_scientific = false )
```

## Como usar

A bibliotea está em estilo *header-only* (apenas cabeçalho), ou seja, não é necessário compilá-la separadamente, você só precisa incluir o arquivo <a href="tabdat-library.hpp">*tabdat-library.hpp*</a> no seu projeto.

## Exemplos de uso

O que segue é um exemplo de como exportar dados numéricos para um arquivo de dados tabulares utilizando C++.
```
#include <iostream>
#include "tabdat-library.hpp"

int main()
{

    // Declarando a quantidade de linhas e colunas
    int rows = 10;
    int columns = 20;

    // Declarando e alocando memória para um array 1D
    double * my_array = new double [ rows*columns ];

    // Armazenando valores quaisquer aos elementos do array 1D
    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            my_array[ i + rows*j ] = 2.1*double(i) + 7.5*double(j);
        }
    }

    // Exportando o array para um arquivo de dados tabulares
    tabdat_export( "my_tabdat_file.dat", my_array, rows, columns );

    // Liberando a memória que fora alocada para o array
    delete[] my_array;

}
```

O que segue é um exemplo de como ler um arquivo de dados numéricos tabulares e mostrar os dados na tela usando C++.
```
#include <iostream>
#include "tabdat-library.hpp"

int main()
{

    // Declarando a quantidade de linhas e colunas
    int rows, columns;

    // Obtendo o número de linhas e colunas
    tabdat_getsize( "my_tabdat_file.dat", rows, columns );

    // Declarando e alocando memória para um array 1D
    double * my_array = new double [ rows*columns ];

    // Importando um arquivo de dados tabulares e armazenando em um array 1D
    tabdat_import( "my_tabdat_file.dat", my_array, rows, columns );

    // Mostrando os dados na tela
    for ( int i = 0; i < rows; i++ )
    {
        for ( int j = 0; j < columns; j++ )
        {
            std::cout << my_array[ i + rows*j ] << "\t";
        }
    std::cout << std::endl;
    }

    // Liberando a memória que fora alocada para o array
    delete[] my_array;

}
```

O trecho abaixo é um exemplo alternativo de como exportar um arquivo de dados numéricos tabulares usando o software Wolfram Mathematica.
```
(* Criando uma tabela qualquer e armazenando-a em MyTable *)
MyTable = Table[ 2.1*i + 7.5*j, {i,0,9}, {j,0,19} ]

(* Exportando MyTable para um arquivo my_tabdat_file.dat *) 
Export["my_tabdat_file.dat", MyTable]
```

O trecho abaixo mostra uma maneira alternativa de importar um arquivo de dados numéricos tabulares no software Wolfram Mathematica.
```
(* Importando um arquivo de dados tabulares e armazenando em MyTable *)
MyTable = Import["my_tabdat_file.dat"]
```

## Licença

Este projeto está protegido sob a licença <a href="LICENSE">MIT License</a> e tem [@jodesarro](https://github.com/jodesarro) como seu principal autor.
