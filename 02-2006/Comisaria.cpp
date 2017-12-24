//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Comisaria.res");
USEFORM("FDelincuentes.cpp", Delincuentes);
USEFORM("FBusqueda.cpp", Busqueda);
USEUNIT("TCara.cpp");
USEUNIT("TDelincuente.cpp");
USEUNIT("TContenedorDelincuentes.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TDelincuentes), &Delincuentes);
                 Application->CreateForm(__classid(TBusqueda), &Busqueda);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
