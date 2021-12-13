//------------------------------------------------------------------------
// ChangeDefocus.h
// Author: Krzysztof Morawiec
//------------------------------------------------------------------------

#include <iostream>

//------------------------------------------------------------------------

// Import TEM Scripting Type Library
#import "C:\titan\Scripting\stdscript.dll" named_guids

//------------------------------------------------------------------------

extern TEMScripting::InstrumentInterfacePtr TEM;		// pointer to TEM instance

//------------------------------------------------------------------------

bool InitTEM();
void ReleaseTEM();
double GetObjLensExcitation();
double GetDefocus();
void SetDefocus(double df);
void ResetDefocus();