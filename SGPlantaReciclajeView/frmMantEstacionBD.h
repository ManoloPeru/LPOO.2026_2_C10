#pragma once
#include "ComboHelper.h"   
#include "frmNuevaEstacionBD.h"
#include "frmEditarEstacionBD.h"

namespace SGPlantaReciclajeView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmMantEstacionBD
	/// </summary>
	public ref class frmMantEstacionBD : public System::Windows::Forms::Form
	{
	public:
		frmMantEstacionBD(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->estacionController = gcnew EstacionController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantEstacionBD()
		{
			if (components)
			{
				delete components;
			}
		}
	private: EstacionController^ estacionController;	// Instancia del controlador de estaciones
	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::DataGridView^ dgvLista;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtEstacionId;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstacionId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colAlias;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colUbicacion;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCapacidadKgH;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colHorasOperacion;

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colEstacionId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colAlias = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colUbicacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCapacidadKgH = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colHorasOperacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtEstacionId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEliminar->Location = System::Drawing::Point(730, 607);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(7);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(180, 39);
			this->btnEliminar->TabIndex = 19;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantEstacionBD::btnEliminar_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(524, 607);
			this->btnEditar->Margin = System::Windows::Forms::Padding(7);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(180, 39);
			this->btnEditar->TabIndex = 18;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantEstacionBD::btnEditar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(312, 607);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(7);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(180, 39);
			this->btnNuevo->TabIndex = 17;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantEstacionBD::btnNuevo_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLista->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colEstacionId,
					this->colAlias, this->colUbicacion, this->colEstado, this->colCapacidadKgH, this->colHorasOperacion
			});
			this->dgvLista->Location = System::Drawing::Point(16, 133);
			this->dgvLista->Margin = System::Windows::Forms::Padding(7);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1195, 460);
			this->dgvLista->TabIndex = 21;
			// 
			// colEstacionId
			// 
			this->colEstacionId->HeaderText = L"Id";
			this->colEstacionId->MinimumWidth = 6;
			this->colEstacionId->Name = L"colEstacionId";
			this->colEstacionId->Width = 80;
			// 
			// colAlias
			// 
			this->colAlias->HeaderText = L"Alias";
			this->colAlias->MinimumWidth = 6;
			this->colAlias->Name = L"colAlias";
			this->colAlias->Width = 200;
			// 
			// colUbicacion
			// 
			this->colUbicacion->HeaderText = L"Ubicación";
			this->colUbicacion->Name = L"colUbicacion";
			this->colUbicacion->Width = 200;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 120;
			// 
			// colCapacidadKgH
			// 
			this->colCapacidadKgH->HeaderText = L"Capacidad Kg/H";
			this->colCapacidadKgH->MinimumWidth = 6;
			this->colCapacidadKgH->Name = L"colCapacidadKgH";
			this->colCapacidadKgH->Width = 180;
			// 
			// colHorasOperacion
			// 
			this->colHorasOperacion->HeaderText = L"Horas Operación";
			this->colHorasOperacion->Name = L"colHorasOperacion";
			this->colHorasOperacion->Width = 180;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->cmbEstado);
			this->groupBox1->Controls->Add(this->btnLimpiar);
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtEstacionId);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(16, 16);
			this->groupBox1->Margin = System::Windows::Forms::Padding(7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(7);
			this->groupBox1->Size = System::Drawing::Size(1195, 103);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(326, 39);
			this->label3->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(160, 24);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Estado operativo :";
			// 
			// cmbEstado
			// 
			this->cmbEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Location = System::Drawing::Point(499, 39);
			this->cmbEstado->Margin = System::Windows::Forms::Padding(6);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(227, 30);
			this->cmbEstado->TabIndex = 18;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnLimpiar->Location = System::Drawing::Point(1001, 30);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(7);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(180, 46);
			this->btnLimpiar->TabIndex = 3;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmMantEstacionBD::btnLimpiar_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnBuscar->Location = System::Drawing::Point(796, 30);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(7);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(180, 46);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantEstacionBD::btnBuscar_Click);
			// 
			// txtEstacionId
			// 
			this->txtEstacionId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtEstacionId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEstacionId->Location = System::Drawing::Point(135, 39);
			this->txtEstacionId->Margin = System::Windows::Forms::Padding(7);
			this->txtEstacionId->Name = L"txtEstacionId";
			this->txtEstacionId->Size = System::Drawing::Size(111, 28);
			this->txtEstacionId->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(14, 39);
			this->label1->Margin = System::Windows::Forms::Padding(7, 0, 7, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"EstacionId :";
			// 
			// frmMantEstacionBD
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkOliveGreen;
			this->ClientSize = System::Drawing::Size(1237, 673);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmMantEstacionBD";
			this->Text = L"frmMantEstacionBD";
			this->Load += gcnew System::EventHandler(this, &frmMantEstacionBD::frmMantEstacionBD_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantEstacionBD_Load(System::Object^ sender, System::EventArgs^ e) {
		ComboHelper::LlenarComboEstadoEstacionBD(this->cmbEstado, 0);

		List<Estacion^>^ listaEstaciones = this->estacionController->ListarEstaciones();
		mostrarGrilla(listaEstaciones);
	}
	public:	void mostrarGrilla(List<Estacion^>^ listaEstaciones)
	{
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaEstaciones->Count; i++)
		{
			// Obtener la estación actual de la lista
			Estacion^ estacion = listaEstaciones[i];
			// Crear un arreglo de strings para representar la fila del DataGridView
			array<String^>^ filaGrilla = gcnew array<String^>(6);
			// Asignar los valores de las propiedades de la estación a cada columna de la fila
			filaGrilla[0] = estacion->getEstacionId().ToString();
			filaGrilla[1] = estacion->getAlias();
			filaGrilla[2] = estacion->getUbicacion();

			EstadoOperativoController^ estadoController = gcnew EstadoOperativoController();
			EstadoOperativo^ estado = estadoController->ConsultarEstado(estacion->getEstado());
			filaGrilla[3] = estado->getDescripcion();

			filaGrilla[4] = estacion->getCapacidadKgH().ToString();
			filaGrilla[5] = estacion->getHorasOperacion().ToString();

			// Agregar la fila al DataGridView
			this->dgvLista->Rows->Add(filaGrilla);
		}
		this->dgvLista->AutoGenerateColumns = false; // Desactivar la generación automática de columnas
		this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		this->dgvLista->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells); // Ajustar el ancho de las columnas al contenido
	}
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ sId = this->txtEstacionId->Text;
		if (String::IsNullOrEmpty(sId) && cmbEstado->SelectedIndex == -1)
		{
			MessageBox::Show("Por favor, selecciones al menos un criterio de búsqueda.", "Error de búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int idEstado = cmbEstado->SelectedIndex != -1 ? Convert::ToInt32(cmbEstado->SelectedValue) : 0;
		int id = (Int32::TryParse(sId, id)) ? id : 0;
		List<Estacion^>^ listaFiltrada = this->estacionController->ConsultarEstacionByIdEstado(id, idEstado);
		if (listaFiltrada->Count > 0)
		{
			mostrarGrilla(listaFiltrada);
		}
		else
		{
			MessageBox::Show("No se encontró ninguna estación con la información proporcionada.", "Resultado de búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->dgvLista->Rows->Clear(); // Limpiar la grilla si no se encuentra la estación
		}
	}
	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->txtEstacionId->Clear();
		this->cmbEstado->SelectedIndex = -1;
		List<Estacion^>^ listaEstaciones = this->estacionController->ListarEstaciones();
		mostrarGrilla(listaEstaciones);
	}
	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		// Crear una nueva instancia del formulario de nueva estación
		frmNuevaEstacionBD^ nuevaEstacionForm = gcnew frmNuevaEstacionBD();
		nuevaEstacionForm->ShowDialog(this);
		// Llamar al método para cargar la lista de estaciones nuevamente
		List<Estacion^>^ listaEstaciones = this->estacionController->ListarEstaciones();
		mostrarGrilla(listaEstaciones);
	}
	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si se ha seleccionado una fila en el DataGridView
		if (this->dgvLista->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dgvLista->SelectedRows[0]->Index;
			int Id = Convert::ToInt32(this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value);

			Estacion^ estacionSeleccionado = this->estacionController->ConsultarEstacion(Id);
			if (estacionSeleccionado == nullptr)
			{
				MessageBox::Show("No se encontró la estación seleccionada.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			frmEditarEstacionBD^ editarEstacionClasificadoraForm = gcnew frmEditarEstacionBD(estacionSeleccionado);
			editarEstacionClasificadoraForm->ShowDialog();
			// Llamar al mtodo para cargar la lista de operadores nuevamente
			List<Estacion^>^ listaEstaciones = this->estacionController->ListarEstaciones();
			mostrarGrilla(listaEstaciones);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si se ha seleccionado una fila en el DataGridView
		if (this->dgvLista->SelectedRows->Count > 0)
		{
			// Preguntar al usuario si est� seguro de eliminar el registro
			System::Windows::Forms::DialogResult respuesta = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
				"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			// Si el usuario selecciona "No", cancelar la operaci�n
			if (respuesta == System::Windows::Forms::DialogResult::No)
			{
				return; // Salir del evento si el usuario cancela
			}

			int selectedRowIndex = this->dgvLista->SelectedRows[0]->Index;
			int Id = Convert::ToInt32(this->dgvLista->Rows[selectedRowIndex]->Cells[0]->Value);
			// Crear una instancia del controlador y eliminar el operador
			String^ resultado = this->estacionController->EliminarEstacion(Id);
			if (resultado == "") {
				// Actualizar la lista de operadores en el DataGridView
				List<Estacion^>^ listaEstaciones = this->estacionController->ListarEstaciones();
				mostrarGrilla(listaEstaciones);
				MessageBox::Show("Estación eliminada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				MessageBox::Show("Error al eliminar la estación:" + resultado, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
};
}
