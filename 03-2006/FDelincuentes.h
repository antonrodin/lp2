//---------------------------------------------------------------------------

#ifndef FDelincuentesH
#define FDelincuentesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
#include <ExtDlgs.hpp>
#include <iostream>
using namespace std;

#include "TDelincuente.h"
#include "lista.h"
#include "TCara.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
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
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *Lista1;
        TMenuItem *Nuevo;
        TMenuItem *Guardartxt1;
        TMenuItem *AbrirTXT;
        TMenuItem *GuardarTXT;
        TMenuItem *GuardarComoTXT;
        TMenuItem *Salir2;
        TMenuItem *Salir;
        TOpenDialog *Abrir;
        TSaveDialog *Salvar;
        TImage *canvas;
        TOpenPictureDialog *AbrirBMP;
        TMenuItem *Nueva1;
        TMenuItem *N1;
        TMenuItem *Aadir1;
        TMenuItem *Modificar1;
        TMenuItem *Eliminar1;
        TMenuItem *Buscar1;
        void __fastcall selPeloClick(TObject *Sender);
        void __fastcall selOjosClick(TObject *Sender);
        void __fastcall selBocaClick(TObject *Sender);
        void __fastcall selOrejasYNarizClick(TObject *Sender);
        void __fastcall botonAgregarClick(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall botonAnteriorClick(TObject *Sender);
        void __fastcall botonSiguienteClick(TObject *Sender);
        void __fastcall botonBorrarClick(TObject *Sender);
        void __fastcall AbrirTXTClick(TObject *Sender);
        void __fastcall GuardarComoTXTClick(TObject *Sender);
        void __fastcall GuardarTXTClick(TObject *Sender);
        void __fastcall canvasClick(TObject *Sender);
        void __fastcall Nueva1Click(TObject *Sender);
        void __fastcall Aadir1Click(TObject *Sender);
        void __fastcall Eliminar1Click(TObject *Sender);
        void __fastcall botonModificarClick(TObject *Sender);
        void __fastcall Modificar1Click(TObject *Sender);
        void __fastcall botonBuscarClick(TObject *Sender);
private:
        Lista* _almacen;
        string _nombre;
        bool _cara;
public:		// User declarations
        __fastcall TDelincuentes(TComponent* Owner);
        TDelincuente* dameDelincuente();
        void ponDelincuente(TDelincuente* del);
        void __fastcall vacia();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
extern PACKAGE TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------
#endif
