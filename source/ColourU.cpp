/*
winamp remote control suite Copyright ©2000-2011  Patrick M. Martin

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Patrick M. Martin may be reached by email at patrickmmartin@gmail.com.
*/


#include <vcl.h>
#pragma hdrstop
#include <math.h> // from M_PI
#include "ColourU.h"

const int BASE_RANGE = 500;
const double offset = 0.15;

double periodic(double percent)
{
  // TODO: function can be optimised
  double temp = M_PI * percent;
  return cos(temp) * cos(temp);
}


TColor rainbowColour(int value)
{
  double percent = (double) ( value % BASE_RANGE) /BASE_RANGE;

  int R = 255 * (periodic(percent + offset));
  int G = 255 * (periodic(percent + offset + (-0.333)));
  int B = 255 * (periodic(percent + offset + ( 0.333)));

  return (TColor) RGB(R, G, B);
  }

