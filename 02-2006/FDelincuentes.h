//---------------------------------------------------------------------------

#ifndef FDelincuentesH
#define FDelincuentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "TDelincuente.h"
#include "TContenedorDelincuentes.h"
//---------------------------------------------------------------------------
class TDelincuentes : public TForm
{
__published:	// IDE-managed Components
   TButton *botonAgregar;
        TRadioGroup *selOjos;
        TRadioGroup *selBoca;
        TRadioGroup *selOrejasYNariz;
        TRadioGroup *selPelo;
        TMemo *cara;
   TButton *botonBorrar;
   TButton *botonModificar;
   TButton *botonBuscar;
   TButton *botonAnterior;
   TButton *botonSiguiente;
   TLabel *Label1;
   TLabel *Label2;
   TLabel *Label3;
   TLabel *nFicha;
        TMemo *MemoDelitos;
        TEdit *EditNombre;
        TMemo *Registro;
        TLabel *Label4;
        void __fastcall botonBuscarClick(TObject *Sender);
        void __fastcall botonAgregarClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall botonAnteriorClick(TObject *Sender);
        void __fastcall botonSiguienteClick(TObject *Sender);
        void __fastcall selPeloClick(TObject *Sender);
        void __fastcall selOjosClick(TObject *Sender);
        void __fastcall selBocaClick(TObject *Sender);
        void __fastcall selOrejasYNarizClick(TObject *Sender);
        void __fastcall botonBorrarClick(TObject *Sender);
        void __fastcall botonModificarClick(TObject *Sender);
private:
        TContenedorDelincuentes* _almacen;
public:		// User declarations
        __fastcall TDelincuentes(TComponent* Owner);
        __fastcall TDelincuente dameDelincuente();
        void __fastcall ponDelincuente(TDelincuente del);
        void __fastcall vacia();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
extern PACKAGE TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
#endif
