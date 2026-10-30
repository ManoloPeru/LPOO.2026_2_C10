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
	/// Resumen de frmEditarEstacion
	/// </summary>
	public ref class frmEditarEstacion : public System::Windows::Forms::Form
	{
	public:
		frmEditarEstacion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmEditarEstacion(EstacionClasificadora^ estacion)
		{
			InitializeComponent();
			this->estacionSeleccionada = estacion;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarEstacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: EstacionClasificadora^ estacionSeleccionada; // Variable para almacenar la estación seleccionada
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::ComboBox^ cmbTipo;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtUbicacion;
	private: System::Windows::Forms::TextBox^ txtAlias;
	private: System::Windows::Forms::TextBox^ txtSerialId;
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
			this->cmbTipo = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtUbicacion = (gcnew System::Windows::Forms::TextBox());
			this->txtAlias = (gcnew System::Windows::Forms::TextBox());
			this->txtSerialId = (gcnew System::Windows::Forms::TextBox());
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
			this->btnGrabar->TabIndex = 18;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarEstacion::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(349, 355);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 56);
			this->btnCancelar->TabIndex = 19;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarEstacion::btnCancelar_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->cmbTipo);
			this->grpBoxPrincipal->Controls->Add(this->cmbEstado);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->txtUbicacion);
			this->grpBoxPrincipal->Controls->Add(this->txtAlias);
			this->grpBoxPrincipal->Controls->Add(this->txtSerialId);
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
			this->grpBoxPrincipal->TabIndex = 20;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general de la Estacion Clasificadora";
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
			this->label2->Size = System::Drawing::Size(99, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Ubicación:";
			// 
			// txtUbicacion
			// 
			this->txtUbicacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtUbicacion->Location = System::Drawing::Point(190, 252);
			this->txtUbicacion->Margin = System::Windows::Forms::Padding(5);
			this->txtUbicacion->Name = L"txtUbicacion";
			this->txtUbicacion->Size = System::Drawing::Size(403, 28);
			this->txtUbicacion->TabIndex = 5;
			// 
			// txtAlias
			// 
			this->txtAlias->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtAlias->Location = System::Drawing::Point(190, 104);
			this->txtAlias->Margin = System::Windows::Forms::Padding(5);
			this->txtAlias->Name = L"txtAlias";
			this->txtAlias->Size = System::Drawing::Size(403, 28);
			this->txtAlias->TabIndex = 2;
			// 
			// txtSerialId
			// 
			this->txtSerialId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtSerialId->Enabled = false;
			this->txtSerialId->Location = System::Drawing::Point(190, 57);
			this->txtSerialId->Margin = System::Windows::Forms::Padding(5);
			this->txtSerialId->Name = L"txtSerialId";
			this->txtSerialId->Size = System::Drawing::Size(126, 28);
			this->txtSerialId->TabIndex = 1;
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
			this->label4->Size = System::Drawing::Size(55, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Alias:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 62);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Serial ID:";
			// 
			// frmEditarEstacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(660, 433);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmEditarEstacion";
			this->Text = L"Modificar la información de una Estación";
			this->Load += gcnew System::EventHandler(this, &frmEditarEstacion::frmEditarEstacion_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEditarEstacion_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargar los datos del objeto EstacionClasificadora en los controles del formulario
		this->txtSerialId->Text = this->estacionSeleccionada->getSerialId();
		this->txtAlias->Text = this->estacionSeleccionada->getAlias();
		this->txtUbicacion->Text = this->estacionSeleccionada->getUbicacion();

		int idTipo = this->estacionSeleccionada->getTipo();
		int idEstado = this->estacionSeleccionada->getEstado();

		ComboHelper::LlenarComboTipoEstacion(this->cmbTipo, idTipo);
		ComboHelper::LlenarComboEstadoEstacion(this->cmbEstado, idEstado);
	}

	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ serialId = this->txtSerialId->Text;
		String^ alias = this->txtAlias->Text;
		String^ ubicacion = this->txtUbicacion->Text;

		// Validar los campos antes de guardar
		if (alias->Equals("") || cmbTipo->SelectedIndex == -1 || cmbEstado->SelectedIndex == -1 || ubicacion->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int idTipo = Convert::ToInt32(cmbTipo->SelectedValue);
		int idEstado = Convert::ToInt32(cmbEstado->SelectedValue);
		
		// Llamando al controlador para registrar la nueva estación
		EstacionClasificadoraController^ estacionController = gcnew EstacionClasificadoraController();
		String^ resultado = estacionController->ModificarEstacion(serialId, alias, idTipo, idEstado, ubicacion);
		if (resultado == "") {
			MessageBox::Show("Los cambios se han guardado correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->Close(); // Cierra el formulario actual
		}
		else {
			MessageBox::Show("Error al modificar la información de la estación clasificadora:" + Environment::NewLine + resultado, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}

	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close(); // Cierra el formulario actual
	}
};
}
