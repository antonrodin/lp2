#ifndef _SalidaWinForms_h
#define _SalidaWinForms_h
#include <string>
#include <vcclr.h>
//using namespace System;

#include "Salida.h"

class CSalidaWinForms : public CSalida{

 public:
	 CSalidaWinForms( System::Windows::Forms::TextBox ^, System::Windows::Forms::ProgressBar ^ );
	void  InitPrueba (const std::string &desc);
	 void  Muestra (int tam, float tiempo);
	 void  FinPrueba ();
  private:
   std::string _desc;
   int _tam; 
   float _tiempo;
  // gcroot _tb;
	gcroot<System::Windows::Forms::TextBox ^> _tb;
	gcroot<System::Windows::Forms::ProgressBar ^> _prog;
// Se usa como cualquier otro puntero
// Se usa como cualquier otro puntero
  
  
};


#endif