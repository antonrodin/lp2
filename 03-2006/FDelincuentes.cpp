//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#pragma hdrstop

#include "FDelincuentes.h"
#include "FBusqueda.h"
#include "TDelincuente.h"
#include "TCara.h"
#include "caragrafica.h"
#include "caratexto.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
__fastcall TDelincuentes::TDelincuentes(TComponent* Owner)
        : TForm(Owner)
{
        _almacen = new Lista();
}
//---------------------------------------------------------------------------
TDelincuente* TDelincuentes::dameDelincuente() {
        TCara* cara;
        if (_cara)  {
                        cara = new CaraGrafica(this->selPelo->ItemIndex,
                                               this->selOjos->ItemIndex,
                                               this->selOrejasYNariz->ItemIndex,
                                               this->selBoca->ItemIndex,
                                               this->AbrirBMP->FileName.c_str());
        }

        else {
                        cara = new CaraTexto(this->selPelo->ItemIndex,
                                             this->selOjos->ItemIndex,
                                             this->selOrejasYNariz->ItemIndex,
                                             this->selBoca->ItemIndex);
        }

        TDelincuente* del = new TDelincuente(this->EditNombre->Text.c_str(),
                                             this->MemoDelitos->Text.c_str(),
                                             cara);
        return del;
}
//---------------------------------------------------------------------------
void TDelincuentes::ponDelincuente(TDelincuente* del) {
        this->EditNombre->Text = del->getNombre().c_str();
        this->MemoDelitos->Text = del->getDelitos().c_str();
        TCara* cara;
        cara = del->getCara();
        cara->dibuja(canvas->Canvas);
        this->cara->Text = (cara->dibujaPelo() + "\r\n" +
                            cara->dibujaOjos() + "\r\n" +
                            cara->dibujaNarizYOrejas() + "\r\n" +
                            cara->dibujaBoca() + "\r\n" +
                            " \\_____/").c_str();
        this->selPelo->ItemIndex = cara->getPelo();
        this->selOjos->ItemIndex = cara->getOjos();
        this->selOrejasYNariz->ItemIndex = cara->getNarizYOrejas();
        this->selBoca->ItemIndex = cara->getBoca();
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::vacia(){
        this->EditNombre->Text = "Vacio";
        this->MemoDelitos->Text = "Vacio";
        this->cara->Text = "Vacio";
        this->selPelo->ItemIndex = -1;
        this->selOjos->ItemIndex = -1;
        this->selOrejasYNariz->ItemIndex = -1;
        this->selBoca->ItemIndex = -1;
        canvas->Canvas->Rectangle(0, 0, 150, 150);
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::selPeloClick(TObject *Sender)
{
        TDelincuente* del;
        del = dameDelincuente();
        ponDelincuente(del);
        delete del;
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::selOjosClick(TObject *Sender)
{

        TDelincuente* del;
        del = dameDelincuente();
        ponDelincuente(del);
        delete del;
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::selBocaClick(TObject *Sender)
{

        TDelincuente* del;
        del = dameDelincuente();
        ponDelincuente(del);
        delete del;
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::selOrejasYNarizClick(TObject *Sender)
{

        TDelincuente* del;
        del = dameDelincuente();
        ponDelincuente(del);
        delete del;
}
//---------------------------------------------------------------------------




void __fastcall TDelincuentes::botonAgregarClick(TObject *Sender)
{
        TDelincuente* del;
        del = dameDelincuente();
        if (_almacen->agregaDelincuente(del)) {
                this->nFicha->Caption = _almacen->indice();

                //Establecemos la cara a falso
                if (_cara) _cara = false;
        }
        else
                this->Registro->Text = "Ya existe delincuente con este nombre";
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::FormDestroy(TObject *Sender)
{
        delete _almacen;        
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonAnteriorClick(TObject *Sender)
{
        if (_almacen->actual() == NULL)
                this->Registro->Text = "La lista esta vacia";
        else if (_almacen->actual()->ant() == NULL)
                this->Registro->Text = "Error! Inicio de la lista";
             else {
                        TDelincuente* del = _almacen->actual()->ant()->del();
                        ponDelincuente(del);
                        _almacen->actual(_almacen->actual()->ant());
                        _almacen->indice(_almacen->indice() - 1);
             }
        this->nFicha->Caption = _almacen->indice();
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonSiguienteClick(TObject *Sender)
{
        if (_almacen->actual() == NULL)
                this->Registro->Text = "La lista esta vacia";
        else if (_almacen->actual()->sig() == NULL)
                this->Registro->Text = "Error! Fin de la lista";
             else {
                        TDelincuente* del = _almacen->actual()->sig()->del();
                        ponDelincuente(del);
                        _almacen->actual(_almacen->actual()->sig());
                        _almacen->indice(_almacen->indice() + 1);
             }
        this->nFicha->Caption = _almacen->indice();
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonBorrarClick(TObject *Sender)
{
        string nombre;
        nombre = (this->EditNombre->Text).c_str();
        if (_almacen->eliminar(nombre)) this->Registro->Text = "Delincuente borrado";
        else
                this->Registro->Text = "Delincuente no borrado";
}
//---------------------------------------------------------------------------


void __fastcall TDelincuentes::AbrirTXTClick(TObject *Sender)
{
        this->Abrir->Execute();
        _nombre = Abrir->FileName.c_str();
        if (_almacen->cargaTXT(_nombre)) {
                this->Registro->Text ="Fichero abierto";
                //TDelincuente* del = _almacen->inicio()->sig()->del();
                //ponDelincuente(del);
                }
        else
                this->Registro->Text = "Error: No se ha abierto el fichero!";
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::GuardarComoTXTClick(TObject *Sender)
{
        this->Salvar->Execute();
        _almacen->salvaTXT(Salvar->FileName.c_str());
}
//---------------------------------------------------------------------------


void __fastcall TDelincuentes::GuardarTXTClick(TObject *Sender)
{
        _almacen->salvaTXT(_nombre);
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::canvasClick(TObject *Sender)
{
        if (this->AbrirBMP->Execute()) {
                CaraGrafica cara(1,1,1,1,this->AbrirBMP->FileName.c_str());
                this->Registro->Text = this->AbrirBMP->FileName;
                Graphics::TBitmap* bmp = cara.cargarBMP(this->AbrirBMP->FileName);
                this->canvas->Canvas->Draw(0,0,bmp);

                //Establecemos la cara verdadero
                _cara = true;
        }
        else
        {
                this->Registro->Text = "No se abrio ninguna imagen";
        }
}
//---------------------------------------------------------------------------


void __fastcall TDelincuentes::Nueva1Click(TObject *Sender)
{
        vacia();
        delete _almacen;
        _almacen = new Lista();        
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::Aadir1Click(TObject *Sender)
{
        TDelincuente* del;
        del = dameDelincuente();
        _almacen->agregaDelincuente(del);
        this->nFicha->Caption = _almacen->indice();

        //Establecemos la cara a falso
        if (_cara) _cara = false;
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::Eliminar1Click(TObject *Sender)
{
        string nombre;
        nombre = (this->EditNombre->Text).c_str();
        if (_almacen->eliminar(nombre)) this->Registro->Text = "Delincuente borrado";
        else
                this->Registro->Text = "Delincuente no borrado";
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonModificarClick(TObject *Sender)
{
        _almacen->actual()->del(dameDelincuente());
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::Modificar1Click(TObject *Sender)
{
        _almacen->actual()->del(dameDelincuente());
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonBuscarClick(TObject *Sender)
{
        TCara* cara;
        TDelincuente* del;
        Busqueda->ShowModal();
        cara = Busqueda->dameCara();
        del = _almacen->buscarDelincuente(cara);
        if (del != NULL) {
                this->Registro->Text = del->getNombre().c_str();
        }
        delete cara;
}
//---------------------------------------------------------------------------

