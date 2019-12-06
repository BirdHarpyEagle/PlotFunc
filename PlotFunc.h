#include <stdio.h>
#include <math.h>

const int PAINTED_CELL = 1;

const int MAX_PLOT_SIZE = 120;
const double VALUES_RANGE = 1.57;

typedef double (*MathFunc_t)(double x);

void Plot(MathFunc_t func, unsigned int size)
{
    double funcRes_HorizC;
    double funcRes_HorizCplus1;

    if(size > MAX_PLOT_SIZE)
        size = MAX_PLOT_SIZE;

    char plotFields[size][size] = {};
    
    for( double horizCell = 0; horizCell <= size - 1; horizCell++ )
    {
        if( (funcRes_HorizC = func( horizCell * VALUES_RANGE / size )) > VALUES_RANGE )
            continue;
        if( (funcRes_HorizCplus1 = func( (horizCell + 1) * VALUES_RANGE / size )) > VALUES_RANGE )
            continue;

        if( funcRes_HorizC >= 0 && funcRes_HorizCplus1 >= 0 )
        {
            if( funcRes_HorizC < funcRes_HorizCplus1 )
                for( double vertCell = floor(size * funcRes_HorizC / VALUES_RANGE); vertCell < ceil(size * funcRes_HorizCplus1 / VALUES_RANGE); vertCell++)
                    plotFields[(int) horizCell][(int) vertCell] = PAINTED_CELL;

            else // if( funcRes_HorizC >= funcRes_HorizCplus1 )
                for( double vertCell = floor(size * funcRes_HorizC / VALUES_RANGE); vertCell >= floor(size * funcRes_HorizCplus1 / VALUES_RANGE); vertCell-- )
                    plotFields[(int) horizCell][(int) vertCell] = PAINTED_CELL;
        }
        //else
    }
    
    for(int vertical = size - 1; vertical >= 0; vertical--)
    {
        for(int horizontal = 0; horizontal < size; horizontal++)
        {
            if(plotFields[horizontal][vertical] == PAINTED_CELL)
                putchar('#');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}
