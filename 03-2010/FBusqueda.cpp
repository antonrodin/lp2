//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
using namespace std;
#pragma hdrstop

#include "FBusqueda.h"
#include "caratexto.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBusqueda *Busqueda;
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
__fastcall TBusqueda::TBusqueda(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TBusqueda::actualizarCara(){
       TCara* cara;
       cara = dameCara();
       this->cara->Text = ( cara->dibujaPelo() + "\r\n" +
                            cara->dibujaOjos() + "\r\n" +
                            cara->dibujaNarizYOrejas() + "\r\n" +
                            cara->dibujaBoca() + "\r\n" +
                            " \\_____/").c_str();
       delete cara;
}
//---------------------------------------------------------------------------
TCara* __fastcall TBusqueda::dameCara(){
        _cara = new CaraTexto( this->selPelo->ItemIndex,
                                this->selOjos->ItemIndex,
                                this->selOrejasYNariz->ItemIndex,
                                this->selBoca->ItemIndex);
        return _cara;
}
//---------------------------------------------------------------------------
void __fastcall TBusqueda::selPeloClick(TObject *Sender)
{
        actualizarCara();
}
//---------------------------------------------------------------------------

void __fastcall TBusqueda::selBocaClick(TObject *Sender)
{
        actualizarCara();
}
//---------------------------------------------------------------------------

void __fastcall TBusqueda::selOjosClick(TObject *Sender)
{
        actualizarCara();        
}
//---------------------------------------------------------------------------

void __fastcall TBusqueda::selOrejasYNarizClick(TObject *Sender)
{
        actualizarCara();        
}
//---------------------------------------------------------------------------

void __fastcall TBusqueda::okClick(TObject *Sender)
{
        ModalResult=mrOk;        
}
//---------------------------------------------------------------------------

void __fastcall TBusqueda::cancelClick(TObject *Sender)
{
        ModalResult=mrCancel;        
}
//---------------------------------------------------------------------------

