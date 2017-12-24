//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
using namespace std;
#pragma hdrstop

#include "FDelincuentes.h"
#include "FBusqueda.h"
#include "TCara.h"
#include "TDelincuente.h"
#include "TContenedorDelincuentes.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDelincuentes *Delincuentes;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
__fastcall TDelincuentes::TDelincuentes(TComponent* Owner)
        : TForm(Owner)
{
        _almacen = new TContenedorDelincuentes(100,-1);
        TDelincuente* del;
        del = new TDelincuente();
        ponDelincuente(*del);
        delete del;
}
//---------------------------------------------------------------------------
TDelincuente __fastcall TDelincuentes::dameDelincuente() {

        TCara* cara;
        cara = new TCara(this->selPelo->ItemIndex,
                         this->selOjos->ItemIndex,
                         this->selOrejasYNariz->ItemIndex,
                         this->selBoca->ItemIndex);
        TDelincuente *del;
        del = new TDelincuente((this->EditNombre->Text).c_str(),
                               (this->MemoDelitos->Text).c_str(),
                                *cara);
        return *del;
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::ponDelincuente(TDelincuente del) {
        this->EditNombre->Text = del.getNombre().c_str();
        this->MemoDelitos->Text = del.getDelitos().c_str();
        TCara* cara;
        cara = new TCara();
        *cara = del.getCara();
        this->cara->Text = (cara->dibujaPelo() + "\r\n" +
                            cara->dibujaOjos() + "\r\n" +
                            cara->dibujaNarizYOrejas() + "\r\n" +
                            cara->dibujaBoca() + "\r\n" +
                            " \\_____/").c_str();
        this->selPelo->ItemIndex = cara->getPelo();
        this->selOjos->ItemIndex = cara->getOjos();
        this->selOrejasYNariz->ItemIndex = cara->getNarizYOrejas();
        this->selBoca->ItemIndex = cara->getBoca();
        delete cara;
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
}
//---------------------------------------------------------------------------
void __fastcall TDelincuentes::botonBuscarClick(TObject *Sender)
{
        TCara tmp;
        TDelincuente del;
        this->Registro->Text = "";
        int delEncontrado;
        bool encontrado = false;
        Busqueda->ShowModal();
        if (Busqueda->ModalResult == mrOk) {
            tmp = Busqueda->dameCara();
            for (int i=0; i<=_almacen->getUltimo(); i++) {
            del = _almacen->getDelincuente(i);
            if ((del.getCara()) == tmp)
                {
                    encontrado = true;
                    this->Registro->Text = del.getNombre().c_str();
                    delEncontrado = i;
                }
            }
            if (!encontrado) this->Registro->Text = "No se encontro ningun delincuente";
            else {
                this->Registro->Text = "Delincuente encontrado numero: " +  (this->Registro->Text);
                del = _almacen->getDelincuente(delEncontrado);
                ponDelincuente(del);
                this->nFicha->Caption = delEncontrado;
            }

        }
        else
        {
            this->Registro->Text = "Se ha pulsado Cancel";
        }
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonAgregarClick(TObject *Sender)
{
        bool conseguido;
        TDelincuente del;

        del = dameDelincuente();
        conseguido = _almacen -> agregaDelincuente(del);
        if (conseguido)
             {
                this->nFicha->Caption = _almacen->getUltimo();
                ponDelincuente(del);
                this->Registro->Text = "El delincuente ha sio agregao";
             }
        else
             {
                this->Registro->Text = "Ya existe delincuente con el mismo nombre!";
             }
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::FormDestroy(TObject *Sender)
{
        delete _almacen;        
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonAnteriorClick(TObject *Sender)
{
        int n = atoi((this->nFicha->Caption).c_str());
        if (n > 0) {
                        this->nFicha->Caption=(n-1);
                        ponDelincuente(_almacen->getDelincuente(atoi((this->nFicha->Caption).c_str())));
                        this->Registro->Text = "";
        }
        else
        {
                this->Registro->Text = "No hay mas fichas";
        }
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonSiguienteClick(TObject *Sender)
{
        int n = atoi((this->nFicha->Caption).c_str());
        if (n < _almacen->getUltimo()) {
                this->nFicha->Caption=(n+1);
                ponDelincuente(_almacen->getDelincuente(atoi((this->nFicha->Caption).c_str())));
                this->Registro->Text = "";
        }
        else
        {
                this->Registro->Text = "No hay mas fichas";
        }
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::selPeloClick(TObject *Sender)
{
        TDelincuente del;
        del = dameDelincuente();
        ponDelincuente(del);
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::selOjosClick(TObject *Sender)
{

        TDelincuente del;
        del = dameDelincuente();
        ponDelincuente(del);
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::selBocaClick(TObject *Sender)
{
        
        TDelincuente del;
        del = dameDelincuente();
        ponDelincuente(del);
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::selOrejasYNarizClick(TObject *Sender)
{
        
        TDelincuente del;
        del = dameDelincuente();
        ponDelincuente(del);        
}
//---------------------------------------------------------------------------


void __fastcall TDelincuentes::botonBorrarClick(TObject *Sender)
{
        bool conseguido;
        
        if (_almacen->getUltimo() == 0) {
                _almacen->setUltimo(-1);
                this->nFicha->Caption = _almacen->getUltimo();
                vacia();
          }
        else  if (_almacen->getUltimo() == -1)
                {
                        this->Registro->Text = "No hay delincuentes que borrar";
                        this->nFicha->Caption = _almacen->getUltimo();
                }
              else {
                    conseguido = _almacen->borraDelincuente((this->EditNombre->Text).c_str());
                    if (conseguido) {
                        this->nFicha->Caption = _almacen->getUltimo();
                        ponDelincuente(_almacen->getDelincuente(atoi((this->nFicha->Caption).c_str())));
                        }
              }
}
//---------------------------------------------------------------------------

void __fastcall TDelincuentes::botonModificarClick(TObject *Sender)
{
        
        int actual;
        bool conseguido;

        actual = atoi((this->nFicha->Caption).c_str());
        if (actual > 0) {
                conseguido = _almacen->setDelincuente(dameDelincuente(),actual);
                if (conseguido) {
                        this->Registro->Text = "";
                }
                else this->Registro->Text = "No se puede modificar! Este Nombre ya existe.";
                         }
        else
             this->Registro->Text = "No se puede modificar porque no hay ningun delincuente";
}
//---------------------------------------------------------------------------

