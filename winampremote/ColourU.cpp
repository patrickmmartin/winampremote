//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h> // from M_PI

#pragma hdrstop

#include "ColourU.h"



const int BASE_RANGE = 500;
const double offset = 0.15;


double periodic(double percent)
{
//returns a periodic (cos ^2) function from any real input periodicity of 1
  double temp = M_PI * percent;
  return cos(temp) * cos(temp);
}


TColor RainbowColour(int value)
{
  double percent = (double) ( value % BASE_RANGE) /BASE_RANGE;

  int R = 255 * (periodic(percent + offset));
  int G = 255 * (periodic(percent + offset + (-0.333)));
  int B = 255 * (periodic(percent + offset + ( 0.333)));

  return (TColor) RGB(R, G, B);
  }


//---------------------------------------------------------------------------
#pragma package(smart_init)
