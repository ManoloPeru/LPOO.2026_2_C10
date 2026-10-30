#pragma once
#include "ComboHelper.h"

namespace SGPlantaReciclajeView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGPlantaReciclajeController;
	using namespace SGPlantaReciclajeModel;

	/// <summary>
	/// Resumen de frmEditarCelda
	/// </summary>
	public ref class frmEditarCelda : public System::Windows::Forms::Form
	{
	public:
		frmEditarCelda(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmEditarCelda(CeldaProceso^ celda)
		{
			InitializeComponent();
			this->celdaSeleccionada = celda;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarCelda()
		{
			if (components)
			{
				delete components;
			}
		}

	private: CeldaProceso^ celdaSeleccionada;
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbTipo;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtCapacidadMax;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->grpBoxPrincipal = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbTipo = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCapacidadMax = (gcnew System::Windows::Forms::TextBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grpBoxPrincipal->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(123, 355);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(173, 56);
			this->btnGrabar->TabIndex = 21;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarCelda::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(361, 355);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 56);
			this->btnCancelar->TabIndex = 22;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarCelda::btnCancelar_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Controls->Add(this->cmbTipo);
			this->grpBoxPrincipal->Controls->Add(this->cmbEstado);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->txtCapacidadMax);
			this->grpBoxPrincipal->Controls->Add(this->txtNombre);
			this->grpBoxPrincipal->Controls->Add(this->txtId);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(14, 14);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(619, 314);
			this->grpBoxPrincipal->TabIndex = 23;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general de la Celda de Procesos";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(415, 256);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 24);
			this->label3->TabIndex = 9;
			this->label3->Text = L"kg/h";
			// 
			// cmbTipo
			// 
			this->cmbTipo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipo->FormattingEnabled = true;
			this->cmbTipo->Location = System::Drawing::Point(190, 150);
			this->cmbTipo->Name = L"cmbTipo";
			this->cmbTipo->Size = System::Drawing::Size(215, 30);
			this->cmbTipo->TabIndex = 3;
			// 
			// cmbEstado
			// 
			this->cmbEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Location = System::Drawing::Point(190, 201);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(215, 30);
			this->cmbEstado->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 256);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(176, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Capacidad Máxima:";
			// 
			// txtCapacidadMax
			// 
			this->txtCapacidadMax->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCapacidadMax->Location = System::Drawing::Point(190, 252);
			this->txtCapacidadMax->Margin = System::Windows::Forms::Padding(5);
			this->txtCapacidadMax->Name = L"txtCapacidadMax";
			this->txtCapacidadMax->Size = System::Drawing::Size(215, 28);
			this->txtCapacidadMax->TabIndex = 5;
			// 
			// txtNombre
			// 
			this->txtNombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtNombre->Location = System::Drawing::Point(190, 104);
			this->txtNombre->Margin = System::Windows::Forms::Padding(5);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(403, 28);
			this->txtNombre->TabIndex = 2;
			// 
			// txtId
			// 
			this->txtId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtId->Enabled = false;
			this->txtId->Location = System::Drawing::Point(190, 57);
			this->txtId->Margin = System::Windows::Forms::Padding(5);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(126, 28);
			this->txtId->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 201);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 24);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Estado:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(13, 150);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(53, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Tipo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(13, 104);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Nombre:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 62);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código:";
			// 
			// frmEditarCelda
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(660, 430);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmEditarCelda";
			this->Text = L"Modificar la información de una Celda";
			this->Load += gcnew System::EventHandler(this, &frmEditarCelda::frmEditarCelda_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEditarCelda_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargar los datos del objeto EstacionClasificadora en los controles del formulario
		this->txtId->Text = this->celdaSeleccionada->getId();
		this->txtNombre->Text = this->celdaSeleccionada->getNombre();
		this->txtCapacidadMax->Text = Convert::ToString(this->celdaSeleccionada->getCapacidad());

		int idTipo = this->celdaSeleccionada->getTipo();
		int idEstado = this->celdaSeleccionada->getEstado();

		ComboHelper::LlenarComboTipoCelda(this->cmbTipo, idTipo);
		ComboHelper::LlenarComboEstadoCelda(this->cmbEstado, idEstado);
	}
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = this->txtId->Text;
		String^ nombre = this->txtNombre->Text;
		String^ capacidadMax = this->txtCapacidadMax->Text;
		double capacidad = 0.0;

		// Validar los campos antes de guardar
		if (nombre->Equals("") || cmbTipo->SelectedIndex == -1 || cmbEstado->SelectedIndex == -1 || capacidadMax->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int idTipo = Convert::ToInt32(cmbTipo->SelectedValue);
		int idEstado = Convert::ToInt32(cmbEstado->SelectedValue);
		if (!Double::TryParse(capacidadMax, capacidad)) {
			MessageBox::Show("Error: La capacidad máxima debe ser un valor numérico válido (ej. 23.4).",
				"Error de validación", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return; // Detiene la ejecución y evita que se guarde el registro
		}

		// Llamando al controlador para registrar la nueva celda
		CeldaProcesoController^ celdaController = gcnew CeldaProcesoController();
		String^ resultado = celdaController->ModificarCelda(id, nombre, idTipo, idEstado, capacidad);
		if (resultado == "") {
			MessageBox::Show("Los cambios se han guardado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close(); // Cierra el formulario actual
		}
		else {
			MessageBox::Show("Error al modificar la información de la celda:" + Environment::NewLine + resultado, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
