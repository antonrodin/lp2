//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
using namespace std;
#pragma hdrstop

#include "FBusqueda.h"

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
       this->cara->Text = ( dameCara().dibujaPelo() + "\r\n" +
                            dameCara().dibujaOjos() + "\r\n" +
                            dameCara().dibujaNarizYOrejas() + "\r\n" +
                            dameCara().dibujaBoca() + "\r\n" +
                            " \\_____/").c_str();
}
//---------------------------------------------------------------------------
TCara __fastcall TBusqueda::dameCara(){
        TCara tmp(this->selPelo->ItemIndex,
                   this->selOjos->ItemIndex,
                   this->selOrejasYNariz->ItemIndex,
                   this->selBoca->ItemIndex);
        return tmp;
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

