#pragma once

namespace SGPlantaReciclajeView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace SGPlantaReciclajeModel;

	/// <summary>
	/// Resumen de frmCalibracionBrazo
	/// </summary>
	public ref class frmCalibracionBrazo : public System::Windows::Forms::Form
	{
	public:
		frmCalibracionBrazo(void)
		{
			InitializeComponent();
			
			// Inicializar la lógica y crear los 5 brazos
			calculadora = gcnew WorkspaceCalculator();
			puntosEspiral = nullptr;
			escalaActual = 1.0f;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmCalibracionBrazo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ cboBrazo;
	private: System::Windows::Forms::Label^ lblCodigo;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Button^ btnGraficar;
	private: System::Windows::Forms::Label^ lblB;
	private: System::Windows::Forms::TextBox^ txtB;
	private: System::Windows::Forms::TextBox^ txtA;
	private: System::Windows::Forms::Label^ lblA;
	private: System::Windows::Forms::PictureBox^ pbLienzo;
	private: System::Windows::Forms::Label^ lblInfo;


	// --- VARIABLES DE LÓGICA ---
	private:
		List<BrazoNeumaticoClasificador^>^ listaBrazos;
		BrazoNeumaticoClasificador^ brazoActual;
		List<PointF>^ puntosEspiral;
		WorkspaceCalculator^ calculadora;
		float escalaActual;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnGraficar = (gcnew System::Windows::Forms::Button());
			this->lblB = (gcnew System::Windows::Forms::Label());
			this->txtB = (gcnew System::Windows::Forms::TextBox());
			this->txtA = (gcnew System::Windows::Forms::TextBox());
			this->lblA = (gcnew System::Windows::Forms::Label());
			this->cboBrazo = (gcnew System::Windows::Forms::ComboBox());
			this->lblCodigo = (gcnew System::Windows::Forms::Label());
			this->pbLienzo = (gcnew System::Windows::Forms::PictureBox());
			this->lblInfo = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLienzo))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnLimpiar);
			this->groupBox1->Controls->Add(this->btnGraficar);
			this->groupBox1->Controls->Add(this->lblB);
			this->groupBox1->Controls->Add(this->txtB);
			this->groupBox1->Controls->Add(this->txtA);
			this->groupBox1->Controls->Add(this->lblA);
			this->groupBox1->Controls->Add(this->cboBrazo);
			this->groupBox1->Controls->Add(this->lblCodigo);
			this->groupBox1->Location = System::Drawing::Point(15, 14);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(873, 239);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Trayectoria de calibración - Espiral de Arquimides";
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::Color::White;
			this->btnLimpiar->Location = System::Drawing::Point(430, 170);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(5);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(137, 43);
			this->btnLimpiar->TabIndex = 15;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmCalibracionBrazo::btnLimpiar_Click);
			// 
			// btnGraficar
			// 
			this->btnGraficar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnGraficar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGraficar->ForeColor = System::Drawing::Color::White;
			this->btnGraficar->Location = System::Drawing::Point(227, 170);
			this->btnGraficar->Margin = System::Windows::Forms::Padding(5);
			this->btnGraficar->Name = L"btnGraficar";
			this->btnGraficar->Size = System::Drawing::Size(137, 43);
			this->btnGraficar->TabIndex = 14;
			this->btnGraficar->Text = L"Graficar";
			this->btnGraficar->UseVisualStyleBackColor = false;
			this->btnGraficar->Click += gcnew System::EventHandler(this, &frmCalibracionBrazo::btnGraficar_Click);
			// 
			// lblB
			// 
			this->lblB->AutoSize = true;
			this->lblB->Location = System::Drawing::Point(361, 107);
			this->lblB->Name = L"lblB";
			this->lblB->Size = System::Drawing::Size(258, 24);
			this->lblB->TabIndex = 11;
			this->lblB->Text = L"Tasa Expansión (b) [mm/rad]:";
			// 
			// txtB
			// 
			this->txtB->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtB->Location = System::Drawing::Point(634, 107);
			this->txtB->Name = L"txtB";
			this->txtB->Size = System::Drawing::Size(100, 29);
			this->txtB->TabIndex = 10;
			// 
			// txtA
			// 
			this->txtA->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtA->Location = System::Drawing::Point(227, 104);
			this->txtA->Name = L"txtA";
			this->txtA->Size = System::Drawing::Size(100, 29);
			this->txtA->TabIndex = 9;
			// 
			// lblA
			// 
			this->lblA->AutoSize = true;
			this->lblA->Location = System::Drawing::Point(24, 107);
			this->lblA->Name = L"lblA";
			this->lblA->Size = System::Drawing::Size(190, 24);
			this->lblA->TabIndex = 8;
			this->lblA->Text = L"Radio Inicial (a) [mm]:";
			// 
			// cboBrazo
			// 
			this->cboBrazo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cboBrazo->FormattingEnabled = true;
			this->cboBrazo->Location = System::Drawing::Point(227, 41);
			this->cboBrazo->Name = L"cboBrazo";
			this->cboBrazo->Size = System::Drawing::Size(507, 32);
			this->cboBrazo->TabIndex = 7;
			this->cboBrazo->SelectedIndexChanged += gcnew System::EventHandler(this, &frmCalibracionBrazo::cboBrazo_SelectedIndexChanged);
			// 
			// lblCodigo
			// 
			this->lblCodigo->AutoSize = true;
			this->lblCodigo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCodigo->Location = System::Drawing::Point(24, 41);
			this->lblCodigo->Name = L"lblCodigo";
			this->lblCodigo->Size = System::Drawing::Size(158, 24);
			this->lblCodigo->TabIndex = 6;
			this->lblCodigo->Text = L"Brazo Registrado:";
			// 
			// pbLienzo
			// 
			this->pbLienzo->BackColor = System::Drawing::SystemColors::Info;
			this->pbLienzo->Location = System::Drawing::Point(248, 264);
			this->pbLienzo->Name = L"pbLienzo";
			this->pbLienzo->Size = System::Drawing::Size(639, 431);
			this->pbLienzo->TabIndex = 1;
			this->pbLienzo->TabStop = false;
			this->pbLienzo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmCalibracionBrazo::pbLienzo_Paint);
			// 
			// lblInfo
			// 
			this->lblInfo->AutoSize = true;
			this->lblInfo->Location = System::Drawing::Point(11, 278);
			this->lblInfo->Name = L"lblInfo";
			this->lblInfo->Size = System::Drawing::Size(126, 24);
			this->lblInfo->TabIndex = 2;
			this->lblInfo->Text = L"Lienzo limpio.";
			// 
			// frmCalibracionBrazo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(981, 710);
			this->Controls->Add(this->lblInfo);
			this->Controls->Add(this->pbLienzo);
			this->Controls->Add(this->groupBox1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"frmCalibracionBrazo";
			this->Text = L"Calibracion de Brazo Neumático";
			this->Load += gcnew System::EventHandler(this, &frmCalibracionBrazo::frmCalibracionBrazo_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLienzo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmCalibracionBrazo_Load(System::Object^ sender, System::EventArgs^ e) {
		listaBrazos = gcnew List<BrazoNeumaticoClasificador^>();

		// Constructor: (id, fabricante, horas, presMin, presMax, velocidad, radioInicial(a), tasaExpansion(b))
		listaBrazos->Add(gcnew BrazoNeumaticoClasificador(1, "Festo", 150.5, 1.5, 6.0, 120.0, 20.0, 15.0)); // Compacta
		listaBrazos->Add(gcnew BrazoNeumaticoClasificador(2, "SMC", 320.0, 2.0, 8.0, 150.0, 50.0, 60.0));  // Amplia
		listaBrazos->Add(gcnew BrazoNeumaticoClasificador(3, "KUKA", 1200.0, 3.0, 9.5, 200.0, 10.0, 25.0)); // Barrido rápido
		listaBrazos->Add(gcnew BrazoNeumaticoClasificador(4, "ABB", 850.0, 1.0, 5.0, 80.0, 40.0, 10.0));   // Muy densa
		listaBrazos->Add(gcnew BrazoNeumaticoClasificador(5, "FANUC", 45.0, 2.5, 7.0, 110.0, 5.0, 40.0));  // Centro despoblado

		// Llenar el ComboBox
		for each (BrazoNeumaticoClasificador ^ b in listaBrazos) {
			cboBrazo->Items->Add(b->getFabricante() + " (ID: " + b->getIdUnidadClasificadora() + ")");
		}

		// Seleccionar el primero por defecto
		if (cboBrazo->Items->Count > 0) {
			cboBrazo->SelectedIndex = 0;
		}
	}

    private: System::Void cboBrazo_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		int index = cboBrazo->SelectedIndex;
		if (index < 0) return;

		brazoActual = listaBrazos[index];
		txtA->Text = brazoActual->getRadioInicial().ToString("0.##");
		txtB->Text = brazoActual->getTasaExpansion().ToString("0.##");

		puntosEspiral = nullptr;
		lblInfo->Text = "Brazo listo para graficar.";
		pbLienzo->Invalidate();
	}

	private: System::Void btnGraficar_Click(System::Object^ sender, System::EventArgs^ e) {
		double a, b;
		if (!Double::TryParse(txtA->Text, a) || !Double::TryParse(txtB->Text, b) || a < 0 || b <= 0) {
			MessageBox::Show("Ingrese 'a' >= 0 y 'b' > 0.", "Datos Inválidos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Actualizar los parámetros del modelo
		brazoActual->setRadioInicial(a);
		brazoActual->setTasaExpansion(b);

		// Calcular espiral
		puntosEspiral = calculadora->CalcularEspiral(a, b);

		// Calcular radio máximo (al final de las 3 vueltas, theta = 6*PI)
		double radioMaxMM = a + b * 6.0 * Math::PI;

		// Calcular escala automática (usando el PictureBox de 639x431)
		float margen = 15.0f;
		float semiLado = Math::Min(pbLienzo->Width, pbLienzo->Height) / 2.0f;
		escalaActual = (float)((semiLado - margen) / radioMaxMM);

		// Actualizar info en pantalla
		lblInfo->Text = String::Format(
			"Fabricante: {0}\nPuntos: {1}\nRadio Máx: {2:F1} mm\nEscala: {3:F3} px/mm",
			brazoActual->getFabricante(), puntosEspiral->Count, radioMaxMM, escalaActual);

		pbLienzo->Invalidate();
	}

	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		puntosEspiral = nullptr;
		txtA->Clear();
		txtB->Clear();
		lblInfo->Text = "Lienzo limpio.";
		pbLienzo->Invalidate();
	}

	private: System::Void pbLienzo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->SmoothingMode = SmoothingMode::AntiAlias;

		// Calculamos el centro (como es 639x431, el centro será X=319.5 e Y=215.5)
		float centroX = pbLienzo->Width / 2.0f;
		float centroY = pbLienzo->Height / 2.0f;

		// A. Dibujar Ejes Coordenados
		Pen^ ejePen = gcnew Pen(Color::LightGray, 1);
		ejePen->DashStyle = DashStyle::Dash;

		// Usamos 0.0f para evitar el error E0308
		g->DrawLine(ejePen, centroX, 0.0f, centroX, (float)pbLienzo->Height); // Eje Y
		g->DrawLine(ejePen, 0.0f, centroY, (float)pbLienzo->Width, centroY);  // Eje X
		delete ejePen;

		// B. Dibujar Origen (Punto rojo)
		g->FillEllipse(Brushes::Red, centroX - 4.0f, centroY - 4.0f, 8.0f, 8.0f);

		// C. Dibujar Espiral
		if (puntosEspiral != nullptr && puntosEspiral->Count > 1) {
			array<PointF>^ puntosPantalla = gcnew array<PointF>(puntosEspiral->Count);

			for (int i = 0; i < puntosEspiral->Count; i++) {
				// Conversión a pixeles
				puntosPantalla[i] = PointF(
					centroX + (puntosEspiral[i].X * escalaActual),
					centroY - (puntosEspiral[i].Y * escalaActual)
				);
			}

			Pen^ lapizCurva = gcnew Pen(Color::RoyalBlue, 2.5f);
			g->DrawLines(lapizCurva, puntosPantalla); // Instrucción solicitada en el enunciado
			delete lapizCurva;
		}
	}
};
}
