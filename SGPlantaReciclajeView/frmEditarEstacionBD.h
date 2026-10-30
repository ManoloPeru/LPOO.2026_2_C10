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
	/// Resumen de frmEditarEstacionBD
	/// </summary>
	public ref class frmEditarEstacionBD : public System::Windows::Forms::Form
	{
	public:
		frmEditarEstacionBD(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmEditarEstacionBD(Estacion^ estacion)
		{
			InitializeComponent();
			this->estacionSeleccionada = estacion;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarEstacionBD()
		{
			if (components)
			{
				delete components;
			}
		}
	private: Estacion^ estacionSeleccionada; // Variable para almacenar la estación seleccionada
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: System::Windows::Forms::GroupBox^ grpBoxPrincipal;
	private: System::Windows::Forms::NumericUpDown^ txtHorasOperacion;
	private: System::Windows::Forms::NumericUpDown^ txtCapacidadKgH;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtUbicacion;
	private: System::Windows::Forms::TextBox^ txtAlias;
	private: System::Windows::Forms::TextBox^ txtEstacionId;
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
			this->txtHorasOperacion = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtCapacidadKgH = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtUbicacion = (gcnew System::Windows::Forms::TextBox());
			this->txtAlias = (gcnew System::Windows::Forms::TextBox());
			this->txtEstacionId = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->grpBoxPrincipal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtHorasOperacion))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtCapacidadKgH))->BeginInit();
			this->SuspendLayout();
			// 
			// btnGrabar
			// 
			this->btnGrabar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGrabar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGrabar->ForeColor = System::Drawing::Color::White;
			this->btnGrabar->Location = System::Drawing::Point(123, 372);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(5);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(173, 42);
			this->btnGrabar->TabIndex = 21;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = false;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarEstacionBD::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnCancelar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancelar->ForeColor = System::Drawing::Color::White;
			this->btnCancelar->Location = System::Drawing::Point(349, 372);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(5);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(173, 42);
			this->btnCancelar->TabIndex = 22;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = false;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarEstacionBD::btnCancelar_Click);
			// 
			// grpBoxPrincipal
			// 
			this->grpBoxPrincipal->Controls->Add(this->txtHorasOperacion);
			this->grpBoxPrincipal->Controls->Add(this->txtCapacidadKgH);
			this->grpBoxPrincipal->Controls->Add(this->label3);
			this->grpBoxPrincipal->Controls->Add(this->cmbEstado);
			this->grpBoxPrincipal->Controls->Add(this->label2);
			this->grpBoxPrincipal->Controls->Add(this->txtUbicacion);
			this->grpBoxPrincipal->Controls->Add(this->txtAlias);
			this->grpBoxPrincipal->Controls->Add(this->txtEstacionId);
			this->grpBoxPrincipal->Controls->Add(this->label6);
			this->grpBoxPrincipal->Controls->Add(this->label5);
			this->grpBoxPrincipal->Controls->Add(this->label4);
			this->grpBoxPrincipal->Controls->Add(this->label1);
			this->grpBoxPrincipal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpBoxPrincipal->Location = System::Drawing::Point(14, 17);
			this->grpBoxPrincipal->Margin = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Name = L"grpBoxPrincipal";
			this->grpBoxPrincipal->Padding = System::Windows::Forms::Padding(5);
			this->grpBoxPrincipal->Size = System::Drawing::Size(619, 345);
			this->grpBoxPrincipal->TabIndex = 23;
			this->grpBoxPrincipal->TabStop = false;
			this->grpBoxPrincipal->Text = L"Información general de la Estacion Clasificadora";
			// 
			// txtHorasOperacion
			// 
			this->txtHorasOperacion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtHorasOperacion->DecimalPlaces = 2;
			this->txtHorasOperacion->Location = System::Drawing::Point(219, 296);
			this->txtHorasOperacion->Name = L"txtHorasOperacion";
			this->txtHorasOperacion->Size = System::Drawing::Size(215, 28);
			this->txtHorasOperacion->TabIndex = 11;
			// 
			// txtCapacidadKgH
			// 
			this->txtCapacidadKgH->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtCapacidadKgH->DecimalPlaces = 2;
			this->txtCapacidadKgH->Location = System::Drawing::Point(219, 249);
			this->txtCapacidadKgH->Name = L"txtCapacidadKgH";
			this->txtCapacidadKgH->Size = System::Drawing::Size(215, 28);
			this->txtCapacidadKgH->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 298);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(186, 24);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Horas de Operacion:";
			// 
			// cmbEstado
			// 
			this->cmbEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Location = System::Drawing::Point(219, 198);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(215, 30);
			this->cmbEstado->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 155);
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
			this->txtUbicacion->Location = System::Drawing::Point(219, 151);
			this->txtUbicacion->Margin = System::Windows::Forms::Padding(5);
			this->txtUbicacion->Name = L"txtUbicacion";
			this->txtUbicacion->Size = System::Drawing::Size(374, 28);
			this->txtUbicacion->TabIndex = 5;
			// 
			// txtAlias
			// 
			this->txtAlias->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtAlias->Location = System::Drawing::Point(219, 104);
			this->txtAlias->Margin = System::Windows::Forms::Padding(5);
			this->txtAlias->Name = L"txtAlias";
			this->txtAlias->Size = System::Drawing::Size(374, 28);
			this->txtAlias->TabIndex = 2;
			// 
			// txtEstacionId
			// 
			this->txtEstacionId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtEstacionId->Enabled = false;
			this->txtEstacionId->Location = System::Drawing::Point(219, 58);
			this->txtEstacionId->Margin = System::Windows::Forms::Padding(5);
			this->txtEstacionId->Name = L"txtEstacionId";
			this->txtEstacionId->Size = System::Drawing::Size(126, 28);
			this->txtEstacionId->TabIndex = 1;
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
			this->label5->Location = System::Drawing::Point(13, 251);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 24);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Capacidad Kg/H:";
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
			this->label1->Size = System::Drawing::Size(107, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Estacion Id:";
			// 
			// frmEditarEstacionBD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->ClientSize = System::Drawing::Size(651, 430);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->grpBoxPrincipal);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6, 6, 6, 6);
			this->Name = L"frmEditarEstacionBD";
			this->Text = L"Modificar la información de una Estación";
			this->Load += gcnew System::EventHandler(this, &frmEditarEstacionBD::frmEditarEstacionBD_Load);
			this->grpBoxPrincipal->ResumeLayout(false);
			this->grpBoxPrincipal->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtHorasOperacion))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtCapacidadKgH))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEditarEstacionBD_Load(System::Object^ sender, System::EventArgs^ e) {
		// Cargar los datos del objeto EstacionClasificadora en los controles del formulario
		this->txtEstacionId->Text = this->estacionSeleccionada->getEstacionId().ToString();
		this->txtAlias->Text = this->estacionSeleccionada->getAlias();
		this->txtUbicacion->Text = this->estacionSeleccionada->getUbicacion();

		int idEstado = this->estacionSeleccionada->getEstado();
		ComboHelper::LlenarComboEstadoEstacionBD(this->cmbEstado, idEstado);
		this->txtCapacidadKgH->Value = Convert::ToDecimal(this->estacionSeleccionada->getCapacidadKgH());
		this->txtHorasOperacion->Value = Convert::ToDecimal(this->estacionSeleccionada->getHorasOperacion());
	}
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		int estacionId = Convert::ToInt32(this->txtEstacionId->Text);
		String^ alias = this->txtAlias->Text;
		String^ ubicacion = this->txtUbicacion->Text;
		// Validar los campos antes de guardar
		if (alias->Equals("") || cmbEstado->SelectedIndex == -1 || ubicacion->Equals("")) {
			MessageBox::Show("Por favor, complete todos los campos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int idEstado = Convert::ToInt32(cmbEstado->SelectedValue);
		double capacidadKgH = Convert::ToDouble(txtCapacidadKgH->Value);
		double horasOperacion = Convert::ToDouble(txtHorasOperacion->Value);
		Estacion^ estacion = gcnew Estacion(estacionId, alias, ubicacion, idEstado, capacidadKgH, horasOperacion);
		// Llamando al controlador para registrar la nueva estación
		EstacionController^ estacionController = gcnew EstacionController();
		String^ resultado = estacionController->ModificarEstacion(estacion);
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
