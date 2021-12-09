#include "ChangeDefocus.h"

using namespace std;
using namespace TEMScripting;

//------------------------------------------------------------------------

InstrumentInterfacePtr TEM;

//------------------------------------------------------------------------

bool InitTEM()
{
	HRESULT hr = TEM.CreateInstance("TEMScripting.Instrument.1");
	if (FAILED(hr))
	{
		cout << "Could not connect to TEM server\n";
		return FALSE;
	}
	return TRUE;
}

//------------------------------------------------------------------------

void ReleaseTEM()
{
	TEM.Release();
	TEM = NULL;
}

//------------------------------------------------------------------------

double GetObjLensExcitation()
{
	return TEM->Projection->ObjectiveExcitation;
}

//------------------------------------------------------------------------

double GetDefocus()
{
	// ProjectionPtr proj = TEM->Projection;
	return TEM->Projection->Defocus;
}

//------------------------------------------------------------------------

void SetDefocus(double df)
{
	TEM->Projection->Defocus = df;
}

//------------------------------------------------------------------------

void ResetDefocus()
{
	TEM->Projection->ResetDefocus();
}

//------------------------------------------------------------------------

int main()
{
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		cout << "Could not initialize COM library\n";
		return FALSE;
	}
	if (!InitTEM()) return FALSE;

	ResetDefocus();

	cout << "Current defocus = " << GetDefocus() * 1e9 << " nm\n"
		 << "Obj. lens excitation = " << GetObjLensExcitation() * 100 << "%\n";

	SetDefocus(1e-7);	// 100 nm

	cout << "Current defocus = " << GetDefocus() * 1e9 << " nm\n"
		 << "Obj. lens excitation = " << GetObjLensExcitation() * 100 << "%\n";

	system("pause");

	ReleaseTEM();
	CoUninitialize();
	return 0;
}