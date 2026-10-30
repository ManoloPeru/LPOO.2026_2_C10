#pragma once
#include "frmMantEstacion.h"
#include "frmMantCeldaProceso.h"
#include "frmCalibracionBrazo.h"
#include "frmMantEstacionBD.h"

namespace SGPlantaReciclajeView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGPlantaReciclajeController;
	using namespace SGPlantaReciclajeModel;

	/// <summary>
	/// Resumen de frmPrincipal
	/// </summary>
	public ref class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		frmPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		frmPrincipal(Usuario^ usuario)
		{
			InitializeComponent();
			this->usuario = usuario;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}

	private: Usuario^ usuario;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ mantenimientoToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ estaciónClasificadoraToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ celdaDeProcesosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ operaciónToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ rutinaDeCalibraciónToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^ stStrip;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblBienvenida;
	private: System::Windows::Forms::ToolStripStatusLabel^ lblFechaHora;
	private: System::Windows::Forms::Timer^ timerReloj;
	private: System::Windows::Forms::ToolStripMenuItem^ baseDeDatosToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ estaciónToolStripMenuItem;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mantenimientoToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->estaciónClasificadoraToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->celdaDeProcesosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->operaciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rutinaDeCalibraciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mantenimientoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stStrip = (gcnew System::Windows::Forms::StatusStrip());
			this->lblBienvenida = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->lblFechaHora = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->timerReloj = (gcnew System::Windows::Forms::Timer(this->components));
			this->baseDeDatosToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->estaciónToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->stStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->mantenimientoToolStripMenuItem1,
					this->baseDeDatosToolStripMenuItem, this->operaciónToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(11, 4, 0, 4);
			this->menuStrip1->Size = System::Drawing::Size(749, 37);
			this->menuStrip1->TabIndex = 0;
			// 
			// mantenimientoToolStripMenuItem1
			// 
			this->mantenimientoToolStripMenuItem1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->mantenimientoToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->estaciónClasificadoraToolStripMenuItem,
					this->celdaDeProcesosToolStripMenuItem
			});
			this->mantenimientoToolStripMenuItem1->Name = L"mantenimientoToolStripMenuItem1";
			this->mantenimientoToolStripMenuItem1->Size = System::Drawing::Size(153, 29);
			this->mantenimientoToolStripMenuItem1->Text = L"Mantenimiento";
			// 
			// estaciónClasificadoraToolStripMenuItem
			// 
			this->estaciónClasificadoraToolStripMenuItem->Name = L"estaciónClasificadoraToolStripMenuItem";
			this->estaciónClasificadoraToolStripMenuItem->Size = System::Drawing::Size(265, 30);
			this->estaciónClasificadoraToolStripMenuItem->Text = L"Estación clasificadora";
			this->estaciónClasificadoraToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::estaciónClasificadoraToolStripMenuItem_Click);
			// 
			// celdaDeProcesosToolStripMenuItem
			// 
			this->celdaDeProcesosToolStripMenuItem->Name = L"celdaDeProcesosToolStripMenuItem";
			this->celdaDeProcesosToolStripMenuItem->Size = System::Drawing::Size(265, 30);
			this->celdaDeProcesosToolStripMenuItem->Text = L"Celda de procesos";
			this->celdaDeProcesosToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::celdaDeProcesosToolStripMenuItem_Click);
			// 
			// operaciónToolStripMenuItem
			// 
			this->operaciónToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->rutinaDeCalibraciónToolStripMenuItem });
			this->operaciónToolStripMenuItem->Name = L"operaciónToolStripMenuItem";
			this->operaciónToolStripMenuItem->Size = System::Drawing::Size(112, 29);
			this->operaciónToolStripMenuItem->Text = L"Operación";
			// 
			// rutinaDeCalibraciónToolStripMenuItem
			// 
			this->rutinaDeCalibraciónToolStripMenuItem->Name = L"rutinaDeCalibraciónToolStripMenuItem";
			this->rutinaDeCalibraciónToolStripMenuItem->Size = System::Drawing::Size(265, 30);
			this->rutinaDeCalibraciónToolStripMenuItem->Text = L"Rutina de Calibración";
			this->rutinaDeCalibraciónToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::rutinaDeCalibraciónToolStripMenuItem_Click);
			// 
			// mantenimientoToolStripMenuItem
			// 
			this->mantenimientoToolStripMenuItem->Name = L"mantenimientoToolStripMenuItem";
			this->mantenimientoToolStripMenuItem->Size = System::Drawing::Size(32, 19);
			// 
			// stStrip
			// 
			this->stStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->lblBienvenida, this->lblFechaHora });
			this->stStrip->Location = System::Drawing::Point(0, 395);
			this->stStrip->Name = L"stStrip";
			this->stStrip->Size = System::Drawing::Size(749, 22);
			this->stStrip->TabIndex = 2;
			this->stStrip->Text = L"statusStrip1";
			// 
			// lblBienvenida
			// 
			this->lblBienvenida->Name = L"lblBienvenida";
			this->lblBienvenida->Size = System::Drawing::Size(0, 17);
			// 
			// lblFechaHora
			// 
			this->lblFechaHora->BorderSides = System::Windows::Forms::ToolStripStatusLabelBorderSides::Left;
			this->lblFechaHora->Name = L"lblFechaHora";
			this->lblFechaHora->Size = System::Drawing::Size(734, 17);
			this->lblFechaHora->Spring = true;
			this->lblFechaHora->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// timerReloj
			// 
			this->timerReloj->Tick += gcnew System::EventHandler(this, &frmPrincipal::timerReloj_Tick);
			// 
			// baseDeDatosToolStripMenuItem
			// 
			this->baseDeDatosToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->estaciónToolStripMenuItem });
			this->baseDeDatosToolStripMenuItem->Name = L"baseDeDatosToolStripMenuItem";
			this->baseDeDatosToolStripMenuItem->Size = System::Drawing::Size(140, 29);
			this->baseDeDatosToolStripMenuItem->Text = L"Base de datos";
			// 
			// estaciónToolStripMenuItem
			// 
			this->estaciónToolStripMenuItem->Name = L"estaciónToolStripMenuItem";
			this->estaciónToolStripMenuItem->Size = System::Drawing::Size(180, 30);
			this->estaciónToolStripMenuItem->Text = L"Estación";
			this->estaciónToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmPrincipal::estaciónToolStripMenuItem_Click);
			// 
			// frmPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(749, 417);
			this->Controls->Add(this->stStrip);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"frmPrincipal";
			this->Text = L"Sistema de Gestión - Planta de Reciclaje Automatizada de Mecatrónica";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &frmPrincipal::frmPrincipal_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->stStrip->ResumeLayout(false);
			this->stStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void estaciónClasificadoraToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantEstacion^ ventana = gcnew frmMantEstacion();
		ventana->MdiParent = this;
		ventana->Show();
	}

	private: System::Void celdaDeProcesosToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantCeldaProceso^ ventana = gcnew frmMantCeldaProceso();
		ventana->MdiParent = this;
		ventana->Show();
	}

	private: System::Void rutinaDeCalibraciónToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmCalibracionBrazo^ ventana = gcnew frmCalibracionBrazo();
		ventana->MdiParent = this;
		ventana->Show();
	}
	private: System::Void frmPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
		lblBienvenida->Text = "";
		if(this->usuario != nullptr) {
			lblBienvenida->Text = "Bienvenido, " + usuario->getNombres() + " " + usuario->getApellidos();
		}

		// Intervalo de 1000 milisegundos (1 segundo)
		this->timerReloj->Interval = 1000;
		this->timerReloj->Tick += gcnew System::EventHandler(this, &frmPrincipal::timerReloj_Tick);
		this->timerReloj->Start();
	}
	private: System::Void timerReloj_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Formato: dd/MM/YYYY hh:mm:ss
		this->lblFechaHora->Text = DateTime::Now.ToString("dd/MM/yyyy HH:mm:ss");
	}
	private: System::Void estaciónToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantEstacionBD^ ventana = gcnew frmMantEstacionBD();
		ventana->MdiParent = this;
		ventana->Show();
	}
};
}
