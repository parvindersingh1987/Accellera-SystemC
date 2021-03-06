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

  display.h -- 

  Original Author: Rocco Jonack, Synopsys, Inc., 1999-07-30

 *****************************************************************************/

/*****************************************************************************

  MODIFICATION LOG - modifiers, enter your name, affiliation, date and
  changes you are making here.

      Name, Affiliation, Date:
  Description of Modification:

 *****************************************************************************/


#include "common.h"

SC_MODULE( display )
{
    SC_HAS_PROCESS( display );

    sc_in_clk clk;

    const sc_signal_bool_vector8&      in_value1;     // Output  port
    const sc_signal_bool_vector8&      in_value2;     // Output  port
    const sc_signal<long>&             in_value3;                        // Output  port
    const sc_signal<int>&              in_value4;                        // Output  port
    const sc_signal<short>&            in_value5;                        // Output  port
    const sc_signal<char>&             in_value6;                        // Output  port
    const sc_signal<bool>&             in_value7;                        // Output  port
    const sc_signal_bool_vector4&      in_value8;     // Output  port
    const sc_signal_logic_vector4&     in_value9;     // Output  port 
    const sc_signal<bool>&             in_valid;                         // Output  port

   //
   // Constructor
   //

   display(
               sc_module_name    NAME,      // reference name
               sc_clock&      CLK,          // clock
               const sc_signal_bool_vector8&     IN_VALUE1,
               const sc_signal_bool_vector8&     IN_VALUE2,
               const sc_signal<long>&            IN_VALUE3,
               const sc_signal<int>&             IN_VALUE4,
               const sc_signal<short>&           IN_VALUE5,
               const sc_signal<char>&            IN_VALUE6,
               const sc_signal<bool>&            IN_VALUE7,
               const sc_signal_bool_vector4&     IN_VALUE8,
               const sc_signal_logic_vector4&    IN_VALUE9,
               const sc_signal<bool>&            IN_VALID
           )
           : 
             in_value1    (IN_VALUE1),
             in_value2    (IN_VALUE2),
             in_value3    (IN_VALUE3),
             in_value4    (IN_VALUE4),
             in_value5    (IN_VALUE5),
             in_value6    (IN_VALUE6),
             in_value7    (IN_VALUE7),
             in_value8    (IN_VALUE8),
             in_value9    (IN_VALUE9),
             in_valid     (IN_VALID)
     {
       clk          (CLK);
	   SC_CTHREAD( entry, clk.pos() );
     };


 void entry();
};

// EOF

