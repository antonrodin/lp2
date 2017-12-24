//---------------------------------------------------------------------------

#ifndef FBusquedaH
#define FBusquedaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "TCara.h"
//---------------------------------------------------------------------------
class TBusqueda : public TForm
{
__published:	// IDE-managed Components
        TButton *ok;
        TRadioGroup *selOjos;
        TRadioGroup *selBoca;
        TRadioGroup *selOrejasYNariz;
        TRadioGroup *selPelo;
        TMemo *cara;
        TButton *cancel;
        void __fastcall selPeloClick(TObject *Sender);
        void __fastcall selBocaClick(TObject *Sender);
        void __fastcall selOjosClick(TObject *Sender);
        void __fastcall selOrejasYNarizClick(TObject *Sender);
        void __fastcall okClick(TObject *Sender);
        void __fastcall cancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TBusqueda(TComponent* Owner);
        void __fastcall actualizarCara();
        TCara __fastcall dameCara();
};
//---------------------------------------------------------------------------
extern PACKAGE TBusqueda *Busqueda;
//---------------------------------------------------------------------------
#endif
