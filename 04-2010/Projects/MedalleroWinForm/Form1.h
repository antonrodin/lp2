#pragma once

#include <iostream>
#include <string>
#include "Pareja.h"
#include "Secuencia.h"
#include "Pais.h"
#include "Medallas.h"
#include "Deporte.h"
#include "Atleta.h"
#include "Prueba.h"
#include "Medallero.h"
#include "Algoritmo.h"
#include "AlgoritmoMedalleroPais.h"
#include "AlgoritmoMedalleroOrdenadoPaises.h"
#include "AlgoritmoPaisAleatorio.h"
#include "AlgoritmoPaisPrimero.h"
#include "AlgoritmoPaisUltimo.h"
#include "AlgoritmoDeporteNormal.h"
#include "AlgoritmoDeporteOrdenado.h"
#include "SalidaEstandar.h"
#include "SalidaGNUPlot.h"
#include "SalidaWinForms.h"
#include "MideTiempos.h"


namespace MedalleroWinForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Resumen de Form1
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			
			//

			this->Restaura();
			
		}

		

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textLongIni;
	private: System::Windows::Forms::TextBox^  textLongFin;
	private: System::Windows::Forms::TextBox^  textInc;
	private: System::Windows::Forms::TextBox^  textRepIni;
	private: System::Windows::Forms::TextBox^  textRepFin;
	private: System::Windows::Forms::Button^  Comenzprueb;
	private: System::Windows::Forms::Button^  Restaurar;
	private: System::Windows::Forms::Button^ Cambiar;









	private: System::Windows::Forms::TextBox^  textResultados;
	private: System::Windows::Forms::TextBox^  textRuta;
	private: System::Windows::Forms::PictureBox^Imagen;

	
	private: System::Windows::Forms::FolderBrowserDialog^  Carpeta;
	private: System::Windows::Forms::ComboBox^  Algoritmo;
	private: System::Windows::Forms::ProgressBar^  progessBar;



	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>

			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textLongIni = (gcnew System::Windows::Forms::TextBox());
			this->textLongFin = (gcnew System::Windows::Forms::TextBox());
			this->textInc = (gcnew System::Windows::Forms::TextBox());
			this->textRepIni = (gcnew System::Windows::Forms::TextBox());
			this->textRepFin = (gcnew System::Windows::Forms::TextBox());
			this->Comenzprueb = (gcnew System::Windows::Forms::Button());
			this->Restaurar = (gcnew System::Windows::Forms::Button());
			this->Imagen = (gcnew System::Windows::Forms::PictureBox());
			this->textResultados = (gcnew System::Windows::Forms::TextBox());
			this->textRuta = (gcnew System::Windows::Forms::TextBox());
			this->Cambiar = (gcnew System::Windows::Forms::Button());
			this->Carpeta = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->Algoritmo = (gcnew System::Windows::Forms::ComboBox());
			this->progessBar = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Imagen))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Longitud Inicial";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 56);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Longitud Final";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 96);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Incremento";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(201, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Repeticiones";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(201, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(69, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Repeticiones";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(201, 92);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Ruta GNUPlot";
			// 
			// textLongIni
			// 
			this->textLongIni->Location = System::Drawing::Point(96, 25);
			this->textLongIni->Name = L"textLongIni";
			this->textLongIni->Size = System::Drawing::Size(81, 20);
			this->textLongIni->TabIndex = 0;
			// 
			// textLongFin
			// 
			this->textLongFin->Location = System::Drawing::Point(96, 51);
			this->textLongFin->Name = L"textLongFin";
			this->textLongFin->Size = System::Drawing::Size(81, 20);
			this->textLongFin->TabIndex = 1;
			// 
			// textInc
			// 
			this->textInc->Location = System::Drawing::Point(96, 87);
			this->textInc->Name = L"textInc";
			this->textInc->Size = System::Drawing::Size(81, 20);
			this->textInc->TabIndex = 2;
			// 
			// textRepIni
			// 
			this->textRepIni->Location = System::Drawing::Point(276, 30);
			this->textRepIni->Name = L"textRepIni";
			this->textRepIni->Size = System::Drawing::Size(81, 20);
			this->textRepIni->TabIndex = 3;
			// 
			// textRepFin
			// 
			this->textRepFin->Location = System::Drawing::Point(276, 55);
			this->textRepFin->Name = L"textRepFin";
			this->textRepFin->Size = System::Drawing::Size(81, 20);
			this->textRepFin->TabIndex = 4;
			// 
			// Comenzprueb
			// 
			this->Comenzprueb->Location = System::Drawing::Point(671, 20);
			this->Comenzprueb->Name = L"Comenzprueb";
			this->Comenzprueb->Size = System::Drawing::Size(115, 23);
			this->Comenzprueb->TabIndex = 8;
			this->Comenzprueb->Text = L"&Comenzar pruebas";
			this->Comenzprueb->UseVisualStyleBackColor = true;
			this->Comenzprueb->Click += gcnew System::EventHandler(this, &Form1::Comenzprueb_Click);
			// 
			// Restaurar
			// 
			this->Restaurar->Location = System::Drawing::Point(711, 53);
			this->Restaurar->Name = L"Restaurar";
			this->Restaurar->Size = System::Drawing::Size(75, 23);
			this->Restaurar->TabIndex = 9;
			this->Restaurar->Text = L"&Restaurar";
			this->Restaurar->UseVisualStyleBackColor = true;
			this->Restaurar->Click += gcnew System::EventHandler(this, &Form1::Restaurar_Click);
			// 
			// Imagen
			// 
			this->Imagen->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Imagen->Location = System::Drawing::Point(267, 142);
			this->Imagen->Name = L"Imagen";
			this->Imagen->Size = System::Drawing::Size(402, 355);
			this->Imagen->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->Imagen->TabIndex = 8;
			this->Imagen->TabStop = false;
			// 
			// textResultados
			// 
			this->textResultados->Location = System::Drawing::Point(11, 143);
			this->textResultados->Multiline = true;
			this->textResultados->Name = L"textResultados";
			this->textResultados->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textResultados->Size = System::Drawing::Size(182, 354);
			this->textResultados->TabIndex = 10;
			// 
			// textRuta
			// 
			this->textRuta->Location = System::Drawing::Point(276, 85);
			this->textRuta->Name = L"textRuta";
			this->textRuta->Size = System::Drawing::Size(346, 20);
			this->textRuta->TabIndex = 5;
			// 
			// Cambiar
			// 
			this->Cambiar->Location = System::Drawing::Point(628, 86);
			this->Cambiar->Name = L"Cambiar";
			this->Cambiar->Size = System::Drawing::Size(75, 23);
			this->Cambiar->TabIndex = 6;
			this->Cambiar->Text = L"&Cambiar";
			this->Cambiar->UseVisualStyleBackColor = true;
			this->Cambiar->Click += gcnew System::EventHandler(this, &Form1::Cambiar_Click);
			// 
			// Algoritmo
			// 
			this->Algoritmo->FormattingEnabled = true;
			this->Algoritmo->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Medallero", L"MedalleroOrdenado", L"MedalleroDeporte", 
				L"MedalleroDeporteOrdenado", L"Clasificacion_Pais_Primero", L"Clasificacion_Pais_Ultimo", L"Clasificacion_Pais_Aleatorio"});
			this->Algoritmo->Location = System::Drawing::Point(393, 27);
			this->Algoritmo->Name = L"Algoritmo";
			this->Algoritmo->Size = System::Drawing::Size(254, 21);
			this->Algoritmo->TabIndex = 7;
			// 
			// progessBar
			// 
			this->progessBar->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->progessBar->Location = System::Drawing::Point(23, 118);
			this->progessBar->Name = L"progessBar";
			this->progessBar->Size = System::Drawing::Size(763, 18);
			this->progessBar->TabIndex = 11;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(798, 523);
			this->Controls->Add(this->progessBar);
			this->Controls->Add(this->Algoritmo);
			this->Controls->Add(this->Cambiar);
			this->Controls->Add(this->textRuta);
			this->Controls->Add(this->textResultados);
			this->Controls->Add(this->Imagen);
			this->Controls->Add(this->Restaurar);
			this->Controls->Add(this->Comenzprueb);
			this->Controls->Add(this->textRepFin);
			this->Controls->Add(this->textRepIni);
			this->Controls->Add(this->textInc);
			this->Controls->Add(this->textLongFin);
			this->Controls->Add(this->textLongIni);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Form1";
			this->Text = L"Mide medallero";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Imagen))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

