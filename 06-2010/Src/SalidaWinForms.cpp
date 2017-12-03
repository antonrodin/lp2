#include "SalidaWinForms.h"

CSalidaWinForms::CSalidaWinForms( System::Windows::Forms::TextBox ^ tb, System::Windows::Forms::ProgressBar ^ prog): _tb(tb), _prog(prog){
	this->_tb->Refresh();
	this->_prog->Refresh();
};
void  CSalidaWinForms::InitPrueba (const std::string &desc){
	
	this->_tb->AppendText(System::String(desc.c_str()).ToString()+"\r\n");
	this->_tb->AppendText("--------------------------------------------\r\n");
	this->_tb->Refresh();
	
	};
void  CSalidaWinForms::Muestra (int tam, float tiempo){

	System::String ^aux1 = tam.ToString();
	System::String ^aux2 = tiempo.ToString();
	System::String ^linea = "N= "+ aux1 +" "+" Tiempo = " + aux2;
	this->_tb->AppendText(linea+"\r\n");
	this->_tb->Refresh();
	_prog->Value++;
	
	

};
void  CSalidaWinForms::FinPrueba (){

//delete _tb;

};