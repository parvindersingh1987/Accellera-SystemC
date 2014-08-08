/*****************************************************************************

  The following code is derived, directly or indirectly, from the SystemC
  source code Copyright (c) 1996-2014 by all Contributors.
  All Rights reserved.

  The contents of this file are subject to the restrictions and limitations
  set forth in the SystemC Open Source License (the "License");
  You may not use this file except in compliance with such restrictions and
  limitations. You may obtain instructions on how to receive a copy of the
  License at http://www.accellera.org/. Software distributed by Contributors
  under the License is distributed on an "AS IS" basis, WITHOUT WARRANTY OF
  ANY KIND, either express or implied. See the License for the specific
  language governing rights and limitations under the License.

 *****************************************************************************/

/*****************************************************************************

  test.cpp -- 

  Original Author: Martin Janssen, Synopsys, Inc., 2002-02-15

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/

/* 
   Verifies directive line_label.
   Author: PRP 
   From Test Case line_label: 7.cc
*/

#include "systemc.h"
#include "test.h"

void test::entry() 
{
  int i,j,y,z;
 
  { 
     int i;
     int x = 0;
      
     a:i = 2;
     if (i == 2)
        {
        foobart: i = 7;
       i = 4;
        i = 5;
        }
     else
        i = 7;
 
     y = 2;
     if (y == 3) {
        z = 1;
     } else {
        z = 2;
     }
 
     switch (x) {
     case 1: break;
     case 3: break;
     default: ;
     }
  }
  b:i = 3;
  j = 5;
 
  while (i == 4) {
        j = 7;
        y = 4;
        i++;
 
        wait();
  }
  do
  {
        j = 7;
        y = 4;
        i++;
 
        wait();
  } while (i < 4);
  if (i == 4) {
        i = 5;
  } else {
        i = 9;
  }
 
  wait();
 
}