void Restaura(){

			this->textLongIni->Text="100";
			this->textLongFin->Text="5000";
			this->textInc->Text="100";
			this->textRepIni->Text="5000";
			this->textRepFin->Text="5000";
			this->textRuta->Text = System::Environment::CurrentDirectory;"";
			this->Carpeta->SelectedPath = System::Environment::CurrentDirectory;
			this->Imagen->Image= System::Drawing::Image::FromFile("Imag.png");
			this->Algoritmo->Text="Algoritmos...";
			this->textResultados->Text="";
			this->progessBar->Value =0 ;
			this->Imagen->Image= System::Drawing::Image::FromFile("Imag.png");
			

}

void crearAlgoritmo(int a,CAlgoritmo * &alg,std::string &nomf){
		
	switch ( a ){
				
			case 0: alg = new CAlgoritmoMedalleroPais;nomf = "Medallero_NPaises.txt";break;
			case 1: alg = new CAlgoritmoMedalleroOrdenadoPais;nomf = "MedalleroOrdenado_NPaises.txt";break;
			case 2: alg = new CAlgoritmoDeporteNormal;nomf = "MedalleroDeporte_DeporteAleatorio.txt";break;	
			case 3: alg = new CAlgoritmoDeporteOrdenado;nomf = "MedalleroDeporteOrdenado_DeporteAleatorio.txt";break;	
			case 4: alg = new CAlgoritmoPaisPrimero;nomf = "Clasif_NPaisesPrimero.txt";break;	
			case 5: alg = new CAlgoritmoPaisUltimo;nomf = "Clasif_NPaisesUltimo.txt";break;	
			case 6: alg = new CAlgoritmoPaisAleatorio;nomf = "Clasif_NPaisesAleatorio.txt";break;	
	}
}


