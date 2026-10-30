#pragma once
#include "ComboHelper.h"   
#include "frmNuevaCelda.h"
#include "frmEditarCelda.h"

namespace SGPlantaReciclajeView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmMantCeldaProceso
	/// </summary>
	public ref class frmMantCeldaProceso : public System::Windows::Forms::Form
	{
	public:
		frmMantCeldaProceso(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->celdaController = gcnew CeldaProcesoController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantCeldaProceso()
		{
			if (components)
			{
				delete components;
			}
		}
	private: CeldaProcesoController^ celdaController;	// Instancia del controlador de celdas de proceso

	private: System::Windows::Forms::Button^ btnEliminar;
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::DataGridView^ dgvLista;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ cmbTipo;
	private: System::Windows::Forms::ComboBox^ cmbEstado;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCapacidadMax;






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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->cmbTipo = (gcnew System::Windows::Forms::ComboBox());
			this->cmbEstado = (gcnew System::Windows::Forms::ComboBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->colId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCapacidadMax = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->btnEliminar->Location = System::Drawing::Point(668, 545);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(98, 34);
			this->btnEliminar->TabIndex = 19;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantCeldaProceso::btnEliminar_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(494, 545);
			this->btnEditar->Margin = System::Windows::Forms::Padding(4);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(98, 34);
			this->btnEditar->TabIndex = 18;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantCeldaProceso::btnEditar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(321, 545);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(4);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(98, 34);
			this->btnNuevo->TabIndex = 17;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantCeldaProceso::btnNuevo_Click);
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
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colId, this->colNombre,
					this->colTipo, this->colEstado, this->colCapacidadMax
			});
			this->dgvLista->Location = System::Drawing::Point(13, 172);
			this->dgvLista->Margin = System::Windows::Forms::Padding(4);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1041, 352);
			this->dgvLista->TabIndex = 21;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->cmbTipo);
			this->groupBox1->Controls->Add(this->cmbEstado);
			this->groupBox1->Controls->Add(this->btnLimpiar);
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtId);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(1041, 151);
			this->groupBox1->TabIndex = 20;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(419, 49);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 24);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Estado :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(8, 102);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 24);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Tipo :";
			// 
			// cmbTipo
			// 
			this->cmbTipo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipo->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTipo->FormattingEnabled = true;
			this->cmbTipo->Location = System::Drawing::Point(148, 96);
			this->cmbTipo->Name = L"cmbTipo";
			this->cmbTipo->Size = System::Drawing::Size(220, 30);
			this->cmbTipo->TabIndex = 17;
			// 
			// cmbEstado
			// 
			this->cmbEstado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbEstado->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbEstado->FormattingEnabled = true;
			this->cmbEstado->Location = System::Drawing::Point(586, 43);
			this->cmbEstado->Name = L"cmbEstado";
			this->cmbEstado->Size = System::Drawing::Size(215, 30);
			this->cmbEstado->TabIndex = 18;
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnLimpiar->Location = System::Drawing::Point(703, 92);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(4);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(98, 34);
			this->btnLimpiar->TabIndex = 3;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmMantCeldaProceso::btnLimpiar_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnBuscar->Location = System::Drawing::Point(586, 93);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(98, 34);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantCeldaProceso::btnBuscar_Click);
			// 
			// txtId
			// 
			this->txtId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtId->Location = System::Drawing::Point(148, 46);
			this->txtId->Margin = System::Windows::Forms::Padding(4);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(220, 28);
			this->txtId->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 49);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código :";
			// 
			// colId
			// 
			this->colId->HeaderText = L"Código";
			this->colId->MinimumWidth = 6;
			this->colId->Name = L"colId";
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre";
			this->colNombre->MinimumWidth = 6;
			this->colNombre->Name = L"colNombre";
			this->colNombre->Width = 280;
			// 
			// colTipo
			// 
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->MinimumWidth = 6;
			this->colTipo->Name = L"colTipo";
			this->colTipo->Width = 120;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 180;
			// 
			// colCapacidadMax
			// 
			this->colCapacidadMax->HeaderText = L"Capacidad Máxima (kg/h)";
			this->colCapacidadMax->Name = L"colCapacidadMax";
			this->colCapacidadMax->Width = 300;
			// 
			// frmMantCeldaProceso
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1080, 611);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmMantCeldaProceso";
			this->Text = L"Mantenimiento de Celdas de Proceso";
			this->Load += gcnew System::EventHandler(this, &frmMantCeldaProceso::frmMantCeldaProceso_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmMantCeldaProceso_Load(System::Object^ sender, System::EventArgs^ e) {
		ComboHelper::LlenarComboTipoCelda(this->cmbTipo, 0);
		ComboHelper::LlenarComboEstadoCelda(this->cmbEstado, 0);

		List<CeldaProceso^>^ listaCeldas = this->celdaController->ListarCeldas();
		mostrarGrilla(listaCeldas);
	}

	public:	void mostrarGrilla(List<CeldaProceso^>^ listaCeldas)
	{
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaCeldas->Count; i++)
		{
			// Obtener la celda actual de la lista
			CeldaProceso^ celda = listaCeldas[i];
			// Crear un arreglo de strings para representar la fila del DataGridView
			array<String^>^ filaGrilla = gcnew array<String^>(5);
			// Asignar los valores de las propiedades de la celda a cada columna de la fila
			filaGrilla[0] = celda->getId();
			filaGrilla[1] = celda->getNombre();
			filaGrilla[4] = celda->getCapacidad().ToString();

			TipoCeldaController^ tipoController = gcnew TipoCeldaController();
			TipoCelda^ tipo = tipoController->ConsultarTipo(celda->getTipo());
			filaGrilla[2] = tipo->getDescripcion();

			EstadoCeldaController^ estadoController = gcnew EstadoCeldaController();
			EstadoCelda^ estado = estadoController->ConsultarEstado(celda->getEstado());
			filaGrilla[3] = estado->getDescripcion();

			// Agregar la fila al DataGridView
			this->dgvLista->Rows->Add(filaGrilla);
		}
		this->dgvLista->AutoGenerateColumns = false; // Desactivar la generación automática de columnas
		this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		this->dgvLista->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells); // Ajustar el ancho de las columnas al contenido
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ id = this->txtId->Text;
		if (String::IsNullOrEmpty(id) && cmbTipo->SelectedIndex == -1 && cmbEstado->SelectedIndex == -1)
		{
			MessageBox::Show("Por favor, selecciones al menos un criterio de búsqueda.", "Error de búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		int idTipo = cmbTipo->SelectedIndex != -1 ? Convert::ToInt32(cmbTipo->SelectedValue) : 0;
		int idEstado = cmbEstado->SelectedIndex != -1 ? Convert::ToInt32(cmbEstado->SelectedValue) : 0;

		List<CeldaProceso^>^ listaFiltrada = this->celdaController->ConsultarCeldaByFiltros(id, idTipo, idEstado);
		if (listaFiltrada->Count > 0)
		{
			mostrarGrilla(listaFiltrada);
		}
		else
		{
			MessageBox::Show("No se encontró ninguna celda con la información proporcionada.", "Resultado de búsqueda", MessageBoxButtons::OK, MessageBoxIcon::Information);
			this->dgvLista->Rows->Clear(); // Limpiar la grilla si no se encuentra la celda
		}
	}

	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->txtId->Clear();
		this->cmbTipo->SelectedIndex = -1;
		this->cmbEstado->SelectedIndex = -1;
		List<CeldaProceso^>^ listaCeldas = this->celdaController->ListarCeldas();
		mostrarGrilla(listaCeldas);
	}

	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		// Crear una nueva instancia del formulario de nueva celda
		frmNuevaCelda^ nuevaCeldaForm = gcnew frmNuevaCelda();
		nuevaCeldaForm->ShowDialog(this);
		// Llamar al método para cargar la lista de celdas nuevamente
		List<CeldaProceso^>^ listaCeldas = this->celdaController->ListarCeldas();
		mostrarGrilla(listaCeldas);
	}

	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si se ha seleccionado una fila en el DataGridView
		if (this->dgvLista->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dgvLista->SelectedRows[0]->Index;
			String^ id = this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value->ToString();

			CeldaProceso^ celdaSeleccionada = this->celdaController->ConsultarCelda(id);
			if (celdaSeleccionada == nullptr)
			{
				MessageBox::Show("No se encontró la celda seleccionada.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			frmEditarCelda^ editarCeldaForm = gcnew frmEditarCelda(celdaSeleccionada);
			editarCeldaForm->ShowDialog();
			// Llamar al mtodo para cargar la lista de celdas nuevamente
			List<CeldaProceso^>^ listaCeldas = this->celdaController->ListarCeldas();
			mostrarGrilla(listaCeldas);
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
			String^ id = this->dgvLista->Rows[selectedRowIndex]->Cells[0]->Value->ToString();
			// Crear una instancia del controlador y eliminar el operador
			String^ resultado = this->celdaController->EliminarCelda(id);
			if (resultado == "") {
				// Actualizar la lista de operadores en el DataGridView
				List<CeldaProceso^>^ listaCeldas = this->celdaController->ListarCeldas();
				mostrarGrilla(listaCeldas);
				MessageBox::Show("Celda eliminada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				MessageBox::Show("Error al eliminar la celda:" + resultado, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
		else
		{
			MessageBox::Show("Por favor, seleccione una celda para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
};
}