void extraerDatosForm(int &tamIni,int &tamFin,int &intervalo,int &numEjeIni,int &numEjeFin){
						
	tamIni =  System::Convert::ToInt32(this->textLongIni->Text);
	tamFin = System::Convert::ToInt32(this->textLongFin->Text);
	intervalo = System::Convert::ToInt32(this->textInc->Text);
	numEjeIni = System::Convert::ToInt32(this->textRepIni->Text);
	numEjeFin = System::Convert::ToInt32(this->textRepFin->Text);
			
		
}

bool rutaOk(){
	std::string mensaje;
	if (!System::IO::File::Exists(this->Carpeta->SelectedPath + "\\wgnuplot.exe")){
		mensaje=" ------------ E R R O R-------------- \n     El directorio seleccionado no contiene \r el fichero wgnuplot.exe. \r\n NO SE GENERARA LA GRAFICA \r\n  --------------------------------------------\r\n ";
		this->textResultados->AppendText(System::String(mensaje.c_str()).ToString());
		this->Carpeta->SelectedPath = this->textRuta->Text;
		return false;
	}	 
	else{
		mensaje=" ------------ DIRECTORIO GNUPLOT CORRECTO-------------- \r\n     Se generara la grafica de los tiempos del algoritmo.  \r\n  --------------------------------------------\r\n ";	
		this->textResultados->AppendText(System::String(mensaje.c_str()).ToString());
		this->textRuta->Text = Carpeta->SelectedPath;
		this->Carpeta->SelectedPath = this->textRuta->Text;
		return true;
	}


}
private: System::Void Cambiar_Click(System::Object^  sender, System::EventArgs^  e) {
		bool rutaOK;	 
			 //System::IO::File::Exists(this->Carpeta->SelectedPath + "\\wgnuplot.exe"))
			 if (this->Carpeta->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					rutaOK= rutaOk();
				 
//				 delete Imagen->Image;
				 //this->Imagen->Image= System::Drawing::Image::FromFile("reloj.gif");
				 
		 }
private: System::Void Restaurar_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Restaura();

		 }

private: System::Void Comenzprueb_Click(System::Object^  sender, System::EventArgs^  e) {

	//Inicializacion y declaracion de variables
			 
	this->progessBar->Value =0;
	std::string nomfich, rutaGNUPlot;
	int alg;
	int tamIni,tamFin,intervalo,numEjeIni,numEjeFin;
	double t1, t2, tiempo;
	alg = this->Algoritmo->SelectedIndex;
	String ^netStr = this->textRuta->Text;
	rutaGNUPlot = (char*)(void*)Marshal::StringToHGlobalAnsi(netStr);

	if ((alg ==-1)){
		this->textResultados->AppendText("Elija un tipo de algoritmo a ejecutar \r\n");
			
	}
	else {

		this->extraerDatosForm(tamIni,tamFin,intervalo,numEjeIni,numEjeFin);
		CAlgoritmo * algoritmo;
		
		CMideTiempos medicion(tamIni,tamFin,intervalo,numEjeIni,numEjeFin);
	
		int interv= (tamFin -tamIni)/intervalo;
		interv++;
		this->progessBar->Value = 0;
		this->progessBar->Minimum = 0;
		this->progessBar->Maximum = interv;

		//Inicializamos la variable de salida del formulario una vez que tenemos los valores definidos
		// de la barra de progreso
		CSalidaWinForms * sal1 = new CSalidaWinForms(this->textResultados,this->progessBar);

		this->crearAlgoritmo(alg,algoritmo,nomfich);

		CSalidaGNUPlot * sal2;
		sal2 = new CSalidaGNUPlot;
		sal2->setFichero(nomfich);
				
		delete Imagen->Image;
		this->Imagen->Image= System::Drawing::Image::FromFile("Imag.png");
		t1 = clock();
		medicion.LanzaPrueba(algoritmo,sal1,sal2);
		t2 = clock();

		if (rutaOk()){//Comprobamos que la ruta del GNUPlot sea la correcta

			//Cogemos la ruta del directorio de trabajo del proyecto
			String ^netStr2 = System::Environment::CurrentDirectory;
			std::string diract= (char*)(void*)Marshal::StringToHGlobalAnsi(netStr2);

			//Formamos una cadena con los parametros necesarios para el gnuplot entre ellos el de cambiar
			// el directorio de trabajo para que nos lea los ficheros de nuestro directorio actual
			std::string cad = rutaGNUPlot + "\\wgnuplot -e \"cd '"+diract+"'; set terminal png;set output \\\"grafica.png\\\";plot \\\""+nomfich+"\\\" with lines lw 2\"";
			
			int codigo = system(cad.c_str());
			if ( codigo == 0){
				System::String ^ mensaje =" El grafico se ha generado correctamente\r\n";
				this->textResultados->AppendText(mensaje);
			}
			else {
					System::String ^ mensaje =" El grafico no se ha podido generar";
					this->textResultados->AppendText(mensaje);
			}
		}
		delete Imagen->Image;
		this->Imagen->Image= System::Drawing::Image::FromFile("grafica.png");

		tiempo = (t2 - t1)/CLOCKS_PER_SEC;
		int hh = ((int)tiempo) /3600;
		int aux =  ((int)tiempo) % 3600;
		int mm =aux/ 60;
		int ss = aux % 60;
		System::String ^hora = hh.ToString();
	System::String ^min = mm.ToString();
	System::String ^seg = ss.ToString();
	System::String ^linea = "El tiempo empleado es  " + hora + " : " + min + " : "  + seg + "  (HH:MM:SS)" ;
	this->textResultados->AppendText(linea+"\r\n");
		
		delete algoritmo;
		delete sal1;
		
		if (sal2 != NULL) delete sal2;
	}
}
};
}